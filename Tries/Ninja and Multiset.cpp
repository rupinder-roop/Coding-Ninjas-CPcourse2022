#include<bits/stdc++.h>
using namespace std;

struct trie
{
    trie *left = NULL, *right = NULL;
    int count = 0;
    void insert(int index, int val)
    {
        if(index < 0)
        {
            return ;
        }
        int a = (1ll << index);
        int b = (a & val);
        if(b == 0)
        {
            if(left == NULL)
                left = new trie();
            left->count++;
            left->insert(index-1,val);
        }
        else
        {
            if(right == NULL)
               right = new trie();
            right->count++;
            right->insert(index-1,val);
        }
    }
    
    void delete_(int index, int val)
    {
        if(index<0)
          return;
        int a = (1ll << index), b = (a & val);
        if(b == 0)
        {
            if(left == NULL)
               left = new trie();
            left->count--;
            left->delete_(index-1,val);
        }
        else
        {
            if(right == NULL)
                right = new trie();
            right->count--;
            right->delete_(index-1,val);
        }
    }
    
    int max_(int index, int val)
    {
        int ans = 0;
        if(index < 0)
            return 0;
        int a = (1ll << index), b = (a & val);
        if(b == 0)
        {
            if(right && right->count > 0)
            {
                ans += (a);
                ans += (right->max_(index-1,val));
            }
            else if(left && left->count > 0)
            {
                ans += (left->max_(index-1,val));
            }
            else
                return ans;
        }
        else
        {
            if(left && left->count > 0)
            {
                ans += (a);
                ans += (left->max_(index-1,val));
            }
            else if(right && right->count > 0)
            {
                ans += (right->max_(index-1,val));
            }
            else
                return ans;
        }
        return ans;
    }
};
int main()
{
   trie *head = new trie();
    int q;
    cin>>q;
    while(q--)
    {
        char x,y;
        int a,b,c,d;
        cin>>x;
        cin>>a;
        if(x == '+')
        {
            head->insert(31,a);
        }
        else if(x == '-')
        {
            head->delete_(31,a);
        }
        else
        {
            b = max(a, head->max_(31,a));
            cout<<b<<endl;
        }
    }
}
