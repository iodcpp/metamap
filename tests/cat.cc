#include <iod/metamap/make.hh>
#include <iod/metamap/algorithms/cat.hh>
#include <cassert>

IOD_SYMBOL(test1)
IOD_SYMBOL(test2)
IOD_SYMBOL(test3)

int main()
{

  auto a = iod::make_metamap(s::test1 = 12, s::test2 = 13);
  auto b = iod::make_metamap(s::test3 = 14);

  auto c = iod::cat(a, b);

  assert(c.test1 == 12);
  assert(c.test2 == 13);
  assert(c.test3 == 14);
}
