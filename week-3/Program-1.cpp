#include<iostream>
using namespace std;

void insertionSort(int arr[],int n,int &shifts,int &comp){
    int i,j,key;
    for(int i=1;i<n;i++){
        key=arr[i];
        j=i-1;
        while(j>=0 && arr[j]>key){
            arr[j + 1] = arr[j];
            j = j - 1;
            ++comp;
            ++shifts;
        }
        arr[j + 1] = key;
        ++shifts;
    }
}

int main(){
    int t,n,shifts,comp;
    cin>>t;
    while(t--){
        shifts=0;comp=0;
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++)cin>>arr[i];
        insertionSort(arr,n,shifts,comp);
        for(int i=0;i<n;i++)cout<<arr[i]<<" ";
        cout<<endl<<"Comparisions="<<comp<<endl<<"Shifts="<<shifts<<endl;
    }
    return 0;
}
