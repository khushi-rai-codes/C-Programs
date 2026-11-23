#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define N 4
#define THREADS 4

int A[N][N] = {
    {1, 2, 3, 4},
    {5, 6, 7, 8},
    {9, 10, 11, 12},
    {13, 14, 15, 16}
};

int B[N][N] = {
    {1, 0, 0, 0},
    {0, 2, 0, 0},
    {0, 0, 3, 0},
    {0, 0, 0, 4}
};

int C[N][N];

typedef struct {
    int startRow;
    int endRow;
} Task;

void *multiply(void *argument) {
    Task *task = (Task *)argument;

    for (int i = task->startRow;
         i < task->endRow; i++) {

        for (int j = 0; j < N; j++) {
            C[i][j] = 0;

            for (int k = 0; k < N; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    return NULL;
}

int main() {
    pthread_t threads[THREADS];
    Task tasks[THREADS];

    for (int i = 0; i < THREADS; i++) {
        tasks[i].startRow = i * N / THREADS;
        tasks[i].endRow = (i + 1) * N / THREADS;

        int result = pthread_create(
            &threads[i],
            NULL,
            multiply,
            &tasks[i]
        );

        if (result != 0) {
            fprintf(stderr, "Thread creation failed.\n");
            return EXIT_FAILURE;
        }
    }

    for (int i = 0; i < THREADS; i++) {
        if (pthread_join(threads[i], NULL) != 0) {
            fprintf(stderr, "Thread joining failed.\n");
            return EXIT_FAILURE;
        }
    }

    printf("Result Matrix:\n");

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%5d", C[i][j]);
        }

        printf("\n");
    }

    return 0;
}
