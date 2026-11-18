#include <bits/stdc++.h>
using namespace std;

//双向链表
struct DLinkedNode{
    int key,value;
    DLinkedNode* prev;
    DLinkedNode* next;
    DLinkedNode():key(0),value(0),prev(nullptr),next(nullptr){}
    DLinkedNode(int _key, int _value): key(_key),value(_value),prev(nullptr),next(nullptr){}
};

class LRUCache {
public:

    unordered_map<int,DLinkedNode*> mp;
    DLinkedNode* head;
    DLinkedNode* tail;
    int size;
    int capacity;
    LRUCache(int capacity) {
        head = new DLinkedNode;
        tail = new DLinkedNode;
        head->next = tail;
        tail->prev = head;
        size = 0;
        this->capacity = capacity;
    }
    
    int get(int key) {
        if(!mp.count(key)){
            return -1;
        }
        DLinkedNode* node = mp[key];
        moveToHead(node);
        return node->value;

    }
    
    void put(int key, int value) {
        if(!mp.count(key)){
            DLinkedNode* node = new DLinkedNode(key,value);
            mp[key] = node;
            addToHead(node);
            size++;
            if(size>capacity){
                DLinkedNode* removed = removeTail();
                mp.erase(removed->key);
                delete removed;
                size--;
            }
        }
        else{
            DLinkedNode* node = mp[key];
            node->value = value;
            moveToHead(node);
        }
    }

    void addToHead(DLinkedNode* node){
        node->next = head->next;
        head->next->prev = node;
        node->prev = head;
        head->next = node;
    }
    void removeNode(DLinkedNode* node){
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    void moveToHead(DLinkedNode* node){
        removeNode(node);
        addToHead(node);
    }

    DLinkedNode* removeTail(){
        DLinkedNode* node = tail->prev;
        removeNode(node);
        return node;
    }
};