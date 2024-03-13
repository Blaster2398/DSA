#include<bits/stdc++.h>
using namespace std ;

// span can be defined as = (Index of the current element) - (Index of the closest greatest element)
// if there is no greater element on the left side then use index + 1


int main(){
    int n;
    cin>>n;
    int arr[n];
    for( int i = 0; i < n; i++){
        cin>>arr[i];
    }

    stack<int> s;
    s.push(0);
    cout << 1 << ' ';
    for(int i = 1; i < n-1; i++){
        while( s.empty() == false && arr[s.top()] < arr[i]){
            s.pop();
        }
        int span = (s.empty()) ? i+1 : i-s.top();
        cout << span<<' ';
        s.push(i);
        
        
    }
    return 0;
}