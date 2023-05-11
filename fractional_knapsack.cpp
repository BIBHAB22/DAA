// Write a program in C or C++ to implement Fractional Knapsack algorithm.
// Find an optimal solution to the knapsack instance n = 7, W = 15.
// (p1, p2, ..., p7) = (10, 5, 15, 7, 6, 18, 3)
// and (w1, w2, ..., w7) = (2, 3, 5, 7, 1, 4, 1).
#include <iostream>
using namespace std;
// class for fractional knapsack
class Item
{
public:
    int value; //profit
    int weight; //weight
    double ratio; // profit/weight
};

void bubbleSort(Item arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j].ratio < arr[j + 1].ratio)
            {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

double fractionalKnapsack(int W, Item arr[], int n)
{
    bubbleSort(arr, n);
    double max_value = 0.0; //profit
    for (int i = 0; i < n; i++)
    {
        if (W == 0)
        {
            return max_value;
        }
        // storing the maximum weight that I put into the knapsack
        int weight = min(W, arr[i].weight);
        max_value += weight * arr[i].ratio;
        W -= weight;
    }
    return max_value;
}

int main()
{
    int n = 7; // mot kota item ache
    int W = 15; // bostar weight
    int p[] = {10, 5, 15, 7, 6, 18, 3}; //profit array
    int w[] = {2, 3, 5, 7, 1, 4, 1}; // weight array
    // creating an array of type Item
    Item arr[n]; // int arr[n];
    // configuring the items vector
    for (int i = 0; i < n; i++)
    {
        Item itemname;
        itemname.value = p[i];
        itemname.weight = w[i];
        itemname.ratio = (double)p[i] / w[i];
        arr[i] = itemname;
    }
    double max_value = fractionalKnapsack(W, arr, n);
    cout << "Maximum profit that can be obtained = " << max_value << endl;
    return 0;
}