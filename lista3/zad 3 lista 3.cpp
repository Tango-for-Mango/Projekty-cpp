#include <iostream>
using namespace std;

struct Node { // Tworzenie struktury elementu listy
    int data;
    Node* next;
    Node(int value) : data(value), next(nullptr) {}
};

Node* reverse(Node* head) { // Funkcja która "obraca" listę
    Node* prev = nullptr;
    Node* current = head;
    Node* next = nullptr;

    while (current != nullptr) {
        next = current->next; // Zapamiętywanie następnego elementu
        current->next = prev; // "Odwracanie" wskaźnika na następny element
        prev = current; // Przesuwanie wskaźnika prev na bieżący element
        current = next; // Przesuwanie wskaźnika current na następny element
    }

    return prev; // Zwracanie odpowiedniej głowy odwróconej listy
}

void printList(Node* head) { // Wypisywanie listy
    Node* current = head;
    while (current != nullptr) {
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << std::endl;
}

int main() {
    // Wprowadzanie listy
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(5);
    head->next->next->next = new Node(9);

    cout << "Oryginalna lista: ";
    printList(head);

    // Odwracanie listy
    head = reverse(head);

    cout << "Odwrócona lista: ";
    printList(head);

    // Zwalnianie pamięci
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}
