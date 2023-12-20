#include <iostream>
#include <algorithm>
#include <vector>
#include <random>

void heapsort(std::vector<int>& arr) 
{
  std::make_heap(arr.begin(), arr.end());

  for (int i = arr.size() - 1; i > 0; i--) 
  {
    std::pop_heap(arr.begin(), arr.begin() + i + 1);
  }
  std::sort_heap(arr.begin(), arr.end());
}

int main() 
  {
  std::vector<int> permutation(100);
  for (int i = 0; i < 100; i++) 
  {
    permutation[i] = i + 1;
  }
  std::random_device rd;
  std::mt19937 gen(rd());
  std::shuffle(permutation.begin(), permutation.end(), gen);
  std::cout << "Original Array: ";
  for (const auto& num : permutation) 
  {
    std::cout << num << " ";
  }
  std::cout << std::endl;

  heapsort(permutation);

  std::cout << "Sorted Array: ";
  for (const auto& num : permutation) 
  {
    std::cout << num << " ";
  }
  std::cout << std::endl; 
  return 0;
}
