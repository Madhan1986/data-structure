#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void append(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        newNode->next = *head; // Making it circular
        return;
    }
    struct Node* temp = *head;
    while (temp->next != *head && temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->next = *head; // Connecting last node to head
}

void makeCircular(struct Node** head) {
    if (*head == NULL) return;
    struct Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = *head; // Connect last node to head
}

void printCircularList(struct Node* head) {
    if (head == NULL) return;
    struct Node* temp = head;
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("(Back to head)\n");
}

int main() {
    struct Node* head = NULL;
    append(&head, 10);
    append(&head, 20);
    append(&head, 30);
    append(&head, 40);
    
    makeCircular(&head);
    
    printf("Circular Linked List: \n");
    printCircularList(head);
    
    return 0;
}