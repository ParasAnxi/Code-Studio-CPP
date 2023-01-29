int bS(int arr[],int s,int e ,int key){
     int start=s;
    int end=e;
    int m=s+(e-s)/2;

    while(s<=e){
        if(arr[m]==key){
            return m;
        }
        else if(arr[m]<key){
            s=m+1;
        }
        else{
            e=m-1;
        }
        m=s+(e-s)/2;
    }
    return -1;
}
int pivot(int arr[],int n){
    int s=0;
    int e=n-1;
    int m=s+(e-s)/2;
    while(s<e){
        if(arr[m]>=arr[0]){
            s=m+1;
        }
        else{
            e=m;
        }
        m=s+(e-s)/2;
    }
    return s;
}
int search(int* arr, int n, int key) {
     int z= pivot(arr,n);
   if(key>=arr[z] && key<=arr[n-1]){
        return bS(arr,z,n-1,key);
   }
   else{
       return bS(arr,0,z-1,key);
   }
}