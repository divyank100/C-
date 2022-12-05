#include <bits/stdc++.h>
using namespace std;

int reverseCount(string s){
    int n=s.size();
    int c1=0;
    int c2=0;
  if(n%2!=0){
      return -1;
  }
  else{
    stack<char>st;

    for(int i=0;i<=n-1;i++){
        if(s[i]=='{'){
            st.push(s[i]);
            c2++;
        }
        else if(!st.empty() && s[i]=='}' && st.top()=='{'){
            st.pop();
            c2--;
        }
        else{
            c1++;
        }
    }
    if(c1%2!=0){
        c1=(c1/2)+1;
    }
    else{
        c1=c1/2;
    }

    if(c2%2!=0){
        c2=(c2/2)+1;
    }
    else{
        c2=c2/2;
    }
  }
  return c1+c2;
} 

int main(){
    string s="{{{}}{";
    cout<<reverseCount(s)<<endl;

}