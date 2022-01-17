#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void permute(int* a, int* b) {
    int tmp;
    tmp = *a;
    *a = *b;
    *b = tmp;
}

void Quicksort(int tab[], int first, int last) {
    int pivot, i, j;
    if (first < last) {
        pivot = first;
        i = first;
        j = last;
        while (i < j) {
            while (tab[i] <= tab[pivot] && i < last)
                i++;
            while (tab[j] > tab[pivot])
                j--;
            if (i < j) {
                permute(&tab[i], &tab[j]);
            }
        }
        permute(&tab[pivot], &tab[j]);
        Quicksort(tab, first, j - 1);
        Quicksort(tab, j + 1, last);
    }
}

int main() {
    clock_t start = clock();
    {
        int tab[1000], nbr, i;

        printf("Input size : ");
        scanf_s("%d", &nbr);
        printf("Random input : ");

        srand((int)time(NULL));
        for (i = 0; i < nbr; i++) {
            tab[i] = rand() % 1000;
            printf(" %4d", tab[i]);
        }

        Quicksort(tab, 0, nbr - 1);

        printf("\nSorted : ");
        for (i = 0; i < nbr; i++) {
            printf(" %4d", tab[i]);
        }
    }
    clock_t end = clock();
    printf("\n\nTime : %f\n", (double)(end - start) / CLOCKS_PER_SEC);
    return 0;
}