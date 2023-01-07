#include "../src/cvec.h"
#include <stdio.h>

int main() {
    cvec vec = cvec_new(sizeof(char), 12);
    cvec_put(&vec, "3");
    cvec_put(&vec, "2");
    cvec_put(&vec, "6");
    cvec_put(&vec, "9");
    printf("Initial contents: %s\n", vec.contents);
    printf("Byte at %d -> %d\n", 2, *cvec_at(&vec, 2));
    cvec_pop(&vec);
    printf("After pop: %s\n", vec.contents);
    printf("Byte at %d after pop -> %d\n", 2, *cvec_at(&vec, 2));
    cvec_remove(&vec, 0);
    printf("%s after remove on %d\n", vec.contents, 0);
    cvec_free(&vec);

    vec = cvec_new(sizeof(size_t), 1);    
    size_t val = (size_t) 0x15dc;
    cvec_put(&vec, &val);
    printf("sizeof(size_t) -> %zu\n", sizeof(size_t));
    printf("%s; size %zu\n", vec.contents, vec.size);
    val = 0x02ec;
    cvec_put(&vec, &val);
    printf("After realloc: %s; size: %zu\n", vec.contents, vec.size);
    printf("At index %d: %zx\n", 1, *(size_t*) cvec_at(&vec, 1));
    cvec_free(&vec);
}