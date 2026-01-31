#include<iostream>
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
int Level(TreeNode*root){
    if(root == NULL){
        return 0;
    }
    TreeNode* leftHeight = root->left;
    TreeNode* rightHeight = root->right;
    
    return 1 + max(Level(leftHeight),Level(rightHeight));
}
void nthLevel(TreeNode* root,int curr,int n){
    if(root == NULL){
        return;
    }
    if(curr == n){
        cout<<root->val<<" ";
        return;
    }
    nthLevel(root->right,curr+1,n);
    nthLevel(root->left,curr+1,n);
    
}
void levelOrderTraversal(TreeNode* root){
    if(root == NULL){
        return;
    }
    int n = Level(root);
    for(int i=1;i<=n;i++){
        nthLevel(root,1,i);
        cout<<endl;
    }
}
int main(){
    TreeNode* a = new TreeNode(1);
    TreeNode* b = new TreeNode(2);
    TreeNode* c = new TreeNode(3);
    TreeNode* d = new TreeNode(4);
    TreeNode* e = new TreeNode(5);
    TreeNode* f = new TreeNode(6);
    TreeNode* g = new TreeNode(7);
    TreeNode* h = new TreeNode(8);
    TreeNode* i = new TreeNode(9);
    TreeNode* j = new TreeNode(10);
    TreeNode* k = new TreeNode(11);

    a->left = b;   a->right = c;
    b->left = d;   b->right = e;
    c->left = f;   c->right = g;
    d->left = h;   d->right = i;
    e->left = j;   e->right = k;

    cout<<"Height of the tree: "<<Level(a);
    cout<<endl;
    cout << "Level Order Traversal:\n";
    levelOrderTraversal(a);

    return 0;
}
