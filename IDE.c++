//inclui AVX/AVX2/AVX512
#include <immintrin.h>


main()
{
    //Trabalhando inicialmente com AVX/AVX2 (256 bits)

    //Standard allocation (unaligned)
    // __m256* A = (__m256*) malloc(sizeof(__m256) * N);

    // Aligned allocation (alligned)
    // __m256* A = aligned_alloc(ALIGN, sizeof(__m256) * N);       
    // __m256* A = _aligned_malloc(ALIGN, sizeof(__m256) * N);       (Same thing)

    
}