#include <iostream>
#include <vector>
#include <algorithm>

void countingSort(std::vector<int>& array, int exp) 
{  
  int size = array.size();
  std::vector<int> count(10, 0);
  std::vector<int> output(size);

  // Count the occurrence of each digit
  for (int i = 0; i < size; i++) 
  {
    count[(array[i] / exp) % 10]++;
  }
  // Calculate the cumulative count
  for (int i = 1; i < 10; i++) 
  {
    count[i] += count[i - 1];
  }
 
  // Place the elements in sorted order
  for (int i = size - 1; i >= 0; i--) 
  {
    output[count[(array[i] / exp) % 10] - 1] = array[i];
    count[(array[i] / exp) % 10]--;
  }

  // Copy the sorted output back to the original array
  for (int i = 0; i < size; i++) 
  {
    array[i] = output[i];
  }
}

void radixSort(std::vector<int>& array) 
{
  int max = *std::max_element(array.begin(), array.end());
  
  // Perform counting sort for each decimal digit
  for (int exp = 1; max / exp > 0; exp *= 10) 
  {
      countingSort(array, exp);
  } 
}

int main() 
{
  std::vector<int> A = {329, 457, 657, 839, 436, 720, 353};
  
  std::cout << "Original Array: ";
  for (const auto& num : A) 
  {
    std::cout << num << " ";
  }
  std::cout << std::endl;

  radixSort(A);

  std::cout << "Sorted Array: ";
  for (const auto& num : A) 
  {
    std::cout << num << " ";
  }
  std::cout << std::endl;

  return 0;
}
