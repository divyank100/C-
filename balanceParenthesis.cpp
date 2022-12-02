#include <bits/stdc++.h>
using namespace std;

bool isbalanced(string str,stack<char> s){
    
        for(int i=0;i<str.length();i++){
            if(str[i]=='('){
                s.push(str[i]);
            }
            else{
                if(!s.empty()){
                    s.pop();
                }
                else{
                    return false;
                }
            }
        }

        if(!s.empty()){
            return false;
        }
        return true;
    
}

int main(){
    string str="(()()())";
    stack<char> s;

    cout<<isbalanced(str,s);

}