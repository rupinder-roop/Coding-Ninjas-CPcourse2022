#include<bits/stdc++.h>
using namespace std;
bool haspath(int **arr,int v,bool *vis,int curr,int end){
    if(curr==end){
        return true;
    }
    for(int i=0;i<v;i++){
        if(!vis[i] and i!=curr and arr[curr][i]==1){
            vis[i]=true;
            if(haspath(arr,v,vis,i,end)){
                return true;
            }
        }
    }
    return false;
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
    while(e--){
        int a,b;
        cin>>a>>b;
        arr[a][b]=1;
        arr[b][a]=1;
    }
    int v1,v2;
    cin>>v1>>v2;
    bool *vis=new bool[v];
    for(int i=0;i<v;i++){
        vis[i]=0;
    }
    vis[v1]=true;
    if(haspath(arr,v,vis,v1,v2)){
        cout<<"true"<<endl;
    }
    else{
        cout<<"false"<<endl;
    }
    }
    return 0;
}
