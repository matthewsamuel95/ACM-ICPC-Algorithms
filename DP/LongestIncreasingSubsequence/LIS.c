#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	int data;
	struct node* next;
}node;

node* append(node* head,int d){
	node *temp=NULL;
	temp=(node *)malloc(sizeof(node));
	temp->data=d;
	temp->next=NULL;
	if(head==NULL){
		head=temp;
		return head;
	}
	temp->next=head;
	return temp;
}

void printReverse(node* head){
    if (head->next==NULL)
       return;
    printReverse(head->next);
    printf("%d  ", head->data);
}

int main(void) {
    int n,i,j;
    scanf("%d",&n);
    int a[n],lis[n];
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
        lis[i]=1;
    }
    node *head[n];
    for(i=0;i<n;i++){
			head[i]=NULL;
			head[i]=(node *)malloc(sizeof(node));
	        head[i]=append(head[i],a[i]);
    }
	for(i=1;i<n;i++){
	    for(j=0;j<i;j++){
	        if(a[i]>a[j] && lis[i]<lis[j]+1){
	            lis[i]=lis[j]+1;
                head[i]=append(head[j],a[i]);
	        }
	    }
	}
	int max=0,index=0;
	for (i=0;i<n;i++){
        if (max<lis[i]){
            max=lis[i];
            index=i;            
        }
    }
    // printf("%d %d\n",max,index);
    printReverse(head[index]);
	printf("\n");
	return 0;
}