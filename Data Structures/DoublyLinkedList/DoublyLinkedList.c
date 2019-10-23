#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
};

struct Node *create_ll(int data)
{
    struct Node *head = malloc(sizeof(struct Node));
    head->data = data;
    head->next = NULL;
    head->prev = NULL;
}

void insertNode_beg(struct Node *head, int data)
{
    struct Node *n = malloc(sizeof(struct Node));
    n->data = head->data;
    n->next = head->next;
    n->prev = head;
    head->data = data;
    head->next = n;
}

void insertNode_bet(struct Node *head, int e, int data)
{
    struct Node *ptr = head, *n = malloc(sizeof(struct Node));
    if (ptr != NULL && ptr->data == e)
    {
        insertNode_beg(head, data);
        return;
    }
    while (ptr != NULL && ptr->data != e)
    {
        ptr = ptr->next;
    }
    if (ptr == NULL)
    {
        printf("Element not found");
        return;
    }
    n->data = data;
    n->next = ptr;
    n->prev = ptr->prev;
    (ptr->prev)->next = n;
    ptr->prev = n;
}

void insertNode_end(struct Node *head, int data)
{
    struct Node *n = malloc(sizeof(struct Node));
    struct Node *ptr = head;
    while (ptr->next != NULL)
    {
        ptr = ptr->next;
    }
    ptr->next = n;
    n->prev = ptr;
    n->data = data;
    n->next = NULL;
}

void deleteNode(struct Node *head, int e)
{
    struct Node *ptr = head;
    if (ptr != NULL && ptr->data == e)
    {
        ptr = ptr->next;
        head->next = ptr->next;
        head->data = ptr->data;
        free(ptr);
        printf("Element deleted.\n");
        return;
    }
    while (ptr != NULL && ptr->data != e)
    {
        ptr = ptr->next;
    }
    if (ptr == NULL)
    {
        printf("Element not found");
        return;
    }
    (ptr->prev)->next = ptr->next;
    (ptr->next)->prev = ptr->prev;
    free(ptr);
    printf("Element deleted.\n");
}

void printList(struct Node *head)
{
    struct Node *ptr = head;
    printf("Elements entered are: \n");
    while (ptr != NULL)
    {
        printf("%d\t", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}

int main()
{
    int n = 0, i = 0;
    printf("Enter element to create list: ");
    scanf("%d", &n);
    struct Node *head = create_ll(n);
    printf("Press 1 to enter element at the beginning.\nPress 2 to enter element before given element in the list.\nPress 3 to enter element at the end.\nPress 4 to delete element.\nPress 5 to print List\n");
    do
    {
        int j = 0;
        scanf("%d", &j);
        switch (j)
        {
        case 1:
            printf("Enter element to be inserted at the beginning: ");
            scanf("%d", &n);
            insertNode_beg(head, n);
            break;
        case 2:
            printf("Enter element in the list: ");
            int e = 0;
            scanf("%d", &e);
            printf("Enter element to be inserted: ");
            scanf("%d", &n);
            insertNode_bet(head, e, n);
            break;
        case 3:
            printf("Enter element to be inserted at the end: ");
            scanf("%d", &n);
            insertNode_end(head, n);
            break;
        case 4:
            printf("Enter element to be deleted: ");
            scanf("%d", &n);
            deleteNode(head, n);
            break;
        case 5:
            printList(head);
            break;
        default:
            printf("Invalid input\n");
        }
        printf("Press 1 to continue\n");
        scanf("%d", &i);
    } while (i == 1);
    return 0;
}