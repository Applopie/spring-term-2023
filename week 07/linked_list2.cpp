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