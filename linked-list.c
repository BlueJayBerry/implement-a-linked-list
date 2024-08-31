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

int main(int argc, char* argv[]){
    node_t *head = NULL;
    node_t *tmp;

    for(int i = 0; i < 11; i++){
        tmp = createNewNode(i*2);
        tmp->next = head;
        head = tmp;
    }

    head = tmp->next;
   
    printList(head);
    return 0;
}