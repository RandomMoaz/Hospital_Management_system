#include<iostream>
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

class QueueUsingLinkedList
{
    public:
    node*front ;
    node*rear ;

    QueueUsingLinkedList()
    {
        front = rear = NULL ;
    }


bool isempty()
{
    if(front == NULL )
    return true ;
    else
    return false ;
}

void enqueue(int newitem)
{
    node*newnode = new node() ;        
    newnode->data = newitem ;

    if (isempty())
    {        
        front = rear = newnode ;
    }
    else
    {
        rear->next = newnode ;
        rear = newnode ;
    }
}

    int dequeue()
    {
        int item = 0;

        if(isempty())
        cout<<"Queue is empty"<<endl;

        else if(front== rear)
        {
            item = front->data ;
            delete front;
            front = rear = NULL ;
        }

        else
        {
            node*delptr = front ;
            item = delptr->data ;
            front = front->next ;
            delete delptr ;
        }

        return item ;            
    }



    void diplay()
    {
        node*temp = front ;
        while(temp!=NULL)
        {
            cout<<temp->data<<"  ";
            temp = temp->next ;
        }
        cout<<endl;
    }


    int count()
    {
        int counter = 0 ;
        node*temp = front ;
        while(temp!=NULL)
        {
            counter++ ;
            temp = temp->next ;
        }
        return counter ;
        cout<<endl;
    }


    int getFront()
    {
        return front->data;
    }


    int getRear()
    {
        return rear->data;
    }


    bool Search(int searched_item)
    {
        bool found = false ;
        node*temp = front ;
        while(temp!=NULL)
        {
            if(temp->data == searched_item)
            found = true ;
            temp = temp->next ;
        }
        return found ;
    }
};








int main()
{
    QueueUsingLinkedList q ;

    for(int i=0 ; i<3 ; i++)
    {
        int newvalue ;
        cout<<"Enter The New Value :";
        cin>>newvalue;
        q.enqueue(newvalue);
    }

    q.diplay(); 
    q.dequeue();
    cout<<"After Dequeue : ";   
    q.diplay();   
     

}