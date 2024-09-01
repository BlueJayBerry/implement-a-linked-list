#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node{
    char value;
    struct node *next;
};
typedef struct node node_t;

node_t *createNewNode(int value){
    node_t *new_node = malloc(sizeof(node_t));
    new_node->value = value;
    new_node->next = NULL;
    return new_node;
}

void insertNodeAtHead(node_t **head, node_t *node_to_insert){
    node_to_insert->next = *head;
    *head = node_to_insert;
}

void push(node_t *head, char value){
    node_t *tmp = createNewNode(value);
    insertNodeAtHead(&head, tmp);
}



void printList(node_t *head){
    node_t *temporary = head;
    
    while(temporary != NULL){
        printf("%d -", temporary->value);
        temporary = temporary->next;
    }
    printf("\n");
}

int main(int argc, char *argv[]){
    node_t *head = NULL;

    push(head, 'a');

    printList(head);
    return 0;   
}