/*************************************************************
    Following is the Binary Serach Tree node structure

    template <typename T>
    class TreeNode
    {
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
            if (left)
                delete left;
            if (right)
                delete right;
        }
    };

*************************************************************/
void inOrder(TreeNode<int>* root ,vector<int>& inO){
    if(root==NULL)
        return;

    inOrder(root->left , inO);
    inO.push_back(root->data);
    inOrder(root->right , inO);
}
TreeNode<int>* inOToBst(int s,int e,vector<int>& inO){
    if(s>e)
        return NULL;

    int mid = (s+e)/2;
    TreeNode<int>*root = new TreeNode<int> (inO[mid]);

    root->left = inOToBst(s,mid-1,inO);
    root->right = inOToBst(mid+1,e,inO);
}
TreeNode<int>* balancedBst(TreeNode<int>* root) {
    vector<int> inO;
    inOrder(root,inO);
    int n = inO.size()-1;
    return inOToBst(0, n,  inO);
}
