#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

#define MAX_WORD_SIZE 100
#define MAX_DICT_SIZE 1000

bool isSubsequence(const char* s, const char* word) {
    int j = 0;
    for (int i = 0; i < strlen(s) && j < strlen(word); i++) {
        if (s[i] == word[j]) {
            j++;
        }
    }
    return j == strlen(word);
}

int compareStrings(const void* a, const void* b) {
    return strcmp((const char*)a, (const char*)b);
}

char* getValidWord(char* s, char dictionary[MAX_DICT_SIZE][MAX_WORD_SIZE], int dictSize) {
    qsort(dictionary, dictSize, MAX_WORD_SIZE, compareStrings);
    for (int i = 0; i < dictSize; i++) {
        if (isSubsequence(s, dictionary[i])) {
            return dictionary[i];
        }
    }
    return "-1";
}

int main() {
    char s[] = "hoplploypa";
    char dictionary[MAX_DICT_SIZE][MAX_WORD_SIZE] = {"coffee", "coding", "happy", "hello", "hop", "hopa", "pulkit"};
    int dictSize = 7;
    char* res;

    res = getValidWord(s, dictionary, dictSize);
    printf("%s\n", res);
    return 0;
}
