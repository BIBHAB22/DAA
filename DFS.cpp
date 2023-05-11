#include<iostream>
#include<fstream>
#define MAX 10
using namespace std;
int adjmatrix[MAX][MAX];
int n=0;
fstream inputfile;
void dfs_recursion(int i,int *visited,int(*adjmatrix)[MAX]){
    inputfile << char(i+'A') << " ";
    visited[i]=1;
    for(int j=0;j<n;j++){
        if(adjmatrix[i][j]==1 && visited[j]){
            dfs_recursion(j,visited,adjmatrix);
        }
    }
}
int main(){
    inputfile open("graph.txt",ios::in);
    inputfile >>n;
    adjmatrix[n][n];
    for(int i=0;i<n;i++){
        for(int j=0;)
    }
}