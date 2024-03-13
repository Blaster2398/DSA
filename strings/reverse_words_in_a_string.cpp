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
    string str;
    getline(cin,str);

    int begin =0;
    int end=0;
    cout<<str.length()<<endl;
    f(i,0,str.length()){
        if(str[i]==' '){
            end=i;
            reverse(&str[begin],&str[end]);
            begin=i+1;
            cout<<str<<endl;
        }
    }

    reverse(&str[begin],&str[str.length()]);
    reverse(&str[0],&str[str.length()]);
    cout<<str<<endl;
    return 0;
}