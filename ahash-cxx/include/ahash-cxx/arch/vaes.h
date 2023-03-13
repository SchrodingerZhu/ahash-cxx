#ifndef AHASH_CXX_ARCH_VAES_H
#define AHASH_CXX_ARCH_VAES_H
#ifdef __VAES__
#define AHASH_CXX_HAS_VAES_ACCELERATION
#include <immintrin.h>
#include <ahash-cxx/common.h>
namespace ahash
{
namespace vaes
{
struct AHashArch
{
  struct AesType
  {
    __m256i data;
    AesType
    encode (AesType other) const
    {
      return { _mm256_aesenc_epi128 (data, other.data) };
    }
    AesType
    add_by_64s (AesType other) const
    {
      return { _mm256_add_epi64 (data, other.data) };
    }
    AesType
    shuffle () const
    {
      const auto mask = _mm256_set_epi64x (SHUFFLE_MASKS_A, SHUFFLE_MASKS_B,
                                           SHUFFLE_MASKS_A, SHUFFLE_MASKS_B);
      return { _mm256_shuffle_epi8 (data, mask) };
    }
    AesType
    shuffle_and_add (AesType other) const
    {
      return this->shuffle ().add_by_64s (other);
    }

    static AesType
    unaligned_load (const void *target)
    {
      return { _mm256_loadu_si256 (
          reinterpret_cast<const __m256i *> (target)) };
    }

    void
    split_into (__m128i (&array)[2]) const
    {
      array[0] = _mm256_extracti128_si256 (data, 0);
      array[1] = _mm256_extracti128_si256 (data, 1);
    }
  private:
    AesType (__m256i data) // NOLINT(google-explicit-constructor)
        : data (data)
    {
    }
  };
  static constexpr size_t HASH_STRIDE = 4;
};
} // namespace vaes
} // namespace ahash
#endif
#endif // AHASH_CXX_ARCH_VAES_H