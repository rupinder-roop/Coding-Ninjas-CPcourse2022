#include<bits/stdc++.h>
string uniqueChar(string str) {
	// Write your code here
    string a="";
    unordered_map<char,int> m;
    for(int i=0;i<str.length();i++){
        if(m[str[i]]>0){
            continue;
        }else{
            a+=str[i];
            m[str[i]]++;
        }
    }
    return a;
}
