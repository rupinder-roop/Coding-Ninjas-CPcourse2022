#include<bits/stdc++.h>
using namespace std;

vector<int> DFS_path(int **arr,int v,bool *vis,int start,int end){
  if(start==end){
      vector<int>ans;
      ans.push_back(start);
      return ans;
  }  
    
    for(int i=0;i<v;i++){
        if(!vis[i] and i!=start and arr[start][i]==1){
            vector<int>ans;
            vis[i]=true;
            ans=DFS_path(arr,v,vis,i,end);
            if(ans.size()!=0){
                ans.push_back(start);
                return ans;
            }
        }
    }
    vector<int> ans;
    return ans;
}

int main(){
    int t;
    cin>>t;
    while(t--){
	int v,e;
    cin>>v>>e;
    int **arr=new int*[v];
    for(int i=0;i<v;i++){
        arr[i]=new int[v];
        for(int j=0;j<v;j++){
            arr[i][j]=0;
        }
    }
    bool *vis=new bool[v];
    for(int i=0;i<v;i++){
        vis[i]=false;
    }
    while(e--){
        int a,b;
        cin>>a>>b;
        arr[a][b]=1;
        arr[b][a]=1;
    }
    int start,end;
    cin>>start>>end;
    vis[start]=true;
    
    vector<int>ans=DFS_path(arr,v,vis,start,end);
    if(ans.size()!=0){
        for(int i=0;i<ans.size();i++){
            cout<<ans[i]<<" ";
        }
    }
    else{
        continue;
    }
        cout<<endl;
}
    return 0;
}
