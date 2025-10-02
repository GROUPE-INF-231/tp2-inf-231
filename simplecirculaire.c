#include <stdio.h>
#include <stdlib.h>

typedef struct linkedlist {
    int data;
    struct linkedlist* next;
} list;

list* createNode(int value) {
    list* newNode = (list*)malloc(sizeof(list));
    if (!newNode) {
        printf("Memory allocation failed!\n");
        exit(EXIT_FAILURE);
    }
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}


list* insertEnd(list* head, int value) {
    list* newNode = createNode(value);

    if (head == NULL) {
        newNode->next = newNode;
        return newNode;
    }

    list* temp = head;
    while (temp->next != head) {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->next = head;
    return head;
}


list* insertHead(list* head, int value) {
    list* newNode = createNode(value);

    if (head == NULL) {
        newNode->next = newNode;
        return newNode;
    }

    list* temp = head;
    while (temp->next != head) {
        temp = temp->next;
    }

    temp->next = newNode;
    newNode->next = head;
    return newNode;
}


void printList(list* head) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    list* temp = head;
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("%d\n", head->data);
}


void freeList(list** head) {
    if (*head == NULL) return;

    list* current = *head;
    list* nextNode;

    do {
        nextNode = current->next;
        free(current);
        current = nextNode;
    } while (current != *head);

    *head = NULL;
}

int main() {
    list* head = NULL;

    head = insertHead(head, 10);
    head = insertHead(head, 20);
    head = insertEnd(head, 30);
    head = insertHead(head, 40);
    head = insertEnd(head, 50);

    printf("Circular List:\n");
    printList(head);  // 40 -> 20 -> 10 -> 30 -> 50 -> 40 (points back to 40 to show its circular nature)

    freeList(&head);
    return 0;
}
