#include <stdio.h>
#include <stdlib.h>
#include "../data.h"

typedef struct Node
{
    Data data;
    struct Node *next;
} Node;

typedef struct
{
    Node *head;
    Node *last;
    int length;
} LinkedList;

LinkedList createLinkedList()
{
    LinkedList list;
    list.length = 0;
    list.head = NULL;
    list.last = NULL;
    return list;
}

int isEmpty(LinkedList *list)
{
    return list->length == 0 ? 1 : 0;
}

Node *findNode(LinkedList *list, unsigned int index)
{
    Node *currentNode = list->head;
    for (int i = 0; i < index; i++)
    {
        if (currentNode == NULL)
        {
            return NULL;
        }
        currentNode = currentNode->next;
    }
    return currentNode;
}

void insert(LinkedList *list, Data data, unsigned int index)
{
    Node *currentNode = findNode(list, index - 1);
    if (currentNode == NULL)
    {
        return;
    }
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = currentNode->next;
    currentNode->next = newNode;
    if(list->length == index){
        list->last = currentNode;
    }
    list->length++;
}

void delete(LinkedList *list, int index)
{
    if (index < 0 || index >= list->length)
    {
        return;
    }
    Node *currentNode = NULL;
    Node *preNode = NULL;

    if (index == 0)
    {
        currentNode = list->head;
        list->head = currentNode->next;
    }
    else
    {
        preNode = findNode(list, index - 1);
        currentNode = preNode->next;
        preNode->next = currentNode->next;
    }
    if (currentNode == list->last)
    {
        list->last = preNode;
    }
    free(currentNode);
    list->length--;
}

void traverse(LinkedList *list)
{
    Node *currentNode = list->head;
    for (int i = 0; i < list->length; i++)
    {
        printf("node:%d;value:%d\n", i, currentNode->data.value);
        currentNode = currentNode->next;
    }
}

void push(LinkedList *list, Data data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    if (isEmpty(list))
    {
        list->head = newNode;
    }
    else
    {
        list->last->next = newNode;
    }
    list->last = newNode;
    list->length++;
}

int main()
{
    LinkedList l = createLinkedList();
    Data d1 = {0, 1};
    Data d2 = {1, 20};
    Data d3 = {2, 30};
    push(&l, d1);
    push(&l, d2);
    delete(&l,0);
    insert(&l, d3, 2);
    delete(&l,1);
    traverse(&l);
    return 0;
}
