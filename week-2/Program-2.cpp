#include<iostream>
using namespace std;

void threePair(int arr[],int n){
    bool flag=false;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            for(int k=i+1;k<n;k++){
                if(arr[i]+arr[j]==arr[k]){
                    cout<<i+1<<","<<j+1<<","<<k+1<<endl;
                    flag=true;
                }
            }
        }
    }
    if(flag==false)cout<<"NO Sequence Found"<<endl;
}

int main(){
    int t,n;
    cin>>t;
    while(t){
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++)cin>>arr[i];
        threePair(arr,n);
        t--;
    }
    return 0;
}
