#include <iostream>

using namespace std;

struct Node
{
    int key = 0;
    Node *head;
};

void push_front(Node *&head_ref, int new_key)
{
    if (head_ref == nullptr)
    {
        head_ref = new Node;
        head_ref->key = new_key;
    }
    Node *new_node = new Node;
    new_node->key = new_key;
    new_node->next = head_ref;
    head_ref = new_node;
}

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

void insert_after(Node *&prev_ref, int new_key)
{
    if (prev_ref == nullptr)
    {
        return;
    }
    Node *el = prev_ref->next;
    prev_ref->next = new Node;
    prev_ref->next->key = new_key;
    prev_ref->next->next = el;
    return;
}

void destroy_list(Node *&head_ref)
{
    if (head_ref == nullptr)
    {
        return;
    }
    while (head_ref->next != nullptr)
    {
        Node *el = head_ref->next->next;
        delete head_ref->next;
        head_ref->next = el;
    }
    delete head_ref->next;
    head_ref = nullptr;
    return;
}

void print_list(Node *&head_ref)
{
    if (head_ref == nullptr)
    {
        std::cout << '\n';
        return;
    }
    Node *el = head_ref;
    while (el->next != nullptr)
    {
        std::cout << el->key << ' ';
        el = el->next;
    }
    std::cout << el->key << std::endl;
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

void *find(Node *&head_ref, int key)
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