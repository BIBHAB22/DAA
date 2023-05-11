//  Write a program in C or C++ to implement Job Scheduling algorithm. What is the
// solution generated by the function JS when n = 7?
// (p1, p2, ..., p7) = (3, 5, 20, 18, 1, 6, 30)
// and (d1, d2, ..., d7) = (1, 3, 4, 3, 2, 1, 2)
#include <iostream>
using namespace std;
#define n 7
class job
{
public:
    int profit;
    int deadline;
};
// function to get the maximum size for gannt chart
int getMax(int deadline[])
{
    int max_size = 0; // initially max_size is 0
    for (int i = 0; i < n; i++)
    {
        max_size = max(max_size, deadline[i]); // updating the max_size
    }
    return max_size;
}
void bubbleSort(job arr[])
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j].profit < arr[j + 1].profit)
            {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}
// main job sequencing function to calculate the maximum profit earned
int jobSequencing(job *arr, int *gantt_chart, int &max_size)
{
    bubbleSort(arr);  // sort the array with respect to profit in descending order
    for (int i = 0; i < n; i++)
    {
        // getting the index of the deadline as per the algorithm
        int index = arr[i].deadline - 1; // -1 is important as array index starts from 0
        // if the current index is not 0 then just go before it's index until it gets 0
        while (gantt_chart[index] > 0 && index > 0)
        {
            index--; // decrementing the index value
        }
        // if the value at the index is 0 that means there is no elements present previosly
        if (gantt_chart[index] == 0)
        {
            // just put the profit at that index
            gantt_chart[index] = arr[i].profit;
        }
    }
    int total_profit = 0;
    // now to calculate total profit we need to traverse whole gannt chart
    for (int i = 0; i < max_size; i++)
    {
        total_profit += gantt_chart[i];
    }
    // returning the maximum profit earned by job scheduling
    return total_profit;
}

int main()
{
    int profit[] = {3, 5, 20, 18, 1, 6, 30};
    int deadline[] = {1, 3, 4, 3, 2, 1, 2};
    // to get the max size for the gannt chart calling getMax()
    int max_size = getMax(deadline);
    // initialized all elements of gannt chart with 0
    int gantt_chart[max_size] = {0};
    job arr[n];                       // creating an array of type jobSequencing
    // fill the array with required informations
    for (int i = 0; i < n; i++)
    {
        arr[i].profit = profit[i];
        arr[i].deadline = deadline[i];
    } 
    // calling the job sequencing function to get the maximum profit
    cout << "Maximum Profit will be: " << jobSequencing(arr, gantt_chart, max_size) << endl;
    return 0;
}
// [6 30 18 20] = 74
// [(30,2),(20,4),(18,3),(6,1),(5,3),(3,1),(1,2)]