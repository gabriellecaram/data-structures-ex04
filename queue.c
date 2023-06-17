#include <stdlib.h>
#include "queue.h"

void initialize(queue *q) {
    // implementar
    q->first = q->last = NULL; //fila vazia
}

void destroy(queue *q) {
    while(!empty(q))
        pop(q);
}

void* front(queue *q) {
    if(!empty(q))
        return q->first->data;
    return 0;
}

void push(queue *q, void* data) {
    // implementar/
    qnode* new_node = (qnode*)malloc(sizeof(qnode));
    new_node->data = data;
    new_node->next = NULL;

    if (empty(q)) {
        q->first = q->last = new_node;
    } else {
        q->last->next = new_node;
        q->last = new_node;
    }
}

void pop(queue *q) {
    // implementar
    if (!empty(q)) {
        qnode* temp = q->first;
        q->first = q->first->next;
        free(temp);
    }
}

int empty(queue *q) {
    return q->first == 0;
}