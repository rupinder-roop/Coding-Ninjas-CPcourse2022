#include<bits/stdc++.h>

using namespace std;
typedef long long  ll;

class TrieNode{
    public:
        TrieNode *left=NULL;
        TrieNode *right=NULL;
        ll leftCount=0;
    	ll rightCount=0;
};

void insert(ll num,TrieNode *head){
    TrieNode *curr=head;
    for(int i=31; i>=0; i--){
        int bit=(num >> i) & 1;
        if(bit==1){
            curr->rightCount++;
            if(!curr->right){
                curr->right=new TrieNode();
            }
            curr=curr->right;
        }else{
            curr->leftCount++;
            if(!curr->left){
                curr->left=new TrieNode();
            }
            curr=curr->left;
        }
    }
}

ll numSubArrayXorLessThanK(ll *arr,int n,int k){
    ll countSubArrayLessThanK = 0;
    ll xorTillNow = 0;
    TrieNode *head=new TrieNode();
    insert(0,head);

    for(int i=0; i<n; i++){
        xorTillNow = xorTillNow^arr[i];
        TrieNode *curr = head;
        if(!curr){
            return 0;
        }
        for(int j=31;j>=0;j--){
            int bitX = (xorTillNow >> j) & 1;
            int bitK = (k >> j) & 1;
            if(bitX==1 & bitK==1){
                countSubArrayLessThanK += curr->rightCount;
                if(curr->left){
                    curr = curr->left;
                }else{
                    break;
                }
            }else if(bitX==0 & bitK==1){
                countSubArrayLessThanK += curr->leftCount;
                if(curr->right){
                    curr = curr->right;
                }else{
                    break;
                }
            }else if(bitX==0 & bitK==0){
                if(curr->left){
                    curr = curr->left;
                }else{
                    break;
                }
            }else if(bitX==1 & bitK==0){
                if(curr->right){
                    curr = curr->right;
                }else{
                    break;
                }
            }
        }
        insert(xorTillNow, head);
    }
    return countSubArrayLessThanK;
}

int main(){
   
        int n,k;
        cin>>n>>k;
        ll *arr=new ll[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        cout << numSubArrayXorLessThanK(arr, n, k) << endl;
    
    return 0;
}
