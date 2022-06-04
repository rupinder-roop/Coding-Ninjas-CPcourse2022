#import<algorithm>
int findDuplicate(int *arr, int n)
{
    //Write your code here
    int i=0;
    sort(arr,arr+n);
    for(i=0;i<n;i++){
        if(arr[i]==arr[i+1] && n>1){
            return arr[i];
        }
    }
}
