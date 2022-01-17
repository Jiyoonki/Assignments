#include <stdio.h>

int number = 6; 
int INF = 1000000000; 


int a[5][5] = {
    {0, 3, 5, INF, INF},
    {INF, 0, 2, 6, INF},
    {INF, 1, 0, 4, 6},
    {INF, INF, INF, 0, 2},
    {3, INF, INF, 7, 0}
};

bool visited[5]; 
int distance[5];


int getSmallIndex() {
    int min = INF;
    int index = 0;

    for (int i = 0; i < number; i++) {
        
        if (distance[i] < min && !visited[i]) {
            min = distance[i];
            index = i; 
        }
    }
    return index;
}


void dijkstra(int start) {
    for (int i = 0; i < number; i++) {
        distance[i] = a[start][i]; 
    }
    visited[start] = true;

    for (int i = 0; i < number - 2; i++) { 
        int current = getSmallIndex(); 
        visited[current] = true;
        
        for (int j = 0; j < number; j++) {
            if (!visited[j]) {
                if (distance[current] + a[current][j] < distance[j]) {
                    distance[j] = distance[current] + a[current][j];
                }
            }
        }
    }
}

int main(void) {
    dijkstra(0);
    for (int i = 0; i < number; i++) {
        printf("%d ", distance[i]);
    }
}