#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void mergesort(int i, int j, int tab[], int tmp[]) {
    if (j <= i) { return; }

    int m = (i + j) / 2;

    mergesort(i, m, tab, tmp);
    mergesort(m + 1, j, tab, tmp);

    int pg = i;
    int pd = m + 1;
    int c;


    for (c = i; c <= j; c++) {
        if (pg == m + 1) {
            tmp[c] = tab[pd];
            pd++;
        }
        else if (pd == j + 1) {
            tmp[c] = tab[pg];
            pg++;
        }
        else if (tab[pg] < tab[pd]) {
            tmp[c] = tab[pg];
            pg++;
        }
        else {
            tmp[c] = tab[pd];
            pd++;
        }
    }

    for (c = i; c <= j; c++) {
        tab[c] = tmp[c];
    }
}


int main() {
    clock_t start = clock();
    {
        int  nbr, i, tab[1000], tmp[1000];

        printf("number of element: ");
        scanf_s("%d", &nbr);
        printf("Random input : ");

        srand((int)time(NULL));
        for (i = 0; i < nbr; i++) {
            tab[i] = rand() % 1000;
            printf("%4d", tab[i]);
        }
        mergesort(0, nbr - 1, tab, tmp);

        printf("\n sorted : ");
        for (i = 0; i < nbr; i++) {
            printf(" %4d", tab[i]);
        }
        printf("\n");
        
    }
    clock_t end = clock();
        printf("Time : %f\n", (double)(end - start) / CLOCKS_PER_SEC);
        return 0;
    
}