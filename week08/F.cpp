#include <iostream>

using std::cin;
using std::cout;
using std::endl;
using std::getchar;

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
void push_back(Node *&head_ref, string new_key)
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

Node *read_list(Node *head, int n)
{
    string a = " ";
    for (i = 0; i < n; i++)
    {
        cin >> a;
        push_back(head, a);
    }
    return head;
}

int howlong(Node *head, int number, int count)
{
    int c = 0;
    Node *el = head;
    while
}

int main()
{
    int N = 0;
    cin >> N;
    Node *head = nullptr;
    head = read_list(head, N);

    int k = 0;
    cin >> k;

    string a = " ";
    cin >> a;

    std::cout << yon(head);
    destroy_list(head);
    return 0;
}