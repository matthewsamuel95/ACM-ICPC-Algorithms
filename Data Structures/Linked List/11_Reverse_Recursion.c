// Write a function to reverse a given linked list Recusrively.

#include <stdio.h>
#include <stdlib.h>
#include "Linked_List.c"

// Reverse_Recursion Implementation
void Reverse_Recursion(NODE *p) {
  if(p->next == NULL) {
    head = p;
    return;
  }
  Reverse_Recursion(p->next);
  NODE *temp = p->next;
  temp->next = p;
  p->next = NULL;
}

void main() {
  int a;
  while(a!=0) {
    printf("\n\n");
    printf("Enter 1 -> Insert_front\n");
    printf("Enter 2 -> Delete_front\n");
    printf("Enter 3 -> Insert_end\n");
    printf("Enter 4 -> Delete_end\n");
    printf("Enter 5 -> Display_LL\n");
    printf("Enter 6 -> Reverse()\n");
    printf("Enter 0 -> Exit\n");
    scanf("%d", &a);
    if(a==0) {
      printf("-------------------------Thank You----------------------------\n");
      return;
    }
    switch(a) {
      case 1 :
      {
        Insert_front();
        Display_LL();
        break;
      }
      case 2 :
      {
        Delete_front();
        Display_LL();
        break;
      }
      case 3 :
      {
        Insert_end();
        Display_LL();
        break;
      }
      case 4 :
      {
        Delete_end();
        Display_LL();
        break;
      }
      case 5 :
      {
        Display_LL();
        break;
			}
      case 6 :
      {
        Reverse_Recursion(head);
        printf("\nAfter Reversing Recusrively:\n");
        Display_LL();
        break;
      }
      default :
      {
        printf("Wrong Value Detacted\n");
        break;
      }
      return;
    }
  }
}
