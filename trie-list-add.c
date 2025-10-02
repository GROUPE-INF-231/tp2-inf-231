#include <stdio.h>
#include <stdlib.h>


typedef struct linkedlist {
	int data;
	struct linkedlist* next;
} list;

// Using Insertion sort
void sortingList(list** head) {
	list* sorted = NULL;
	list* current = *head;

	while (current != NULL) {
		list* nextNode = current->next;

		if (sorted == NULL || current->data < sorted->data) {
			current->next = sorted;
			sorted = current;
		}
		else {
			list* temp = sorted;

			while (temp->next != NULL && temp->next->data <= current->data) {
				temp = temp->next;
			}
			current->next = temp->next;
			temp->next = current;
		}

		current = nextNode;
	}

	*head = sorted;
}

void insertIntoList(list** head, int elm) {
	list* newNode = (list*)malloc(sizeof(list));
	if (newNode == NULL) {
		printf("Memory allocation failed!\n");
		exit(1);
	}

	newNode->data = elm;
	newNode->next = NULL;

	if (*head == NULL || elm < (*head)->data) {
		newNode->next = *head;
		*head = newNode;
		return;
	}

	list* current = *head;
	while (current->next != NULL && current->next->data < elm) {
		current = current->next;
	}

	newNode->next = current->next;
	current->next = newNode;
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

void freeList(list** head) {
	list* current = *head;
	list* nextNode;

	while (current != NULL) {
		nextNode = current->next;
		free(current);
		current = nextNode;
	}
}

int main() {
	list* head = NULL;
	int i, nb, elm, ins;

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

	sortingList(&head);
	printf("Liste triee en ordre croissant:\n");
	printList(head);

	printf("Entrez la valeur a ajoute de la liste: ");
	scanf("%d", &ins);

	insertIntoList(&head, ins);
	printList(head);

	freeList(&head);
	return 0;
}


