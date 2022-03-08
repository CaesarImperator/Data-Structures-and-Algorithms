#include <stdio.h>
#include <stdlib.h>
#include <time.h>


struct node {

    int data;
    struct node *leftPtr;
    struct node *rightPtr;

};

void insertNode(struct node **Node, int value) {

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

struct node *deleteNode(struct node *Node, int value) {

    struct node *child = NULL;
    struct node *successor = NULL;

    if(Node == NULL) {
        printf("There is no such value in the tree\n");
        return Node;
    }

    //finding the node to be deleted
    if(value < Node->data)
        Node->leftPtr = deleteNode(Node->leftPtr, value);

    else if (value > Node->data)
        Node->rightPtr = deleteNode(Node->rightPtr, value);


    // node to be deleted has two children
    else {
        if (Node->leftPtr != NULL && Node->rightPtr != NULL) {

            successor = Node->rightPtr;

            while(successor->leftPtr != NULL)
                successor = successor->leftPtr;

            Node->data = successor->data;
            Node->rightPtr = deleteNode(Node->rightPtr, successor->data);

        }


    // node to be deleted has one child or none
        else {

            if(Node->leftPtr != NULL)
                child = Node->leftPtr;

            else
                child = Node->rightPtr;

            free(Node);
            return child;

            }
        }

        return Node;

        }

struct node *search(struct node *Node, int value) {


    while(Node != NULL) {
        if(value < Node->data)
            Node = Node->leftPtr;
        else if(value > Node->data)
            Node = Node->rightPtr;
        else
            return Node;
    }

    return NULL;

};

struct node *min(struct node *Node) {

    if (Node == NULL)
        return NULL;

    while(Node->leftPtr != NULL)
        Node = Node->leftPtr;

    return Node;
};

struct node *max(struct node *Node) {

    if (Node == NULL)
        return NULL;

    while(Node->rightPtr != NULL)
        Node = Node->rightPtr;

    return Node;
};

void inOrder(struct node *Node) {

    if (Node != NULL) {

        inOrder(Node->leftPtr);
        printf("%3d", Node->data);
        inOrder(Node->rightPtr);

    }

}

void preOrder(struct node *Node) {

    if (Node != NULL) {

        printf("%3d", Node->data);
        preOrder(Node->leftPtr);
        preOrder(Node->rightPtr);

    }

}

void postOrder(struct node *Node) {

    if (Node != NULL) {

        postOrder(Node->leftPtr);
        postOrder(Node->rightPtr);
        printf("%3d", Node->data);

    }

}

int height(struct node *Node) {

    int hL = 0;
    int hR = 0;

    if(Node == NULL)
        return 0;

    hL = height(Node->leftPtr);
    hR = height(Node->rightPtr);

    if(hL > hR)
        return 1 + hL;
    else
        return 1 + hR;

}

int main() {

    int value = 0;
    struct node *root = NULL;
    struct node *searchedForNode = NULL;
    struct node *deletedNode = NULL;
    //int searchedForValue = 0;

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

    printf("\n\nThe height of the binary search tree is %d\n\n", height(root));

    if(min(root) != NULL)
        printf("The minimum value in the tree is %d\n\n", min(root)->data);
    else
        printf("Tree is empty\n");

    if(min(root) != NULL)
        printf("The maximum value in the tree is %d\n\n", max(root)->data);
    else
        printf("Tree is empty\n");


    printf("Enter a value to delete\n");
    scanf("%d", &value);

    root = deleteNode(root, value);

    printf("\n\nThe in-order traversal of the binary search tree is now:\n");
    inOrder(root);


    /*printf("Enter a value to search for:\n");
    scanf("%d", &searchedForValue);

    searchedForNode = search(root, searchedForValue);
    if(searchedForNode != NULL)
        printf("Key found!\n");
    else
        printf("Key not found!\n");*/

    return 0;
}
