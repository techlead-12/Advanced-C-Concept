#include<iostream>
#include<stack>
using namespace std;
int solve(int v1,int v2,char ch){
    if(ch == '+'){
        return v1+v2;
    }
    else if(ch == '-'){
        return v1-v2;
    }
    else if(ch == '*'){
        return v1*v2;
    }
    else return v1/v2;
}
string postfixToInfix(string s){
    stack<string> val;
    for(int i=0;s[i]!='\0';i++){
        if(s[i] >= 48 && s[i] <=57){
            val.push(to_string(s[i] - 48));
        }
        else{
           
                string v2 = val.top();
                val.pop();
                string v1 = val.top();
                val.pop();
                string ans = v1 + s[i] + v2;
                val.push(ans);
            
        }
    }
    return val.top();
}
int main(){
    string s;
    cout<<"Enter the Postfix string: ";
    cin>>s;
    string ans = postfixToInfix(s);
    cout<<"Answer = "<<ans;
    return 0;
}
