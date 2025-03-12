//16. Write a linked list to store strings of variable length 
//(do not use fixed lenghth length arrays for strings)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct Node {
    char *data;        
    struct Node *next; 
};
struct Node* createNode(const char *str) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newNode->data = (char *)malloc(strlen(str) + 1); 
    if (newNode->data == NULL) {
        printf("Memory allocation failed for string!\n");
        free(newNode);  
        exit(1);
    }
    strcpy(newNode->data, str);
    newNode->next = NULL; 
    return newNode;
}
void printList(struct Node *head) {
    struct Node *current = head;
    while (current != NULL) {
        printf("%s\n", current->data);
        current = current->next;
    }
}
void freeList(struct Node *head) {
    struct Node *current = head;
    struct Node *nextNode;
    while (current != NULL) {
        nextNode = current->next;
        free(current->data);  
        free(current);         
        current = nextNode;
    }
}
int main() {
    struct Node *head = NULL, *tail = NULL;
    char buffer[100]; 
    int n;
    printf("Enter the number of strings: ");
    scanf("%d", &n);
    getchar(); 
    for (int i = 0; i < n; i++) {
        printf("Enter string %d: ", i + 1);
        fgets(buffer, sizeof(buffer), stdin);
        buffer[strcspn(buffer, "\n")] = '\0';  
        struct Node *newNode = createNode(buffer);
        if (head == NULL) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }
    printf("\nThe linked list of strings:\n");
    printList(head);
    freeList(head);
    return 0;
}