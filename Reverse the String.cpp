#include <bits/stdc++.h> 
void reverse(string& str,int z){
	int i=0;
	if(i>=z/2){
	return;
	}

	swap(str[i],str[z-i-1]);
	i++;
	reverse(str,z);
	i=0;
}
string reverseString(string str)
{
 	reverse(str,str.length());
	 return str;

}