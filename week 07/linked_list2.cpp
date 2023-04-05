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
    if ((list_ptr == nullptr) or (prev_ptr == nullptr))
    {
        return nullptr;
    }
    if ([prev_ptr == list_ptr->NIL])
    {
        return list_ptr;
    }
    Node *add = new Node;
    if (prev_ptr == list_ptr->TAIL)
    {
        list_ptr->TAIL = add;
    }
    add->key = new_key;
    add->next = prev_ptr->next;
    add->prev = prev_ptr;
    prev_ptr->next = add;
    list_ptr->size++;
    return list_ptr;
}

void print_list(const List *list_ptr)
{
    if (list_ptr == nullptr)
    {
        std::cout << '\n';
        return;
    }
    if (list_ptr->HEAD == list_ptr->NIL)
    {
        std::cout << '\n';
        return;
    }
    Node *uel = list_ptr->HEAD;
    while (uel != list_ptr->NIL)
    {
        std::cout << uel->key << ' ';
        uel = uel->next;
    }
    std::cout << std::endl;
    return;
}

void clear_list(List *list_ptr) void clear_list(List *list_ptr)
{
    if (list_ptr == nullptr)
    {
        return;
    }
    if (list_ptr->HEAD == list_ptr->NIL)
    {
        return;
    }
    Node *el = list_ptr->HEAD;
    while (el->next != list_ptr->NIL)
    {
        Node *ex = el;
        el = el->next;
        delete ex;
    }
    delete el;
    list_ptr->HEAD = list_ptr->NIL;
    list_ptr->TAIL = list_ptr->NIL;
    list_ptr->size = 0;
    return;
}

void delete_list(List *list_ptr)
{
    if (list_ptr == nullptr)
    {
        return;
    }
    if (list_ptr->HEAD == list_ptr->NIL)
    {
        delete list_ptr->NIL;
        delete list_ptr;
        return;
    }
    Node *el = list_ptr->HEAD;
    while (el->next != list_ptr->NIL)
    {
        Node *ex = el;
        el = el->next;
        delete ex;
    }
    delete el;
    list_ptr->HEAD = list_ptr->NIL;
    list_ptr->TAIL = list_ptr->NIL;
    list_ptr->size = 0;
    delete list_ptr->NIL;
    delete list_ptr;
    return;
}

Node *find_key(List *list_ptr, int key)
{
    if (list_ptr = nullptr)
    {
        return nullptr;
    }
    if (list_ptr->HEAD->key == key)
    {
        return list_ptr->HEAD;
    }

    Node *searched = list_ptr->HEAD->next;
    while (searched != list_ptr->NIL)
    {
        if (searched->key == key)
        {
            return searched;
        }
        searched = searched->next;
    }
    return nullptr;
}

void remove_key(List *list_ptr, int key)
{
    if (list_ptr == nullptr)
    {
        return;
    }
    if (list_ptr->HEAD == list_ptr->NIL)
    {
        return;
    }
    if (list_ptr->HEAD->key == key)
    {
        if (list_ptr->HEAD->next == list_ptr->NIL)
        {
            delete list_ptr->HEAD;
            list_ptr->HEAD = list_ptr->NIL;
            list_ptr->TAIL = list_ptr->NIL;
            return;
        }
        else
        {
            Node *newh = list_ptr->HEAD->next;
            delete list_ptr->HEAD;
            list_ptr->HEAD = newh;
            list_ptr->HEAD->prev = list_ptr->NIL;
            return;
        }
    }

    Node *uel = list_ptr->HEAD->next;
    while (uel->next != list_ptr->NIL)
    {
        if (uel->next->key == key)
        {
            if (uel->next->next != list_ptr->NIL)
            {
                Node *newn = uel->next->next;
                uel->next->next->prev = uel;
                delete uel->next;
                uel->next = newn;
                return;
            }
            else
            {
                delete uel->next;
                uel->next = list_ptr->NIL;
                list_ptr->TAIL = uel;
                return;
            }
        }
        uel = uel->next;
    }
    return;
}