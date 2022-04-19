#include<iostream>
using namespace std;

void swap(int &a,int &b){
    int temp=a;
    a=b;
    b=temp;
}

int partition(int arr[],int lb,int ub,int &comp,int & swaps){
    int randNum = rand()%(ub-lb + 1) + lb;
    swap(arr[lb],arr[randNum]);
    int pivot=arr[lb];
    int i=lb,j=ub;
    while(i<j){
        while(arr[i]<=pivot){i++;comp++;}
        while(arr[j]>pivot){j--;comp++;}
        if(i<j){
            swap(arr[i],arr[j]);
            swaps++;
        }
    }swap(arr[lb],arr[j]);
        swaps++;

    return j;
}

void quickSort(int arr[],int lb,int ub,int &comp,int & swaps){
    if(lb>=ub)return;
    int p;
    p=partition(arr,lb,ub,comp,swaps);
    
    //sorting the both halfs
    quickSort(arr,lb,p-1,comp,swaps);
    quickSort(arr,p+1,ub,comp,swaps);
}

int main(){
    int t,n,comp,swaps;
    bool fl=false;
    cin>>t;
    while(t--){
        comp=swaps=0;
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++)cin>>arr[i];
        quickSort(arr,0,n-1,comp,swaps);
        for(int i=0;i<n;i++)cout<<arr[i]<<" ";
        cout<<endl<<"Comparision="<<comp<<endl<<"Swaps="<<swaps<<endl;
    }
    return 0;
}
