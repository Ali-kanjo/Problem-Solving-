#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
typedef struct Node
{
    int value;
    struct Node *next;
} Node;

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

void enQeueu(Node **Head, char ch)
{
    insertAtEnd(Head, ch);
}
int deQueue(Node **Head)
{
    int value;
    if (*Head != NULL)
    {
        value = (*Head)->value;
        deleteFromBegining(Head);
        return value;
    }
    return '\0';
}

void printList(Node *Head)
{
    while (Head != NULL)
    {
        printf("%c ", Head->value);
        Head = Head->next;
    }
}
void prepareAdjancencyList(Node **nodes)
{
    insertAtEnd(&nodes['a' - 'a'], 'a');
    insertAtEnd(&nodes['a' - 'a'], 'b');
    insertAtEnd(&nodes['a' - 'a'], 'c');

    insertAtEnd(&nodes['b' - 'a'], 'b');
    insertAtEnd(&nodes['b' - 'a'], 'f');

    insertAtEnd(&nodes['c' - 'a'], 'c');
    insertAtEnd(&nodes['c' - 'a'], 'e');
    insertAtEnd(&nodes['c' - 'a'], 'f');

    insertAtEnd(&nodes['f' - 'a'], 'f');
    insertAtEnd(&nodes['f' - 'a'], 'g');
    insertAtEnd(&nodes['f' - 'a'], 'h');

    insertAtEnd(&nodes['e' - 'a'], 'e');
    insertAtEnd(&nodes['e' - 'a'], 'd');
    insertAtEnd(&nodes['e' - 'a'], 'i');
    insertAtEnd(&nodes['e' - 'a'], 'h');

    insertAtEnd(&nodes['h' - 'a'], 'h');
    insertAtEnd(&nodes['h' - 'a'], 'e');
    insertAtEnd(&nodes['h' - 'a'], 'i');

    insertAtEnd(&nodes['g' - 'a'], 'g');
    insertAtEnd(&nodes['g' - 'a'], 'b');

    insertAtEnd(&nodes['d' - 'a'], 'd');
    insertAtEnd(&nodes['d' - 'a'], 'c');

    insertAtEnd(&nodes['i' - 'a'], 'i');
    insertAtEnd(&nodes['i' - 'a'], 'h');
}

void BFS(Node **nodes, char startNode, Node **Head)
{
    bool IsvisitedNodes[26] = {false};
    Node *Queue = NULL;
    enQeueu(&Queue, startNode);
    IsvisitedNodes[startNode - 'a'] = true;
    insertAtEnd(Head, startNode);

    while (Queue != NULL)
    {
        int value = deQueue(&Queue);
        Node *CurrentNode = nodes[value - 'a'];
        while (CurrentNode != NULL)
        {
            int neghiberValue = CurrentNode->value;
            if (!IsvisitedNodes[neghiberValue - 'a'])
            {
                enQeueu(&Queue, neghiberValue);
                insertAtEnd(Head, neghiberValue);
                IsvisitedNodes[neghiberValue - 'a'] = true;
            }
            CurrentNode = CurrentNode->next;
        }
    }
}

int main()
{
    Node *nodes[26] = {NULL};
    Node *Head = NULL;
    prepareAdjancencyList(nodes);
    BFS(nodes, nodes[0]->value, &Head);
    printList(Head);
}