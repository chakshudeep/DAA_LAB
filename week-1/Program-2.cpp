//Binary Search
#include<iostream>
using namespace std;

void input(int arr[],int n){
    cout<<"Enter array elements:";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
}

//iterative method
// bool binarySearch(int arr[],int l,int r,int key,int &c){
//     while(l<=r){
//         int mid=l+(r-l)/2;
//         c++;
//         if(arr[mid]==key){
//             return true;
//         }
//         else if(arr[mid]>key){
//             r=mid-1;
//         }
//         else if(arr[mid]<key){
//             l=mid+1;
//         }
//     }
//     return false;
// }

//recursive method

bool binarySearch(int arr[],int l,int r,int key,int &c){
    if(l<=r){
        int mid=l+(r-l)/2;
        c++;
        if(arr[mid]==key){
            return true;
        }
        else if(arr[mid]>key){
           return binarySearch(arr,l,mid-1,key,c);
        }
        else if(arr[mid]<key){
           return binarySearch(arr,mid+1,r,key,c);
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
        if(binarySearch(arr,0,n-1,key,c)!=0)
            cout<<"Present "<<c<<endl;
        else
            cout<<"Not Present "<<c<<endl;
        --t;
    }
    return 0;
}
