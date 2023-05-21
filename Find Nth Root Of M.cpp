#include <bits/stdc++.h> 
double multiply(double num,int n){
	double ans = 1.0;
	for(int i = 1;i<= n;i++){
		ans*= num;
	}
	return ans;
}
double findNthRootOfM(int n, int m) {
	// Write your code here.
	double low = 1,high = m,eps= 1e-8; // take it upto 8 decimal places 
									   // got error at 7 decimal places
	while((high - low)>eps){
		double mid = (low+high)/2.0;
		if(multiply(mid,n)<m){
			low=mid;
		}
		else
			high= mid;
	}
	return low;
}