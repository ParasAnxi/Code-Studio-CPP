#include <bits/stdc++.h> 
/************************************************************

    Following is the Binary Tree node structure
    
    template <typename T>
    class TreeNode {
        public :
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~TreeNode() {
            if(left)
                delete left;
            if(right)
                delete right;
        }
    };

************************************************************/
void inOrder(TreeNode<int>* root ,vector<int>& inO){
    if(root==NULL)
        return;

    inOrder(root->left , inO);
    inO.push_back(root->data);
    inOrder(root->right , inO);
}
TreeNode<int>* flatten(TreeNode<int>* root)
{
    vector<int> inO;
    inOrder(root,inO);
    int n = inO.size();
    TreeNode<int>* newRoot = new TreeNode<int>(inO[0]);
    TreeNode<int>* curr = newRoot;
    for(int i =1 ;i<n ;i++){
        TreeNode<int>* temp = new TreeNode<int>(inO[i]);
        curr->left = NULL;
        curr->right = temp;
        curr = temp;
    }
    curr->left = NULL;
    curr->right = NULL;

    return newRoot;
}
