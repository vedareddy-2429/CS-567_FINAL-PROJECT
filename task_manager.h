#ifndef TASK_MANAGER_H
#define TASK_MANAGER_H

#define MAX_TASKS 100
#define TASK_NAME_LENGTH 50

typedef struct {
    char name[TASK_NAME_LENGTH];
    int completed;
} Task;

void addTask(Task tasks[], int &taskCount, const char *name);
void markTaskCompleted(Task tasks[], int taskCount, const char *name);
void listTasks(Task tasks[], int taskCount);
void deleteTask(Task tasks[], int &taskCount, const char *name);
void editTask(Task tasks[], int taskCount, const char *oldName, const char *newName);
void sortTasks(Task tasks[], int taskCount);
void clearAllTasks(Task tasks[], int &taskCount);

#endif /* TASK_MANAGER_H */
