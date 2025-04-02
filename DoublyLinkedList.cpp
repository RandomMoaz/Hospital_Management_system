#include<iostream>
using namespace std ;


class node{
    public:
    int data ;
    node*prev;
    node*next;

    node()
    {
        data = 0 ;
        prev = next = NULL ;
    }
};

class DoublyLinkedList{
    public:
    node*head ;

    DoublyLinkedList()
    {
        head = NULL ;
    }


    bool isfull()
    {
        node*newnode = new node ();
        if(newnode==NULL)
        return true ;
        else
        return false ;
    }


    bool isempty()
    {
        if(head==NULL)
        return true ;
        else
        return false ;
    }


    void insertFirst(int newvalue)
    {
        node*newnode = new node ();
        newnode->data = newvalue ;
        if(isempty())
        {
            newnode->next = newnode->prev = NULL ;
            head = newnode ;
        }
        else
        {
            newnode->prev = NULL ;
            newnode->next = head ;
            head->prev = newnode ;
            head = newnode ;
        }   
    }

    void insertEnd(int newvalue)
    {
        node*newnode = new node ();
        node*temp = head ;
        newnode->data = newvalue;
        newnode->next = NULL ;
        while(temp->next != NULL)
        {
            temp = temp->next ;
        }
        temp->next = newnode ;
        newnode->prev = temp ;
    }


    bool search(int item)
    {
        bool isfound = false ;
        node*temp=head;
        while (temp!=NULL)
        {
            if (temp->data==item) 
            isfound = true;
            else   
            temp=temp->next;
        }
        return isfound ;
    }


    void display()
    {
        node*temp = head ;
        while(temp !=NULL)
        {
            cout<<temp->data << "  ";
            temp = temp->next ;
        }
    }


    int removeFromBeginning()
    {


        if(isempty())
        cout<<"LINKED LIST IS EMPTY."<<endl;
        else
        {
            int deletedvalue ;
            node*temp = head ;
            deletedvalue =  temp->data ;  
            head = head->next ;
            head->prev = NULL ;                            
            
            delete temp ;
            return deletedvalue ;            
        }
    }

   
    int removeFromEnd()
    {
        if(isempty())
        cout<<"LINKED LIST IS EMPTY."<<endl;
        else
        {
            int deletedvalue ;
            node*temp = head ;            
            node*prvdel = head ;            

            while(temp->next != NULL)
            {
                prvdel = temp ;
                temp = temp->next ;
            }
            deletedvalue = temp->data ;
            prvdel->next = NULL ;
            delete temp ;
            return deletedvalue ;        
        }        
    }

    int removeSearchedItem(int searched_item)
    {
        if(isempty())
        cout<<"LINKED LIST IS EMPTY."<<endl;
        else if (head != NULL)
        {
            int deletedvalue ;
            node*temp = head ;
            node*prevdel = head ;
            node*afterdel = head ;
            while(temp->data != searched_item)
            {
                prevdel = temp ;
                temp = temp->next ;
                afterdel = temp ;
                afterdel = afterdel->next ;
            }
            deletedvalue =  temp->data ;
            prevdel->next = temp->next ;
            afterdel->prev = prevdel ;
            delete temp ;
            return deletedvalue ;
        }
        else
        cout<<"ITEM NOT FOUND"<<endl;
    }

    void insertsorted(int item)
    { 
        node *newnode = new node(); 
        newnode->data=item;
        if(isempty())
        { 
            newnode->next = NULL;
            newnode->prev = NULL;
            head=newnode; 
        }
        else
        {
            node*temp = head ;
            while((temp->data > item && temp->next->data > item) || (temp->data<item && temp->next->data<item) && temp!=NULL)
            {
                temp = temp->next ;
            }
            newnode->next = temp->next ;
            temp->next = newnode ;
            newnode->prev = temp ;
            newnode->next->prev = newnode ;
        }
    }


};




int main()
{
    DoublyLinkedList DLL ;

    for(int i=0 ; i<=3 ; i++)
    {
        int newvalue ;
        cout<<"ENTER NEW VALUE :";
        cin>>newvalue;  
        DLL.insertFirst(newvalue) ;
    }
    DLL.display();
    cout<<endl;

    int searcheditem ;
    cout<<"ENTER ITEM TO DELETE :";
    cin>>searcheditem;
    DLL.removeSearchedItem(searcheditem);
    cout<<"AFTER DELETION :" ;
    DLL.display();
    cout<<endl;


}