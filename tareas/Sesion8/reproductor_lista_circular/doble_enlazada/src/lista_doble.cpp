#include "lista_doble.h"

void ListaDoble::append(const std::string & title) {
    Node *n = new Node(title);
    if (!tail) {
        head=n;
        tail=n;
        current = n;
        return;
    }

    n->prev=tail;
    tail->next=n;
    tail=n;
}

Node *ListaDoble::find_prev(Node *node) {
    if(node==nullptr)
        return nullptr;
    
    return node->prev; //el anteiror:Vv
}

void ListaDoble::move_left() {
    if (!current)
        return;
    
    Node *prev = find_prev(current);
    
    if (prev) 
        current = prev;
}

void ListaDoble::move_right() {

    if(current && current->next) current = current -> next;
}

const char *ListaDoble::title_cstr() const {
    static std::string empty = "No songs";
    return current ? current -> song.c_str() : empty.c_str();
}

ListaDoble::~ListaDoble() {
    Node *t = head;
    while (t) {
        Node *nx = t -> next;
        delete t;
        t = nx;
    }
    head = current = nullptr;
}