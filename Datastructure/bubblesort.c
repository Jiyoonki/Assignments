#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main() {
    clock_t start = clock();
    {
        int tab[1000], i, j, tmp, nbr;

        printf("Input size : ");
        scanf_s("%d", &nbr);
        printf("Random input : ");

        srand((int)time(NULL));
        for (i = 0; i < nbr; i++) {
            tab[i] = rand() % 1000;
            printf("%4d", tab[i]);
        }
        for (i = 0; i < nbr - 1; i++)
        {
            for (j = 0; j < nbr - i - 1; j++)
            {
                if (tab[j] > tab[j + 1])
                {
                    tmp = tab[j];
                    tab[j] = tab[j + 1];
                    tab[j + 1] = tmp;
                }
            }
        }

        printf("\nSorted :");

        for (i = 0; i < nbr; ++i){
            printf("%4d", tab[i]);
        }
    }
    clock_t end = clock();
    printf("\nTime : %f", (double)(end - start) / CLOCKS_PER_SEC);
    return 0;
}