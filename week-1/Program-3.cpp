//Jump Search
#include<iostream>
#include<cmath>
using namespace std;

void input(int arr[],int n){
    cout<<"Enter array elements:";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
}

bool jumpSearch(int arr[],int n, int key,int &c){
    int step,prev;
    step=sqrt(n);
    prev=0;
    while(arr[step]<key && prev<n ){
        c++;
        prev=step;
        step+=sqrt(n);
        if(step>n-1)step=n-1;
    }
    for(int i=prev;i<=step;i++){
        c++;
        if(arr[i]==key)return true;
    }
    return false;
}

int main(){
    int t,n,c,key;
    cout<<"Enter test case:";
    cin>>t;
    while(t){
        c=0;
        cout<<"Enter array size:";
        cin>>n;
        int *arr=new int[n];
        input(arr,n);
        cout<<"Enter the key:";
        cin>>key;
        if(jumpSearch(arr,n,key,c)!=0)
            cout<<"Present "<<c<<endl;
        else
            cout<<"Not Present "<<c<<endl;
        --t;
    }
    return 0;
}
