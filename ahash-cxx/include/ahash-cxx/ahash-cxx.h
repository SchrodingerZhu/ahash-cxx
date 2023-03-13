#ifndef AHASH_CXX_H
#define AHASH_CXX_H
#include <ahash-cxx/arch/vaes.h>
#include <ahash-cxx/arch/ssse3.h>
namespace ahash {
    uint64_t hash(const void *buf, size_t len, uint64_t seed);
} // namespace ahash
#endif //AHASH_CXX_H