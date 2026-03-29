#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>
typedef struct stack
{
    int value;
    struct stack *next;
} stack;

void insertAtBegining(stack **Head, int value)
{
    stack *newNode = (stack *)(malloc(sizeof(stack)));
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
void deleteFromBegining(stack **Head)
{
    if (*Head == NULL)
    {
        return;
    }
    stack *current = *Head;
    *Head = (*Head)->next;
    free(current);
}
int length(stack *Head)
{
    int count = 0;
    while (Head != NULL)
    {
        count++;
        Head = Head->next;
    }
    return count;
}
bool isEmpty(stack *Head)
{
    return Head == NULL;
}
void push(stack **Head, int value)
{
    insertAtBegining(Head, value);
}
void pop(stack **Head)
{
    deleteFromBegining(Head);
}
int top(stack *Head)
{
    if (Head != NULL)
    {
        return Head->value;
    }
    else
        return '\0';
}
int presedence(char op)
{
    if (op == '*' || op == '/')
        return 2;
    if (op == '+' || op == '-')
        return 1;
    return 0;
}
int calculate(int num1, int num2, char op)
{
    switch (op)
    {
    case '+':
        return num1 + num2;
    case '-':
        return num1 - num2;
    case '*':
        return num1 * num2;
    case '/':
        return (num2 == 0) ? 0 : num1 / num2;
    default:
        return 0;
    }
}
bool isOp(char op)
{
    return (op == '+' || op == '-' || op == '*' || op == '/');
}
int evaluatePostfix(char *postfix)
{
    stack *s = NULL;
    char *token = strtok(postfix, " ");
    while (token != NULL)
    {
        if (isdigit(token[0]))
        {
            push(&s, atoi(token));
        }
        else if (isOp(token[0]))
        {
            char op = token[0];
            int num1, num2;
            int result;
            num1 = top(s);
            pop(&s);
            num2 = top(s);
            pop(&s);
            result = calculate(num2, num1, op);
            push(&s, result);
        }

        token = strtok(NULL, " ");
    }
    int endResult = top(s);
    pop(&s);
    return endResult;
}
void infixToPostfix(char *infix, char *postfix)
{
    int j = 0;
    stack *Head = NULL;
    for (int i = 0; infix[i] != '\0'; i++)
    {
        char current = infix[i];
        if (isalnum(current))
        {
            postfix[j] = current;
            j++;
        }
        else if (current == '(')
        {
            push(&Head, current);
        }
        else if (current == ')')
        {
            while (!isEmpty(Head) && (char)top(Head) != '(')
            {
                postfix[j] = (char)top(Head);
                j++;
                pop(&Head);
            }
            pop(&Head);
        }
        else
        {
            while (!isEmpty(Head) && presedence((char)top(Head)) >= presedence(current))
            {
                postfix[j] = (char)top(Head);
                j++;
                pop(&Head);
            }
            push(&Head, current);
        }
    }
    while (!isEmpty(Head))
    {
        postfix[j] = (char)top(Head);
        j++;
        pop(&Head);
    }
    postfix[j] = '\0';
}
void infixToPostfixMoreThan1Digit(char *infix, char *postfix)
{
    int j = 0;
    stack *s = NULL;
    for (int i = 0; infix[i] != '\0'; i++)
    {
        char current = infix[i];
        if (isdigit(current))
        {
            while (isdigit(infix[i]))
            {

                postfix[j] = infix[i];
                j++;
                i++;
            }
            i--;
            postfix[j] = ' ';
            j++;
        }
        else if (current == '(')
        {
            push(&s, current);
        }
        else if (current == ')')
        {

            while (!isEmpty(s) && top(s) != '(')
            {
                postfix[j] = top(s);
                j++;
                pop(&s);
                postfix[j] = ' ';
                j++;
            }
            pop(&s);
        }
        else
        {
            while (!isEmpty(s) && presedence(top(s)) >= presedence(current))
            {
                postfix[j] = top(s);
                j++;
                pop(&s);
                postfix[j] = ' ';
                j++;
            }
            push(&s, current);
        }
    }
    while (!isEmpty(s))
    {
        postfix[j] = top(s);
        j++;
        pop(&s);
        postfix[j] = ' ';
        j++;
    }
    postfix[j] = '\0';
}
int main()
{
    char infix[100];
    char postfix[100];

    printf("\n\nenter your mathematical expression: ");
    fgets(infix, sizeof(infix), stdin);
    infix[strcspn(infix, "\n")] = '\0';

    infixToPostfixMoreThan1Digit(infix, postfix);
    int result = evaluatePostfix(postfix);
    printf("\n\nResult : %d", result);

    return 0;
}
