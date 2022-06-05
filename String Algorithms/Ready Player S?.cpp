#include <bits/stdc++.h>
using namespace std;

int ans = 0;

void checker(int p_len, string &pattern, vector<int> &v)
{
    int j = 0;
    for (int i = 1; i < p_len; ++i)
    {
        while (j >= 0 and pattern[j] != pattern[i])
        {
            if (j > 0)
                j = v[j - 1];
            else
                j = -1;
        }
        j += 1;
        v[i] = j;
    }
}

bool find_occurence(int t_len, int p_len, string &text, string &pattern, vector<int> &v)
{
    bool found = false;
    int j = 0;

    for (int i = 0; i < t_len; ++i)
    {
        while (j >= 0 and text[i] != pattern[j])
        {
            if (j > 0)
                j = v[j - 1];
            else
                j = -1;
        }
        j += 1;
        if (j == p_len)
        {
            j = v[p_len - 1];
            ans++;
            found = true;
        }
    }
    return found;
}
int main()
{
    int n, m, k;
    string text, temp, pattern = "";
    cin >> n >> m >> k;
    cin >> text >> temp;

    for (int i = 0; i < k; ++i)
        pattern += temp[i];

    int t_len = text.size();
    int p_len = pattern.size();

    vector<int> v(p_len, 0);
    checker(p_len, pattern, v);

    bool found = find_occurence(t_len, p_len, text, pattern, v);

    if (found == false)
        cout << -1 << endl;

    else
        cout << ans << endl;
}
