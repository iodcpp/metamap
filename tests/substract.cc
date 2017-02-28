#include <iod/metamap/make.hh>
#include <iod/metamap/algorithms/substract.hh>
#include <cassert>
#include <iostream>

IOD_SYMBOL(test1)
IOD_SYMBOL(test2)
IOD_SYMBOL(test3)
IOD_SYMBOL(test4)
using namespace s;

int main()
{

  auto a = iod::make_metamap(_test1 = 12, _test2 = 13, _test3 = 13, _test4 = 14);
  auto b = iod::make_metamap(_test2 = 12, _test3 = 14);

  auto c = iod::substract(a, b);

  assert(has_key(c, _test1));
  assert(!has_key(c, _test2));
  assert(!has_key(c, _test3));
  assert(has_key(c, _test4));
  std::cout << c.test1 << std::endl;
  assert(c.test1 == 12);
  assert(c.test4 == 14);
}
