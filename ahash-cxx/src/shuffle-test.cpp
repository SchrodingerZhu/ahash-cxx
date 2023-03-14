#include <ahash-cxx/hasher.h>
#include <cstdlib>

#define CHECK_EQ(a, b)                                                        \
  do                                                                          \
    {                                                                         \
      if ((a) != (b))                                                         \
        ::abort ();                                                           \
    }                                                                         \
  while (0)

void
test_shuffle_does_not_collide_with_aes ()
{
  using namespace ahash;
  using Vector = VectorOperator::VecType;
  Vector value{};
  const auto zero_mask_enc = VectorOperator::encode (Vector{}, Vector{});
  const auto zero_mask_dec = VectorOperator::decode (Vector{}, Vector{});
  for (size_t index = 0; index < 16; ++index)
    {
      value[index] = 1;
      const auto excluded_positions_enc
          = VectorOperator::encode (value, zero_mask_enc);
      const auto excluded_positions_dec
          = VectorOperator::decode (value, zero_mask_dec);
      const auto mask = VectorOperator::shuffle_mask ();
      const auto actual_location
          = VectorOperator::shuffle (value, mask);
      for (size_t pos = 0; pos < 16; ++pos)
        {
          if (actual_location[pos] != 0)
            {
              CHECK_EQ (0, excluded_positions_enc[pos]);
              CHECK_EQ (0, excluded_positions_dec[pos]);
            }
        }
      value[index] = 0;
    }
}

int main () {
  test_shuffle_does_not_collide_with_aes();
}