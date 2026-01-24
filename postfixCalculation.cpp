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
int postfixCalculationWithBracket(string s){
    stack<int> val;
    for(int i=0;s[i]!='\0';i++){
        if(s[i] >= 48 && s[i] <=57){
            val.push(s[i] - 48);
        }
        else{
           
                int v2 = val.top();
                val.pop();
                int v1 = val.top();
                val.pop();
                int ans = solve(v1,v2,s[i]);
                val.push(ans);
            
        }
    }
    return val.top();
}
int main(){
    string s;
    cout<<"Enter the Postfix string: ";
    cin>>s;
    int ans = postfixCalculationWithBracket(s);
    cout<<"Answer = "<<ans;
    return 0;
}
