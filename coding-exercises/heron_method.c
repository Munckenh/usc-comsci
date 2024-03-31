#include <stdio.h>

double fabs(double x) {
    if (x < 0) {
        return x * -1;
    }
    return x;
}

double sqrt(double x) {
    double y = x;
    double z = (y + x / y) / 2;
    while (fabs(y - z) > 0.0000000000001) {
        double y = z;
        double z = (y + x / y) / 2;
    }
    return z;
}

int main() {
    printf("%lf", sqrt(2));
    return 0;
}