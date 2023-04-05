#include <iostream>

using namespace std;

struct Node
{
    int key = 0;
    Node *next = nullptr;
    Node *prev = nullptr;
};

struct List
{
    size_t size = 0;
    Node *HEAD = nullptr;
    Node *TAIL = nullptr;
    Node *NIL = nullptr;
};

List *create_empty_list()
{
    List *list = new List;
    List->NIL = new Node;
    List->HEAD = List->NIL;
    List->TAIL = List->NIL;
    return List;
}

List *push_front(List *list_ptr, int new_key)
{
    if (list_ptr == nullptr)
    {
        return nullptr;
    }
    if (list_ptr->HEAD == list_ptr->NIL)
    {
        list_ptr->HEAD = new Node;
        list_ptr->HEAD->key = new_key;
        list_ptr->HEAD->prev = list_ptr->NIL;
        list_ptr->HEAD->next = list_ptr->NIL;
        list_ptr->TAIL = list_ptr->HEAD;
        list_ptr->size++;
        return list_ptr;
    }
    if (list_ptr->HEAD->next == list_ptr->NIL)
    {
        list_ptr->HEAD = new Node;
        list_ptr->HEAD->key = new_key;
        list_ptr->HEAD->prev = list_ptr->NIL;
        list_ptr->HEAD->next = list_ptr->TAIL;
        list_ptr->TAIL->prev = list_ptr->HEAD;
        list_ptr->size++;
        return list_ptr;
    }
    Node *el = list_ptr->HEAD;
    list_ptr->HEAD = new Node;
    list_ptr->HEAD->key = new_key;
    list_ptr->HEAD->prev = list_ptr->NIL;
    list_ptr->HEAD->next = el;
    el->prev = list_ptr->HEAD;
    list_ptr->size++;
    return list_ptr;
}

List *push_back(List *list_ptr, int new_key)
{
    if (list_ptr == nullptr)
    {
        return nullptr;
    }
    if (list_ptr->HEAD == list_ptr->NIL)
    {
        list_ptr->TAIL = new Node;
        list_ptr->TAIL->key = new_key;
        list_ptr->TAIL->prev = list_ptr->NIL;
        list_ptr->TAIL->next = list_ptr->NIL;
        list_ptr->TAIL = list_ptr->HEAD;
        list_ptr->size++;
        return list_ptr;
    }
    if (list_ptr->HEAD->next == list_ptr->NIL)
    {
        list_ptr->TAIL = new Node;
        list_ptr->TAIL->key = new_key;
        list_ptr->TAIL->prev = list_ptr->HEAD;
        list_ptr->TAIL->next = list_ptr->NIL;
        list_ptr->HEAD->next = list_ptr->TAIL;
        list_ptr->size++;
        return list_ptr;
    }
    Node *el = list_ptr->TAIL;
    list_ptr->TAIL = new Node;
    list_ptr->TAIL->key = new_key;
    list_ptr->TAIL->next = list_ptr->NIL;
    list_ptr->TAIL->prev = el;
    el->next = list_ptr->TAIL;
    list_ptr->size++;
    return list_ptr;
}

List *insert_after(List *list_ptr, Node *prev_ptr, int new_key)
{
    if (list_ptr == nullptr)
    {
        return nullptr;
    }
    if
}