#include <bits/stdc++.h> 
#include <bits/stdc++.h> 
using namespace std;
void setZeros(vector<vector<int>> &m){
	int r = m.size();
        int c = m[0].size();
        int row[r];
        int col[c];
        for(int i=0; i<r; i++){
            row[i]= -1;
        }
        for(int i=0; i<c; i++){
            col[i]= -1;
        }
        for(int i=0; i<r; i++){
            for(int j=0; j<c; j++){
                if(m[i][j]==0){
                    row[i]=0;
                    col[j]=0;
                }
            }
        }
        for(int i=0; i<r; i++){
            for(int j=0; j<c; j++){
                if(row[i]==0 || col[j]==0){
                    m[i][j]=0;
                }
            }
        }
}