#include <stdio.h>

#define MAX 1000

int contains(int frames[], int capacity, int page) {
    for (int i = 0; i < capacity; i++) {
        if (frames[i] == page)
            return i;
    }

    return -1;
}

void displayFrames(int frames[], int capacity) {
    for (int i = 0; i < capacity; i++) {
        if (frames[i] == -1)
            printf("- ");
        else
            printf("%d ", frames[i]);
    }
}

void fifo(int pages[], int n, int capacity) {
    int frames[MAX];
    int pointer = 0;
    int faults = 0;

    for (int i = 0; i < capacity; i++)
        frames[i] = -1;

    printf("\nFIFO PAGE REPLACEMENT\n");

    for (int i = 0; i < n; i++) {
        int hit = contains(frames, capacity, pages[i]);

        if (hit == -1) {
            frames[pointer] = pages[i];
            pointer = (pointer + 1) % capacity;
            faults++;

            printf("Page %d: FAULT | ", pages[i]);
        } else {
            printf("Page %d: HIT    | ", pages[i]);
        }

        displayFrames(frames, capacity);
        printf("\n");
    }

    printf("Total Page Faults: %d\n", faults);
}

void lru(int pages[], int n, int capacity) {
    int frames[MAX];
    int lastUsed[MAX] = {0};
    int faults = 0;

    for (int i = 0; i < capacity; i++)
        frames[i] = -1;

    printf("\nLRU PAGE REPLACEMENT\n");

    for (int i = 0; i < n; i++) {
        int index = contains(frames, capacity, pages[i]);

        if (index == -1) {
            int replace = 0;

            for (int j = 0; j < capacity; j++) {
                if (frames[j] == -1) {
                    replace = j;
                    break;
                }

                if (lastUsed[j] < lastUsed[replace])
                    replace = j;
            }

            frames[replace] = pages[i];
            lastUsed[replace] = i;
            faults++;

            printf("Page %d: FAULT | ", pages[i]);
        } else {
            lastUsed[index] = i;

            printf("Page %d: HIT    | ", pages[i]);
        }

        displayFrames(frames, capacity);
        printf("\n");
    }

    printf("Total Page Faults: %d\n", faults);
}

void optimal(int pages[], int n, int capacity) {
    int frames[MAX];
    int faults = 0;

    for (int i = 0; i < capacity; i++)
        frames[i] = -1;

    printf("\nOPTIMAL PAGE REPLACEMENT\n");

    for (int i = 0; i < n; i++) {
        if (contains(frames, capacity, pages[i]) == -1) {
            int replace = -1;
            int farthest = -1;

            for (int j = 0; j < capacity; j++) {
                if (frames[j] == -1) {
                    replace = j;
                    break;
                }

                int nextUse = n;

                for (int k = i + 1; k < n; k++) {
                    if (pages[k] == frames[j]) {
                        nextUse = k;
                        break;
                    }
                }

                if (nextUse > farthest) {
                    farthest = nextUse;
                    replace = j;
                }
            }

            frames[replace] = pages[i];
            faults++;

            printf("Page %d: FAULT | ", pages[i]);
        } else {
            printf("Page %d: HIT    | ", pages[i]);
        }

        displayFrames(frames, capacity);
        printf("\n");
    }

    printf("Total Page Faults: %d\n", faults);
}

int main(void) {
    int n, capacity;
    int pages[MAX];

    printf("Enter number of page references: ");

    if (scanf("%d", &n) != 1 ||
        n <= 0 || n > MAX) {
        printf("Invalid input.\n");
        return 1;
    }

    printf("Enter reference string:\n");

    for (int i = 0; i < n; i++) {
        scanf("%d", &pages[i]);

        if (pages[i] < 0) {
            printf("Page numbers cannot be negative.\n");
            return 1;
        }
    }

    printf("Enter number of frames: ");

    if (scanf("%d", &capacity) != 1 ||
        capacity <= 0 || capacity > MAX) {
        printf("Invalid frame capacity.\n");
        return 1;
    }

    fifo(pages, n, capacity);
    lru(pages, n, capacity);
    optimal(pages, n, capacity);

    return 0;
}
