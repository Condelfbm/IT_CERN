#include <assert.h>
#include <immintrin.h>

// straightforward implementation
float dot_product(float *a, float *b, size_t n) {
  float sum = 0;
  const float* limit = a + n;
  for ( ; a < limit; a++, b++) {
    sum += a[0] * b[0];
  }
  return sum;
}

// AVX2 implementation
float dot_product_256(float *a, float *b, size_t n) {
    assert(n % 8 == 0);
    __m256 sum = _mm256_setzero_ps();
     size_t limit = n - 7;

     for (size_t i = 0; i < limit; i += 8) {
      __m256 buf1 = _mm256_loadu_ps(a + i);
      __m256 buf2 = _mm256_loadu_ps(b + i);
      sum = _mm256_fmadd_ps(buf1, buf2, sum);
    }

    float buffer[8];
    _mm256_storeu_ps(buffer, sum);
    return buffer[0] + buffer[1] + buffer[2] + buffer[3] + buffer[4] + buffer[5] +
         buffer[6] + buffer[7];
}