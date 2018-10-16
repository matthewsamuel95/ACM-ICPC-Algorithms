#include<stdio.h>
#include<stdlib.h>
typedef struct vertex{
	int d;
	struct vertex *next;
}vertex;
vertex* append(vertex* head,int d){
	vertex *temp=NULL;
	temp=(vertex *)malloc(sizeof(vertex));
	temp->d=d;
	temp->next=NULL;
	if(head==NULL)
		return temp;
	temp->next=head;
	return temp;
}

//strongly connected components
void scc(vertex *head,int a[],int i,vertex* hea[]){
	a[i]=1;
	printf("%d\n",i);
	vertex *first=head;
	while(first!=NULL){
		if(a[first->d]!=1 && first->d!=0)
			scc(hea[first->d],a,first->d,hea);
		first=first->next;
	}
}

int arr[1000005],k=0;
void toposort(vertex *head,int v[],int i,vertex* hea[]){
	v[i]=1;
	vertex *first=head;
	while(first!=NULL){
		if(v[first->d]!=1 && first->d!=0)
			toposort(hea[first->d],v,first->d,hea);
		first=first->next;
	}
	arr[k++]=i;
}

int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int n,m,i,p,q;
		scanf("%d %d",&n,&m);
		vertex *head[n+1],*head2[n+1];
		int v[n+1];
		for(i=1;i<=n;i++){
			head2[i]=NULL;
			head[i]=NULL;
			v[i]=0;
		}
		for(i=1;i<=n;i++){
			head[i]=(vertex *)malloc(sizeof(vertex));
			head2[i]=(vertex *)malloc(sizeof(vertex));
		}
		for(i=0;i<m;i++){
			scanf("%d %d",&p,&q);
			head[p]=append(head[p],q);
			head2[q]=append(head2[q],p);
		}
		k=0;
		for(i=1;i<=n;i++){
			if(v[i]==0)
				toposort(head[i],v,i,head);
		}
		for(i=1;i<=n;i++)
			v[i]=0;
		for(i=k-1;i>=0;i--){
			if(v[arr[i]]==0){
				scc(head2[arr[i]],v,arr[i],head2);
			}
		}
	}
	return 0;
}
