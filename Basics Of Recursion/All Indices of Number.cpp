
int allIndexes(int input[], int size, int x, int output[]) {
  /* Don't write main().
     Don't read input, it is passed as function argument.
     Save all the indexes in the output array passed and return the size of output array.
     Taking input and printing output is handled automatically.
  */
    static int ind1=0;
    static int indOut=0;
    
    if(ind1==size){
        return indOut;
    }
    
    if(input[ind1]==x){
        output[indOut]=ind1;
        indOut++;
    }

    ind1++;
    return allIndexes(input,size,x,output);
}
