#include <iostream>//-2147483648
#include<climits>
#include<queue>
using namespace std;
class TreeNode{
public:
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val){
        this->val = val;
        left = right = NULL;
    }
};
TreeNode* construct(int arr[],int n){
    queue<TreeNode*> qu;
    TreeNode* root = new TreeNode(arr[0]);
    qu.push(root);
    int i = 1;
    int j = 2;
    while(qu.size() > 0 && i<n){
        TreeNode* temp = qu.front();
        qu.pop();
        TreeNode*l;
        TreeNode*r ;
        
        if(arr[i] != INT_MIN){
            l = new TreeNode(arr[i]);
        }
        else{
            l = NULL;
        }
        if(j != n && arr[j] != INT_MIN){
            r = new TreeNode(arr[j]);
        }
        else{
            r = NULL;
        }
        temp->left = l;
        temp->right = r;
        if(l){
            qu.push(l);
        }
        if(r){
            qu.push(r);
        }
        i = i+2;
        j = j+2;
        
    }
    return root;
}
void levelOrder(TreeNode* root){
    queue<TreeNode*> qu;
    qu.push(root);
    TreeNode* temp;
    while(qu.size() > 0){
        temp = qu.front();
        qu.pop();
        cout<<temp->val<<" ";
        if(temp->left){
            qu.push(temp->left);
        }
        if(temp->right){
            qu.push(temp->right);
        }
    }
    cout<<endl;
}
int main(){
    int arr[] = {1,2,3,4,5,INT_MIN,6,INT_MIN,INT_MIN,7,8,9};
    int n = sizeof(arr)/sizeof(arr[0]);
    TreeNode* root = construct(arr,n);
    levelOrder(root);
    return 0;
}
