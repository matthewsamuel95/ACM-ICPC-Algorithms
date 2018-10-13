/* Priority Queue for patients */
#include <iostream.h>
#include <string.h>
#include<ctype.h>
class Queue
{
  private:
     struct Node
      {
	    int Priority;
	    char Name[20];
	    Node *Next;
      }*Front;
 public:
   Queue() {Front=NULL;}

int isEmpty()
{
	if(Front==NULL)
		return 1;
	return 0;
}
void Insert(char[10],int);
void Remove();
void Display();

};
void Queue:: Insert(char N[10],int P)
{

   Node *Temp,*Prev,*Patient=new Node;
   if(Patient==NULL)
     cout<<"System Memory Full";
   else
{  strcpy(Patient->Name,N);
   Patient->Priority=P;
   Patient->Next=NULL;
	if(Front==NULL)
	       Front=Patient;
		else
		     {
			Temp=Front;
			while(Temp!=NULL && Patient->Priority<=Temp->Priority)
				{ Prev=Temp;Temp=Temp->Next;}
				if(Temp==Front)
				 {
				   Patient->Next=Front;
				   Front=Patient;
				 }
				else
				 {
				   Patient->Next=Temp;
				   Prev->Next=Patient;
				 }
		     }
}
}
void Queue::Remove()
{
  Node *Temp = Front;
  Front=Front->Next;
  switch(Temp->Priority)
	 {
		case 1: cout<<"   General Checkup";break;
		case 2: cout<<"   Non-serious";break;
		case 3: cout<<"   Serious";break;
		default:cout<<"   Unknown";
	}
  cout<<"\nPatient \""<<Temp->Name<<"\"got the treatment\n ";
  delete Temp;
}


void Queue::Display()
{ Node *Temp=Front;
 if(!isEmpty())
 {
    cout<<"\nSerious Patient List";
     if(Temp->Priority==3)
       do
       {
	 cout<<"\n "<<Temp->Name;
	 Temp=Temp->Next;
       }while(Temp->Priority==3);
    else cout<<"is Empty\n";
    cout<<"\n__________________________________";
    cout<<"\nNon Serious Patient List";
    if(Temp->Priority==2)
       do
       {
	 cout<<"\n"<<Temp->Name;
	 Temp=Temp->Next;
	}while(Temp->Priority==2);
     else cout<<"is Empty\n";
    cout<<"\n__________________________________";
     cout<<"\nGeneral Checkup Patient List";
     if(Temp->Priority==1)
       do
       {
	 cout<<"\n"<<Temp->Name;
	 Temp=Temp->Next;
	}while(Temp->Priority==1);
     else cout<<"is Empty\n";
  }
}

int main()
 {
	int Choice,J,Flag,P;
	char N[20];
	Queue Q;
	do
	   {
		cout<<"\n\n1)Enter a New Patient";
		cout<<"\n2)Service the next patient";
		cout<<"\n3)Display the list of patients";
		cout<<"\n4)Quit";
		cout<<"\nEnter Your Choice : ";
		cin>>Choice;
		switch(Choice)
		   {
			case 1:
				do
				{
				  cout<<"\nName of the patient : ";
				  cin>>N;
				  J=0;Flag=0;
				  while(N[J]!='\0')
				       {
					if(isalpha(N[J])) J++;
					else {Flag=1;break;}
					}
				  if(Flag==1) cout<<"\nReenter First name";
				}while(Flag!=0);

				do
				{
				cout<<"\nPriority(1- General checkup,2- non-serious,3- serious ): ";
				cin>>P;
				} while(P<1||P>3);
				Q.Insert(N,P);
				break;
			case 2: if(!Q.isEmpty())
				  
					Q.Remove();
				    
				else
				    cout<<"\nQueue is empty";
				break;
			case 3: Q.Display();break;
		    }
	}while(Choice!=4);
return 1;
}