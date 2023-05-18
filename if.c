#include <stdio.h>

int main() {
    int a, b, c, d;

    printf("Podaj cztery liczby: ");
    scanf("%d %d %d %d", &a, &b, &c, &d);

    int max = a;  // Za³o¿enie pocz¹tkowe - pierwsza liczba jest najwiêksza

    if (b > max) {
        max = b;
    }

    if (c > max) {
        max = c;
    }

    if (d > max) {
        max = d;
    }

    printf("Najwiêksza liczba: %d\n", max);

    return 0;
}
