#include<bits/stdc++.h>
using namespace std;
struct trie
{
    int cnt;
    trie *arr[26] = {NULL};
    trie() : cnt(0) {}
};

void insert(trie *root, string &s)
{
    for(int i=0;i<s.length();i++)
    {
        int val = (s[i] - 'a');
        if(root->arr[val] == NULL)
        {
            root->arr[val] = new trie();
        }
        root = root->arr[val];
    }
    root->cnt +=1;
}

string search(trie *root, string &s)
{
    string ans = "";
    for(int i=0;i<s.length();i++)
    {
        if(root->arr[s[i]-'a']!=NULL)
        {
            root = root->arr[s[i]-'a'];
            ans += s[i];
        }
        else
        {
            break;
        }
    }
    if(root->cnt)
    {
        return ans;
    }
    for(int i=0;i<26;i++)
    {
        if(root->arr[i]!=NULL)
        {
            root = root->arr[i];
            char c = 'a';
            c += i;
            i = -1;
            ans += c;
            if(root->cnt)
                return ans;
            
            continue;            
        }
    }
    return ans;
}
int main()
{
    int n, q;
    cin>>n;
    string s[n+1];
    trie *root = new trie;
    for(int i=1;i<=n;i++)
    {
        cin>>s[i];
    }
    cin>>q;
    vector<pair<string, int>> v[n+1];
    
    for(int i=1;i<=q;i++)
    {
        int r;
        string s;
        cin>>r>>s;
        v[r].push_back({s, i});
    }
    string ans[q+1];
    for(int i=1;i<=n;i++)
    {
        int sz = v[i].size();
        insert(root, s[i]);
        for(int j=0;j<sz;j++)
        {
            string temp = search(root, v[i][j].first);
            ans[v[i][j].second] = temp;
        }
    }
    for(int i=1;i<=q;i++)
    {
        cout<<ans[i]<<endl;
    }
    return 0;
    
}
