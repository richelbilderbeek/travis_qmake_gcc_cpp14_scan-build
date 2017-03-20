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
  int a[3] = { 0, 1, 2 };
  a[4] = 0; // Access violation!
  std::cout
    << a[4] //Access violation!
    << f() << '\n';
}
