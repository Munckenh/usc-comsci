#define MAX 10

typedef struct {
    int elements[MAX];
    int count;
} *List;

void initialize(List L) {
    L->count = 0;
}

int main() {
    List L;
    initialize(L);
    return 0;
}