//Merge Sort
#include <stdio.h> 
#include<time.h> 
#include <iostream> 
using namespace std;

// Merges two subarrays of a[].
// First subarray is a[l..m]
// Second subarray is a[m+1..r] 
void merge(int a[], int x, int y, int r) 
{
    int i, j, k;
    int n1 = y - x + 1; int n2 = r - y;
    /* create temp arrays */ 
    int L[n1], R[n2];
    /* Copy data to temp arrays L[] and R[] */ 
    for (i = 0; i < n1; i++)
        L[i] = a[x + i];
    for (j = 0; j < n2; j++)
        R[j] = a[y + 1 + j];
        
    /* Merge the temp arrays back into a[x..r]*/ 
    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = x; // Initial index of merged subarray 

    while (i < n1 && j < n2) 
    {
       if (L[i] <= R[j]) 
        { 
            a[k] = L[i]; 
            i++;
        } 
        else 
        {
            a[k] = R[j];
            j++; 
        }
        k++; 
    }

    while (i < n1) 
    { 
        a[k] = L[i]; 
        i++;
        k++;
    }

    while (j < n2) 
    { 
        a[k] = R[j]; 
        j++;
        k++;
    } 
}

/* l is for left index and r is right index of the sub-array of arr to be sorted */
void mergeSort(int a[], int l, int r) 
{
    if (l < r) 
    {
    // Same as (l+r)/2, but avoids overflow for 
    // large l and h
        int m = l + (r - l) / 2;
    // Sort first and second halves 
        mergeSort(a, l, m); 
        mergeSort(a, m + 1, r);
        merge(a, l, m, r); 
    }
}

/* Function to print an array */ 
void display(int A[], int size) 
{
    int i;
    for (i = 0; i < size; i++)
    {
        cout<<A[i]<<" ";
    }
}

int main() 
{
    clock_t start, end; 
    int i,a[100],n;
    cout<<"enter the limit "; 
    cin>>n; 
    for(i=0;i<n;i++) 
        cin>>a[i];
    start=clock();
    mergeSort(a, 0, n - 1); 
    cout<<"\nSorted array is \n"; 
    display(a, n);
    end=clock();
    double t_time=double(end - start) / double(CLOCKS_PER_SEC);
    cout << "Time taken by program is : " <<t_time<<" sec"; 
    return 0;
}
