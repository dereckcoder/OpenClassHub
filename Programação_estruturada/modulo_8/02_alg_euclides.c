#include <stdio.h>

int main() {

    int a = 33;
    int b = 12;
    int r = 1;

    while(r != 0) {

        r = a % b;

        a = b;
        b = r;

        printf("%d\n", r);
    }

    printf("%d\n", a);
}