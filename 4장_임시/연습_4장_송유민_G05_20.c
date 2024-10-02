#include <stdio.h>
#include <stdlib.h>

typedef struct _node {
    int data;
    struct _node* next;
} node;

node* head, * tail;

void init_list(void) {
    head = (node*)malloc(sizeof(node));
    tail = (node*)malloc(sizeof(node));
    head->next = tail;
    tail->next = tail;
}
//(가)
node* ordered_insert(int k) {
    node* new_node = (node*)malloc(sizeof(node));
    new_node->data = k;
    new_node->next = NULL;

    if (head->next == tail || head->next->data >= k) {
        new_node->next = head->next;
        head->next = new_node;
    }
    else {
        node* current = head;
        while (current->next != tail && current->next->data < k) {
            current = current->next;
        }
        new_node->next = current->next;
        current->next = new_node;
    }
    return new_node;
}
//(나)
void print_list(node* t) {
    printf("List: ");
    while (t != tail) {
        printf("%d ", t->data);
        t = t->next;
    }
    printf("\n");
}
//(다)
int delete_node(int k) {
    node* current = head;
    node* previous = NULL;
    while (current->next != tail && current->next->data != k) {
        previous = current;
        current = current->next;
    }
    if (current->next == tail) {
        return -1;
    }
    else {
        node* temp = current->next;
        current->next = temp->next;
        free(temp);
        return 0;
    }
}

int _tmain(int argc, char* argv[]) {
    init_list();
    ordered_insert(10);
    ordered_insert(5);
    ordered_insert(8);
    ordered_insert(3);
    ordered_insert(1);
    ordered_insert(7);

    printf("\nInitial Linked list is ");
    print_list(head->next);

    delete_node(8);
    print_list(head->next);

    return 0;
}
