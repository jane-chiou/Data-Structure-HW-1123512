// 邱涵楨
// 1123512
// 113.11.28
#include <iostream>
#include <queue>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

// Define a Task structure
struct Task {
    string name;
    int priority;

    // Constructor for convenience
    Task(string n, int p) : name(n), priority(p) {}
};

// Comparator for priority queue
struct TaskComparator {
    bool operator()(const Task& a, const Task& b) {
        return a.priority < b.priority; // Higher priority first
    }
};

// Comparator function for sorting
bool compareTasks(const Task& a, const Task& b) {
    return a.priority > b.priority; // Sort descending
}

int main() {
    int N; // Number of operations
    cin >> N;
    cin.ignore(); // Ignore the newline character

    priority_queue<Task, vector<Task>, TaskComparator> taskQueue; // Max heap
    vector<Task> remainingTasks;
    vector<string> results;

    for (int i = 0; i < N; ++i) {
        string operation;
        getline(cin, operation);

        stringstream ss(operation);
        string command;
        ss >> command;

        if (command == "ADD") {
            string taskName;
            int priority;
            ss >> taskName >> priority;

            // Add task to the heap
            taskQueue.push(Task(taskName, priority));

        } else if (command == "GET") {
            if (!taskQueue.empty()) {
                Task highest = taskQueue.top();
                taskQueue.pop();
                results.push_back(highest.name);
            } else {
                results.push_back("NO_TASK");
            }
        }
    }

    // Transfer remaining tasks from the priority queue to a vector
    while (!taskQueue.empty()) {
        remainingTasks.push_back(taskQueue.top());
        taskQueue.pop();
    }

    // Sort tasks by priority (descending) using the named comparator function
    sort(remainingTasks.begin(), remainingTasks.end(), compareTasks);

    // Output results of "GET" operations
    for (const string& result : results) {
        cout << result << endl;
    }

    // Output remaining tasks in the specified format
    cout << "Remaining tasks: [";
    for (size_t i = 0; i < remainingTasks.size(); ++i) {
        cout << "('" << remainingTasks[i].name << "', " << remainingTasks[i].priority << ")";
        if (i != remainingTasks.size() - 1) {
            cout << ", ";
        }
    }
    cout << "]" << endl;

    return 0;
}


