#include<iostream>
#include<stack>
using namespace std;
string prefixToInfix(string s){
    stack<string> val;
    int n = s.length();
    for(int i=n-1;i>=0;i--){
        if(s[i] >= 48 && s[i] <= 57){
            val.push(to_string(s[i] - 48));
        }
        else{
            string v1 = val.top();
            val.pop();
            string v2 = val.top();
            val.pop();
            string ans  = v1 + s[i] +v2;
            val.push(ans);
        }
    }
    return val.top();
}
int main(){
    string s;
    cout<<"Enter the Prefix string: ";
    cin>>s;
    string ans = prefixToInfix(s);
    cout<<"Answer = "<<ans;
    return 0;
}
