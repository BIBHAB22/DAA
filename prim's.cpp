#include <iostream>
#include <fstream>
#include <climits>
using namespace std;
#define vertices 6
int key[vertices];    // track for minimum edge weights
bool mst[vertices];   // track for if the node is visited or not
int parent[vertices]; // track for who is the parent of the node
// function to find out the minimum edge length index value from key array
int findMin(int key[], int n, bool mst[])
{
    int minVal = INT_MAX;
    int minIndex = -1;
    // finding the minimum value
    for (int i = 0; i < n; i++)
    {
        // if mst[i] = true then it can't be considered again
        if (mst[i] == false && key[i] < minVal)
        {
            minVal = key[i];
            minIndex = i;
        }
    }
    return minIndex;
}
void primsAlgo(int n, int adjMatrix[vertices][vertices])
{
    key[0] = 0; // it is the requirement of the algorithm
    parent[0] = -1;
    for (int i = 0; i < n; i++)
    {
        // find the index whose edge weight is minimum
        int minIndex = findMin(key, n, mst);
        // as the minimum index has been chosen so update the mst index as True
        mst[minIndex] = true;
        // now explore other vertices from this selected node
        for (int i = 0; i < n; i++)
        {
            // that means the edge has a connection
            if (adjMatrix[minIndex][i] != 0)
            {
                // if the node value is smaller and it is marked false in mst also then it should be visited
                if (key[i] > adjMatrix[minIndex][i] && mst[i] == false)
                {
                    // update the key index with the minimum value node
                    key[i] = adjMatrix[minIndex][i];
                    // update parent index with the minimum
                    parent[i] = minIndex;
                }
            }
        }
    }
    // now print which edges should be connected to build a spanning tree
    cout << "Parent\tChild\tWeight\n";
    for (int i = 1; i < n; i++)
    {
        cout << char('A' + parent[i]) << "\t" << char('A' + i) << "\t" << key[i] << endl;
    }
}
int main()
{
    fstream inputFile;
    inputFile.open("graph.txt", ios::in);
    int n;
    inputFile >> n;
    int adjMatrix[vertices][vertices]; // creating a adjacency matrix for the graph
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            inputFile >> adjMatrix[i][j];
        }
    }
    // now initialization of different arrays
    for (int i = 0; i < n; i++)
    {
        // initialized all elements of key array with INT_MAX except first element
        key[i] = INT_MAX;
        // initialized all elements of mst with false value
        mst[i] = {false};
        // initialized all parent array elements with -1
        parent[i] = -1;
    }
    primsAlgo(n, adjMatrix);
    return 0;
}