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
  const int x{42};
  std::cout << (x / (x-x)) << '\n';
}
