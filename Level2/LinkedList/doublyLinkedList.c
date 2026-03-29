#include <stdio.h>
#include <stdlib.h>
typedef struct Node
{
    struct Node *next;
    struct Node *previus;
    int value;
} Node;

void insertAtBegining(Node **Head, int value)
{
    Node *newNode = (Node *)(malloc(sizeof(Node)));
    newNode->previus = NULL;
    newNode->value = value;
    if (*Head == NULL)
    {
        newNode->next = NULL;
        *Head = newNode;
        return;
    }
    (*Head)->previus = newNode;
    newNode->next = *Head;
    *Head = newNode;
}
Node *findNode(Node *Head, int value)
{
    while (Head != NULL)
    {
        if (Head->value == value)
            return Head;
        Head = Head->next;
    }
    return NULL;
}
void deleteByValue(Node **Head, int targetValue)
{
    if (*Head == NULL || findNode(*Head, targetValue) == NULL)
        return;

    if ((*Head)->next == NULL)
    {
        free(*Head);
        *Head = NULL;
        return;
    }
    Node *current = *Head;
    while (current != NULL)
    {
        if (current->value == targetValue)
            break;
        current = current->next;
    }
    if (current->next != NULL)
    {
        current->next->previus = current->previus;
    }
    if (current == *Head)
    {
        *Head = current->next;
    }
    else
    {
        current->previus->next = current->next;
    }
    free(current);
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
    Node *Head = NULL;
    insertAtBegining(&Head, 5);
    insertAtBegining(&Head, 4);
    insertAtBegining(&Head, 8);
    printf("\nList : ");
    printList(Head);
    deleteByValue(&Head, 8);
    printf("\nList : ");
    printList(Head);
    return 0;
}