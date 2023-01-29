int isPossible(vector<int> &boards, int k,int mid){

int painter=1;
int board=0;

for(int i=0; i<boards.size();i++){
    if(board+boards[i]<=mid){
        board+=boards[i];
    }
    else{
        painter++;
        if(painter>k||boards[i]>mid){
            return false;
        }
        board=boards[i];
    }
}
return true;
}


int findLargestMinDistance(vector<int> &boards, int k)
{
    int start=0;
    int board=0;
    for(int i=0;i<boards.size();i++){
        board+=boards[i];
    }
    int end=board;
    int mid=start+(end-start)/2;
    int ans=-1;
    while(start<=end){
        if(isPossible(boards,k,mid)){
            ans=mid;
            end=mid-1;
        }
        else{
            start=mid+1;
        }
        mid=start+(end-start)/2;
    }
    return ans;
}