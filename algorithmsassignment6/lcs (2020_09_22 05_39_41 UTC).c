#include <stdlib.h>
#include <stdio.h>
#include <string.h>


#define LEFT  	2
#define UP	 	3
#define LR		4


int LCS(char* str1, char* str2, int len1, int len2, char* b, char* c)
{
    if (NULL == str1 || NULL == str2 || NULL == b || NULL == c) {
        return -1;
    }

    int i, j;

    for (i = 0; i <= len1; i++) {
        *(b + len1 * i) = 0; //b[i][j] = *(*b + i * len1+ j)
        *(c + len1 * i) = 0;
    }

    for (j = 0; j <= len2; j++) {
        *(b + j) = 0;
        *(c + j) = 0;
    }

    for (i = 1; i <= len1; i++) {
        for (j = 1; j <= len2; j++) {
            if (str1[i - 1] == str2[j - 1]) {
                *(c + i * len1 + j) = *(c + (i - 1) * len1 + j - 1) + 1;
                *(b + i * len1 + j) = LR;
            }
            else {
                if (*(c + (i - 1) * len1 + j) >= *(c + i * len1 + j - 1)) {
                    *(c + i * len1 + j) = *(c + (i - 1) * len1 + j);
                    *(b + i * len1 + j) = UP;
                }
                else {
                    *(c + i * len1 + j) = *(c + i * len1 + j - 1);
                    *(b + i * len1 + j) = LEFT;
                }
            }
        }
    }

    return 0;
}

int PrintLCS(char* b, char* str1, int len1, int len2)
{
    if (0 == len1 || 0 == len2 || NULL == b || NULL == str1) {
        return -1;
    }


    if (*(b + len1 * 7 + len2) == LR) {
        PrintLCS(b, str1, len1 - 1, len2 - 1);
        printf("%c ", str1[len1 - 1]);
    }
    else {
        if (*(b + len1 * 7 + len2) == UP) {
            PrintLCS(b, str1, len1 - 1, len2);
        }
        else if (*(b + len1 * 7 + len2) == LEFT) {
            PrintLCS(b, str1, len1, len2 - 1);
        }
    }
    return 0;
}

int main(void)
{
    char* X = "ABCBDAB";
    char* Y = "BDCABA";


    int len1 = strlen(X);
    int len2 = strlen(Y);


    char b[len1 + 1][len2 + 1], c[len1 + 1][len2 + 1];


    int i, j;

    LCS(X, Y, len1, len2, *b, *c);

    for (i = 0; i <= len1; i++) {
        for (j = 0; j <= len2; j++) {
            printf("%d ", c[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    for (i = 0; i <= len1; i++) {
        for (j = 0; j <= len2; j++) {
            if (b[i][j] == LR)
                printf("* ");
            else if (b[i][j] == LEFT)
                printf("< ");
            else if (b[i][j] == UP)
                printf("^ ");
            else
                printf("  ");
        }
        printf("\n");
    }
    printf("\n");

    PrintLCS(*b, X, len1, len2);

    return 0;

}
