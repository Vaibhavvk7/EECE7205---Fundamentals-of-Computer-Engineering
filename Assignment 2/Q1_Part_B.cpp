#include <iostream>
#include <cstdlib>
#include <ctime>

// Partition subroutine
void partition(int arr[], int low, int high, int& leftIndex, int& rightIndex)
{
  int pivotIndex = low + rand() % (high - low + 1);
  int pivot = arr[pivotIndex];
  leftIndex = low; // Initialize leftIndex to low
  rightIndex = high; // Initialize rightIndex to high

  int i = low;
  while (i <= rightIndex) 
  { 
    // Change 'high' to 'rightIndex' here
    if (arr[i] < pivot)
      std::swap(arr[i++], arr[leftIndex++]);
    else if (arr[i] > pivot)
      std::swap(arr[i], arr[rightIndex--]);
    else
      i++;
  }
}

// Quicksort
void quicksort(int arr[], int low, int high)
{
  if (low < high) 
  {
    int leftIndex = low, rightIndex = high;
    partition(arr, low, high, leftIndex, rightIndex);
    quicksort(arr, low, leftIndex - 1);
    quicksort(arr, rightIndex + 1, high);
  }
}

// Randomized Quicksort
void randomizedQuicksort(int arr[], int low, int high)
{
  if (low < high) 
  {
    int leftIndex = low, rightIndex = high;
    partition(arr, low, high, leftIndex, rightIndex);
    randomizedQuicksort(arr, low, leftIndex - 1);
    randomizedQuicksort(arr, rightIndex + 1, high);
  }
}

int main()
{
  int A1[] = { 1, 2, 3, 4, 5, 2, 6, 4, 3, 5 }; 
  int A2[] = { 9, 7, 6, 3, 3, 1, 9, 7, 4, 2 };

  srand(time(0));

  std::cout << "Input 1: ";
  for (int i = 0; i < 10; i++)
  {
    std::cout << A1[i] << " ";
  }
  std::cout << std::endl;

  randomizedQuicksort(A1, 0, 9);

  std::cout << "Sorted 1: ";
  for (int i = 0; i < 10; i++) 
  {
    std::cout << A1[i] << " ";
  }
  std::cout << std::endl;

  std::cout << "Input 2: ";
  for (int i = 0; i < 10; i++) 
  {
    std::cout << A2[i] << " ";
  }
  std::cout << std::endl;

  randomizedQuicksort(A2, 0, 9);

  std::cout << "Sorted 2: ";
  for (int i = 0; i < 10; i++) 
  {
    std::cout << A2[i] << " ";
  }
  std::cout << std::endl;

  return 0;
}
