#include <iod/metamap/make.hh>
#include <iod/metamap/algorithms/substract.hh>
#include <cassert>

IOD_SYMBOL(test1)
IOD_SYMBOL(test2)
IOD_SYMBOL(test3)
IOD_SYMBOL(test4)

int main()
{

  auto a = iod::make_metamap(s::test1 = 12, s::test2 = 13, s::test3 = 13, s::test4 = 14);
  auto b = iod::make_metamap(s::test2 = 12, s::test3 = 14);

  auto c = iod::substract(a, b);

  assert(has_key(c, s::test1));
  assert(!has_key(c, s::test2));
  assert(!has_key(c, s::test3));
  assert(has_key(c, s::test4));
  assert(c.test1 == 12);
  assert(c.test4 == 14);
}
