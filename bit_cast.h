#ifndef BIT_CAST_H
#define BIT_CAST_H 1

#include <bit>
#include <type_traits>

#define BIT_CAST_CONSTEXPR

namespace std
{

#define __cpp_lib_bit_cast 201810L

  template<typename _To, typename _From>
    BIT_CAST_CONSTEXPR
    std::enable_if_t<(sizeof(_To) == sizeof(_From))
		      && std::is_trivially_copyable_v<_From>
		      && std::is_trivially_copyable_v<_To>,
		     _To>
    bit_cast(const _From &__src) noexcept
    {
      _To __dst{};
      __builtin_memcpy(&__dst, &__src, sizeof(_To));
      return __dst;
    }

} // namespace std

#endif // BIT_CAST_H
