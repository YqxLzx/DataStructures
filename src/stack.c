#include <stdio.h>
#include <stdlib.h>
#include "../data.h"
typedef struct
{
    Data storages[100];
    int length;
} Stack;
Stack createStack()
{
    Stack stack;
    stack.length = 0;
    return stack;
}

int isFull(Stack *stack)
{
    if (stack->length == 99)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int isEmpty(Stack *stack)
{
    if (stack->length == 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
void push(Stack *stack, Data data)
{
    int is_full = isFull(stack);
    if (is_full)
    {
        printf("push error , this stack is full ");
    }
    else
    {
        stack->storages[stack->length] = data;
        stack->length++;
    }
}
Data pop(Stack *stack)
{
    int is_empty = isEmpty(stack);
    if (is_empty)
    {
        printf("pop error , this stack is empty ");
         return (Data){0}; 
    }
    else
    {
        Data topElement = stack->storages[stack->length - 1];
        stack->storages[stack->length] = (Data){0};
        stack->length--;
        return topElement;
    }
}
Data peek(Stack *stack)
{
    if (isEmpty(stack))
    {
        printf("peek error , this stack is empty ");
        return (Data){0};
    }
    Data topElement = stack->storages[stack->length - 1];
    return topElement;
}

int main()
{
    Data data1 = {
        1, 100};
    Data data2 = {
        2, 200};
    Data data3 = {
        3, 300};
    Stack stack = createStack();
    push(&stack, data1);
    push(&stack, data2);
    push(&stack, data3);
    printf("removed id:%d\n", peek(&stack).id);
    for (int i = 0; i < stack.length; i++)
    {
        printf("%d:%d\n", i, stack.storages[i].value);
    }
    return 0;
}