#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CHARS 256

typedef struct Node {
    unsigned char ch;
    unsigned long frequency;
    struct Node *left, *right;
} Node;

typedef struct {
    Node *items[MAX_CHARS * 2];
    int size;
} MinHeap;

Node *createNode(unsigned char ch, unsigned long freq) {
    Node *node = malloc(sizeof(Node));

    if (!node) {
        perror("Memory allocation failed");
        exit(EXIT_FAILURE);
    }

    node->ch = ch;
    node->frequency = freq;
    node->left = node->right = NULL;

    return node;
}

void swap(Node **a, Node **b) {
    Node *temp = *a;
    *a = *b;
    *b = temp;
}

void push(MinHeap *heap, Node *node) {
    int i = heap->size++;

    heap->items[i] = node;

    while (i > 0) {
        int parent = (i - 1) / 2;

        if (heap->items[parent]->frequency <=
            heap->items[i]->frequency)
            break;

        swap(&heap->items[parent], &heap->items[i]);
        i = parent;
    }
}

Node *pop(MinHeap *heap) {
    if (heap->size == 0)
        return NULL;

    Node *result = heap->items[0];

    heap->items[0] = heap->items[--heap->size];

    int i = 0;

    while (1) {
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        int smallest = i;

        if (left < heap->size &&
            heap->items[left]->frequency <
            heap->items[smallest]->frequency)
            smallest = left;

        if (right < heap->size &&
            heap->items[right]->frequency <
            heap->items[smallest]->frequency)
            smallest = right;

        if (smallest == i)
            break;

        swap(&heap->items[i], &heap->items[smallest]);
        i = smallest;
    }

    return result;
}

Node *buildHuffmanTree(unsigned long frequency[]) {
    MinHeap heap = { .size = 0 };

    for (int i = 0; i < MAX_CHARS; i++) {
        if (frequency[i] > 0) {
            push(&heap, createNode(i, frequency[i]));
        }
    }

    if (heap.size == 0)
        return NULL;

    while (heap.size > 1) {
        Node *left = pop(&heap);
        Node *right = pop(&heap);

        Node *parent = createNode(
            0,
            left->frequency + right->frequency
        );

        parent->left = left;
        parent->right = right;

        push(&heap, parent);
    }

    return pop(&heap);
}

void generateCodes(
    Node *root,
    char code[],
    int depth,
    char codes[MAX_CHARS][MAX_CHARS]
) {
    if (!root)
        return;

    if (!root->left && !root->right) {
        if (depth == 0)
            code[depth++] = '0';

        code[depth] = '\0';

        strcpy(codes[root->ch], code);
        return;
    }

    code[depth] = '0';

    generateCodes(
        root->left, code, depth + 1, codes
    );

    code[depth] = '1';

    generateCodes(
        root->right, code, depth + 1, codes
    );
}

void freeTree(Node *root) {
    if (!root)
        return;

    freeTree(root->left);
    freeTree(root->right);
    free(root);
}

int main() {
    char text[] = "HUFFMAN CODING IS AN ADVANCED DATA STRUCTURE";

    unsigned long frequency[MAX_CHARS] = {0};
    char codes[MAX_CHARS][MAX_CHARS] = {{0}};
    char code[MAX_CHARS];

    for (int i = 0; text[i] != '\0'; i++) {
        frequency[(unsigned char)text[i]]++;
    }

    Node *root = buildHuffmanTree(frequency);

    if (!root) {
        printf("No input data.\n");
        return 0;
    }

    generateCodes(root, code, 0, codes);

    printf("HUFFMAN CODES\n");
    printf("-------------------------\n");

    for (int i = 0; i < MAX_CHARS; i++) {
        if (frequency[i] > 0) {
            if (i == ' ')
                printf("SPACE");
            else
                printf("%c", i);

            printf(" : %s\n", codes[i]);
        }
    }

    unsigned long originalBits = strlen(text) * 8;
    unsigned long compressedBits = 0;

    printf("\nEncoded Text:\n");

    for (int i = 0; text[i] != '\0'; i++) {
        printf("%s", codes[(unsigned char)text[i]]);

        compressedBits += strlen(
            codes[(unsigned char)text[i]]
        );
    }

    printf("\n\nOriginal Size: %lu bits", originalBits);
    printf("\nEncoded Size: %lu bits", compressedBits);

    printf("\nCompression Ratio: %.2f%%\n",
        100.0 * compressedBits / originalBits
    );

    freeTree(root);

    return 0;
}
