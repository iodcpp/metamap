#pragma once

#include <utility>

namespace iod
{

  namespace internal
  {
    struct {
      template <typename A, typename... B>
      constexpr auto operator()(A&& a, B&&... b)
      {
        auto result = a;
        using expand_variadic_pack  = int[];
        (void)expand_variadic_pack{0, ((result += b), 0)... };
        return result;
      }
    } reduce_add;

  }

  template <typename ...Ms>
  struct metamap;
  
  template <typename F, typename... M>
  decltype(auto) find_first(metamap<M...>&& map, F fun);
  
  template <typename ...Ms>
  struct metamap : public Ms...
  {
    typedef metamap<Ms...> self;
    // Constructors.
    inline metamap() = default;
    inline metamap(self&&) = default;
    inline metamap(const self&) = default;

    metamap(self& other)
      : metamap(const_cast<const self&>(other)) {}

    template <typename... M>
    inline metamap(M&&... members) : Ms(std::forward<M>(members))... {}

    // Assignemnt ?

    // Retrive a value.
    template <typename K>
    decltype(auto) operator[](K k)
    {
      return symbol_member_access(*this, k);
    }

    template <typename K>
    decltype(auto) operator[](K k) const
    {
      return symbol_member_access(*this, k);
    }

  };
  
  template <typename K, typename M>
  constexpr auto has_key(M&& map, K k)
  {
    return decltype(has_member(map, k)){};
  }

  template <typename M, typename K>
  constexpr auto has_key(K k)
  {
    return decltype(has_member(std::declval<M>(), k)){};
  }
}
