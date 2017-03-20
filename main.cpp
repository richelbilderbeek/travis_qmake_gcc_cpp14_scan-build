#include <cassert>
#include <iostream>

//C++14
auto f() noexcept {
  return "Hello world\n";
}

int main() 
{
  #ifdef NDEBUG
  #error Must use scan-build in debug mode
  #endif
  // This error is missed
  {
    int v[3] = { 1, 4, 9};
    std::cout << v[3] << '\n';
  }
  // This error is found by the GCC compiler
  //{
  //  const int x{42};
  //  std::cout << (x / (x-x)) << '\n';
  //}
}
