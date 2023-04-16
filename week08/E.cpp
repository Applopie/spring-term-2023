#include <iostream>

using namespace std;
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

int main()
{
    Node *head = nullptr;
    Node *el = head;
    int t = 0;
    char a = ' ';
    a = std::getchar();
    if ((a == ')') || (a == ']') || (a == '}') || (a == '>')) {
        t = 1;
    }
    while ((a != '\n') || (a != '\0'))
    {
        if ((a == '(') || (a == '[') || (a == '{') || (a == '<'))
        {
            push_back(head, a);
        }
        if (a == ')') {
            if ((head == nullptr)||(head->key != '(')) {
                t = 1;
                break;
            }
            head = head -> next;
        }
        if (a == ']') {
            if ((head == nullptr) || (head->key != '[')) {
                t = 1;
                break;
            }
            head = head -> next;
        }
        if (a == '}')
        {
            if ((head == nullptr) || (head->key != '{'))
            {
                t = 1;
                break;
            }
            head = head->next;
        }
        if (a == '>')
        {
            if ((head == nullptr) || (head->key != '<'))
            {
                t = 1;
                break;
            }
            head = head->next;
        }
        a = std::getchar();
    }
    if (t == 1) {
        cout << "NO" << endl;
    }
    if (t == 0) {
        cout << "YES" << endl;
    }
    destroy_list(head);
    return 0;
}