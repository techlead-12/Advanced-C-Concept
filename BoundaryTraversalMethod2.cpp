#include <iostream>
#include<stack>
#include<vector>
using namespace std;
class TreeNode{
public:
    int val;
    TreeNode* right;
    TreeNode* left;
    TreeNode(int val){
        this->val = val;
        this->right = this->left = NULL;
    }
};
int level(TreeNode* root){
    if(root == NULL){
        return 0;
    }
    return 1 + max(level(root->left),level(root->right));
}
void nthLevel(TreeNode* root,int curr,int n){
    if(root == NULL){
        return;
    }
    if(curr == n){
        cout<<root->val<<" ";
        return;
    }
    nthLevel(root->left,curr+1,n);
    nthLevel(root->right,curr+1,n);
}
bool isLeafNode(TreeNode* root){
    if(root == NULL){
        return false;
    }
    else if(root->left == NULL && root->right == NULL){
        return true;
    }
    return false;
}
void levelOrderTraversal(TreeNode*root){
    if(root == NULL){
        return;
    }
    int n = level(root);
    for(int i=1;i<=n;i++){
        nthLevel(root,1,i);
    }
    return;
}
void leftBoundary(TreeNode* root){
    if(root == NULL){
        return;
    }
    if(isLeafNode(root)){
        return;
    }
    cout<<root->val<<" ";
    leftBoundary(root->left);
    if(root->left == NULL){
         leftBoundary(root->right);
    }
}
void rightBoundary(TreeNode*root){
    if(root == NULL){
        return;
    }
    if(isLeafNode(root)){
        return;
    }
    cout<<root->val<<" ";
    rightBoundary(root->right);
    if(root->right == NULL){
        rightBoundary(root->left);
    }
}
void leafBoundary(TreeNode* root){
    if(root == NULL){
        return;
    }
    if(isLeafNode(root)){
        cout<<root->val<<" ";
    }
    leafBoundary(root->left);
    leafBoundary(root->right);
}
int main(){
    TreeNode* a  = new TreeNode(1);
    TreeNode* b  = new TreeNode(2);
    TreeNode* c  = new TreeNode(3);
    TreeNode* d  = new TreeNode(4);
    TreeNode* e  = new TreeNode(5);
    TreeNode* f  = new TreeNode(6);
    TreeNode* g  = new TreeNode(7);
    TreeNode* h  = new TreeNode(8);
    TreeNode* i  = new TreeNode(9);
    TreeNode* j  = new TreeNode(10);
    TreeNode* k  = new TreeNode(11);
    TreeNode* l  = new TreeNode(12);
    TreeNode* m  = new TreeNode(13);
    TreeNode* n  = new TreeNode(14);
    TreeNode* o  = new TreeNode(15);
    
    // Level 1
    a->left  = b;
    a->right = c;
    
    // Level 2
    b->left  = d;
    b->right = e;
    c->left  = f;
    c->right = g;
    
    // Level 3
    d->left  = h;
    d->right = i;
    e->left  = j;
    e->right = k;
    f->left  = l;
    f->right = m;
    g->left  = n;
    g->right = o;

    cout<<"\nBoundary Traversal: ";
    leftBoundary(a);
    leafBoundary(a);
    rightBoundary(a->right);
    
    cout<<"\nLevel Order Traversal: ";
    levelOrderTraversal(a);
    
    return 0;
}
