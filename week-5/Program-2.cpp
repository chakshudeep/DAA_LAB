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
        if(first[index1]<second[index2]){arr[k++]=first[index1++];}
        else{ arr[k++]=second[index2++];}
    }

    while(index1<len1)arr[k++]=first[index1++];
    while(index2<len2)arr[k++]=second[index2++];

    delete []first;
    delete []second;
}

void search(int arr[],int n,int key){
    int i=0,j=n-1;
    while(i<j){
        if(arr[i]+arr[j]==key){
            cout<<arr[i]<<" "<<arr[j]<<endl;
            return;
        }
            else if(arr[i]+arr[j]<key)
            i++;
            else 
            j--;
    }
    cout<<"No such elements exits\n";
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
    int t,n,target;
    cin>>t;
    while(t--){
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++){cin>>arr[i];}
        cin>>target;
        mergeSort(arr,0,n-1);
        search(arr,n,target);
    }
    return 0;
}
