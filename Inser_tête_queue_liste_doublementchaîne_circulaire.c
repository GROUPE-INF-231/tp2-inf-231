#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
} Node;

Node* head = NULL;

// Insertion en tête
void insertHead(int x) {
    Node* n = (Node*)malloc(sizeof(Node));
    n->data = x;
    if (head == NULL) {
        head = n;
        head->next = head;
        head->prev = head;
    } else {
        Node* tail = head->prev;
        n->next = head;
        n->prev = tail;
        tail->next = n;
        head->prev = n;
        head = n;
    }
}

// Insertion en queue
void insertTail(int x) {
    Node* n = (Node*)malloc(sizeof(Node));
    n->data = x;
    if (head == NULL) {
        head = n;
        head->next = head;
        head->prev = head;
    } else {
        Node* tail = head->prev;
        n->next = head;
        n->prev = tail;
        tail->next = n;
        head->prev = n;
    }
}

// Affichage en ordre normal
void display() {
    if (head == NULL) { printf("Liste vide\n"); return; }
    Node* temp = head;
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("\n");
}

// Affichage en ordre inverse
void displayReverse() {
    if (head == NULL) { printf("Liste vide\n"); return; }
    Node* tail = head->prev; // dernier élément
    Node* temp = tail;
    do {
        printf("%d ", temp->data);
        temp = temp->prev;
    } while (temp != tail);
    printf("\n");
}

int main() {
    int choix, val;
    do {
        printf("\n--- MENU ---\n");
        printf("1. Inserer en tete\n");
        printf("2. Inserer en queue\n");
        printf("3. Afficher (avant)\n");
        printf("4. Afficher (arriere)\n");
        printf("0. Quitter\n");
        printf("Choix: ");
        scanf("%d", &choix);

        switch (choix) {
            case 1: printf("Valeur: "); scanf("%d",&val); insertHead(val); break;
            case 2: printf("Valeur: "); scanf("%d",&val); insertTail(val); break;
            case 3: display(); break;
            case 4: displayReverse(); break;
        }
    } while (choix != 0);

    return 0;
}
