#include <iostream>
#include <algorithm>
#include <random>

int main() 
{
  int A[100];
  for (int i = 0; i < 100; i++) 
  {
    A[i] = i + 1;
  }

  std::random_device rd;
  std::mt19937 gen(rd());
  std::shuffle(A, A + 100, gen);

  for (int i = 0; i < 100; i++) 
  {
    std::cout << A[i] << " ";
  }
  std::cout << std::endl;

  return 0;
}
