#include <stdio.h>
#include <stdlib.h>
typedef struct Node
{
    int value;
    struct Node *next;
} Node;

void insertAtBegining(Node **Head, int value)
{
    Node *newNode = (Node *)(malloc(sizeof(Node)));
    newNode->value = value;
    if (*Head == NULL)
    {
        *Head = newNode;
        (*Head)->next = NULL;
        return;
    }
    newNode->next = *Head;
    *Head = newNode;
}
void deleteFromBegining(Node **Head)
{
    if (*Head == NULL)
    {
        return;
    }
    Node *current = *Head;
    *Head = (*Head)->next;
    free(current);
}
void deleteFromEnd(Node **Head)
{
    if (*Head == NULL)
    {
        return;
    }
    if ((*Head)->next == NULL)
    {
        free(*Head);
        *Head = NULL;
        return;
    }
    Node *current = *Head;
    while (current->next->next != NULL)
    {
        current = current->next;
    }
    free(current->next);
    current->next = NULL;
}
void insertAtEnd(Node **Head, int value)
{
    Node *newNode = (Node *)(malloc(sizeof(Node)));
    newNode->value = value;
    newNode->next = NULL;
    if (*Head == NULL)
    {
        *Head = newNode;
        return;
    }
    Node *current = *Head;
    while (current->next != NULL)
    {
        current = current->next;
    }
    current->next = newNode;
}
void printList(Node *Head)
{
    while (Head != NULL)
    {
        printf("%d ", Head->value);
        Head = Head->next;
    }
}

int main()
{

    Node *Head1 = NULL;
    Node *Head2 = NULL;
    Node *Head3 = NULL;
    insertAtEnd(&Head1, 1);
    insertAtEnd(&Head1, 2);
    insertAtEnd(&Head1, 3);
    insertAtEnd(&Head1, 4);

    insertAtEnd(&Head2, 7);
    insertAtEnd(&Head2, 8);

    insertAtEnd(&Head3, 4);
    insertAtEnd(&Head3, 3);
    insertAtEnd(&Head3, 2);

    printf("List  : ");
    printList(Head1);

    return 0;
}