#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>
int rear = 0;
int front = -1;
const int length = 3;
int arr[3] = {INT32_MIN};
int empty = INT32_MIN;

void prepareArr(int *arr, int length)
{
    for (int i = 0; i < length; i++)
    {
        arr[i] = INT32_MIN;
    }
}
bool enqueue(int num)
{
    bool result = false;

    if (rear < length && rear != -1)
    {
        if (front == -1)
        {
            front = 0;
        }

        arr[rear] = num;
        rear++;
        result = true;
    }

    if (rear >= length)
    {
        rear = 0;
    }

    if (rear == front)
    {
        rear = -1;
    }

    return result;
}
// return value if not found return INT_MAX
int dequeue()
{
    bool result = false;
    int num = empty;

    if (front != -1)
    {
        if (rear == -1)
            rear = front;

        num = arr[front];
        arr[front] = empty;
        front++;
        result = true;
    }

    if (front >= length)
    {
        front = 0;
    }

    if (front != -1)
        if (arr[front] == empty)
        {
            front = -1;
        }

    return num;
}

void printArr(int *arr, int length)
{
    for (int i = 0; i < length; i++)
    {
        if (i != 0)
            printf("--");

        if (arr[i] == empty)
            printf("Empty ");
        else
            printf("%d ", arr[i]);
    }
    printf("\n");
}
int main()
{
    prepareArr(arr, length);
    printArr(arr, length);
    enqueue(3);
    printArr(arr, length);
    enqueue(5);
    printArr(arr, length);
    enqueue(4);
    printArr(arr, length);
    dequeue();
    printArr(arr, length);
    dequeue();
    printArr(arr, length);
    dequeue();
    printArr(arr, length);

    return 0;
}