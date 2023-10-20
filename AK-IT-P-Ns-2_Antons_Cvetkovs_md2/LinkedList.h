#ifndef AK_IT_P_NS_2_ANTONS_CVETKOVS_MD2_LINKEDLIST_H
#define AK_IT_P_NS_2_ANTONS_CVETKOVS_MD2_LINKEDLIST_H

#include <iostream>
#include "Coordinates.h"
using namespace std;

class LinkedList {
public:
    explicit LinkedList(int);
    void push(string, string);
    void pop();
    int length();
    bool isFull();
    void show();
    ~LinkedList();

private:
    int size;
    Coordinates * head;
    Coordinates * end;
};

#endif //AK_IT_P_NS_2_ANTONS_CVETKOVS_MD2_LINKEDLIST_H
