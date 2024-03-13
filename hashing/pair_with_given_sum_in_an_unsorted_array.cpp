//Billo Bagge Billeyan Da Ki Karegi
//Bagge - Bagge Billeyan Da Ki Karegi

#include<bits/stdc++.h>
using namespace std ;

#pragma GCC optimise(2)
#pragma GCC optimise("O1")
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")

#define f(i,s,n) for(int i=s;i<n;i++)
#define inp(arr,n) for(int i=0;i<n;i++) cin>>arr[i];
#define out(arr,n) for(int i=0;i<n;i++) cout<<arr[i]<<" ";
#define fast_fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define convert_toint(a) static_cast<int>(std::round(a));



bool ispair(int arr[],int n, int sum){
    unordered_set <int> s;
    for(int i=0;i<n;i++){
        if(s.find(sum-arr[i])!=s.end()){
            return true ;
        }
        s.insert(arr[i]);
    }
    return false;
}

int main(){
    fast_fast
    int n;
    cin>>n;
    int arr[n];
    inp(arr,n);
    int sum;
    cin>>sum;

    bool res= ispair(arr,n,sum);
    if(res){
        cout<<"YES"<<endl;
    }
    else{
        cout<<"NO"<<endl;
    }
    return 0;
}