#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int n=4;
int X[10];
int place(int k,int i){
    int j;
    for(j=1;j<=k-1;j++){
        if(X[j]==i || abs(j-k)==abs(X[j]-i))
            return 0;
    }
    return 1;
}
int count=0;
void nqueen(int k,int n){
    int i,j;
    for(i=1;i<=n;i++){
        if(place(k,i)){
            X[k]=i;
            if(k==n){
                count++;
                for(j=1;j<=n;j++){
                    printf("%3d",X[j]);
                }
                printf("\n");
            }
            else nqueen(k+1,n);
        }
    }
}
int main(){
    nqueen(1,n);
    printf("Number of solution=%d\n",count);
    return 0;
}