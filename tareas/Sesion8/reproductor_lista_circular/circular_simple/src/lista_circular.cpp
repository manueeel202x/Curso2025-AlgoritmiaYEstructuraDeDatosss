#include "lista_circular.h"

void ListaCircular::append(const std::string & title) {
    Node *n = new Node(title);
    if (!head) {
        head = n;
        current = head;
        n->next = n;
        return;
    }
    Node *t = head;
    
    while (t -> next != head) 
        t = t -> next;
    t -> next = n;
    n->next = head;
}

Node *ListaCircular::find_prev(Node *node) {
    if (!head || head == node) 
        return nullptr;
    Node *t = head;
    
    while (t && t -> next != node) 
        t = t -> next;

    return t;
}

void ListaCircular::move_left() {
    if (!current)
        return;
    
    Node *prev = find_prev(current);
    
    if (prev) 
        current = prev;
}

void ListaCircular::move_right() {

    if(current && current->next) current = current -> next;
}

const char *ListaCircular::title_cstr() const {
    static std::string empty = "No songs";
    return current ? current -> song.c_str() : empty.c_str();
}

ListaCircular::~ListaCircular() {
    Node *t = head;
    while (t) {
        Node *nx = t -> next;
        delete t;
        t = nx;
    }
    head = current = nullptr;
}