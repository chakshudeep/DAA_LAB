//Linear Search
#include<iostream>
using namespace std;

void input(int arr[],int n){
    cout<<"Enter array elements:";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
}

bool linearSearch(int arr[],int n,int key,int &c){
    int flag=0;
    for(int i=0;i<n;i++){
            c++;
        if(arr[i]==key){
            return true;
        }
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
        if(linearSearch(arr,n,key,c)!=0)
            cout<<"Present "<<c<<endl;
        else
            cout<<"Not Present "<<c<<endl;
        --t;
    }
    return 0;
}
