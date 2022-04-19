#include<iostream>
using namespace std;

void merge(int arr[],int lb,int mid,int ub,int &comp,int &inversion){
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
        comp++;
        if(first[index1]<second[index2]){arr[k++]=first[index1++];}
        else{ arr[k++]=second[index2++];inversion+=mid-index1-1;}
    }

    while(index1<len1)arr[k++]=first[index1++];
    while(index2<len2)arr[k++]=second[index2++];

    delete []first;
    delete []second;
}

void mergeSort(int arr[],int lb,int ub,int &comp,int & inversion){
    if(lb<ub){
        int mid=(lb+ub)/2;
        mergeSort(arr,lb,mid,comp,inversion);
        mergeSort(arr,mid+1,ub,comp,inversion);
        merge(arr,lb,mid,ub,comp,inversion);
    }
}

int main(){
    int t,n,comp,inversion;
    bool fl=false;
    cin>>t;
    while(t--){
        comp=inversion=0;
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++)cin>>arr[i];
        mergeSort(arr,0,n-1,comp,inversion);
        for(int i=0;i<n;i++)cout<<arr[i]<<" ";
        cout<<endl<<"Comparision="<<comp<<endl<<"inversion="<<inversion<<endl;
    }
    return 0;
}
