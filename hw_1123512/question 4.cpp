// 邱涵楨
// 1123512
// 113.11.28
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

// Task structure to hold profit, deadline, and task ID
struct Task {
    int profit, deadline, id;
};

// Comparator function for sorting tasks by profit in descending order
bool compareTasks(const Task& a, const Task& b) {
    return a.profit > b.profit;
}

int main() {
    int N;
    cout << "Enter the number of tasks: ";
    cin >> N;

    vector<Task> tasks(N);
    cout << "Enter profit and deadline for each task:\n";
    for (int i = 0; i < N; ++i) {
        cin >> tasks[i].profit >> tasks[i].deadline;
        tasks[i].id = i + 1; // Store task ID (1-based index)
    }

    // Sort tasks by profit in descending order
    sort(tasks.begin(), tasks.end(), compareTasks);

    // Find the maximum deadline to determine the size of the timeline
    int maxDeadline = 0;
    for (const auto& task : tasks) {
        maxDeadline = max(maxDeadline, task.deadline);
    }

    // Use a set to track available time slots (1-based index)
    set<int> availableSlots;
    for (int i = 1; i <= maxDeadline; ++i) {
        availableSlots.insert(i); // Initially, all slots are available
    }

    int totalProfit = 0;
    vector<int> scheduledTasks;

    // Try to schedule each task
    for (const auto& task : tasks) {
        // Find the latest available slot that is <= task's deadline
        auto slot = availableSlots.lower_bound(task.deadline);
        if (slot != availableSlots.begin()) {
            --slot; // Move to the largest available slot that fits the deadline
            availableSlots.erase(slot); // Schedule this task and remove the slot
            totalProfit += task.profit;
            scheduledTasks.push_back(task.profit); // Record the scheduled task's profit
        }
    }

    // Output the results
    cout << "Maximum Profit: " << totalProfit << endl;
    cout << "Scheduled Tasks: [";
    for (size_t i = 0; i < scheduledTasks.size(); ++i) {
        cout << scheduledTasks[i];
        if (i != scheduledTasks.size() - 1) cout << ", ";
    }
    cout << "]\n";

    return 0;
}


