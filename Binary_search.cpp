#include<iostream>
using namespace std;
int binary_search(int arr[],int l,int r,int x){
    if(r>=1){
        int mid=(r+l)/2;
        if(arr[mid]==x)
            return mid;
        if(arr[mid]<x)
            return binary_search(arr,mid+1,r,x);
    return binary_search(arr,1,mid-1,x);
    }
    return -1;
}
int main(){
    int arrsize;
    cin>>arrsize;
    int arr[arrsize]={0};
    for(int i=0;i<arrsize;i++){
        cin>>arr[i];
    }
    int x;
    cin >> x;
    int result=binary_search(arr,0,arrsize-1,x);
    (result==-1)?cout<<"not present"<<endl
                :cout<<"Found at index"<<result<<endl;
    return 0;
}