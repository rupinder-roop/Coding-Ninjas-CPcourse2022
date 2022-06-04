#include<bits/stdc++.h>
using namespace std;

const int N = (int) 1e5+5;

int src[N], dst[N], val[N], idx[N];
int ans[N], visited[N], depth[N];
int parent[N], r[N];

vector<vector<pair<int, int>>> graph(N);



void make_set() {
    for(int i = 0 ; i < N ; ++i) {
        r[i] = 0;
        parent[i] = i;
    }
}


int get_parent(int x) {
    while(x != parent[x]) {
        x = parent[x];
    }
    return x;
}


void union_set(int x, int y) {
    x = get_parent(x);
    y = get_parent(y);
    graph[x].clear();
    graph[y].clear();
    visited[x] = visited[y] = false;
    
   
    if(x != y) {
        if(r[x] == r[y]) ++r[x];
        if(r[x] < r[y]) swap(x, y);
        parent[y] = x;
    }
}


void kruskal(int v, int index, int h) {
    visited[v] = true;
    depth[v] = h;
    
    for(pair<int, int> p : graph[v]) {
        
        if(!visited[p.first]) {
            kruskal(p.first, p.second, h+1);
            depth[v] = min(depth[v], depth[p.first]);
        }
        
        else if(p.second != index) {
            depth[v] = min(depth[v], depth[p.first]);
        }
    }
    
    if(depth[v] == h) ans[index] = 2;
}

int main()
{
	
    int n, m;
    cin >> n >> m;
    
    
    for(int i = 1 ; i <= m ; i++) {
        cin >> src[i] >> dst[i] >> val[i];
        idx[i] = i;
    }
    
    sort(idx+1, idx+m+1, [&](int x, int y) {
        return val[x] < val[y];
    });
    
    
    make_set();
  	
    for(int i = 1 ; i <= m ; ) {
        int j = i;
       
        for(j = i ; val[idx[i]] == val[idx[j]] ; ++j) {
            int set1 = get_parent(src[idx[j]]);
            int set2 = get_parent(dst[idx[j]]);
            if(set1 != set2) {
                ans[idx[j]] = 1; 
                graph[set1].push_back({set2, idx[j]});
                graph[set2].push_back({set1, idx[j]});
            }
        }
        
    
        for(j = i ; val[idx[i]] == val[idx[j]] ; ++j) {
            int v = get_parent(src[idx[j]]);
            if(!visited[v]) {
                kruskal(v, 0, 0);
            }
        }
        
       
        for(j = i ; val[idx[i]] == val[idx[j]] ; ++j) {
            union_set(src[idx[j]], dst[idx[j]]);
        }
        
        i = j;
    }
    
   
    for(int i = 1 ; i <= m ; ++i) {
        if(ans[i] == 0) cout << "none" << endl;
        else if(ans[i] == 1) cout << "at least one" << endl;
        else cout << "any" << endl;
    }
	
    return 0;
}
