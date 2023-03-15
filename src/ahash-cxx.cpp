#include <ahash-cxx/hasher.h>
#include <ahash-cxx/ahash-cxx.h>

namespace ahash {
    uint64_t
    hash(const void *buf, size_t len, uint64_t seed) {
        VectorizedHasher hasher{seed};
        hasher.consume(buf, len);
        return hasher.finalize();
    }
}