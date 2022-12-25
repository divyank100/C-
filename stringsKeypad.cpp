#include <iostream>
using namespace std;

void keypad(string s,string ans){
    string charArr[]={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    if(s.length()==0){
        cout<<ans<<endl;
        return;
    }
    char ch=s[0];
    string code=charArr[ch-'0'];

    for(int i=0;i<code.length();i++){
        keypad(s.substr(1),ans+code[i]);
    }

}

int main(){
    int n;
    cin>>n;
    string s=to_string(n);
    keypad(s,"");
}