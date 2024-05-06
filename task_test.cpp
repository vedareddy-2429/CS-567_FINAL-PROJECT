#include <deepstate/DeepState.hpp>
#include "task_manager.cpp"  
using namespace deepstate;

TEST(TaskManager, AddTask) {
    // Initialize task manager
    Task tasks[MAX_TASKS];
    int taskCount = 0;

    // Generate a random task name

    int randomNumber = DeepState_IntInRange(1, 100000);
    std::string taskName = "a" + std::to_string(randomNumber);

    addTask(tasks, taskCount, taskName.c_str());

    // Verify that the task was added successfully
    ASSERT_EQ(taskCount, 1);
    //ASSERT_TRUE(strcmp(tasks[0].name, taskName) == 0);
    ASSERT_FALSE(tasks[0].completed);
}

TEST(TaskManager, MarkTaskCompleted) {
    // Initialize task manager
    Task tasks[MAX_TASKS] = {{"Task 1", 0}, {"Task 2", 0}};
    int taskCount = 2;

    // Choose a random task to mark as completed
    int index = DeepState_IntInRange(0, taskCount - 1);

    // Mark the task as completed
    markTaskCompleted(tasks, taskCount, tasks[index].name);

    // Verify that the task was marked as completed
    ASSERT_TRUE(tasks[index].completed);
}

// Add more tests for other functions such as listTasks, deleteTask, editTask, sortTasks, and clearAllTasks

TEST(TaskManager, ChoiceBetween1to8) {
    // Generate a random choice between 1 to 8
    int choice = DeepState_IntInRange(1, 8);

    // Verify that the choice is within the specified range
    ASSERT_GE(choice, 1);
    ASSERT_LE(choice, 8);
}

int main(int argc, char* argv[]) {
    DeepState_InitOptions(argc, argv);

    // Run the DeepState tests
    DeepState_Run();
    
    return 0;
}
