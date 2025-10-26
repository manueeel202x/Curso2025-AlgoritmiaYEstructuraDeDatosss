#ifndef LISTA_CIRCULAR_H
#define LISTA_CIRCULAR_H

#include <string>
//using namespace std;

// Nodo simple
struct Node {
    std::string song;
    Node* next;
    explicit Node(const std::string& s) : song(s), next(nullptr) {}
};

// Lista enlazada simple con puntero al actual
struct ListaCircular {
    Node* head{nullptr};
    Node* current{nullptr};

    // Inserta al final y sitúa current en la primera inserción
    void append(const std::string& title);

    // Busca el anterior a 'node' (o nullptr si es el primero/inexistente)
    Node* find_prev(Node* node);

    // Navegación
    void move_left();   // va al anterior si existe (no circular)
    void move_right();  // va al siguiente si existe (no circular)

    // Título de la canción actual (o "No songs")
    const char* title_cstr() const;

    // Libera memoria
    ~ListaCircular();
};

#endif // LISTA_CIRCULAR_H
