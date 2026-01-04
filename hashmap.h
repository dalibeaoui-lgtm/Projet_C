#ifndef HASHMAP_H
#define HASHMAP_H


typedef struct Node {
    int key;            
    int value;          
    struct Node* next;  
} Node;


typedef struct {
    int size;
    Node** buckets;     
} HashMap;


HashMap* createMap(int size);
void insert(HashMap* map, int key);
int get(HashMap* map, int key);
void freeMap(HashMap* map);
#endif


