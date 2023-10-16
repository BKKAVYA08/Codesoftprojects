#include <iostream>
#include <vector>

struct Task {
    std::string description;
    bool completed;
};

class TodoList {
private:
    std::vector<Task> tasks;

public:
    void addTask(const std::string& description) {
        Task newTask{description, false};
        tasks.push_back(newTask);
        std::cout << "Task added: " << description << std::endl;
    }

    void viewTasks() {
        std::cout << "Tasks:" << std::endl;
        for (size_t i = 0; i < tasks.size(); ++i) {
            std::cout << i + 1 << ". ";
            std::cout << (tasks[i].completed ? "[X] " : "[ ] ");
            std::cout << tasks[i].description << std::endl;
        }
    }

    void deleteTask(size_t index) {
        if (index >= 1 && index <= tasks.size()) {
            tasks.erase(tasks.begin() + index - 1);
            std::cout << "Task deleted successfully." << std::endl;
        } else {
            std::cout << "Invalid task number." << std::endl;
        }
    }
};

int main() {
    TodoList todoList;

    while (true) {
        std::cout << "Options:" << std::endl;
        std::cout << "1. Add Task" << std::endl;
        std::cout << "2. View Tasks" << std::endl;
        std::cout << "3. Delete Task" << std::endl;
        std::cout << "4. Exit" << std::endl;

        int choice;
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1: {
                std::string taskDescription;
                std::cout << "Enter task description: ";
                std::cin.ignore(); // Ignore newline character left in the input buffer
                std::getline(std::cin, taskDescription);
                todoList.addTask(taskDescription);
                break;
            }
            case 2:
                todoList.viewTasks();
                break;
            case 3: {
                size_t taskIndex;
                std::cout << "Enter task number to delete: ";
                std::cin >> taskIndex;
                todoList.deleteTask(taskIndex);
                break;
            }
            case 4:
                std::cout << "Exiting program. Goodbye!" << std::endl;
                return 1;
            default:
                std::cout << "Invalid choice. Please try again." << std::endl;
        }
    }

    return 1;
}
