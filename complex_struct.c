#include<stdio.h>
struct Complex {
    int r1, i1, r2, i2;
};
void addComplex(struct Complex c) {
    int r = c.r1 + c.r2;
    int i = c.i1 + c.i2;
    printf("Sum of complex numbers: %d + %di\n", r, i);
}
int main() {
    struct Complex c = {3, 4, 5, 6};
    addComplex(c);
    return 0;
}