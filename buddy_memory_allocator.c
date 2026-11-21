#include <stdio.h>

#define MEMORY_SIZE 1024
#define MIN_BLOCK 16
#define LEVELS 7

int freeBlocks[LEVELS][MEMORY_SIZE / MIN_BLOCK];
int allocated[MEMORY_SIZE / MIN_BLOCK];

int blockSize(int level) {
    return MEMORY_SIZE >> level;
}

int allocateMemory(int requested) {
    if (requested <= 0 || requested > MEMORY_SIZE)
        return -1;

    int required = MIN_BLOCK;
    while (required < requested)
        required *= 2;

    int level = 0;
    while (blockSize(level) > required)
        level++;

    int found = level;

    while (found >= 0 && !freeBlocks[found][0]) {
        int available = 0;

        for (int i = 0; i < MEMORY_SIZE / blockSize(found); i++) {
            if (freeBlocks[found][i]) {
                available = 1;
                break;
            }
        }

        if (available) break;
        found--;
    }

    if (found < 0)
        return -1;

    int index = 0;
    while (!freeBlocks[found][index])
        index++;

    freeBlocks[found][index] = 0;

    while (found < level) {
        found++;

        int left = index * 2;
        int right = left + 1;

        freeBlocks[found][right] = 1;
        index = left;
    }

    int address = index * blockSize(level);
    allocated[address / MIN_BLOCK] = blockSize(level);

    return address;
}

void releaseMemory(int address) {
    if (address < 0 || address >= MEMORY_SIZE ||
        address % MIN_BLOCK != 0 ||
        allocated[address / MIN_BLOCK] == 0) {
        printf("Invalid memory address!\n");
        return;
    }

    int size = allocated[address / MIN_BLOCK];
    allocated[address / MIN_BLOCK] = 0;

    int level = 0;
    while (blockSize(level) > size)
        level++;

    int index = address / size;

    freeBlocks[level][index] = 1;

    while (level > 0) {
        int buddy = index ^ 1;

        if (!freeBlocks[level][buddy])
            break;

        freeBlocks[level][index] = 0;
        freeBlocks[level][buddy] = 0;

        index /= 2;
        level--;

        freeBlocks[level][index] = 1;
    }

    printf("Memory released at address %d\n", address);
}

int main() {
    freeBlocks[0][0] = 1;

    int a = allocateMemory(100);
    int b = allocateMemory(200);
    int c = allocateMemory(50);

    printf("Allocated addresses:\n");
    printf("Block A: %d\n", a);
    printf("Block B: %d\n", b);
    printf("Block C: %d\n", c);

    releaseMemory(b);
    releaseMemory(a);
    releaseMemory(c);

    return 0;
}
