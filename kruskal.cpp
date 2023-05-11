#include <iostream>
#include <fstream>
using namespace std;
int n;

struct Edge
{
    int v1;
    int v2;
    int weight;
};

struct Edge edge[100];
int edgeCount = 0;

void readGraph()
{
    fstream input;
    input.open("graph.txt", ios::in);
    input >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int number;
            input >> number;
            if (number != 0)
            {
                edge[edgeCount].v1 = i;
                edge[edgeCount].v2 = j;
                edge[edgeCount++].weight = number;
            }
        }
    }
    input.close();
}

void showGraph()
{
    for (int i = 0; i < edgeCount; i++)
    {
        cout << "(" << char('A' + edge[i].v1) << "," << char('A' + edge[i].v2) << ") -> " << edge[i].weight << endl;
    }
}

void BubbleSort()
{
    for (int i = 0; i < edgeCount - 1; i++)
    {
        for (int j = 0; j < edgeCount - i - 1; j++)
        {
            int weight1 = edge[j].weight;
            int weight2 = edge[j + 1].weight;
            if (weight1 > weight2)
            {
                swap(edge[j], edge[j + 1]);
            }
        }
    }
}

int parent[100];
int mst[100][3];
int mstE = 0; 
void MakeSet()
{
    for (int i = 0; i < n; i++)
    {
        parent[i] = -1;
    }
}

int find(int i)
{
    while (parent[i] > 0)
    {
        i = parent[i];
    }
    return i;
}

void Union(int i, int j)
{
    int u = find(i);
    int v = find(j);
    parent[u] = v;
}

void Kruskal()
{
    BubbleSort();
    MakeSet();
    for (int i = 0; i < edgeCount; i++)
    {
        if (find(edge[i].v1) != find(edge[i].v2))
        {
            Union(edge[i].v1, edge[i].v2);
            mst[mstE][0] = edge[i].v1;
            mst[mstE][1] = edge[i].v2;
            mst[mstE][2] = edge[i].weight;
            mstE++;
        }
    }
}
void showMst()
{
    for (int i = 0; i < mstE; i++)
    {
        cout << "(" << char('A' + mst[i][0]) << "," << char('A' + mst[i][1]) << ") -> " << mst[i][2] << endl;
    }
}
int main()
{
    readGraph();
    Kruskal();
    showMst();
    return 0;
}
