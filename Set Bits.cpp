#include <bits/stdc++.h> 
#include <iostream>

using namespace std;

    //Write your countBits function here
int countBits(int n){
    int cnt = 0;
    while(n!=0){

    if(n&1){
        cnt++;
    }
        n=n>>1;
    }
    return cnt;
}
int main() {
    int n;
    cin >> n;
    cout<<countBits(n);
    return 0;
}