#include <stdio.h>
#include <stdlib.h>

#define CHUNK_SIZE 100000

typedef struct {
    long long value;
    int file_id;
} HeapNode;

typedef struct {
    HeapNode *data;
    int size;
} MinHeap;

int compare_ll(const void *a, const void *b) {
    long long x = *(const long long *)a;
    long long y = *(const long long *)b;

    return (x > y) - (x < y);
}

void swap(HeapNode *a, HeapNode *b) {
    HeapNode temp = *a;
    *a = *b;
    *b = temp;
}

void push(MinHeap *heap, HeapNode node) {
    int i = heap->size++;
    heap->data[i] = node;

    while (i > 0) {
        int p = (i - 1) / 2;

        if (heap->data[p].value <= heap->data[i].value)
            break;

        swap(&heap->data[p], &heap->data[i]);
        i = p;
    }
}

HeapNode pop(MinHeap *heap) {
    HeapNode result = heap->data[0];

    heap->data[0] = heap->data[--heap->size];

    int i = 0;

    while (1) {
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        int smallest = i;

        if (left < heap->size &&
            heap->data[left].value < heap->data[smallest].value)
            smallest = left;

        if (right < heap->size &&
            heap->data[right].value < heap->data[smallest].value)
            smallest = right;

        if (smallest == i)
            break;

        swap(&heap->data[i], &heap->data[smallest]);
        i = smallest;
    }

    return result;
}

int main(void) {
    int n;

    printf("Enter number of integers: ");

    if (scanf("%d", &n) != 1 || n < 0) {
        printf("Invalid input.\n");
        return 1;
    }

    FILE **runs = NULL;
    int run_count = 0;
    int run_capacity = 0;

    long long *chunk = malloc(CHUNK_SIZE * sizeof(long long));

    if (!chunk) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    int remaining = n;

    while (remaining > 0) {
        int count = remaining < CHUNK_SIZE
                        ? remaining : CHUNK_SIZE;

        for (int i = 0; i < count; i++) {
            if (scanf("%lld", &chunk[i]) != 1) {
                printf("Invalid integer input.\n");
                free(chunk);

                for (int j = 0; j < run_count; j++)
                    fclose(runs[j]);

                free(runs);
                return 1;
            }
        }

        qsort(chunk, count, sizeof(long long), compare_ll);

        FILE *temp = tmpfile();

        if (!temp) {
            printf("Unable to create temporary file.\n");
            free(chunk);

            for (int j = 0; j < run_count; j++)
                fclose(runs[j]);

            free(runs);
            return 1;
        }

        if (fwrite(chunk, sizeof(long long), count, temp) !=
            (size_t)count) {
            printf("Temporary file write failed.\n");
            fclose(temp);
            free(chunk);

            for (int j = 0; j < run_count; j++)
                fclose(runs[j]);

            free(runs);
            return 1;
        }

        rewind(temp);

        if (run_count == run_capacity) {
            int new_capacity = run_capacity == 0
                                   ? 4 : run_capacity * 2;

            FILE **new_runs = realloc(
                runs, new_capacity * sizeof(FILE *)
            );

            if (!new_runs) {
                fclose(temp);
                free(chunk);

                for (int j = 0; j < run_count; j++)
                    fclose(runs[j]);

                free(runs);
                return 1;
            }

            runs = new_runs;
            run_capacity = new_capacity;
        }

        runs[run_count++] = temp;
        remaining -= count;
    }

    free(chunk);

    MinHeap heap;
    heap.data = malloc(
        (run_count ? run_count : 1) * sizeof(HeapNode)
    );
    heap.size = 0;

    if (!heap.data) {
        for (int i = 0; i < run_count; i++)
            fclose(runs[i]);

        free(runs);
        return 1;
    }

    for (int i = 0; i < run_count; i++) {
        long long value;

        if (fread(&value, sizeof(value), 1, runs[i]) == 1) {
            HeapNode node = {value, i};
            push(&heap, node);
        }
    }

    printf("\nSorted output:\n");

    while (heap.size > 0) {
        HeapNode current = pop(&heap);

        printf("%lld ", current.value);

        long long next_value;

        if (fread(&next_value, sizeof(next_value), 1,
                  runs[current.file_id]) == 1) {
            HeapNode next = {next_value, current.file_id};
            push(&heap, next);
        }
    }

    printf("\n");

    for (int i = 0; i < run_count; i++)
        fclose(runs[i]);

    free(runs);
    free(heap.data);

    return 0;
}
