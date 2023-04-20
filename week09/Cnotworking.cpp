#include <iostream>
#include <cmath>

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

Node *one(int n, int m, Node *head)
{
    if (n == 1)
    {
        push_back(head, m);
        return head;
    }
    else if (m % n == 0)
    {
        push_back(head, m / n);
    }
    else
    {
        push_back(head, ceil(m / n));
        one(n * ceil(m / n) - m, m * ceil(m / n), head);
    }
}

int main()
{
    Node *head = nullptr;
    int n = 0, m = 0;
    cin >> n >> m;
    head = one(n, m, head);
    print_list(head);
    destroy_list(head);
    return 0;
}