#include<iostream>
#include<stack>
#include<string>
using namespace  std;
int priority(char ch){
    if(ch  == '+' || ch == '-'){
        return 1;
    }
    else if(ch  == '*' || ch == '/'){
        return 2;
    }
    return 0;
}
int solve(int v1,char ch,int v2){
    if(ch == '+'){
        return v1+v2;
    }
    else if(ch == '-'){
        return v1-v2;
    }
    else if(ch == '*'){
        return v1*v2;
    }
    else if(ch == '/'){
        return v1/v2;
    }
    return 0;
}
int infixCalculationWithBrackets(string s){
    stack<int> val;
    stack<char> op;
    for(int i=0;s[i]!='\0';i++){
        if(s[i] >= 48 && s[i] <= 57){
            val.push(s[i] - 48);
        }
        else{
            if(op.empty() || priority(s[i]) > priority(op.top())){
                op.push(s[i]);
            }
            else if(s[i] == '(' || op.top() == '('){
                op.push(s[i]);
            }
            else if(s[i] == ')'){
                while(op.top() != '('){
                    int v2 = val.top();
                    val.pop();
                    int v1 = val.top();
                    val.pop();
                    char ch = op.top();
                    op.pop();
                    int ans = solve(v1,ch,v2);
                    val.push(ans);
                }
                op.pop();
            }
            else{
                while(!op.empty() && priority(s[i]) <= priority(op.top())){
                    int v2 = val.top();
                    val.pop();
                    int v1 = val.top();
                    val.pop();
                    char ch = op.top();
                    op.pop();
                    int ans = solve(v1,ch,v2);
                    val.push(ans);
                }
                op.push(s[i]);
            }
        }
    }
    while(!op.empty()){
        int v2 = val.top();
        val.pop();
        int v1 = val.top();
        val.pop();
        char ch = op.top();
        op.pop();
        int ans = solve(v1,ch,v2);
        val.push(ans);
    }
    return val.top();
}
int main(){
    string s ;
    cout<<"Enter the Infix string: ";
    cin>>s;
    int ans = infixCalculationWithBrackets(s);
    cout<<"Answer = "<<ans;
    return 0;
}
