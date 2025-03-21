#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *head = NULL;

void create() {
    struct node *tmpcell, *ptr;
    int ele;

    tmpcell = (struct node*)malloc(sizeof(struct node));
    if (tmpcell == NULL) {
        printf("Memory is not allocated\n");
        exit(0);
    }
    
    printf("Enter element: ");
    scanf("%d", &ele);
    
    tmpcell->data = ele;
    tmpcell->next = NULL;
    
    if (head == NULL) {
        head = tmpcell;
    } else {
        ptr = head;
        while (ptr->next != NULL) {
            ptr = ptr->next;
        }
        ptr->next = tmpcell;
    }
}

void display() {
    struct node *ptr = head;
    while (ptr != NULL) {
        printf("%d -> ", ptr->data);
        ptr = ptr->next;
    }
    printf("NULL\n");
}

int main() {
    int n, i;
    printf("Enter the number of nodes: ");
    scanf("%d", &n);
    
    for (i = 0; i < n; i++) {
        create();
    }
    
    printf("Linked List: ");
    display();
    
    return 0;
}






