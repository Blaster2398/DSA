#include<bits/stdc++.h>
using namespace std ;



//logic for the code 
// 1. Initialize result = 0
// 2. Find the Prev_Smaller Element for every element 
// 3. Find the Next_Smaller Element for every element 
// 4. Traverse through each element and then do the following{
    //curr = curr[i];
    //curr += ( i - ( ps[i] - 1 )) * arr[i]; 
    //curr += ( ns[i] - ( i - 1 )) * arr[i];
    //res = max( res, curr );
//}   return res 

// as this approach needs 3 traversal of the arraya with 2O(n) aux space so we need to optimize the solution


//optimized 
int main(){
    int n;
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++){
        cin>>arr[i];
    }

    stack<int> s;
    int result = 0;
    for(int i = 0; i < n; i++){
        while( s.empty() == false && arr[s.top()]>=arr[i]){
            int tp = s.top();
            s.pop();
            int curr = arr[tp] * (s.empty() ? i : (i-s.top()-1));
            result = max(result, curr);
        }
        s.push(i);
    }
    while(s.empty() == false){
        int tp = s.top();
        s.pop();
        int curr = arr[tp] * (s.empty() ? n : (n-s.top()-1));
        result = max(result, curr);
    }

    cout << result << endl;

    return 0;
}