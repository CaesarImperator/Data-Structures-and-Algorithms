#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct nodeQueue {

    int data;
    struct nodeQueue *next;

};

void displayQueue(struct nodeQueue *current) {

    if (current == NULL) {
        printf("Queue is empty\n");
    }

    else {
        while (current != NULL) {

            printf("%d --> ", current -> data);
            current = current->next;

        }

    printf("NULL\n\n");

    }

}

void enqueue (struct nodeQueue **front, struct nodeQueue **rear, int value) {

    struct nodeQueue *temp = NULL;

    temp = (struct nodeQueue *) malloc(sizeof(struct nodeQueue));
    temp->data = value;

    if (*front == NULL && *rear == NULL) {

        temp->next = *rear;
        *rear = temp;
        *front = temp;


    }

   else {

        temp->next = *rear;
        *rear = temp;

   }

}

int dequeue (struct nodeQueue **front, struct nodeQueue **rear) {

    struct nodeQueue *temp = NULL;

    if (*front == NULL && *rear == NULL) {

        printf("Queue is empty, you cannot dequeue\n");
        exit(1);

    }

    else if (*front == *rear) {

        temp = *front;
        *front = NULL;
        *rear = NULL;
        return temp->data;
        free(temp);

    }

    else {

        struct nodeQueue *current = *rear;

        while(current->next->next != NULL)
            current = current->next;

        temp = *front;
        *front = current;
        current->next = NULL;
        return temp->data;
        free(temp);

    }

}


struct node {

    int data;
    struct node *leftPtr;
    struct node *rightPtr;

};


void insertNode (struct node **Node, int value) {

    if (*Node == NULL) {

        *Node = (struct node *) malloc (sizeof(struct node));

        if (*Node != NULL) {

            (*Node)->data = value;
            (*Node)->leftPtr = NULL;
            (*Node)->rightPtr = NULL;


        }
        else {
            printf("Memory not allocated correctly\n");
            exit (-1);
        }

    }

    else {

        if (value < (*Node)->data) {
            insertNode(&((*Node)->leftPtr), value);
        }
        else if (value > (*Node)->data) {
            insertNode(&((*Node)->rightPtr), value);
        }
        else {
            printf("duplicate");
        }

    }


}

void inOrder (struct node *Node) {

    if (Node != NULL) {

        inOrder(Node->leftPtr);
        printf("%3d", Node->data);
        inOrder(Node->rightPtr);

    }

}

void preOrder (struct node *Node) {

    if (Node != NULL) {

        printf("%3d", Node->data);
        preOrder(Node->leftPtr);
        preOrder(Node->rightPtr);

    }

}

void postOrder (struct node *Node) {

    if (Node != NULL) {

        postOrder(Node->leftPtr);
        postOrder(Node->rightPtr);
        printf("%3d", Node->data);

    }

}

void levelOrder (struct node *Node, struct nodeQueue **front, struct nodeQueue **rear) {

    if (Node == NULL){

        printf("Tree is empty, nothing to do\n");
        return;

    }

    enqueue (struct nodeQueue **front, struct nodeQueue **rear, Node->data);

    while (*front != NULL && *rear != NULL)
        dequeue (struct nodeQueue **front, struct nodeQueue **rear);
        printf("%d--> ", Node->data);
        if(Node->leftPtr != NULL)
            enqueue(struct nodeQueue **front, struct nodeQueue **rear, Node->leftPtr->data);
        if(Node->rightPtr != NULL)
            enqueue(struct nodeQueue **front, struct nodeQueue **rear, Node->rightPtr->data);

}

int main() {

    struct nodeQueue *rear = NULL;
    struct nodeQueue *front = NULL;
    int value = 0;
    struct node *root = NULL;

    srand(time(NULL));
    printf("The numbers being placed in the tree are:\n");

    for (int i = 1; i <= 10; i++) {

        value = rand() % 15;
        printf("%3d", value);
        insertNode(&root, value);

    }

    printf("\n\nThe in-order traversal of the binary search tree is:\n");
    inOrder(root);

    printf("\n\nThe pre-order traversal of the binary search tree is:\n");
    preOrder(root);

    printf("\n\nThe post-order traversal of the binary search tree is:\n");
    postOrder(root);

    printf("\n\nThe level-order traversal of the binary search tree is:\n");
    levelOrder(root, &front, &rear);

    return 0;
}
