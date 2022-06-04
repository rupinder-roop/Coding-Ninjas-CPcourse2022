#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a=0,s=0,p=0;
    int n=0;
    cin>>n;
    char * str =new char [n];
    cin>>str;
    for(int i=0;i<n;i++){
        if(str[i]=='a'){
            a++;
        }else if(str[i]=='s'){
            s++;
        }else if(str[i]=='p'){
            p++;
        }
    }
    cout<<a<<" "<<s<<" "<<p;
	return 0;
}
