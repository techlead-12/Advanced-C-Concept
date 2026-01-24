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
string solve(string v1,string v2,char ch){
    string s = "";
    s += v1;
    s += v2;
    s.push_back(ch);
    return s;
}
string infixToPostfix(string s){
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
            else if(s[i] == '(' || op.top() == '('){
                op.push(s[i]);
            }
            else if(s[i] == ')'){
                while(op.top()!='('){
                    string v2 = val.top();
                    val.pop();
                    string v1 = val.top();
                    val.pop();
                    char ch = op.top();
                    op.pop();
                    string ans = solve(v1,v2,ch);
                    val.push(ans);
                }
                op.pop();
            }
            else{
                while(!op.empty() && priority(op.top()) >= priority(s[i])){
                    string v2 = val.top();
                    val.pop();
                    string v1 = val.top();
                    val.pop();
                    char ch = op.top();
                    op.pop();
                    string ans = solve(v1,v2,ch);
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
        string ans = solve(v1,v2,ch);
        val.push(ans);
    }
    return val.top();
}
int main(){
    string s;
    cout<<"Enter the infix string: ";
    cin>>s;
    string ans = infixToPostfix(s);
    cout<<"Postfix = "<<ans;
    return 0;
}
