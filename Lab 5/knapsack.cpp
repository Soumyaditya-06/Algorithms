#include <iostream>
#include <algorithm>
using namespace std;

struct Item {
    int weight, profit;
};

// 🔸 Profit-wise sorting
bool cmpProfit(Item a, Item b) {
    return a.profit > b.profit;
}

// 🔸 Weight-wise sorting
bool cmpWeight(Item a, Item b) {
    return a.weight < b.weight;
}

// 🔸 Ratio-wise sorting
bool cmpRatio(Item a, Item b) {
    return (double)a.profit / a.weight > (double)b.profit / b.weight;
}

// 🔹 Fractional Knapsack Function
double knapsack(Item arr[], int n, int capacity, int type) {

    if(type == 1)
        sort(arr, arr+n, cmpProfit);
    else if(type == 2)
        sort(arr, arr+n, cmpWeight);
    else
        sort(arr, arr+n, cmpRatio);

    double totalProfit = 0.0;

    for(int i = 0; i < n; i++) {
        if(capacity >= arr[i].weight) {
            capacity -= arr[i].weight;
            totalProfit += arr[i].profit;
        }
        else {
            totalProfit += arr[i].profit * ((double)capacity / arr[i].weight);
            break;
        }
    }

    return totalProfit;
}

int main() {
    int n = 5;
    Item arr[] = {
        {10, 60},
        {20, 100},
        {30, 120},
        {5, 50},
        {15, 70}
    };

    int capacity = 50;

    cout << "Profit-wise: " << knapsack(arr, n, capacity, 1) << endl;
    cout << "Weight-wise: " << knapsack(arr, n, capacity, 2) << endl;
    cout << "Ratio-wise: " << knapsack(arr, n, capacity, 3) << endl;

    return 0;
}