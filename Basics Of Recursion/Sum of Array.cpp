int sum(int input[], int n) {
  /* Don't write main().
     Don't read input, it is passed as function argument.
     Return output and don't print it.
     Taking input and printing output is handled automatically.
  */
	
    static int s=0;
    if(n==0){
        return s;
    }
    
    s +=input[n-1];
    
    return sum(input,n-1);
}
