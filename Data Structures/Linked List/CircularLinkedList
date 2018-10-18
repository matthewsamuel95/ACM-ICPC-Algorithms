#include<iostream>
using namespace std;

struct node
{
    int info;
    node *link;
};

class circlist
{
    node *top = NULL,*ptr,*rear = NULL,*end = NULL;
    int x,count;
public:

    void insert();
    void del();
    void search();
    void display();

};

void circlist::insert()
{
    char ch = 'y';
    while(ch == 'y' || ch == 'Y')
    {
        cout<<"\nEnter element : ";
        cin>>x;
        ptr = new node;
        ptr->info = x;
        if(top == NULL)
        {
            top = ptr;
            ptr->link = top;
            rear = ptr;
        }
        else
        {
            rear->link = ptr;
            ptr->link = top;
            rear = ptr;
        }
        cout<<"\nDo you want to enter more?(y/n)...";
        cin>>ch;
    }
}
void circlist::display()
{
    node *tp = top;
    while(tp->link != top)
    {
        cout<<tp->info<<"\n";
        tp = tp->link;
    }
    cout<<tp->info;
    tp = tp->link;
    cout<<"\nInitial element-->"<<tp->info<<"-->";
}

void circlist::del()
{
    node *a;
    char ch = 'y';
    while(ch == 'y' || ch == 'Y')
    {
        a = top;
        top = top->link;
        rear->link = top;
        cout<<a->info<<" deleted succesfully!";
        delete(a);
        cout<<"\nDo you want to delete more?(y/n)...";
        cin>>ch;
    }

}

int main()
{
    circlist o;
    int choice;
    while(1)
    {
        cout<<"\nMENU\n1.Insertion\n2.Display\n3.Deletion\n4.Exit";
        cout<<"\nEnter choice : ";
        cin>>choice;
        switch (choice)
        {
        case 1: o.insert();
                break;
        case 2: o.display();
                break;
        case 3: o.del();
                break;
        case 4: exit(0);
        default: cout<<"\nInvalid choice : ";
                break;
        }
    }

    return 0;
}
