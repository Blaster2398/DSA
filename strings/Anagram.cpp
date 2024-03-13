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


// this will take O(nlogn) time complexity due to use of sort
int Anagram_using_sort(string &s1, string &s2){

    if(s1.length()!=s2.length()){
        return 0;
    }
    sort(s2.begin(),s2.end());
    sort(s1.begin(),s1.end());
    if(s1==s2){
        return 1;
    }
    return 0;
}

const int CHAR =256;
// using iterative logic and making a list basic counting (this will take only O(n) time )
int Anagram_using_array(string &s1, string &s2){
    if(s1.length()!=s2.length()){
        return 0;
    }

    int count[CHAR]={0};
    for(int i=0;i<s1.length();i++){
        count[s1[i]]++;
        count[s2[i]]--;
    }

    for(int i=0;i<CHAR;i++){
        if(count[i]!=0){
            return 0;
        }
    }
    return 1;
}




int main(){
    fast_fast
    string s1,s2;
    cin>>s1>>s2;
    int res=Anagram_using_sort(s1,s2);
    cout<<res<<endl;
    int res2=Anagram_using_array(s1,s2);
    cout<<res2<<endl;

    return 0;
}