// Write a function to reverse a given linked list. You should not use the separate list and you should
// work on the original list and reverse the same.

#include <stdio.h>
#include <stdlib.h>
#include "Linked_List.c"

void Reverse() {
  if(head == NULL) {
    return;
  }

  NODE *curr = head;            // Point to Current node of the List
  NODE *next;                   // Point to Next of Current node of the list
  NODE *temp = NULL;
  while(curr != NULL){
    next = curr->next;
    curr->next = temp;          // Curr will Detached from next and point to temp
    temp = curr;                // Changing Temp to curr therefore next Element Detached will point to Current
    curr = next;                // Hence list will reverse after execuation of while loop.
  }
  head = temp;
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
        Reverse();
        printf("\nAfter reversing:\n");
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
