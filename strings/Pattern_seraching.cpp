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


void Naive_search(string &s,string &ss){
    if(s.length()<ss.length()){
        return;
    }
    bool flag =true;
    for(int i=0;i<s.length()-ss.length()+1;i++){
        for(int j=i;j<i+ss.length();j++){
            if(s[j]!=ss[j-i]){
                flag=false;
            }
        }
        if(flag){
            cout<<i<<" ";
        }
        flag=true;
    }
    cout<<endl;
}

//for all distinct elements in the pattern this works in linear time O(n)
void Naive_better_search(string &s,string &ss){
    if(s.length()<ss.length()){
        return;
    }
    for(int i=0;i<s.length()-ss.length()+1;i++){
        if(s.substr(i,ss.length())==ss){
            cout<<i<<" ";
            i+=ss.length();
        }
    }
}



int main(){
    fast_fast
    string s,ss;
    cin>>s>>ss;
    Naive_better_search(s,ss);

    return 0;
}