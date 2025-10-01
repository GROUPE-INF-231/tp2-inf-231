#include<stdio.h>
#include<stdlib.h>

typedef struct linkedlist {
    int data;
    struct linkedlist* next;
} list;

void deleteElementOccurrence(list** head, int data) {
    if (*head == NULL) {
        printf("List is empty!\n");
        return;
    }

    while (*head != NULL && (*head)->data == data) {
        list* temp = *head;
        *head = (*head)->next;
        free(temp);
    }

    list* current = *head;
    while (current != NULL && current->next != NULL) {
        if (current->next->data == data) {
            list* temp_2 = current->next;
            current->next = current->next->next;
            free(temp_2);
        }
        else {
            current = current->next;
        }
    }
}

void printList(list* head) {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }

    printf("Liste: ");
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}


list* createlist(int data) {
    list* newNode = (list*)malloc(sizeof(list));
    if (!newNode) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void insertEnd(list** head, int data) {
    list* newNode = createlist(data);

    if (*head == NULL) {
        *head = newNode;
        return;
    }

    list* temp = *head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = newNode;
}

int main() {
    list* head = NULL;
    int i, nb, elm, del;

    printf("Entrez le nombre d'element que vous voulez inserer: ");
    do {
        scanf("%d", &nb);
        if (nb <= 0) {
            printf("Erreur! Entrez une valeur valide.\n");
        }
    } while (nb <= 0);

    for (i = 0; i < nb; i++) {
        printf("Valeur %d: ", i + 1);
        scanf("%d", &elm);
        insertEnd(&head, elm);
    }
    printList(head);

    printf("Entrez la valeur a retire de la liste: ");
    scanf("%d", &del);

    deleteElementOccurrence(&head, del);
    printList(head);

    return 0;
}