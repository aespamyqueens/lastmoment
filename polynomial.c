#include <stdio.h>
#include <stdlib.h>

struct Poly {
    int coeff, pow;
    struct Poly* next;
};

struct Poly* insert(struct Poly* head, int c, int p) {
    struct Poly* n = malloc(sizeof(struct Poly));
    n->coeff = c; n->pow = p; n->next = NULL;

    if (!head) return n;

    struct Poly* temp = head;
    while (temp->next) temp = temp->next;
    temp->next = n;
    return head;
}

void display(struct Poly* head) {
    while (head) {
        printf("%dx^%d ", head->coeff, head->pow);
        head = head->next;
    }
}

int main() {
    struct Poly* p = NULL;
    p = insert(p, 3, 2);
    p = insert(p, 4, 1);
    p = insert(p, 5, 0);
    display(p);
}
