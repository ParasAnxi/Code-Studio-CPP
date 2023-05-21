int duplicateNumber(int *arr, int size)
{
    for(int i=0;i<size;i++){
        for(int j=i+1;j<size;j++){
                if(arr[i]==arr[j]){
                    return arr[i];
                }
        }
    }
    return -1;
}