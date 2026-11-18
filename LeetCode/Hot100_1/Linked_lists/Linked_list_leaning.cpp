#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int value;
    Node *next;
};

Node *head = nullptr;
Node *endNode = nullptr;
//头插法
void push_front(int value){
    
    Node *tmp = (Node *)malloc(sizeof(Node));   //在堆上分配内存
    tmp -> value = value;
    tmp -> next = head->next;
    head->next = tmp;
}


void push_back(int value){
    Node *tmp = (Node *)malloc(sizeof(Node));
    tmp -> value = value;
    tmp ->next = nullptr;
    endNode ->next = tmp;
    endNode = tmp;
}

void insert(int pos,int value){
    Node *tmp = (Node *)malloc(sizeof(Node));
    tmp -> value = value;

    int index = 0;
    Node *t = head;
    while(index < pos){
        t = t->next;
        index++;
    }

    tmp -> next = t->next;
    t->next = tmp;
}

void del(int pos){
    int index =0;
    Node *t = head;
    Node *pre;
    while(index < pos){
        pre = t;
        t = t->next;
        index++;
    }

    pre->next = t->next;
    free(t);
    
}