#pragma once
#include <ahash-cxx/arch/config.h>
#if AHASH_CXX_HAS_SSSE3_ACCELERATION
#  include <ahash-cxx/common.h>
namespace ahash
{
namespace ssse3
{
struct AHashArch
{
  struct AesType
  {
    __m128i data;
    AesType
    encode (AesType other) const
    {
      return { _mm_aesenc_si128 (data, other.data) };
    }
    AesType
    add_by_64s (AesType other) const
    {
      return { _mm_add_epi64 (data, other.data) };
    }
    AesType
    shuffle () const
    {
      const auto mask = _mm_set_epi64x (SHUFFLE_MASKS_A, SHUFFLE_MASKS_B);
      return { _mm_shuffle_epi8 (data, mask) };
    }
    AesType
    shuffle_and_add (AesType other) const
    {
      return this->shuffle ().add_by_64s (other);
    }

    static AesType
    unaligned_load (const void *target)
    {
      return { _mm_loadu_si128 (reinterpret_cast<const __m128i *> (target)) };
    }

  private:
    AesType (__m128i data) // NOLINT(google-explicit-constructor)
        : data (data)
    {
    }
  };
  static constexpr size_t HASH_STRIDE = 4;
};
} // namespace vaes
} // namespace ahash
#endif