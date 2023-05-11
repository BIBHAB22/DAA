#include<iostream>
using namespace std;
void maxmin(int *arr,int start,int end,int &max, int &min){
    if(start==end){
        max=min=arr[start];
        return;
    }
    else if(end==start-1){
        if(arr[start]>arr[end]){
            max=arr[start];
            min=arr[end];
        }
        else{
            max=arr[end];
            min=arr[start];
        }
    }
    else{
        int mid=(start+end)/2;
        int max_left,min_left,max_right,min_right;
        maxmin(arr,0,mid,max_left,min_left);
        maxmin(arr,mid+1,end,max_right,min_right);
        max=max_left>max_right?max_left:max_right;
        min=min_left<min_right?min_left:min_right;
    }
}
int main(){
    int arrsize;
    cin>>arrsize;
    int arr[arrsize]={0};
    for(int i=0;i<arrsize;i++){
        cin>>arr[i];
    }
    int n=sizeof(arr)/sizeof(arr[0]);
    int max=arr[0],min=arr[0];
    maxmin(arr,0,n-1,max,min);
    cout<<"Max:"<<max<<"Min:"<<min<<endl;
    return 0;
}
