#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <assert.h>

typedef unsigned char Set;

void initialize(Set *s) {
    *s = 0;
}

void display(Set s) {
    for (unsigned char mask = 1 << (8 * sizeof(unsigned char) - 1); mask > 0; mask >>= 1) {
        printf("%d", (mask & s) != 0);
    }
    printf("\n");
}

void insert(Set *s, int pos) {
    *s |= 1 << pos;
}

bool is_member(Set s, int pos) {
    return (s >> pos) & 1;
}

void delete(Set *s, int pos) {
    *s &= ~(1 << pos);
}

Set get_union(Set s1, Set s2) {
    return s1 | s2;
}

Set get_intersection(Set s1, Set s2) {
    return s1 & s2;
}

Set get_difference(Set s1, Set s2) {
    return s1 & ~s2;
}

int main() {
    Set a;

    // Test initialize()
    initialize(&a);
    assert(a == 0);

    /// Test insert()
    insert(&a, 1);
    insert(&a, 3);
    assert(a == 0b1010);

    // Test is_member()
    assert(!is_member(a, 0));
    assert(is_member(a, 1));
    assert(!is_member(a, 2));
    assert(is_member(a, 3));

    // Test delete()
    delete(&a, 0);
    delete(&a, 1);
    assert(a == 0b1000);

    // Test get_union()
    assert(get_union(0b0001, 0b1000) == 0b1001);

    // Test get_intersection()
    assert(get_intersection(0b1110, 0b1010) == 0b1010);

    // Test get_difference()
    assert(get_difference(0b1111, 0b1010) == 0b0101);

    return 0;
}