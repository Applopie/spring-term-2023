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

Node *read_list(Node *head, int n)
{
    string a = " ";
    for (int i = 0; i < n; i++)
    {
        cin >> a;
        push_back(head, a);
    }
    return head;
}

int howlong(Node *head, int number, int count, int obj)
{
    int c = 1;
    int t = 0;
    int hl = 0;
    int ans = 0;
    Node *el = head;
    while (t != 1) {
        for (int i = 0; i < number-1; i++) {
            if (c%count == 0) {
                if (el->key != 0) {
                    hl++;
                    if (el->key == obj)
                    {
                        t = 1;
                        ans = hl;
                    }
                    el->key = 0;
                    c++;
                    el = el->next;
                }
                else {
                    el = el->next;
                }
            }
            else {
                if (el->key != 0) {
                    c++;
                    el = el->next;
                }
                else {
                    el = el->next;
                }
            }
        }
        if (c % count == 0)
        {
            if (el->key != 0)
            {
                hl++;
                if (el->key == obj)
                {
                    t = 1;
                }
                el->key = 0;
                c++;
                el = head;
            }
            else
            {
                el = head;
            }
        }
        else
        {
            if (el->key != 0)
            {
                c++;
                el = head;
            }
            else
            {
                el = head;
            }
        }
    }
    return ans;
}

int main()
{
    int N = 0;
    cin >> N;
    char a[N][100];
    Node *head = nullptr;
    for (int i = 0; i < N; i++) {
        cin << a[i];
        push_back (head, i+1);
    }

    int k = 0;
    cin >> k;

    int need = 0;
    char b[100];
    cin >> b;
    for (int i = 0; i < N; i++) {
        if (a[i] == a) {
            need = i + 1;
        }
    }

    std::cout << howlong(head, N, k, need);
    destroy_list(head);
    return 0;
}