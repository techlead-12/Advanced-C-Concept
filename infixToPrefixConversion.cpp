#include<iostream>
#include<stack>
using namespace std;
int priority(char ch){
    if(ch == '+' || ch == '-'){
        return 1;
    }
    if(ch == '*' || ch == '/'){
        return 2;
    }
    return 0;
}
string infixToPrefix(string s){
    stack<string> val;
    stack<char>op;
    for(int i=0;s[i]!='\0';i++){
        if(s[i] >= 48 && s[i] <= 57){
            val.push(to_string(s[i]-48));
        }
        else{
            if(op.empty() || priority(op.top()) < priority(s[i])){
                op.push(s[i]);
            }
            else{
                while(!op.empty() && priority(op.top()) >= priority(s[i])){
                    string v2 = val.top();
                    val.pop();
                    string v1 = val.top();
                    val.pop();
                    char ch = op.top();
                    op.pop();
                    string ans = ch+v1+v2;
                    val.push(ans);
                }
                op.push(s[i]);
            }
        }
    }
    while(!op.empty()){
        string v2 = val.top();
        val.pop();
        string v1 = val.top();
        val.pop();
        char ch = op.top();
        op.pop();
        string ans = ch+v1+v2;
        val.push(ans);
    }
    return val.top();
}
int main(){
    string s;
    cout<<"Enter the infix string: ";
    cin>>s;
    string ans = infixToPrefix(s);
    cout<<"Prefix = "<<ans;
    return 0;
}
