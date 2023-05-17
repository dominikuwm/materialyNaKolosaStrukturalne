#include <stdio.h>
#include<stdlib.h>

//funkcja
int count_divisors(int num) {
    int count = 0;
    for (int i = 1; i <= num; i++) {
        if (num % i == 0) {
            count++;
        }
    }
    return count;
}

int find_number_with_most_divisors() {
    int max_divisors = 0;
    int number_with_most_divisors = 0;

    for (int i = 1; i <= 999; i++) {
        int num_divisors = count_divisors(i);
        if (num_divisors > max_divisors) {
            max_divisors = num_divisors;
            number_with_most_divisors = i;
        }
    }

    return number_with_most_divisors;
}

// wskazniki
// zwraca wskaznik na zmienna

int* min1(int* a, int* b) {
    if (*a < *b) {
        return a;
    } else {
        return b;
    }
}
int min(int* a, int* b) {
    if (*a < *b) {
        return *a;
    } else {
        return *b;
    }
}

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void swap_if_smaller(int* a, int* b) {
    if (*b < *a) {
        int temp = *a;
        *a = *b;
        *b = temp;
    }
}

int sum(const int* a, const int* b) {
    return *a + *b;
}

void assign_value(int n, int* w) {
    *w = n;
}

void assign_constant_to_variable(const int* constant_ptr, const int* variable_ptr) {
    *variable_ptr = *constant_ptr;
}

//wazne wskazniki
//Napisz bezargumentow¹ funkcjê, która rezerwuje pamiêæ
//dla pojedynczej zmiennej typu int i zwraca jako wartoœæ wskaŸnik
//do niej.
int* allocate_int() {
    int* ptr = (int*)malloc(sizeof(int));
    return ptr;
}

int* allocate_memory(int n) {
    int* ptr = (int*)malloc(n * sizeof(int));
    return ptr;
}

double* allocate_memory(int n) {
    double* ptr = (double*)malloc(n * sizeof(double));
    return ptr;
}

//tablice odwraca kolejnosc
void reverse_array(int n, int* tab) {
    int i, temp;

    for (i = 0; i < n / 2; i++) {
        temp = tab[i];
        tab[i] = tab[n - i - 1];
        tab[n - i - 1] = temp;
    }
}
//przesuwa w lewo o jeden
void shift_left(int n, int* tab) {
    int temp = tab[0]; // Przechowanie wartoœci pierwszego elementu

    for (int i = 0; i < n - 1; i++) {
        tab[i] = tab[i + 1]; // Przesuniêcie elementów o jeden w lewo
    }

    tab[n - 1] = temp; // Przypisanie przechowanej wartoœci do ostatniego elementu
}

//przesuwa o jeden w prawo
void shift_right(int n, int* tab) {
    int temp = tab[n - 1]; // Przechowanie wartoœci ostatniego elementu

    for (int i = n - 1; i > 0; i--) {
        tab[i] = tab[i - 1]; // Przesuniêcie elementów o jeden w prawo
    }

    tab[0] = temp; // Przypisanie przechowanej wartoœci do pierwszego elementu
}
//sortowanie tablicy rosnaca
void sort_asc(int n, int* tab) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (tab[j] > tab[j + 1]) {
                // Zamiana miejscami gdy elementy s¹ w niew³aœciwej kolejnoœci
                int temp = tab[j];
                tab[j] = tab[j + 1];
                tab[j + 1] = temp;
            }
        }
    }
}

//sortowanie malejaco

void sort_desc(int n, int* tab) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (tab[j] < tab[j + 1]) {
                // Zamiana miejscami gdy elementy s¹ w niew³aœciwej kolejnoœci
                int temp = tab[j];
                tab[j] = tab[j + 1];
                tab[j + 1] = temp;
            }
        }
    }
}

//rekurencnja
//napisz funkcję rekurencyjną, która dla otrzymanej w argumencie nieujemnej liczby całkowitej n zwraca wartość elementu o indeksie
//n ciągu zdefiniowanego w następujący sposób
//a0 = a1 = a2 = 1
//oraz dla k > 2
//a3·k = a3·k−1 + a3·k−2
//a3·k+1 = 5 ∗ a3·k + 4
//a3·k+2 = a3·k+1

int ciag(int n) {
    if (n == 0 || n == 1 || n == 2) {
        return 1;
    } else if (n % 3 == 0) {
        return ciag(n - 1) + ciag(n - 2);
    } else if (n % 3 == 1) {
        return 5 * ciag(n - 1) + 4;
    } else {
        return ciag(n - 1);
    }
}

//void przepiszWartosc(int n, int* w) {
   // *w = n;
}//

//int main() {
  //  int n, w;

    //printf("Podaj wartość n: ");
    //scanf("%d", &n);

    //przepiszWartosc(n, &w);

    //printf("Wartość w: %d\n", w);

    //return 0;
//}

int main() {
    int n = 5;
    double* ptr = allocate_memory(n);

        for (int i = 0; i < n; i++) {
        ptr[i] = i + 1.0;
        printf("Wartoœæ elementu %d: %lf\n", i, ptr[i]);
    }

    free(ptr);
    return 0;
}
