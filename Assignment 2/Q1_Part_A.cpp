 #include <iostream>
 #include <cstdlib>
 #include <ctime>
 
 // Partition subroutine
 int partition(int arr[], int low, int high)
 {
    int pivot = arr[high];
    int i = low - 1;
 
    for (int j = low; j <= high - 1; j++) 
    {
        if (arr[j] <= pivot) 
        {
            i++;
            std::swap(arr[i], arr[j]);
        }
    }
    std::swap(arr[i + 1], arr[high]);
    return i + 1;
}

 // Quicksort
 void quicksort(int arr[], int low, int high)
 {
    if (low < high) 
    {
        int pivotIndex = partition(arr, low, high);
        quicksort(arr, low, pivotIndex - 1);
        quicksort(arr, pivotIndex + 1, high);
    }
}

// Randomized Quicksort
 void randomizedQuicksort(int arr[], int low, int high)
 {
    if (low < high) 
    {
        int pivotIndex = partition(arr, low, high);
        // Randomly choose a pivot index
        int randomPivotIndex = low + rand() % (high - low + 1);
        std::swap(arr[randomPivotIndex], arr[pivotIndex]);

        randomizedQuicksort(arr, low, pivotIndex - 1);
        randomizedQuicksort(arr, pivotIndex + 1, high);
    } 
 }
 
int main()
{
    int A[100];
    for (int i = 0; i < 100; i++) 
    {
        A[i] = i + 1;
    }
    srand(time(0));
    for (int i = 0; i < 5; i++) 
    {
        int B[100];
        std::copy(A, A + 100, B); // Create a copy of A
        
        std::clock_t start = std::clock();
        randomizedQuicksort(B, 0, 99);
        std::clock_t end = std::clock();
        double elapsed = double(end - start) / CLOCKS_PER_SEC;
        std::cout << "Running time " << i + 1 << ": " << elapsed << "seconds." << std::endl;
    }
return 0;
}
