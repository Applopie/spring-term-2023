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
void push_back(Node *&head_ref, char new_key)
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
    char a = ' ';
    a = std::getchar();
    while ((a != '\n') || (a != '\0'))
    {
        push_back(head, a);
        a = std::getchar();
    }
    return head;
}

string yon(Node *head)
{
    if (head == nullptr)
    {
        return "NO";
    }
    else
    {
        Node *el = head;
        if (el->key != '(')
        {
            return "NO";
        }
        else
        {
            int t = 1;
        }
        while ((el->key != '\n') || (el->key != '\0'))
        {
            if (el->next->key == '(')
            {
                t++;
                el = el->next;
            }
            else if (el->next->key == ')')
            {
                if (t <= 0)
                {
                    return "NO";
                }
                else
                {
                    t--;
                }
            }
        }
        if (t == 0)
        {
            return "YES";
        }
        else
        {
            return "NO";
        }
    }
}

int main()
{
    Node *head = nullptr;
    head = read_list(head);
    std::cout << yon(head);
    destroy_list(head);
    return 0;
}