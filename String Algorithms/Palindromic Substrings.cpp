# include<bits/stdc++.h>
using namespace std;

//return length of longest palindrome string
int lps(string s){

    int max = 0;
    int n = s.length();

    int cnt = 0;

    for (int i = 0; i < n; i++)
    {
        //Odd length
        int l=i;
        int r=i;


        while (l>=0 && r<n && s[l] == s[r])
        {
            int curr_l  = r-l+1;
            if(curr_l>max){
                max = curr_l;
            }
            cnt++;
            l--;
            r++;
        }
        
        //For even length
        l=i;
        r = i+1;

        while (l>=0 && r<n && s[l] == s[r])
        {
            int curr_l = r-l+1;
            if(curr_l > max){
                max = curr_l;
            }
            cnt++;
            l--;
            r++;
        }
    }
    return cnt;
}

int main(){
    int t;
    cin>>t;
    while (t--)
    {
            string s;
            cin>>s;
            cout<<lps(s)<<endl;
    }
    
    return 0;
}
