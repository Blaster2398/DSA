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

// this was using an map 
// char LMBTR(string &s1){
//     map<int ,int> m;
//     for(int c:s1){
//         m[c]++;
//     }
//     for(auto x:m){
//         if(x.second>=2){
//             return x.first;
//         }
//     }return '?';
// }


// int main(){
//     fast_fast
//     string s1;
//     cin>>s1;
//     char res=LMBTR(s1);
//     int res2
//     for(int i=0;i<s1.length();i++){
//         if(s1[i]==res){
//             res2=i;
//             break;
//         }
//     }
//     if(res=='?'){
//         cout<<-1<<endl;
//     }
//     else{
//         cout<<res2<<endl;
//     }
//     return 0;
// }

//better approach 
const int CHAR =256;

int LMCTR(string &s1){
    int count[CHAR] ={0};
    f(i,0,s1.length()){
        count[s1[i]]++;
    }
    f(i,0,s1.length()){
        if(count[s1[i]]>=2){
            return i;
        }
    }
    return -1;

}

int main(){
    fast_fast
    string s1;
    cin>>s1;
    int res= LMCTR(s1);
    cout<<res<<endl;
}



