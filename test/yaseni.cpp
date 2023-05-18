// очередь - первый вошел, первый вышел

#include <iostream>

using namespace std;

struct Node
{
    int key = 0;
    Node *next;
};

void push_back(Node *&head_ref, int new_key)
{
    if (head_ref == nullptr)
    {
        head_ref = new Node;
        head_ref->key = new_key;
        return;
    }
    Node *el = head_ref;
    while (el->next != nullptr)
    {
        el = el->next;
    }
    el->next = new Node;
    el->next->key = new_key;
    return;
}

Node *find(Node *&head_ref, int key)
{
    if (head_ref == nullptr)
    {
        return nullptr;
    }
    Node *el = head_ref;
    while (el != nullptr)
    {
        if (el->key == key)
        {
            return el;
        }
    }
    return nullptr;
}

// для реализации очереди удаляется первый элемент => мы удаляем не по значению так что сигнатура функции слегка другая но в целом похоже
void *delete_el(Node *&head_ref, int key)
{
    if (head_ref == nullptr)
    {
        return;
    }
    if (head_ref->key == key)
    {
        Node *el = head_ref->next;
        delete head_ref;
        head_ref = el;
        return;
    }
    Node *el = head_ref;
    while (el->next != nullptr)
    {
        if (el->next->key == key)
        {
            Node *el2 = el->next->next;
            delete el->next;
            el->next = el2;
            return;
        }
        el = el->next;
        return;
    }
}