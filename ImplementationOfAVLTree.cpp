#include<iostream>
using namespace std;
class Node{
public:
    int val;
    Node* right;
    Node* left;
    int height;
};
Node* createNode(int key){
    Node* newNode = new Node();
    newNode->val = key;
    newNode->height = 1;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}
int getHeight(Node* root){
    if(root == NULL){
        return 0;
    }
    return root->height;
}
int getBalanced(Node* root){
    if(root == NULL){
        return 0;
    }
    return getHeight(root->left) - getHeight(root->right);
}
Node * rightRotate(Node* y){
    Node* x = y->left;
    Node* temp = x->right;
    
    x->right = y;
    y->left = temp;
    
    x->height = max(getHeight(x->left) , getHeight(x->right)) + 1;
    y->height = max(getHeight(y->left) , getHeight(y->right)) + 1;
    
    return x;
}
Node* leftRotate(Node* x){
    Node* y = x->right;
    Node* temp = y->left;
    
    y->left = x;
    x->right = temp;
    
    x->height = max(getHeight(x->left) , getHeight(x->right)) + 1;
    y->height = max(getHeight(y->left) , getHeight(y->right)) + 1;
    
    return y;
}
Node* insertAVL(Node* root,int key){
    if(root == NULL){
        return createNode(key);
    }
    if(key < root->val){
        root->left = insertAVL(root->left,key);
    }
    else if(key > root->val){
        root->right = insertAVL(root->right,key);
    }
    else{
        return root;
    }
    
    root->height = max(getHeight(root->left),getHeight(root->right)) + 1;
    
    int bl = getBalanced(root);
    
    
    if(bl > 1 && key < root->left->val){
        return rightRotate(root);
    }
    if(bl < -1 && key > root->right->val){
        return leftRotate(root);
    }
    if(bl > 1 && key > root->left->val){
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }
    if(bl < -1 && key < root->right->val){
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }  
    return root;
}
void inorderTraversal(Node* root){
    if(root == NULL){
        return;
    }
    inorderTraversal(root->left);
    cout<<root->val<<" ";
    inorderTraversal(root->right);
}
int main(){
    Node* root = NULL;
    int arr[] =  {90, 110, 95, 88, 87, 10, 55, 38, 27, 99, 101, 28};
    int n = sizeof(arr)/sizeof(arr[0]);
    
    for(int i=0;i<n;i++){
        root = insertAVL(root,arr[i]);
    }
    cout<<"Inorder Traversal of AVL tree : "<<endl;
    inorderTraversal(root);
    cout<<endl;
    return 0;
}





















