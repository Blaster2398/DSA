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

int main(){
    fast_fast
    int t;
    cin>> t;
    while(t--){
    int n,m ;
    cin>>m>>n;
    int a[m],b[n]; 
    inp(a,m);
    inp(b,n); 
    unordered_set <int> a_(a,a+m);
    unordered_set <int> b_(b,b+n);
    // unordered_set <int> c_;
    // if(a_.size()>b_ .size()){
    //     c_=a_;
    //     a_=b_;
    //     b_=c_;
    // }
    int res=0;
    for(auto it=a_.begin();it!=a_.end();it++){
        if(b_.count(*it)){
            res++;
        }
    }
    cout<<res<<endl;
    }
    return 0;
}