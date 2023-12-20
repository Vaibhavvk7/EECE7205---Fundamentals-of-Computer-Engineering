// Insertion sort
#include <iostream> 
#include<time.h> 
using namespace std;

// Function to sort using insertion sort 
void insertion(int a[], int n)
{
    int i, key, j;
    for (i = 1; i < n; i++) 
    {
        key = a[i];
        j = i - 1;
        while (j >= 0 && a[j] > key) 
        {
            a[j + 1] = a[j];
            j = j - 1; 
        }
    a[j + 1] = key; 
    }
}

void display(int a[], int n) 
{
    int i;
    for (i = 0; i < n; i++)
        cout << a[i] << " "; 
    cout << endl;
}

int main() 
{
    clock_t start, end;
    int a[100],n,i; start=clock(); 
    cout<<"Enter the limit"; 
    cin>>n; for(i=0;i<n;i++)
    {
        cin>>a[i];
    }
    insertion(a, n); display(a, n);
    end=clock();
    double t_time=double(end - start) / double(CLOCKS_PER_SEC); 
    cout << "Time taken by program is : " <<t_time<<" sec";
    return 0; 
}
