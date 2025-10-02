#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} node;

node *head = NULL, *tail = NULL;

void insertAtHead(int value) {
    node *newNode = (node *)malloc(sizeof(node));
    if (!newNode) {
        printf("Erreur d’allocation mémoire\n");
        return;
    }
    newNode->data = value;

    if (head == NULL) {
        head = tail = newNode;
        newNode->next = head;
    } else {
        newNode->next = head;
        head = newNode;
        tail->next = head;
    }
}

void insertAtTail(int value) {
    node *newNode = (node *)malloc(sizeof(node));
    if (!newNode) {
        printf("Erreur d’allocation mémoire\n");
        return;
    }
    newNode->data = value;

    if (head == NULL) {
        head = tail = newNode;
        newNode->next = head;
    } else {
        tail->next = newNode;
        tail = newNode;
        tail->next = head;
    }
}

void display() {
    if (head == NULL) {
        printf("La liste est vide.\n");
        return;
    }
    node *temp = head;
    printf("Liste : ");
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("\n");
}

void freeList() {
    if (head == NULL) return;
    node *temp = head;
    do {
        node *next = temp->next;
        free(temp);
        temp = next;
    } while (temp != head);
    head = tail = NULL;
}

int main() {
    insertAtHead(10);
    insertAtHead(20);
    insertAtTail(30);
    insertAtTail(40);
    
    display();
    
    freeList(); // libère la mémoire
    return 0;
}
.
