#include <stdio.h>

int main() {
    int a, b, c, d;

    printf("Podaj cztery liczby: ");
    scanf("%d %d %d %d", &a, &b, &c, &d);

    int max = a;  // Założenie początkowe - pierwsza liczba jest największa

    if (b > max) {
        max = b;
    }

    if (c > max) {
        max = c;
    }

    if (d > max) {
        max = d;
    }

    printf("Największa liczba: %d\n", max);

    return 0;
}
