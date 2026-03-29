#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int value;
    struct Node *next;
} Node;

void insertAtEnd(Node **Head, int value)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
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

int getLength(Node *head)
{
    int length = 0;
    Node *current = head;
    while (current != NULL)
    {
        length++;
        current = current->next;
    }
    return length;
}

void connectLists(Node *head1, Node *head2)
{
    if (head1 == NULL)
        return;

    Node *current = head1;
    while (current->next != NULL)
    {
        current = current->next;
    }
    current->next = head2;
}

Node *findIntersection(Node *headA, Node *headB)
{
    int lenA = getLength(headA);
    int lenB = getLength(headB);
    int diff;

    Node *ptrA = headA;
    Node *ptrB = headB;

    if (lenA > lenB)
    {
        diff = lenA - lenB;
        for (int i = 0; i < diff; i++)
        {
            ptrA = ptrA->next;
        }
    }
    else
    {
        diff = lenB - lenA;
        for (int i = 0; i < diff; i++)
        {
            ptrB = ptrB->next;
        }
    }

    while (ptrA != NULL && ptrB != NULL)
    {
        if (ptrA == ptrB)
        {
            return ptrA;
        }
        ptrA = ptrA->next;
        ptrB = ptrB->next;
    }

    return NULL;
}
Node *findIntersection2(Node *HeadA, Node *HeadB)
{
    Node *ptrA = HeadA;
    Node *ptrB = HeadB;

    while (ptrA != ptrB)
    {
        ptrA = (ptrA == NULL) ? HeadB : ptrA->next;
        ptrB = (ptrB == NULL) ? HeadA : ptrB->next;
    }
    return ptrA;
}
void printList(Node *head)
{
    while (head != NULL)
    {
        printf("%d -> ", head->value);
        head = head->next;
    }
    printf("NULL\n");
}
int main()
{
    Node *listA = NULL;
    Node *listB = NULL;
    Node *listC = NULL;

    insertAtEnd(&listA, 10);
    insertAtEnd(&listA, 20);

    insertAtEnd(&listB, 1);
    insertAtEnd(&listB, 2);
    insertAtEnd(&listB, 3);

    insertAtEnd(&listC, 100);
    insertAtEnd(&listC, 200);
    insertAtEnd(&listC, 300);

    connectLists(listA, listC);
    connectLists(listB, listC);

    printf("List A: ");
    printList(listA);
    printf("List B: ");
    printList(listB);

    Node *intersectionNode = findIntersection2(listA, listB);

    if (intersectionNode != NULL)
    {
        printf("\nIntersection found at Node with value: %d\n", intersectionNode->value);
    }
    else
    {
        printf("\nNo intersection found.\n");
    }

    return 0;
}