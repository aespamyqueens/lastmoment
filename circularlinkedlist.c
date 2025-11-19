#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
} *last = NULL;

void insertEnd(int x) {
    struct Node* n = malloc(sizeof(struct Node));
    n->data = x;

    if (last == NULL) {
        last = n;
        n->next = n;
    } else {
        n->next = last->next;
        last->next = n;
        last = n;
    }
}

void deleteNode(int key) {
    if (last == NULL) return;

    struct Node *curr = last->next, *prev = last;

    do {
        if (curr->data == key) {
            if (curr == last && curr->next == last)
                last = NULL;
            else {
                prev->next = curr->next;
                if (curr == last)
                    last = prev;
            }
            free(curr);
            return;
        }
        prev = curr;
        curr = curr->next;
    } while (curr != last->next);
}

int main() {
    insertEnd(10);
    insertEnd(20);
    insertEnd(30);
    deleteNode(20);
}
