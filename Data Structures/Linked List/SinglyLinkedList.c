#include<stdio.h>
#include<conio.h>
#include<process.h>
#include<stdlib.h>
struct node
{
int info;
struct node *next;
}*start;
void addfront(void);
void addlast(void);
void delfront(void);
void dellast(void);
void traverse(void);
void sum(void);
void min();
void max();
void search();
void sort(void);
int main()
{
int choice;
while(1)
{
printf("\n 1. add front \n 2. add last \n 3. del front \n 4. del last \n 5. traverse \n 6. sum \n 7. min \n 8. max \n 9. search \n 10. sort \n 11. exit \n enter your choice...");
scanf("%d",&choice);
switch(choice)
{
case 1: addfront(); break;
case 2: addlast(); break;
case 3: delfront(); break;
case 4: dellast(); break;
case 5: traverse(); break;
case 6: sum(); break;
case 7: min(); break;
case 8: max(); break;
case 9: search(); break;
case 10: sort(); break;
case 11: exit(0);
default: printf("\n invalid choice....");
}
getch();
}
}


void addfront()
{
struct node *n=(struct node*)malloc(sizeof(struct node));
printf("\n enter the information 	");
scanf("%d",&n->info);
n->next=start;
start=n;
printf("\n node inserted at front ...");
}


void addlast(void)
{
struct node *t=start,*last;
struct node *n=(struct node*)malloc(sizeof(struct node));
printf("\n enter the information 	");
scanf("%d",&n->info);
n->next=NULL;
if(start==NULL)                         //   if(start==NULL)
start=n;                                //   {
else                                    //   start=n;
{                                       //   last=n;
while(t->next!=NULL)                    //   }
t=t->next;                              //   else
t->next=n;                              //   {
}                                       //   last->next=n;
printf("\n node inserted at last");     //   last=n;
}                                       //   }


void traverse(void)
{
struct node *t=start;
int s=0;
if(start==NULL)
printf("\n empty");
else
{
while(t!=NULL)
{
printf("%d\t",t->info);
s++;
t=t->next;
}
printf("\ntotal node is %d",s);
}
}

void delfront(void)
{
struct node *t=start;
if(start==NULL)
printf("\n underflow");
else
{
start=start->next;
free(t);
printf("\n deleted from front ....");
}
}

void dellast(void)
{
struct node *t=start;
if(start==NULL)
printf("\n underflow");
else if(start->next==NULL)
{
free(t);
start=NULL;
printf("\n last single node deleted");
}
else
{
while(t->next->next!=NULL)
t=t->next;
free(t->next);
t->next=NULL;
printf("\n deleted from last...");
}
}


void sum(void)
{
int s=0;
struct node *t=start;
while(t!=NULL)
{
s=s+t->info;
t=t->next;
}
printf("\n sum = %d",s);
}



void min(void)
{
struct node *t=start->next;
int m;
m=start->info;
while(t!=NULL)
{
if(m>t->info)
m=t->info;
t=t->next;
}
printf("\n min= %d",m);
}


void max(void)
{
struct node *t=start->next;
int m;
m=start->info;
while(t!=NULL)
{
if(m<t->info)
m=t->info;
t=t->next;
}
printf("\n max is =%d",m);
}

void search(void)
{
struct node *t=start;
int s;
printf("Enter your data to search");
scanf("%d",&s);
while(t!=NULL)
{
t=t->next;
if(s==t->info)
{
printf("data found");
}
else
{
    t=t->next;

}
}
}

void sort(void)
{
struct node *t=start,*q,*w;
while(t!=NULL)
{
 q=t->next;
 while(q!=NULL)
 {
  if(t->info>q->info)
  {
   int temp;
   temp=t->info;
   t->info=q->info;
   q->info=temp;
  }
  q=q->next;
 }
 t=t->next;
}
w=start;
printf("\n");
while(w!=NULL)
{
printf("%d\t",w->info);
w=w->next;
}
}
