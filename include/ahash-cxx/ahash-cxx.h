#pragma once
namespace ahash {
    __attribute__((visibility("default"), used)) uint64_t hash(const void *buf, size_t len, uint64_t seed);
} // namespace ahash
