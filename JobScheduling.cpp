#include <iostream>
using namespace std;

class Job {
public:
    char id;
    int deadline;
    int profit;
};

int main() {
    int n;

    cout << "Enter number of jobs: ";
    cin >> n;

    Job job[100];

    // Input jobs
    for (int i = 0; i < n; i++) {
        cout << "\nEnter Job ID: ";
        cin >> job[i].id;

        cout << "Enter Deadline: ";
        cin >> job[i].deadline;

        cout << "Enter Profit: ";
        cin >> job[i].profit;
    }

    // Sort jobs by profit in decreasing order
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (job[i].profit < job[j].profit) {
                Job temp = job[i];
                job[i] = job[j];
                job[j] = temp;
            }
        }
    }

    // Find maximum deadline
    int maxDeadline = 0;

    for (int i = 0; i < n; i++) {
        if (job[i].deadline > maxDeadline) {
            maxDeadline = job[i].deadline;
        }
    }

    // Create empty slots
    char slot[100];

    for (int i = 0; i < maxDeadline; i++) {
        slot[i] = '-';
    }

    int totalProfit = 0;

    // Schedule jobs
    for (int i = 0; i < n; i++) {

        // Check from the latest slot before the deadline
        for (int j = job[i].deadline - 1; j >= 0; j--) {

            if (slot[j] == '-') {
                slot[j] = job[i].id;
                totalProfit = totalProfit + job[i].profit;
                break;
            }
        }
    }

    // Display scheduled jobs
    cout << "\nScheduled Jobs: ";

    for (int i = 0; i < maxDeadline; i++) {
        if (slot[i] != '-') {
            cout << slot[i] << " ";
        }
    }

    cout << "\nMaximum Profit: " << totalProfit << endl;

    return 0;
}