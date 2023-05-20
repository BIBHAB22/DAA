#include <iostream>
#include <fstream>
#include <climits>
#define MAX 10
using namespace std;

int arr[MAX] = {0};
int top = -1;

bool isEmpty()
{
    return top == -1;
}

void push(int element)
{
    arr[++top] = element;
}

int pop()
{
    if (isEmpty())
    {
        return INT_MIN;
    }
    else
    {
        int element = arr[top];
        top--;
        return element;
    }
}

int main()
{
    fstream inputFile;
    inputFile.open("graph.txt", ios::in);
    int n;
    inputFile >> n;
    int adjMatrix[n][n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            inputFile >> adjMatrix[i][j];
        }
    }
    inputFile.close();
    int visited[n] = {0};
    printf("%c ", char(65 + j) );
    push(0);
    visited[0] = 1;
    while (!isEmpty())
    {
        int node = pop();
        for (int j = 0; j < n; j++)
        {
            if (adjMatrix[node][j] == 1 && visited[j] == 0)
            {
                push(j);
                visited[j] = 1;
                printf("%c ", char(65 + j) );
            }
        }
    }
    return 0;
}
