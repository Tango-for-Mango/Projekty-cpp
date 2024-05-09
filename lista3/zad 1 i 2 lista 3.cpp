#include <iostream>
using namespace std;
// Funkcje opisujące listę (zad 1)
struct Link
{
    int value;
    Link* next;
    Link(int val) : value(val), next(NULL) {}
};

size_t size(const Link* head) {
    size_t count = 0;
    const Link* current = head;

    while (current != NULL) {
        count++;
        current = current->next;
    }

    return count;
}

size_t sum(const Link* head) {
    size_t total_sum = 0;
    const Link* current = head;

    while (current != NULL) {
        total_sum += current->value;
        current = current->next;
    }

    return total_sum;
}

void append(Link*& head, int value) {
    Link* new_link = new Link(value);
    if (head == NULL) {
        head = new_link;
    } else {
        Link* current = head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new_link;
    }
}
// Czyszczenie pamięci (zad 2)
void release(Link** phead) {
    Link* head = *phead;

    if (head != NULL) {
        release(&head->next); // Rekurencyjnie zwalnia następne elementy listy
        delete head; // Zwalnia pamięć po bieżącym elemencie
    }

    *phead = NULL; // Ustawia wskaźnik na głowę listy na nullptr
}


void printList(const Link* head) {
    const Link* current = head;

    while (current != NULL) {
        cout << current->value << " ";
        current = current->next;
    }

}


int main() {
    Link* head = NULL;

    append(head, 2);
    append(head, 3);
    append(head, 5);
    append(head, 4);
    append(head, 6);
    append(head, 1);

    cout << "Liczba elementow w liscie: " << size(head) << endl;
    cout << "Suma wartosci w liscie: " << sum(head) << endl;
    cout << "liczby w liscie to: ";
    printList(head);

    release (&head);

    return 0;
}
