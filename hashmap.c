#include <stdlib.h>
#include  "hashmap.h" 


int hash(int key, int size) {
    int h = key % size;
    if (h < 0) h += size; 
    return h;
}


HashMap* createMap(int size) {
    HashMap* map = malloc(sizeof(HashMap));
    map->size = size;
    map->buckets = calloc(size, sizeof(Node*)); 
}


void insert(HashMap* map, int key) {
    int index = hash(key, map->size);
    Node* current = map->buckets[index];


    while (current != NULL) {
        if (current->key == key) {
            current->value++;
            return;
        }
        current = current->next;
    }

    
    Node* newNode = malloc(sizeof(Node));
    newNode->key = key;
    newNode->value = 1;
    newNode->next = map->buckets[index];
    map->buckets[index] = newNode;
}


int get(HashMap* map, int key) {
    int index = hash(key, map->size);
    Node* current = map->buckets[index];

    while (current != NULL) {
        if (current->key == key) {
            return current->value;
        }
        current = current->next;
    }
    return 0; 
}


void freeMap(HashMap* map) {
    for (int i = 0; i < map->size; i++) {
        Node* current = map->buckets[i];
        while (current != NULL) {
            Node* temp = current;
            current = current->next;
            free(temp);
        }
    }
    free(map->buckets);
    free(map);
}