#pragma once

#include <iod/metamap/metamap.hh>
#include <experimental/tuple>

namespace iod { namespace metamap {

  template <typename... E, typename F>
  void apply_each(F&& f, E&&... e)
  {
    (void)std::initializer_list<int>{
      ((void)f(std::forward<E>(e)), 0)...};
  }

  template <typename T, typename F>
  void tuple_apply_each(F&& f, T&& t)
  {
    return std::experimental::apply([&] (auto&&... e) { apply_each(f, std::forward<decltype(e)>(e)...); },
                                    std::forward<T>(t));
  }
  
  // Map a function(key, value) on all kv pair
  template <typename... M, typename F>
  void map(const metamap<M...>& m, F fun)
  {
    auto apply = [&] (auto key) -> decltype(auto)
      {
        return fun(key, m[key]);
      };

    apply_each(apply, typename M::_iod_symbol_type{}...);
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
  
}}
