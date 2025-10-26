#include "lista_doble_circular.h"

void ListaDobleCircular::append(const std::string & title) {
    Node *n = new Node(title);
    if (!tail) {
        head=n;
        tail=n;
        current = n; //va
        n->next=n;
        n->prev=n;
        return;
    }

    n->prev=tail;
    tail->next=n;
    head->prev=n;
    n->next=head;
    tail=n;
}

Node *ListaDobleCircular::find_prev(Node *node) {
    if(node==nullptr)
        return nullptr;
    
    return node->prev; //el anteiror:Vv
}

void ListaDobleCircular::move_left() {
    if (!current)
        return;
    
    Node *prev = find_prev(current);
    
    if (prev) 
        current = prev;
}

void ListaDobleCircular::move_right() {

    if(current && current->next) current = current -> next;
}

const char *ListaDobleCircular::title_cstr() const {
    static std::string empty = "No songs";
    return current ? current -> song.c_str() : empty.c_str();
}

ListaDobleCircular::~ListaDobleCircular() {
    Node *t = head;
    while (t) {
        Node *nx = t -> next;
        delete t;
        t = nx;
    }
    head = current = nullptr;
}