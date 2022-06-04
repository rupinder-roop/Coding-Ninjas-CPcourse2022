int firstIndex(int input[], int size, int x) {
  /* Don't write main().
     Don't read input, it is passed as function argument.
     Return output and don't print it.
     Taking input and printing output is handled automatically.
  */
	static int ind=0;
    if(ind==size){
        return -1;
    }
    
    if(input[ind]==x){
        return ind;
    }
    
    ind++;
    return firstIndex(input,size,x);
}
