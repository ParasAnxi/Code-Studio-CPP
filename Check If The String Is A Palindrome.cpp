#include <bits/stdc++.h> 
string toLc(string s){
    int start = 0;
    int end = s.size()-1;
    string str="";
    while(start<=end){
        if(s[start]>='a' && s[start]<='z' || s[start]>='0' && s[start]<='9'){
                str+=s[start++];
        }
            else if(s[start]>='A' && s[start]<='Z'){
                str+=s[start++] -'A' + 'a';
            }
            else{
                start++;
            }
        }
    return str;
    }

bool checkPalindrome(string s)
{
    string z = toLc(s);
   int st=0;
   int e = z.size()-1;
   bool f=true;
   while(st<=e){
       if(z[st]!=z[e]){
           return false;
           f=false;
       }
       else{
           st++;
           e--;
       }
   }
   return f;
}