#include<iostream>
#include<fstream>
#include<climits>
#define MAX 10
using namespace std;
int arr[MAX]={0};
int front=-1,rear=-1;
bool isEmpty(){
    return front==-1;
}
void enque(int element){
    if(front==-1)
        front=0;
    rear++;
    arr[rear]=element;
}
void del(){
    if(isEmpty())
        return;
    else{
        if(front>=rear){
            front=-1;
            rear=-1;
        }
        else{
            front++;
        }
        
        
    }
}
int peek(){
    if(isEmpty())
        return INT_MIN;
    return arr[front];
}
int main(){
    fstream inputfile;
    inputfile.open("graph.txt",ios::in);
    int n;
    inputfile >> n;
    int adjmatrix[n][n];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            inputfile >> adjmatrix[i][j];
        }
    }
    inputfile.close();
    // inputfile.open("output.txt",ios::out);
    int visited[n]={0};
    cout << char(0+65) << " ";
    enque(0);
    visited[0]=1;
    while(!isEmpty()){
        int node=peek();
        del();
        for(int j=0;j<n;j++){
            if(adjmatrix[node][j]==1 && visited[j]==0){
                enque(j);
                visited[j]=1;
                cout << char(65+j) << " ";
            }
        }
    }
    inputfile.close();
    return 0;
}