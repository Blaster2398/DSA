#include<bits/stdc++.h>
using namespace std ;

bool matching(char a , char b){
  return ((a == '(' && b == ')') || (a == '{' && b == '}') || (a == '[' && b == ']'));
}    

bool balanced( string str){
  stack<char> s;
  for( int i = 0; i < str.length(); i++ ){
    if(( str[i] == '(') || ( str[i] == '[') || ( str[i] == '{')){
      s.push(str[i]);
    }
    else{
      if(s.empty() == true){
        return false;
      }
      else if(matching( s.top(), str[i])){
        s.pop();
      }
      else{ 
        return false;
      }
    }
  }
  return (s.empty() == true);
}
int main(){
  cout<<balanced("(){([)}")<<endl;

  return 0;
}