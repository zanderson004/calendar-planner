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

void saveTasks(const vector<Task>& tasks) {
    ofstream saveFile;
    saveFile.open("tasks.txt", std::ofstream::out | std::ofstream::trunc);
    for (auto& task : tasks) {
        saveFile << task.getName() << ";" << task.getDescription() << ";" << to_string(task.getDueDateTime().getTime()) << "\n";
    }
    saveFile.close();
}

vector<Task> loadTasks() {
    ifstream saveFile;
    saveFile.open("tasks.txt");
    string line;
    vector<Task> res;

    while (getline(saveFile, line)) {
        vector<string> params = split(line, ';');
        res.emplace_back(params[0], params[1], make_unique<DateTime>(stoi(params[2])));
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

int main() {
    srand(time(nullptr));
    string cmd;
    vector<Task> tasks = loadTasks();
    Scheduler s;
    for (auto& task : tasks) s.addTask(task);

    while (true) {
        cout << "Enter command: ";
        cin >> cmd;
        if (cmd == "exit") {
            saveTasks(tasks);
            break;
        }
        else if (cmd == "task") {
            tasks.push_back(addTask());
            s.addTask(tasks.back());
        }
        else if (cmd == "get") {
            const ITask& temp = s.getNextTask();
            cout << temp.getName() << " " << temp.getDescription() << " " << temp.getDueDateTime().toString() << "\n";
        }
        else if (cmd == "print") {
            for (auto& task : tasks) cout << task.getId() << " " << task.getName() << " " << task.getDescription() << " " << task.getDueDateTime().toString() << "\n";
        }
        else if (cmd == "del") {
            cout << "Enter id: ";
        }
        else cout << "Wrong command" << endl;
    }
}

// vector<Task> tasks{Task("name", "desc", make_unique<DateTime>(30))};