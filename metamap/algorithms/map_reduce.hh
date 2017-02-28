#pragma once

#include <iod/metamap/metamap.hh>

namespace iod
{

  // Map a function(key, value) on all kv pair
  template <typename... M, typename F>
  void map(const metamap<M...>& m, F fun)
  {
    auto apply = [&] (auto key) -> decltype(auto)
      {
        return fun(key, m[key]);
      };
    
    (void)std::initializer_list<int>{
      ((void)apply(typename M::_iod_symbol_type{}), 0)...};
  }

  // Map a function(key, value) on all kv pair an reduce
  // all the results value with the reduce(r1, r2, ...) function.
  template <typename... M, typename F, typename R>
  decltype(auto) map_reduce(const metamap<M...>& m, F map, R reduce)
  {
    auto apply = [&] (auto key) -> decltype(auto)
      {
        return map(key, std::forward<decltype(m[key])>(m[key]));
      };

    return reduce(apply(typename M::_iod_symbol_type{})...);
  }
  
}
