#include <stdio.h>
#include <stdlib.h>

// initialize struct node 
struct node {
    int data;
    struct node * next;
};
typedef struct node Node;
Node * head;

Node * newNode (int data) {
    Node * p_node = malloc(sizeof(Node));
    if (p_node != NULL) {
        p_node->data = data;
        p_node->next = NULL;
    }
    return p_node;
}

Node * addFront(Node * head, int data) {
    Node * pNode = newNode(data);
    if (pNode == NULL) return head;
    pNode->next = head;
    return pNode;
}

Node * addBack(Node * head, int data) {
    Node * p_node = newNode(data);
    Node * curr = NULL;
    if (p_node == NULL) return head;
    // empty list
    if (head == NULL) {
        // assign node as head
        head = p_node;
        return head;
    } else {
        /* find last element */
        for (curr = head; curr->next != NULL; curr = curr->next) 
            ;
        curr->next = p_node;
        return head;
    }
}

void display (Node * head) {
    Node * curr = head;
    while (curr->next != NULL) {
        printf("%d -> ", curr->data);
        curr = curr->next;
    }
    // when curr->next is NULL, that's the last node 
    printf("%d\n", curr->data);
}

Node * find(Node * head, int data) {
    struct node * curr = NULL; 
    for (curr = head; curr->next != NULL; curr = curr->next) {
        if (curr->data == data) return curr;
    }
    return NULL;
}

Node * delNode(Node * head, Node * node) {
    struct node *p = NULL;
    struct node *q = NULL;
    for (p = head; p != NULL && p != node; p = p->next) {
        q = p;
    }
    if (p == NULL) return head;
    if (q == NULL) {
        head = head->next;
        free(p);
    } else {
        q->next = p->next;
        free(p);
    }
    return head;
}

void freelist(Node * head) {
    struct node * pNode = NULL;
    while (head) {
        pNode = head;
        head = head->next;
        free(pNode);
    }
}

// function regarding struct node 
Node * newNode (int data);
// from lecture to add to the front of the list
Node * addFront(Node * head, int data);
// 5_b implement to add to the back of the list
Node * addBack(Node * head, int data);
// 5_c implement to find a node which contains data
Node * find(Node * head, int data);
// 5_d implement to delete a node from the list 
Node * delNode(Node * head, Node * node);
// 5_f implement to delete all elements
void freelist(Node * head);

// function from assignment 5
// function to display all elements in the list
void display (Node * head);

int main () {
    // create head
    head = newNode(1);
    // add a node to the front
    head = addFront(head, 0);
    // add a node to the back
    head = addBack(head, 2);
    // display linked list
    display(head);
    // find node with 1 as data
    Node * testFind_1 = find(head, 1);
    // node with 1 with data exist so should print data
    if (testFind_1) {
        printf("%d found\n", testFind_1->data);
    } else {
        printf("1 not found\n");
    }
    Node * testFind_2 = find(head, 3);
    if (testFind_2) {
        printf("%d\n", testFind_2->data);
    } else {
        printf("2 not found\n");
    }

    // obtain a node to delete using find 
    // find node with data = 2
    Node * del_1 = find(head, 2);
    // then delete it
    head = delNode(head, del_1);
    // now display again
    display(head);
    // delete head which is node with 0 as data
    Node * del_2 = find(head, 0);
    head = delNode(head, del_2);
    // display again
    display(head);

    // add new node again
    // add a node to the front
    head = addFront(head, 0);
    // add a node to the back
    head = addBack(head, 2);
    // display the list
    display(head);

    // then delete the whole list
    freelist(head);

    display(head);

    return 0;
}



