#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>
#include <ctime>

struct Task {
    std::string description;
    std::string time;        // Format: "HH:MM"
    bool isCompleted = false;
};

class Schedule {
private:
    std::vector<Task> tasks;

    // Helper to convert time string to minutes since midnight for sorting
    int timeToMinutes(const std::string& t) {
        int h, m;
        sscanf(t.c_str(), "%d:%d", &h, &m);
        return h * 60 + m;
    }

public:
    void addTask(const std::string& desc, const std::string& t) {
        tasks.push_back({desc, t, false});
        sortTasks();
        std::cout << "✨ Task added successfully!\n";
    }

    void markCompleted(int index) {
        if (index >= 0 && index < tasks.size()) {
            tasks[index].isCompleted = true;
            std::cout << "💖 Task marked as complete!\n";
        } else {
            std::cout << "Invalid task number.\n";
        }
    }

    void removeTask(int index) {
        if (index >= 0 && index < tasks.size()) {
            std::cout << "Removed: " << tasks[index].description << "\n";
            tasks.erase(tasks.begin() + index);
        }
    }

    void sortTasks() {
        std::sort(tasks.begin(), tasks.end(), [&](const Task& a, const Task& b) {
            return timeToMinutes(a.time) < timeToMinutes(b.time);
        });
    }

    void display() {
        std::cout << "\n";
        std::cout << "======================================\n";
        std::cout << "     MITCHEL MARITIM'S SCHEDULE ❤️\n";
        std::cout << "======================================\n\n";

        if (tasks.empty()) {
            std::cout << "   No tasks yet... Time to make some plans? 😉\n\n";
            return;
        }

        for (size_t i = 0; i < tasks.size(); ++i) {
            std::string status = tasks[i].isCompleted ? "✅" : "⬜";
            std::cout << i + 1 << ". " << status << "  "
                      << std::setw(8) << tasks[i].time << "  -  "
                      << tasks[i].description << "\n";
        }

        std::cout << "\n======================================\n";
        std::cout << "   Made with love for Mitchel Maritim\n";
        std::cout << "======================================\n\n";
    }

    size_t size() const { return tasks.size(); }
};

int main() {
    Schedule mySchedule;

    // Initial romantic tasks
    mySchedule.addTask("(Bring Dairyland Mint Choc) its Maritim's favorite.", "11:30");
    mySchedule.addTask("Meet Mitchel Maritim at the Echoes of Glory auditions", "15:40");

    int choice;
    do {
        std::cout << "\n=== Schedule Menu ===\n";
        std::cout << "1. View Schedule\n";
        std::cout << "2. Add New Task\n";
        std::cout << "3. Mark Task as Done\n";
        std::cout << "4. Remove Task\n";
        std::cout << "5. Exit\n";
        std::cout << "Choice: ";
        std::cin >> choice;
        std::cin.ignore();  // Clear newline

        switch (choice) {
            case 1:
                mySchedule.display();
                break;
            case 2: {
                std::string desc, time;
                std::cout << "Task description: ";
                std::getline(std::cin, desc);
                std::cout << "Time (HH:MM): ";
                std::getline(std::cin, time);
                mySchedule.addTask(desc, time);
                break;
            }
            case 3: {
                int idx;
                mySchedule.display();
                std::cout << "Enter task number to complete: ";
                std::cin >> idx;
                mySchedule.markCompleted(idx - 1);
                break;
            }
            case 4: {
                int idx;
                mySchedule.display();
                std::cout << "Enter task number to remove: ";
                std::cin >> idx;
                mySchedule.removeTask(idx - 1);
                break;
            }
            case 5:
                std::cout << "See you later, lover girl 💕\n";
                break;
            default:
                std::cout << "Invalid choice!\n";
        }
    } while (choice != 5);

    return 0;
}