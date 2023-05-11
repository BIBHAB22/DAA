#include<iostream>
using namespace std;
struct Edge{
    int v1;
    int v2;
    int weight;
};

int w[4][4]={0, 10, 8, 999,
            999, 0, -6,999,
            999, 999, 0, 2,
            999, 999, 999,0};


struct Edge edge[4]={{0,1,10},{1,2,-6},{0,2,8},{2,3,2}};
int noE=4;
int noV=4;

int dist[20];
int pred[20];
void Bellman_Ford(int src){
    for(int i=0;i<noV;i++){
        dist[i]=999;
        pred[i]=-1;
    }
    dist[src]=0;
    for(int i=1;i<=noV-1;i++){
        for(int j=0;j<noE;j++){
            int u=edge[j].v1;
            int v=edge[j].v2;
            if(dist[u]+w[u][v]<dist[v]){
                dist[v]=dist[u]+w[u][v];
                pred[v]=u;
            }
        }
    }
}

void displayPath(int i){
    if(i==-1) return;
    else{
        displayPath(pred[i]);
        cout<<"    "<<(char)(i+'A');
    }
}
int main(void){
    Bellman_Ford(0);
    displayPath(3);
    cout<<endl;
    cout<<"cost="<<dist[3]<<endl;
    return 0;
}