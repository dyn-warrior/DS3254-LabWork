//C++ Implementation of Fractional Knapsack (Greedy)

#include <bits/stdc++.h>
using namespace std;

// Structure for an item
struct Item {
    int weight, value;
};

// Comparator function to sort items by value-to-weight ratio
bool compare(Item a, Item b) {
    double r1 = (double)a.value / a.weight;
    double r2 = (double)b.value / b.weight;
    return r1 > r2;  // Sort in decreasing order
}

// Function to solve the Fractional Knapsack problem
double fractionalKnapsack(int W, vector<Item>& items) {
    // Sort items based on value/weight ratio
    sort(items.begin(), items.end(), compare);
    
    double totalValue = 0.0; // Total value collected
    int currentWeight = 0;   // Current weight in knapsack
    
    for (auto item : items) {
        if (currentWeight + item.weight <= W) {
            // Take full item
            currentWeight += item.weight;
            totalValue += item.value;
        } else {
            // Take fraction of item
            int remaining = W - currentWeight;
            totalValue += (item.value * ((double)remaining / item.weight));
            break; // Knapsack is full
        }
    }

    return totalValue;
}

int main() {
    int W = 50; // Knapsack weight capacity
    vector<Item> items = {{10, 60}, {20, 100}, {30, 120}}; // {weight, value}

    double maxValue = fractionalKnapsack(W, items);
    cout << "Maximum value in Knapsack = " << maxValue << endl;

    return 0;
}


//Greedy Algorithm for Fractional Knapsack

double fractionalKnapsack(int W, vector<Item>& items) {
    // Sort items based on value/weight ratio
    sort(items.begin(), items.end(), [](Item a, Item b) {
        return (double)a.value / a.weight > (double)b.value / b.weight;
    });

    double totalValue = 0.0;
    int currentWeight = 0;

    for (auto item : items) {
        if (currentWeight + item.weight <= W) {
            // Take full item
            currentWeight += item.weight;
            totalValue += item.value;
        } else {
            // Take fraction of item
            int remaining = W - currentWeight;
            totalValue += (item.value * ((double)remaining / item.weight));
            break; // Knapsack is full
        }
    }

    return totalValue;
}


//0-1 Knapsack DP Algorithm (Bottom-Up)

int knapsack(int W, vector<int>& weight, vector<int>& value, int n) {
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));

    for (int i = 1; i <= n; i++) {
        for (int w = 0; w <= W; w++) {
            if (weight[i - 1] <= w) {
                dp[i][w] = max(dp[i - 1][w], dp[i - 1][w - weight[i - 1]] + value[i - 1]);
            } else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    return dp[n][W];
}


//
