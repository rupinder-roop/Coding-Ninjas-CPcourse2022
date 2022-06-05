# include<bits/stdc++.h>
using namespace std;

int *getlps(string pattern){
    int len = pattern.length();
    int *lps = new int[len];

    lps[0] = 0;
    int i=1;
    int j=0;

    while (i<len)
    {
        if(pattern[i] == pattern[j]){
            lps[i] = j+1;
            i++;
            j++;
        }
        else{
            if(j != 0){
                j = lps[j-1];
            }
            else{
                lps[i] = 0;
                i++; 
            }
        }
    }
    
    return lps;
}

bool kmpSearch(string text , string pat){
    int lenText = text.length();
    int lenPat = pat.length();

    int i=0;
    int j=0;

    int *lps = getlps(pat);

    while (i<lenText && j<lenPat)
    {
        if(text[i] == pat[j]){
            i++;
            j++;
        }
        else{
            if(j != 0){
                j = lps[j-1];
            }
            else{
                i++;
            }
        }
    }
    if(j == lenPat){
        return true;
    }
    return false;
}

int main(){

    int t;
    cin>>t;
    while (t--)
    {
        string s,ts;
        cin>>s>>ts;
        if(kmpSearch(ts,s) == 1){
            cout<<"Yes"<<endl;
        }
        else{
            cout<<"No"<<endl;
        }
    }
    

    return 0;
}
