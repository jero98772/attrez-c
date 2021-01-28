/* merge sort */
#define MERSORT_DECL(TYPE, NAME)                     \
    void merge##NAME(TYPE *, size_t, size_t, size_t, \
                     bool (*comp)(TYPE *, TYPE *));  \
                                                     \
    void mersort##NAME(TYPE *, size_t, size_t, bool (*comp)(TYPE *, TYPE *));

#define MERSORT_IMPL(TYPE, NAME)                              \
    void merge##NAME(TYPE *arr, size_t p, size_t q, size_t r, \
                     bool (*comp)(TYPE *, TYPE *)) {          \
        size_t n1 = q - p, n2 = r - q;                        \
        TYPE larr[n1], rarr[n2];                              \
                                                              \
        memcpy(larr, arr + p, sizeof(TYPE) * n1);             \
        memcpy(rarr, arr + q, sizeof(TYPE) * n2);             \
                                                              \
        size_t i = 0, j = 0;                                  \
        for (int k = p; k < r; ++k) {                         \
            if (i >= n1) {                                    \
                arr[k] = rarr[j++];                           \
            } else if (j >= n2) {                             \
                arr[k] = larr[i++];                           \
            } else {                                          \
                if (comp(&larr[i], &rarr[j])) {               \
                    arr[k] = rarr[j++];                       \
                } else {                                      \
                    arr[k] = larr[i++];                       \
                }                                             \
            }                                                 \
        }                                                     \
    }                                                         \
                                                              \
    void mersort##NAME(TYPE *arr, size_t p, size_t r,         \
                       bool (*comp)(TYPE *, TYPE *)) {        \
        if (p + 1 < r) {                                      \
            size_t q = (p + r) / 2;                           \
            mersort##NAME(arr, p, q, comp);                   \
            mersort##NAME(arr, q, r, comp);                   \
            merge##NAME(arr, p, q, r, comp);                  \
        }                                                     \
    }

#define MERSORT(TYPE, NAME)  \
    MERSORT_DECL(TYPE, NAME) \
    MERSORT_IMPL(TYPE, NAME)
