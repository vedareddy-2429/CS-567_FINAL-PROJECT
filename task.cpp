#include "task_manager.h"
#include <iostream>
#include <cstring>

void addTask(Task tasks[], int &taskCount, const char *name) {
    if (taskCount >= MAX_TASKS) {
        std::cout << "Task limit reached. Cannot add more tasks." << std::endl;
        return;
    }
    
    strcpy(tasks[taskCount].name, name);
    tasks[taskCount].completed = 0;
    taskCount++;
    std::cout << "Task added successfully." << std::endl;
}

void markTaskCompleted(Task tasks[], int taskCount, const char *name) {
    for (int i = 0; i < taskCount; i++) {
        if (strcmp(tasks[i].name, name) == 0) {
            tasks[i].completed = 1;
            std::cout << "Task marked as completed." << std::endl;
            return;
        }
    }
    std::cout << "Task not found." << std::endl;
}

void listTasks(Task tasks[], int taskCount) {
    std::cout << "Tasks:" << std::endl;
    for (int i = 0; i < taskCount; i++) {
        std::cout << tasks[i].name << " - " << (tasks[i].completed ? "Completed" : "Not Completed") << std::endl;
    }
}

void deleteTask(Task tasks[], int &taskCount, const char *name) {
    bool found = false;
    for (int i = 0; i < taskCount; i++) {
        if (strcmp(tasks[i].name, name) == 0) {
            found = true;
            for (int j = i; j < taskCount - 1; j++) {
                strcpy(tasks[j].name, tasks[j + 1].name);
                tasks[j].completed = tasks[j + 1].completed;
            }
            taskCount--;
            std::cout << "Task deleted successfully." << std::endl;
            break;
        }
    }
    if (!found) {
        std::cout << "Task not found." << std::endl;
    }
}

void editTask(Task tasks[], int taskCount, const char *oldName, const char *newName) {
    bool found = false;
    for (int i = 0; i < taskCount; i++) {
        if (strcmp(tasks[i].name, oldName) == 0) {
            found = true;
            strcpy(tasks[i].name, newName);
            std::cout << "Task edited successfully." << std::endl;
            break;
        }
    }
    if (!found) {
        std::cout << "Task not found." << std::endl;
    }
}

void sortTasks(Task tasks[], int taskCount) {
    Task temp;
    for (int i = 0; i < taskCount - 1; i++) {
        for (int j = 0; j < taskCount - i - 1; j++) {
            if (strcmp(tasks[j].name, tasks[j + 1].name) > 0) {
                temp = tasks[j];
                tasks[j] = tasks[j + 1];
                tasks[j + 1] = temp;
            }
        }
    }
    std::cout << "Tasks sorted successfully." << std::endl;
}

void clearAllTasks(Task tasks[], int &taskCount) {
    taskCount = 0;
    std::cout << "All tasks cleared successfully." << std::endl;
}


int main() {
    Task tasks[MAX_TASKS];
    int taskCount = 0;
    int choice;
    char taskName[TASK_NAME_LENGTH];
    char newName[TASK_NAME_LENGTH];

    do {
        std::cout << "\nTask Manager Menu:\n";
        std::cout << "1. Add Task\n";
        std::cout << "2. Mark Task Completed\n";
        std::cout << "3. List Tasks\n";
        std::cout << "4. Delete Task\n";
        std::cout << "5. Edit Task\n";
        std::cout << "6. Sort Tasks\n";
        std::cout << "7. Clear All Tasks\n";
        std::cout << "8. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch(choice) {
            case 1:
                std::cout << "Enter task name: ";
                std::cin >> taskName;
                addTask(tasks, taskCount, taskName);
                break;
            case 2:
                std::cout << "Enter task name to mark as completed: ";
                std::cin >> taskName;
                markTaskCompleted(tasks, taskCount, taskName);
                break;
            case 3:
                listTasks(tasks, taskCount);
                break;
            case 4:
                std::cout << "Enter task name to delete: ";
                std::cin >> taskName;
                deleteTask(tasks, taskCount, taskName);
                break;
            case 5:
                std::cout << "Enter task name to edit: ";
                std::cin >> taskName;
                std::cout << "Enter new task name: ";
                std::cin >> newName;
                editTask(tasks, taskCount, taskName, newName);
                break;
            case 6:
                sortTasks(tasks, taskCount);
                break;
            case 7:
                clearAllTasks(tasks, taskCount);
                break;
            case 8:
                std::cout << "Exiting..." << std::endl;
                break;
            default:
                std::cout << "Invalid choice. Please try again." << std::endl;
        }
    } while (choice != 8);

    return 0;
}
