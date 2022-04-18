#include<iostream>
using namespace std;

void merge(int arr[],int lb,int mid,int ub){
    int len1=mid-lb+1,len2=ub-mid;
    int *first=new int[len1],*second=new int[len2];

    //copying first part
    int k=lb;
    for(int i=0;i<len1;i++)first[i]=arr[k++];
    //copying second part
    k=mid+1;
    for(int i=0;i<len2;i++)second[i]=arr[k++];

    //merge
    int index1=0,index2=0;
    k=lb;
    while(index1<len1 && index2<len2){
        if(first[index1]<second[index2])arr[k++]=first[index1++];
        else arr[k++]=second[index2++];
    }

    while(index1<len1)arr[k++]=first[index1++];
    while(index2<len2)arr[k++]=second[index2++];
    //deleting the memory
    delete []first;
    delete []second;
}

void mergeSort(int arr[],int lb,int ub){
    if(lb<ub){
        int mid=(lb+ub)/2;
        mergeSort(arr,lb,mid);
        mergeSort(arr,mid+1,ub);
        merge(arr,lb,mid,ub);
    }
}

int main(){
    int t,n;
    bool fl=false;
    cin>>t;
    while(t--){
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++)cin>>arr[i];
        mergeSort(arr,0,n-1);
        for(int i=0;i<n-1;i++){
            if(arr[i]==arr[i+1]){cout<<"YES\n";fl=true;break;}
        }
        if(fl==false)cout<<"NO\n";
    }
    return 0;
}
