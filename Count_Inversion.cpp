#include <bits/stdc++.h>
using namespace std;

void merge(long long arr[], int left, int mid, int right, long long &inversion)
{
    int *newArray = new int[right + 1];
    int i = left;
    int j = mid + 1;
    int k = left;

    while (i <= mid && j <= right)
    {
        if (arr[i] < arr[j])
        {
            newArray[k++] = arr[i++];
        }
        else
        {
            newArray[k++] = arr[j++];
            inversion = inversion + (mid - i) + 1;
        }
    }
    if (i > mid)
    {
        while (j <= right)
        {
            newArray[k++] = arr[j++];
        }
    }
    else
    {
        while (i <= mid)
        {
            newArray[k++] = arr[i++];
        }
    }
    for (int k = left; k <= right; k++)
    {
        arr[k] = newArray[k];
    }
    delete[] newArray;
}

long long mergeSort(long long arr[], int left, int right, long long &inversion)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid, inversion);
        mergeSort(arr, mid + 1, right, inversion);

        merge(arr, left, mid, right, inversion);
    }
    return inversion;
}

long long getInversions(long long *arr, int n){
    // Write your code here.
    long long int inversion = 0;
    int ans = mergeSort(arr, 0, n-1, inversion);
    return ans;
}