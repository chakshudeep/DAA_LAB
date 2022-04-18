#include<iostream>
using namespace std;

void swap(int &a,int &b){
    int temp=a;
    a=b;
    b=temp;
}

void selectionSort(int arr[],int n,int &swaps,int &comp){
    int min_index,i,j;
    for(int i=0;i<n-1;i++){
        min_index=i;
        for(int j=i+1;j<n;j++){
            if(arr[min_index]>arr[j])min_index=j;++comp;
        }
        swap(arr[min_index],arr[i]);++swaps;
    }
}

int main(){
    int t,n,swaps,comp;
    cin>>t;
    while(t--){
        swaps=0;comp=0;
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++)cin>>arr[i];
        selectionSort(arr,n,swaps,comp);
        for(int i=0;i<n;i++)cout<<arr[i]<<" ";
        cout<<endl<<"Comparisions="<<comp<<endl<<"Swaps="<<swaps<<endl;
    }
    return 0;
}
