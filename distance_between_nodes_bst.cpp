#include<iostream>
#include<vector>
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
    
    display(root->left);
    cout<<root->val<<" ";
    display(root->right);
    return;
}
int distanceFromRoot(TreeNode* root,int x){
    if(root->val == x){
        return 0;
    }
    else if(root->val > x){
        return 1+distanceFromRoot(root->left,x);
    }
    else{
        return 1+ distanceFromRoot(root->right,x);
    }
}
int distance(TreeNode* root,int a,int b){
    if(root == NULL){
        return 0;
    }
    if(root->val > a && root->val > b){
        return distance(root->left,a,b);
    }
    if(root->val < a && root->val < b){
        return distance(root->right,a,b);
    }
    return distanceFromRoot(root,a) + distanceFromRoot(root,b);
}
int main(){
    TreeNode* root = NULL;
    root = insertNode(root,20);
    root = insertNode(root,10);
    root = insertNode(root,30);
    root = insertNode(root,5);
    root = insertNode(root,15);
    root = insertNode(root,25);
    root = insertNode(root,35);
    cout<<"Inorder: ";
    display(root);
    cout<<endl;
    int k1,k2;
    cout<<"Enter the two keys respectively [k1,k2]: ";
    cin>>k1>>k2;
    int dis = distance(root,k1,k2);
    cout<<"Distance = "<<dis;
    return 0;
}


