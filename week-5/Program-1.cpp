#include<iostream>
using namespace std;

void input(char arr[],int n){
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
}

void counting_duplicate(char arr[],int count[],int n,int m){
    //count array
    for(int i=0;i<n;i++){
        ++count[arr[i]-'a'];
    }
    int max=1,index;

    for(int i=0;i<m;i++){
        if(count[i]>max){
            max=count[i]; 
            index=i;
        }
    }

    if(max>1){
        cout<<(char)(index+'a')<<"-"<<max<<endl;
    }
    else{
        cout<<"No Duplicate Elements\n";
    }
}

int main(){
    int t,n,m=26;
    cin>>t;
    while(t){
        cin>>n;
        char arr[n];
        int count[m]={0};
        input(arr,n);
        counting_duplicate(arr,count,n,m);
        t--;
    }
    return 0;
}
