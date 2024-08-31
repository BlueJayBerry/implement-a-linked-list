#include <stdio.h>
#include <stdlib.h>

struct node{
    int value;
    struct node* next;
};
typedef struct node node_t;

void printList(node_t *head){
    node_t *temporary = head;
    
    while(temporary != NULL){
        printf("%d -", temporary->value);
        temporary = temporary->next;
    }
    printf("\n");
}

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

void insertNodeAfter(node_t *node_to_insert_after, node_t* new_node){
    new_node->next = node_to_insert_after->next;
    node_to_insert_after->next = new_node;
}

node_t *findNode(node_t *head, int value){
    node_t *temporary = head;
    while(temporary != NULL){
        if(temporary->value == value) return temporary;
        temporary = temporary->next;
    }
    return NULL;
}

node_t *findLastNode(node_t *head){
    node_t *temporary = head;
    while(temporary->next != NULL){
        temporary = temporary->next;
    }
    return temporary;
}

void insertAtTail(node_t *tail_node, node_t *node_to_insert){
    node_to_insert->next = tail_node->next;
    tail_node->next = node_to_insert;
}

int main(int argc, char* argv[]){
    node_t *head = NULL;
    node_t *tmp;

    for(int i = 0; i < 11; i++){
        tmp = createNewNode(i);
        insertNodeAtHead(&head,tmp);
    }
     
    tmp = findLastNode(head);
    insertAtTail(tmp,createNewNode(23));

    printList(head);
    return 0;
}