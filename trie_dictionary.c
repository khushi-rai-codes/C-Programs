#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define ALPHABET_SIZE 26
#define MAX_WORD_LENGTH 100

struct TrieNode {
    struct TrieNode *children[ALPHABET_SIZE];
    int isEndOfWord;
};

struct TrieNode *createNode() {
    struct TrieNode *node =
        (struct TrieNode *)malloc(sizeof(struct TrieNode));

    node->isEndOfWord = 0;

    for (int i = 0; i < ALPHABET_SIZE; i++) {
        node->children[i] = NULL;
    }

    return node;
}

void insert(struct TrieNode *root, const char *word) {
    struct TrieNode *current = root;

    for (int i = 0; word[i] != '\0'; i++) {
        char ch = tolower((unsigned char)word[i]);

        if (ch < 'a' || ch > 'z') {
            continue;
        }

        int index = ch - 'a';

        if (current->children[index] == NULL) {
            current->children[index] = createNode();
        }

        current = current->children[index];
    }

    current->isEndOfWord = 1;
}

int search(struct TrieNode *root, const char *word) {
    struct TrieNode *current = root;

    for (int i = 0; word[i] != '\0'; i++) {
        char ch = tolower((unsigned char)word[i]);

        if (ch < 'a' || ch > 'z') {
            return 0;
        }

        int index = ch - 'a';

        if (current->children[index] == NULL) {
            return 0;
        }

        current = current->children[index];
    }

    return current->isEndOfWord;
}

int startsWith(struct TrieNode *root, const char *prefix) {
    struct TrieNode *current = root;

    for (int i = 0; prefix[i] != '\0'; i++) {
        char ch = tolower((unsigned char)prefix[i]);

        if (ch < 'a' || ch > 'z') {
            return 0;
        }

        int index = ch - 'a';

        if (current->children[index] == NULL) {
            return 0;
        }

        current = current->children[index];
    }

    return 1;
}

void freeTrie(struct TrieNode *root) {
    if (root == NULL) {
        return;
    }

    for (int i = 0; i < ALPHABET_SIZE; i++) {
        freeTrie(root->children[i]);
    }

    free(root);
}

int main() {
    struct TrieNode *root = createNode();

    char word[MAX_WORD_LENGTH];

    int numberOfWords;

    printf("How many words do you want to insert? ");
    scanf("%d", &numberOfWords);

    for (int i = 0; i < numberOfWords; i++) {
        printf("Enter word %d: ", i + 1);
        scanf("%99s", word);

        insert(root, word);
    }

    printf("\nEnter a word to search: ");
    scanf("%99s", word);

    if (search(root, word)) {
        printf("'%s' exists in the dictionary.\n", word);
    } else {
        printf("'%s' was not found.\n", word);
    }

    printf("\nEnter a prefix: ");
    scanf("%99s", word);

    if (startsWith(root, word)) {
        printf("Words starting with '%s' exist.\n", word);
    } else {
        printf("No word starts with '%s'.\n", word);
    }

    freeTrie(root);

    return 0;
}
