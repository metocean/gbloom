#include <stdio.h>
#include <string.h>
#include "bloom.h"

int main() {

    int k = 20;
    char filter[1100];
    memset(filter, 0, sizeof(filter));
    size_t bits = sizeof(filter) * 8;

    bloom_add_str(filter, bits, k, "Aardvark");
    bloom_add_str(filter, bits, k, "Bear");
    bloom_add_str(filter, bits, k, "Beaver");
    bloom_add_str(filter, bits, k, "Bee");

    printf("Dog: %d\n", bloom_contains_str(filter, bits, k, "Dog"));
    printf("Bear: %d\n", bloom_contains_str(filter, bits, k, "Bear"));
    printf("Bea: %d\n", bloom_contains_str(filter, bits, k, "Bea"));
}
