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

//recursive approach (here we are just traversing the string from the back )
bool isSubSeq(string &s1, string &s2, int l1, int l2){
    if(l2==0){
        return true;
    }
    if(l1==0){
        return false;
    }

    if(s1[l1-1]==s2[l2-1]){    // dont forget to subtact 1 as this is the length not the index
        isSubSeq(s1,s2,l1-1,l2-1);
    }
    else{
        isSubSeq(s1,s2,l1-1,l2);
    }
}




int main(){
    fast_fast
    string s1,s2;
    cin>>s1>>s2;

    int l1=s1.length();
    int l2=s2.length();

    // bool res=isSubSeq(s1,s2,l1,l2);
    // cout<<res<<endl;

    
    int j=0;
    f(i,0,l1){
        if((s1[i]==s2[j]) && j<l2){
            j++;
        }
    }
    if(j==l2){
        cout<<"YES"<<endl;
    }
    else{
        cout<<"NO"<<endl;
    }
    return 0;
}