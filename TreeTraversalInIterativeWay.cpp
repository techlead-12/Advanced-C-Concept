#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
using namespace std;
class TreeNode{
public: 
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val){
        left = right = NULL;
        this->val = val;
    }
};
void displayIterativelyInorder(TreeNode* root,vector<int> & ans){
    stack<TreeNode*> st;
    TreeNode*temp = root;
    
    while(temp != NULL || st.size() > 0){
        while(temp != NULL){
            st.push(temp);
            temp = temp->left;
        }
        
        temp = st.top();
        st.pop();
        ans.push_back(temp->val);
        
        temp = temp->right;
    }
}
void displayIterativelyPreorder(TreeNode* root,vector<int> & ans){
    if(root == NULL){
        return;
    }
    stack<TreeNode*> st;
    st.push(root);
    
    while(st.size() > 0){
        TreeNode*temp = st.top();
        st.pop();
        ans.push_back(temp->val);
        
        if(temp->right != NULL){
            st.push(temp->right);
        }
        if(temp->left != NULL){
            st.push(temp->left);
        }
        
    }
}
void displayIterativelyPostOrder(TreeNode* root,vector<int> &ans){
    if(root == NULL){
        return;
    }
    stack<TreeNode*> st;
    st.push(root);
    TreeNode* temp;
    while(st.size() > 0){
        temp = st.top();
        st.pop();
        ans.push_back(temp->val);
        if(temp->left != NULL){
            st.push(temp->left);
        }
        if(temp->right != NULL){
            st.push(temp->right);
        }
    }
    reverse(ans.begin(),ans.end());
}
bool isLeafNode(TreeNode* root){
    if(root == NULL){
        return 0;
    }
    if(root->left == NULL && root->right == NULL){
        return true;
    }
    else return false;
}
void addLeftBoundry(TreeNode* root,vector<int>& ans){
    TreeNode* curr = root->left;
    while(curr != NULL){
        if(!isLeafNode(curr)){
            ans.push_back(curr->val);
        }
        if(curr->left != nullptr){
            curr = curr->left;
        }
        else{
            curr = curr->right;
        }
    } 
}
void addRightBoundry(TreeNode* root,vector<int>&ans){
    TreeNode* curr = root->right;
    vector<int>TempAns;
    while(curr != NULL){
        if(!isLeafNode(curr)){
            TempAns.push_back(curr->val);
        }
        if(curr->right != NULL){
            curr = curr->right;
        }
        else{
            curr = curr->left;
        }
    }
    for(int i=TempAns.size()-1;i>=0;i--){
        ans.push_back(TempAns[i]);
    }
}
void addLeaves(TreeNode* root,vector<int> &ans){
    if(root == NULL){
        return;
    }
    if(isLeafNode(root)){
        ans.push_back(root->val);
        return;
    }
    addLeaves(root->left,ans);
    addLeaves(root->right,ans); 
}
void boundryNodes(TreeNode* root,vector<int> &ans){
    
    if(root == NULL){
        return ;
    }
    if(!isLeafNode(root)){
        ans.push_back(root->val);
    }
    addLeftBoundry(root,ans);
    addLeaves(root,ans);
    addRightBoundry(root,ans);
}
int main(){
    
    TreeNode* n1  = new TreeNode(1);
    TreeNode* n2  = new TreeNode(2);
    TreeNode* n3  = new TreeNode(3);
    TreeNode* n4  = new TreeNode(4);
    TreeNode* n5  = new TreeNode(5);
    TreeNode* n6  = new TreeNode(6);
    TreeNode* n7  = new TreeNode(7);
    TreeNode* n8  = new TreeNode(8);
    TreeNode* n9  = new TreeNode(9);
    TreeNode* n10 = new TreeNode(10);
    TreeNode* n11 = new TreeNode(11);
    
    
    n1->left = n2;   n1->right = n3;

    n2->left = n4;  n2->right = n5;
    n3->left = n6;  n3->right = n7;
    
    n4->left = n8;  n4->right = n9;
    n5->left = n10; n5->right = n11;
   

    
    vector<int> ans;

    displayIterativelyInorder(n1,ans);
    cout<<"\nIn-order Traversal: ";
    
    for(int i=0;i<ans.size();i++){
        cout<<ans[i] <<" ";
    }
    
    vector<int> ans1;
    
    displayIterativelyPreorder(n1,ans1);
    cout<<"\nPre-Order Traversal: ";
    
    for(int i=0;i<ans1.size();i++){
        cout<<ans1[i] <<" ";
    }
    
    vector<int> ans2;
    
    displayIterativelyPostOrder(n1,ans2);
    cout<<"\nPost-Order Traversal: ";
    
    for(int i=0;i<ans2.size();i++){
        cout<<ans2[i] <<" ";
    }
    
    vector<int> ans3;
    cout<<"\nBoundry of the Tree: ";
    boundryNodes(n1,ans3);
    for(int i=0;i<ans3.size();i++){
        cout<<ans3[i]<<" ";
    }
    
    return 0;
}

