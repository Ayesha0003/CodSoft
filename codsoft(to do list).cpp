#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Task structure to store task details
struct Task {
    string description;
    bool completed;

    Task(string desc) : description(desc), completed(false) {}
};

// Function to add a task to the list
void AddTask(vector<Task>& tasks, const string& description) {
    tasks.push_back(Task(description));
    cout << "Task added: " << description << endl;
}

// Function to view tasks
void ViewTasks(const vector<Task>& tasks) {
    if (tasks.empty()) {
        cout << "No tasks in the list." << endl;
    } else {
        cout << "Tasks:" << endl;
        for (size_t i = 0; i < tasks.size(); ++i) {
            cout << i + 1 << ". ";
            cout << (tasks[i].completed ? "[X] " : "[ ] ");
            cout << tasks[i].description << endl;
        }
    }
}

// Function to mark a task as completed
void MarkTaskAsCompleted(vector<Task>& tasks, int index) {
    if (index >= 0 && index < tasks.size()) {
        tasks[index].completed = true;
        cout << "Task marked as completed: " << tasks[index].description << endl;
    } else {
        cout << "Invalid task index." << endl;
    }
}

// Function to remove a task from the list
void RemoveTask(vector<Task>& tasks, int index) {
    if (index >= 0 && index < tasks.size()) {
        cout << "Task removed: " << tasks[index].description << endl;
        tasks.erase(tasks.begin() + index);
    } else {
        cout << "Invalid task index." << endl;
    }
}

int main() {
    vector<Task> tasks;
    int choice;

    cout << "Simple To-Do List Manager" << endl;

    while (true) {
        cout << "\nOptions:\n";
        cout << "1. Add Task\n";
        cout << "2. View Tasks\n";
        cout << "3. Mark Task as Completed\n";
        cout << "4. Remove Task\n";
        cout << "5. Quit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                {
                    string description;
                    cout << "Enter task description: ";
                    cin.ignore(); // Clear newline character from previous input
                    getline(cin, description);
                    AddTask(tasks, description);
                    break;
                }
            case 2:
                ViewTasks(tasks);
                break;
            case 3:
                {
                    int index;
                    cout << "Enter the index of the task to mark as completed: ";
                    cin >> index;
                    MarkTaskAsCompleted(tasks, index - 1);
                    break;
                }
            case 4:
                {
                    int index;
                    cout << "Enter the index of the task to remove: ";
                    cin >> index;
                    RemoveTask(tasks, index - 1);
                    break;
                }
            case 5:
                cout << "Goodbye!" << endl;
                return 0;
            default:
                cout << "Invalid choice. Please select a valid option." << endl;
        }
    }

    return 0;
}
