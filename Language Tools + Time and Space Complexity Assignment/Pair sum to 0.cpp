#include<bits/stdc++.h>
int pairSum(int *arr, int n) {
	// Write your code here
     unordered_map<int,int> m;
    for(int i=0;i<n;i++){
        m[arr[i]]++;
    }
    int count = 0;
    for(int i=0;i<n;i++){
        if(arr[i] == 0){
            continue;
        }
        int comp = -arr[i];
        if(m[comp] != 0){
            count += (m[arr[i]] * m[comp]);
            m[comp] = 0;
            m[arr[i]] = 0;
        }
    }
    if(m[0] != 0){
        int temp = m[0]-1;
        count += (temp*(temp+1)/2);
    }
    return count;
}
