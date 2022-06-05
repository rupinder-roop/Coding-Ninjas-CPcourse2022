#include <bits/stdc++.h>
using namespace std;
void LPS(string patt, int lps[], int m) 
{
    lps[0] = 0;
    int i = 1, len = 0;
    while (i < m) 
    {
        if (patt[i] == patt[len]) 
        {
            len++; 
            lps[i] = len;
            i++; 
        }
        else
        {
            if (len != 0) 
                len = lps[len - 1];
            else {
                lps[i] = 0;
                i++; 
            }
        }
    }
    return;
}
int KMP(string text, string patt)
{
    int n = text.length();
    int m = patt.length(); 
    int lps[m];
    memset(lps, 0, sizeof lps);
    LPS(patt, lps, m);
    int i = 0, j = 0, ans = 0;
    while (i < n)
    {
        if (text[i] == patt[j]) 
        {
            i++; 
            j++;
        }
        if (j == m)
        {
            ans++; 
            j = lps[j - 1];
        }
        else if (i < n && text[i] == ' ')
            i++;
        else if (i < n && text[i] != patt[j]) 
        {
            if (j != 0) 
            {
                j = lps[j - 1]; 
            }
            else
                i++; 
        }
    }
    return ans;

}
int main()
{
    int t;
    cin >> t;
    string text, patt;
    getline(cin, text);
    while (t--)
    {
        getline(cin, text); 
        cin >> patt; 
        cout << KMP(text, patt) << endl;
        getline(cin, text); 
    }
}
