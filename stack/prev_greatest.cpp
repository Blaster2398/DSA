#include<bits/stdc++.h>
using namespace std ;

int main(){
    int n;
    cin>>n;
    int arr[n];
    for( int i = 0; i < n; i++){
        cin>>arr[i];
    }

    stack<int> s;
    s.push(arr[0]);
    cout << -1 << ' ';   

    // for(int i = 1; i < n; i++){
    //     s.push(arr[i]);
    // }
    
    // for(int i = 0; i < n; i++){
    //     s.pop();
    //     cout<<s.top()<<' ';
    // }

    for(int i = 1; i < n; i++){
        while( s.empty() == false && s.top() <= arr[i]){
            s.pop();
        }
        int span = (s.empty()) ? -1 : s.top();
        cout << span << ' ';
        s.push(arr[i]);
        
    }
  return 0;
}