#include <assert.h>
#include <limits.h>
#include "queue.h"

void test() {
    struct queue queue;
    initialize(&queue);
    enqueue(&queue, 10);
    assert(dequeue(&queue) == 10);
    assert(dequeue(&queue) == INT_MAX);
    enqueue(&queue, 20);
    enqueue(&queue, 30);
    assert(dequeue(&queue) == 20);
    assert(dequeue(&queue) == 30);
}

int main() {
    test();
    return 0;
}