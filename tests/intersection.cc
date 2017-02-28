#include <iod/metamap/make.hh>
#include <iod/metamap/algorithms/intersection.hh>
#include <cassert>
#include <iostream>

IOD_SYMBOL(test1)
IOD_SYMBOL(test2)
IOD_SYMBOL(test3)
IOD_SYMBOL(test4)
IOD_SYMBOL(test5)
using namespace s;

int main()
{
  auto a = iod::make_metamap(_test1 = 12, _test2 = 13, _test4 = 14, _test5 = std::string("test"));

  auto b = iod::make_metamap(_test2 = 12, _test3 = 14, _test5 = 16);
  auto c = iod::intersection(a, b);

  assert(!has_key(c, _test1));
  assert(has_key(c, _test2));
  assert(!has_key(c, _test3));
  assert(!has_key(c, _test4));
  assert(has_key(c, _test5));

  assert(c.test2 == 13);
  assert(c.test5 == "test");
}
