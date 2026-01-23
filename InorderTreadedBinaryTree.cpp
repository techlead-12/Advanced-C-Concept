#include<iostream>
using namespace std;
class Node{
public:
    int val;
    Node* right;
    Node* left;
    bool lbit,rbit;
};
Node* createNode(int key){
    Node* newNode = new Node();
    newNode->val = key;
    newNode->right = NULL;
    newNode->left = NULL;
    newNode->lbit = 1;
    newNode->rbit = 1;
    return newNode;
}
Node* insertTBT(Node* root,int key){
    Node* parent = NULL;
    Node* curr = root;
    
    while(curr != NULL){
        if(key == curr->val){
            cout<<"Dupliactes Node are Not allowed.";
            return root;
        }
        parent = curr;
        if(key < curr->val){
            if(curr->lbit == 0){
                curr = curr->left;
            }
            else{
                break;
            }
        }
        else{
            if(curr->rbit == 0){
                curr = curr->right;
            }
            else{
                break;
            }
        }
    }
    Node* newNode = createNode(key);
    if(parent == NULL){
        return newNode;
    }
    if(key < parent->val){
        newNode->left = parent->left;
        newNode->right = parent;
        parent->left = newNode;
        parent->lbit = 0;
    }
    else{
        newNode->right = parent->right;
        newNode->left = parent;
        parent->right = newNode;
        parent->rbit = 0;
    }
    return root;
}
Node* leftMost(Node* root){
    if(root == NULL){
        return NULL;
    }
    while(root->lbit == 0){
        root = root->left;
    }
    
    return root;
}
void inorderTBT(Node* root){
    Node* curr = leftMost(root);
    while(curr!=NULL){
        cout<<curr->val<<" ";
        if(curr->rbit == 1){
            curr = curr->right;
        }
        else{
            curr = leftMost(curr->right);
        }
    }
    
}
int main(){
    Node* root = nullptr;

    int arr[] = {50, 30, 70, 20, 40, 60, 80};
    int n = sizeof(arr) / sizeof(arr[0]);

    for (int i = 0; i < n; i++)
        root = insertTBT(root, arr[i]);

    cout << "Inorder traversal of Threaded Binary Tree:\n";
    inorderTBT(root);
    cout << endl;

    return 0;   
}
