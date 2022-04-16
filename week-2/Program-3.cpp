#include<iostream>
using namespace std;

int countDifference(int arr[],int n,int key){
    int count=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(arr[i]-arr[j]==key)count++;
        }
    }
    return count;
}

int main(){
    int t,n,key;
    cin>>t;
    while(t--){
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++)cin>>arr[i];
        cin>>key;
        cout<<countDifference(arr,n,key)<<endl;
    }
    return 0;
}
