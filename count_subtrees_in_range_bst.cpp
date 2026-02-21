#include<iostream>
using namespace std;
class TreeNode{
public:
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val){
        this->val = val;
        this->left = NULL;
        this->right = NULL;
    }
};
TreeNode*insertNode(TreeNode*root,int val){
    TreeNode* newNode = new TreeNode(val);
    if(root == NULL){
        return newNode;
    }
    if(val < root->val){
        root->left = insertNode(root->left,val);
    }
    else if(val > root->val){
        root->right = insertNode(root->right,val);
    }
    return root;
}
void display(TreeNode* root){
    if(root == NULL){
        return;
    }
    cout<<root->val<<" ";
    display(root->left);
    display(root->right);
    return;
}
bool count(TreeNode* root,int &x,int Low,int High){
    if(root == NULL){
        return true;
    }
    bool leftValid = count(root->left,x,Low,High);
    bool rightValid = count(root->right,x,Low,High);
    
    if(leftValid && rightValid && root->val >= Low && root->val <= High){
        x++;
        return true;
    }
    return false;
}
int main(){
    TreeNode* root = NULL;
    root = insertNode(root,10);
    root = insertNode(root,5);
    root = insertNode(root,15);
    root = insertNode(root,1);
    root = insertNode(root,8);
    root = insertNode(root,20);
    cout<<"Postorder: ";
    display(root);
    cout<<endl;
    int Low,High;
    cout<<"Enter the range [Low,High]: ";
    cin>>Low>>High;
    int x = 0;
    count(root,x,Low,High);
    cout<<"Count = "<<x;
    return 0;
}


