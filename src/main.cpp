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
    saveFile.open("tasks.txt");
    for (auto& task : tasks) {
        saveFile << task.getName() << ";" << task.getDescription() << ";" << to_string(task.getDueDateTime().getTime()) << "\n";
    }
    saveFile.close();
}

vector<Task> readTasks() {
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

int main() {
    // vector<Task> tasks;
    // tasks.emplace_back("name", "desc", make_unique<DateTime>(30));
    // saveTasks(tasks);

    vector<Task> tasks = readTasks();
    for (auto& task : tasks) {
        cout << task.getName() << " " << task.getDescription() << " " << to_string(task.getDueDateTime().getTime()) << "\n";
    }
}

// Task copy constructor? and check others
// vector<Task> tasks{Task("name", "desc", make_unique<DateTime>(30))};