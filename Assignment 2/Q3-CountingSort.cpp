#include <iostream>
#include <algorithm>
#include <vector>

void countingSort(std::vector<int>& array, int range) 
{
  int size = array.size();
  std::vector<int> count(range + 1, 0);
  std::vector<int> output(size);
  // Count the occurrence of each element
    for (int i = 0; i < size; i++) 
    {    
      count[array[i]]++;  
    }
  // Calculate the cumulative count
  for (int i = 1; i <= range; i++) 
  {
      count[i] += count[i - 1];
  }

  // Place the elements in sorted order
  for (int i = size - 1; i >= 0; i--) 
    {
      output[count[array[i]] - 1] = array[i];
      count[array[i]]--;
    }

  // Copy the sorted output back to the original array
  for (int i = 0; i < size; i++) 
  {
    array[i] = output[i];
  }
}

int main() 
{
  std::vector<int> A = {20, 18, 5, 7, 16, 10, 9, 3, 12, 14, 0};
  int range = *std::max_element(A.begin(), A.end());

  std::cout << "Original Array: ";
  for (const auto& num : A) 
  {
    std::cout << num << " ";
  }
  std::cout << std::endl;

  countingSort(A, range);

  std::cout << "Sorted Array: ";
  for (const auto& num : A) 
  {
    std::cout << num << " ";
  }
  std::cout << std::endl; 

  return 0;
}

