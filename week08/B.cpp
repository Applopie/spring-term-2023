#include <iostream>

using std::cin;
using std::cout;
using std::endl;

struct Node
{
    int key;
    Node *next;
};

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

// Место для реализации функций
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

Node *read_list(Node *head)
{
    int a = -1;
    cin >> a;
    while (a != 0)
    {
        push_front(head, a);
        cin >> a;
    }
    return head;
}

int find_middle(Node *head)
{
    Node *el = head;
    Node *el2 = head;
    int t = 0;
    while (el2 != nullptr)
    {
        el = el->next;
        el2 = el2->next;
        if (el2 != nullptr)
        {
            el2 = el2->next;
        }
        else
        {
            t = 1;
        }
    }
    if (t == 1)
    {
        return el->key;
    }
    else
    {
        return el->next->key;
    }
}

int main()
{
    Node *head = nullptr;
    head = read_list(head);
    cout << find_middle(head) << endl;
    destroy_list(head);
    return 0;
}