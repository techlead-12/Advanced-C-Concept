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
int solve(int v1,char ch,int v2){
    if(ch == '+'){
        return v1+v2;
    }
    if(ch == '-'){
        return v1-v2;
    }
    if(ch == '*'){
        return v1*v2;
    }
    if(ch == '/'){
        return v1/v2;
    }
    return 0;
}
int solveInfix(string s){
    stack<int> val;
    stack<char> op;
    for(int i=0;s[i] != '\0';i++){
        //check if s[i] is digit
        int ascii = int(s[i]);
        if(ascii >= 48 && ascii <=57){
            val.push(ascii - 48);
        }
        //check is s[i] is operator
        else{
            if(op.empty()){
                op.push(s[i]);
            }
            else if(priority(s[i]) > priority(op.top())){
                op.push(s[i]);
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
    return val.top();
}
int main(){
    string s;
    cout<<"Enter the infix string: ";
    cin>>s;
    int ans = solveInfix(s);
    cout<<"Infix Answer = "<<ans;
    return 0;
}
