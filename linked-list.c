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

int main(int argc, char* argv[]){
    node_t *head, *tail;
    node_t n1,n2,n3,n4;
    n1.value = 22;
    n2.value = 7;
    n3.value = 28;
    n4.value = 15;

    head = &n2;
    n2.next = &n1;
    n1.next = &n4;
    n3.next = NULL;
    n4.next = &n3;
    printList(head);

    return 0;
}