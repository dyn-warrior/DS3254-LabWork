//The Activity Selection Problem is a classic Greedy Algorithm problem where we aim to select the maximum number of non-overlapping activities.
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Activity {
    int start, finish;
};

// Comparator function to sort by finish time
bool compare(Activity a, Activity b) {
    return a.finish < b.finish;
}

void activitySelection(vector<Activity> &activities) {
    sort(activities.begin(), activities.end(), compare);
    
    cout << "Selected Activities: \n";
    int last_finish = 0;
    
    for (auto act : activities) {
        if (act.start >= last_finish) {
            cout << "(" << act.start << ", " << act.finish << ")\n";
            last_finish = act.finish;
        }
    }
}

int main() {
    vector<Activity> activities = {{1, 3}, {2, 5}, {4, 6}, {6, 8}, {5, 7}, {8, 9}};
    activitySelection(activities);
    return 0;
}


