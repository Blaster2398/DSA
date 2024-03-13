#include<bits/stdc++.h>
using namespace std ;

int largest_hist(int arr[], int n){

    // this code is from the largest rectangle problem 
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

    return result;
}


int main(){
    int m, n;
    cin >> m >> n;
    int arr[m][n];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin>>arr[i][j];
        }
    }

    // what i am doing is just apply largest rect problem for each row by considering all above 1 as each block height 
    //if there is a zero just ignore the block  
    int result = 0;
    for(int i = 0; i < m; i++){
        if(i != 0){
            for(int j = 0; j < n; j++){
                if(arr[i][j] != 0){
                    arr[i][j] += arr[i-1][j];
                }
            }
        }
        result = max(result, largest_hist(arr[i] , n));
    }

    cout<<result<<endl;


    return 0;
}