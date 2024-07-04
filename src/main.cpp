#include "entities/DateTime.hpp"
#include "entities/Task.hpp"

#include <iostream>
#include <vector>

using namespace std;

int main() {
    string n = "name";
    int ti = 2100000000;
    Task t{n, make_unique<DateTime>(ti)};
    const string& curr = t.getId();
    cout << curr << endl;
    const auto& x = t.getDueDateTime();
    cout << x.toString() << endl;
}