#include <iostream>
#include "vector_util.h"

namespace vectorUtil
{
  using std::vector;
  
  template<typename T>
  void PrintVector(const vector<T>& v)
  {
    std::cout << "vector: " << std::endl;
    for (const auto& i : v)
    {
      std::cout << i << " ";
    }
  }

}

