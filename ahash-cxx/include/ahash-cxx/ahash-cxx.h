#ifndef AHASH_CXX_H
#define AHASH_CXX_H
namespace ahash {
    uint64_t hash(const void *buf, size_t len, uint64_t seed);
} // namespace ahash
#endif //AHASH_CXX_H