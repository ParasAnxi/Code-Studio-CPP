#include <bits/stdc++.h> 
class Node{
    public:
    int data;
    int i;
    int j;
    Node(int data,int row,int col){
        this->data = data;
        i=row;
        j=col;
    }
};
class compare{
    public:
    bool operator()(Node* a,Node* b){
        return a->data > b->data;
    }
};
vector<int> mergeKSortedArrays(vector<vector<int>>&kArrays, int k)
{
    priority_queue<Node*,vector<Node*>,compare> minHeap;

    for(int i=0;i<k;i++){
        Node* temp = new Node(kArrays[i][0],i,0);
        minHeap.push(temp);
    }
    vector<int> ans;
    while(minHeap.size()>0){
        Node* temp = minHeap.top();
        ans.push_back(temp->data);
        minHeap.pop();

        int i = temp->i;
        int j = temp->j;

        if(j+1<kArrays[i].size()){
            Node* next = new Node(kArrays[i][j+1],i,j+1);
            minHeap.push(next);
        }
    }
    return ans;
}
