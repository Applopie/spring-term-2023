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
void push_back(Node *&head_ref, int new_key)
{
    if (head_ref == nullptr)
    {
        head_ref = new Node;
        head_ref->key = new_key;
        return;
    }
    Node *current = head_ref;
    while (current != nullptr)
    {
        current = current->next;
    }
    current = new Node;
    current->key = new_key;
    return;
}

Node *read_list(Node *head)
{
    int a = -1;
    cin >> a;
    while (a != 0)
    {
        push_back(head, a);
        cin >> a;
    }
    return head;
}
Node *reverse(Node *head)
{
    Node *el = head;
    Node *prev = nullptr;
    while (el != nullptr)
    {
        Node *omel = head->next;
        el->next = prev;
        prev = el;
        head = el;
        el = omel;
    }
    return head;
}

int main()
{
    Node *head = nullptr;
    head = read_list(head);
    head = reverse(head);
    print_list(head);
    destroy_list(head);
    return 0;
}