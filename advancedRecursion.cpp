#include <iostream>
using namespace std;

int calculateLength(char s[]){
    if(s[0]=='\0'){
        return 0;
    }
    int smallLength=calculateLength(s+1);
    return smallLength+1;   
}

void removeX(char s[]){
    if(s[0]=='\0'){
        return;
    }
    if(s[0]!='x'){
        removeX(s+1);
    }
    else{
        int i=1;
        for(;s[i]!='\0';i++){
            s[i-1]=s[i];
        }
        s[i-1]=s[i];
        removeX(s);
    }
}

int main(){
    char str[100];
    cin>>str;

    cout<<calculateLength(str)<<endl;
    removeX(str);
    cout<<str<<endl;
    cout<<calculateLength(str);
}


