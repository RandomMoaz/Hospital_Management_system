#include <iostream>
using namespace std ;


class node{
    public:
    int data ;
    node*next ;

    node()
    {
        data = 0 ;
        next = NULL ;
    }
};


class StackLinkedList
{
    public:
    node*top ;

    StackLinkedList()
    {
        top = NULL ;
    }

    // there is no full

    bool IsEmpty()
    {
        if(top==NULL)
        return true ;
        else
        return false ;
    }

    void Push(int newitem)
    {
        node*newnode = new node() ;
        newnode->data = newitem;

        if(IsEmpty())
        {newnode->next = NULL;}
        else
        {newnode->next = top ;}

        top = newnode ;
    }

    void Display()
    {
        node*temp = top;

        if(IsEmpty())
            cout<<"THE STACK IS EMPTY. ";
        else
        {
            while (temp!= NULL)
            {
                cout<< temp->data<<" " ;
                temp = temp->next ;
            }
        }
        cout<<endl;             
    }

    int Count()
    {
        int counter=0 ;
        node*temp = top;

        while (temp!= NULL)
        {
            counter++ ;
            temp = temp->next ;
        }
        return counter ;
    }

    int pop()
    {
        int deleteditem ;
        node*temp = top ;
        deleteditem = temp->data ;

        top = top->next ;

        delete temp ;
        return deleteditem ;
    }

    int peek()
    {
        return top->data ;
    }

    bool IsFound(int searcheditem)
    {
        node*temp = top ;
        bool found = false ;

        while(temp != NULL)
        {
            if(temp->data == searcheditem)
            {
                found = true ;
                break;
            }
            temp = temp->next ;
        }
        return found ;
    }
    
};




int main()
{
    StackLinkedList SLL ;

    int data ;

    for(int i=0 ; i<=3 ; i++)
    {
        cout<<"ENTER THE NEW VALUE TO STORE IT : ";
        cin>> data ;
        SLL.Push(data) ;
        SLL.Display();
    }
    cout<<endl;
    cout<<"THE DELETED ITEM = "<<SLL.pop() <<endl;
    cout<<endl;
    cout<<"THE ITEMS IN THE STACK : " ;
    SLL.Display();
    cout<<endl;

    cout<<"THE TOP = "<<SLL.peek() <<endl;
    cout<<endl;
    cout<<"THE NUMBER OF ITEMS IN THE STACK = "<<SLL.Count() <<endl;
    cout<<endl;

    int searcheditem ;
    cout<<"ENTER THE ITEM YOU WANT TO SEARCH ABOUT :" ;
    cin>>searcheditem ;

    if(SLL.IsFound(searcheditem))
    cout<<"THE ITEM WAS FOUND "<<endl;
    else
    cout<<"THE ITEM WAS NOT FOUND "<<endl;

}
