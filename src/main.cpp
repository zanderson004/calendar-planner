#include "entities/DateTime.hpp"
#include "entities/Task.hpp"

#include <iostream>
#include <vector>

using namespace std;

vector<string> split(const string& s, char delimiter) {
    if (s.size() == 0) return {};

    vector<string> res;
    size_t prevPos = s[0] == delimiter ? 1 : 0;
    size_t pos = s.find(delimiter, prevPos);

    while (pos < string::npos) {
        res.push_back(s.substr(prevPos, pos-prevPos));
        pos++;
        prevPos = pos;
        pos = s.find(delimiter, pos);
    }
    if (prevPos != s.size()) res.push_back(s.substr(prevPos));
    return res;
}

#include <fstream>

void saveTasks(const vector<unique_ptr<Task>>& tasks) {
    ofstream saveFile;
    saveFile.open("tasks.txt", std::ofstream::out | std::ofstream::trunc);
    for (auto& task : tasks) {
        saveFile << task->getName() << ";" << task->getDescription() << ";" << to_string(task->getDueDateTime().getTime()) << "\n";
    }
    saveFile.close();
}

vector<unique_ptr<Task>> loadTasks() {
    ifstream saveFile;
    saveFile.open("tasks.txt");
    string line;
    vector<unique_ptr<Task>> res;

    while (getline(saveFile, line)) {
        vector<string> params = split(line, ';');
        res.emplace_back(make_unique<Task>(params[0], params[1], make_unique<DateTime>(stoi(params[2]))));
    }
    saveFile.close();
    return res;
}

Task addTask() {
    string name, desc, hours;
    cout << "Enter name: ";
    cin >> name;
    cout << "Enter description: ";
    cin >> desc;
    cout << "Enter hours until due: ";
    cin >> hours;
    return Task{name, desc, make_unique<DateTime>(time(nullptr) + stoi(hours) * 60 * 60)};
}

#include "entities/Scheduler.hpp"

void deleteTask(Scheduler& s, vector<unique_ptr<Task>>& tasks) {
    cout << "Enter id: ";
    string id;
    cin >> id;
    s.removeTask(id);
    bool sentinel = true;
    for (auto& task : tasks) {
        if (task->getId() == id) {
            swap(task, tasks.back());
            tasks.pop_back();
            sentinel = false;
            break;
        }
    }
    if (sentinel) cout << "No task found with given id.\n";
    else cout << "Task deleted.\n";
}

#include <map>
#include <exception>

const unordered_map<string, string> dayMap {
    {"Mon", "0"},
    {"Tue", "1"},
    {"Wed", "2"},
    {"Thu", "3"},
    {"Fri", "4"},
    {"Sat", "5"},
    {"Sun", "6"}
};

void loadConfig(vector<unique_ptr<Task>>& tasks) {
    // Consider edge case where small delay makes difference
    // Store last task instead of time
    // Stored time is has already been processed, is not inclusive of what needs to be added
    fstream lastRunFile;
    lastRunFile.open("lastRun.txt", std::ofstream::out | std::ofstream::trunc);
    string lastRunTimeString;
    lastRunFile >> lastRunTimeString;
    time_t lastRunTime = stoi(lastRunTimeString);
    time_t currTime = time(nullptr);
    lastRunFile << to_string(currTime);
    lastRunFile.close();

    // Week day then time to due day, time
    map<string, string> configuredTasks;

    ifstream configFile;
    configFile.open("config.txt");
    string line;

    // map days to tasks in sorted order by their start time
    // iterate day by day and add all tasks starting on that day, edge cases for begin and end days
    while (getline(configFile, line)) {
        if (line.size() == 0) continue;
        vector<string> params = split(line, ';');
        if (params.size() != 6) throw runtime_error("Incorrect config file");
        string name = params[0], duration = params[1], startDay = params[2], startTime = params[3], endDay = params[4], endTime = params[5];
        configuredTasks[dayMap.at(startDay) + startTime] = name + ";" + duration + ";" + dayMap.at(endDay) + endTime;
    }
    configFile.close();

    // Insert new tasks
    tm* time_info = localtime(&lastRunTime);
    string start = to_string(time_info->tm_wday) + to_string(time_info->tm_hour) + to_string(time_info->tm_min);
    auto it = configuredTasks.upper_bound(start);
    DateTime dtsd
    while () {

    }
}

int main() {
    // Vector reallocation, need to either reserve or use unique ptrs
    srand(static_cast<unsigned int>(time(nullptr)));
    string cmd;
    vector<unique_ptr<Task>> tasks = loadTasks();
    loadConfig(tasks);
    Scheduler s;
    for (auto& task : tasks) s.addTask(*task);

    while (true) {
        cout << "Enter command: ";
        cin >> cmd;
        if (cmd == "exit") {
            saveTasks(tasks);
            break;
        }
        else if (cmd == "task") {
            tasks.push_back(make_unique<Task>(addTask()));
            s.addTask(*tasks.back());
        }
        else if (cmd == "get") {
            if (tasks.size() == 0) {
                cout << "No tasks.\n";
                continue;
            }
            const ITask& temp = s.getNextTask();
            cout << temp.getName() << " " << temp.getDescription() << " " << temp.getDueDateTime().toString() << "\n";
        }
        else if (cmd == "print") {
            for (auto& task : tasks) cout << task->getId() << " " << task->getName() << " " << task->getDescription() << " " << task->getDueDateTime().toString() << "\n";
        }
        else if (cmd == "del") {
            deleteTask(s, tasks);
        }
        else cout << "Wrong command" << endl;
    }
}

// Add weekly tasks automatically
    // config file
    // specify task name, estimated duration, datetime to add to scheduler, due datetime
    // will need to store when app was last used so new tasks are automatically scheduled upon launch

// Add estimated hours I have per week
    // config file x hours per day

// Topological task requirements eg task1 -> task2

// Am I ahead or behind schedule?
    // print x hours required to be on schedule for the week
    // based on hours remaining in week + estimated durations
    // 9;9;2;11;8;0;0