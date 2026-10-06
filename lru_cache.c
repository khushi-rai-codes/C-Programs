#include <stdio.h>
#include <stdlib.h>

#define CAPACITY 4

struct Node {
    int key;
    int value;
    struct Node *prev;
    struct Node *next;
};

struct LRUCache {
    int capacity;
    int size;
    struct Node *head;
    struct Node *tail;
};

struct Node *createNode(int key, int value) {
    struct Node *node =
        (struct Node *)malloc(sizeof(struct Node));

    node->key = key;
    node->value = value;
    node->prev = NULL;
    node->next = NULL;

    return node;
}

void removeNode(struct LRUCache *cache, struct Node *node) {
    if (node->prev != NULL) {
        node->prev->next = node->next;
    } else {
        cache->head = node->next;
    }

    if (node->next != NULL) {
        node->next->prev = node->prev;
    } else {
        cache->tail = node->prev;
    }

    cache->size--;
}

void insertAtFront(struct LRUCache *cache, struct Node *node) {
    node->next = cache->head;
    node->prev = NULL;

    if (cache->head != NULL) {
        cache->head->prev = node;
    } else {
        cache->tail = node;
    }

    cache->head = node;
    cache->size++;
}

struct Node *findNode(struct LRUCache *cache, int key) {
    struct Node *current = cache->head;

    while (current != NULL) {
        if (current->key == key) {
            return current;
        }

        current = current->next;
    }

    return NULL;
}

int get(struct LRUCache *cache, int key) {
    struct Node *node = findNode(cache, key);

    if (node == NULL) {
        return -1;
    }

    removeNode(cache, node);
    insertAtFront(cache, node);

    return node->value;
}

void put(struct LRUCache *cache, int key, int value) {
    struct Node *existing = findNode(cache, key);

    if (existing != NULL) {
        existing->value = value;

        removeNode(cache, existing);
        insertAtFront(cache, existing);

        return;
    }

    if (cache->size == cache->capacity) {
        struct Node *leastUsed = cache->tail;

        removeNode(cache, leastUsed);
        free(leastUsed);
    }

    struct Node *newNode = createNode(key, value);

    insertAtFront(cache, newNode);
}

void display(struct LRUCache *cache) {
    struct Node *current = cache->head;

    printf("Cache: ");

    while (current != NULL) {
        printf("[%d:%d] ", current->key, current->value);
        current = current->next;
    }

    printf("\n");
}

void initializeCache(struct LRUCache *cache, int capacity) {
    cache->capacity = capacity;
    cache->size = 0;
    cache->head = NULL;
    cache->tail = NULL;
}

void freeCache(struct LRUCache *cache) {
    struct Node *current = cache->head;

    while (current != NULL) {
        struct Node *temp = current;
        current = current->next;
        free(temp);
    }
}

int main() {
    struct LRUCache cache;

    initializeCache(&cache, CAPACITY);

    put(&cache, 1, 100);
    put(&cache, 2, 200);
    put(&cache, 3, 300);
    put(&cache, 4, 400);

    display(&cache);

    printf("Value for key 2: %d\n", get(&cache, 2));

    put(&cache, 5, 500);

    display(&cache);

    printf("Value for key 1: %d\n", get(&cache, 1));

    freeCache(&cache);

    return 0;
}
