#include<bits/stdc++.h>
using namespace std ;

struct trieNode
{
    trieNode* childNode[2];
    // we do not need isEnd as we know each row woll be of same length
    trieNode(){
        childNode[0] = NULL;
        childNode[1] = NULL;
    }
};

bool insert( trieNode* root, int row, vector<vector<int>>& mat, int n){
    trieNode * curr = root;
    bool flag = false;
    for(int i = 0; i < n; i++){
        int index = mat[row][i];
        if(curr->childNode[index] == NULL){
            curr->childNode[index] = new trieNode();
            flag = true;
        }
        curr = curr->childNode[index];
    }
    return flag;
}

int countDis(vector<vector<int>> &mat, int n){
    trieNode * root = new trieNode();
    int res = 0;
    for(int row = 0; row < n; row++){
        if(insert(root, row, mat, n)){
            res++;
        }
    }
    return res;
}


int main(){
    cout << "enter the binary square matrix of Length: ";
    int n; 
    cin >> n;
    vector<vector<int>> mat(n);
    for(int i = 0; i < n; i++){
        for( int j = 0; j < n; j++){
            int ele;
            cin >> ele;
            mat[i].push_back(ele);
        }
    }
    cout << "the result is " << countDis(mat, n) << endl;
}