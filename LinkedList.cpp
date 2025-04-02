#include<iostream>
using namespace std;

class node{
    public:
    int data ;
    node*next ;
};

class LinkedList {
    public:
    node*head;

    LinkedList()
    {
        head = NULL ;
    }


    bool IsEmpty()
    {
        if (head==NULL)
        {
            return true ;
        }
        else
        {
            return false ;
        }
    }


    void InsertFirst(int newvalue)
    {
        node* newnode = new node();
        newnode->data=newvalue ;

        if (IsEmpty())

        {
            newnode->next = NULL ;
            head= newnode ;
        }
        else
        {
            newnode->next = head ;
            head = newnode ;
        }
    }

    void Display()
    {
        node*temp= head ;
        while(temp!= NULL)
        {
            cout<< temp->data<<" " ;
            temp = temp->next ;
        }
        cout<<endl;
    }

    bool IsFound(int searched_item)
    {
        bool key = false;
        node*temp= head ;

        while(temp!= NULL)
        {
            if(temp->data== searched_item)
            {
               key = true ;
               break;
            }

            temp = temp->next ;
        }

        return key ;
    }

    int counter()
    {
        int counter= 0 ;
        node*temp= head ;
            while(temp != NULL)
            {
                counter ++;
                temp = temp->next ;
            }
        return counter ;
    }


    void InsertBefore(int item , int newitem)
    {
        if(IsEmpty())
            InsertFirst(newitem);

        if(IsFound(item))
        {
            node*newnode = new node() ;
            newnode->data = newitem ;
            node*temp = head ;

            while (temp !=NULL && temp->next->data !=item)
            {
                temp= temp->next ;
            }

            newnode->next=temp->next ;
            temp->next=newnode;
        }
        else
        cout<<"SORRY, THE ITEM WAS NOT FOUND "<<endl;
    }



    void Append(int newitem)
    {
        if (IsEmpty())
        {
            InsertFirst(newitem);
        }
        else
        {
            node*temp = head ;
                while (temp->next != NULL)
                {
                    temp = temp->next ;
                }
            node* newnode = new node() ;
            newnode->data = newitem;
            temp->next = newnode ;
            newnode->next = NULL ;
        }   
    }


};



int main()
{
    LinkedList list ;

    if(list.IsEmpty())
    cout<<"THE LIST IS EMPTY"<<endl;
    else
    cout<<"THE NUMBER OF ITEMS OF THE LINKESLIST IS :" <<list.counter()<<endl;

    int item ;

    cout<<"ENTER THE ITEM YOU WANT TO INSERT :"<<endl;
    cin>>item;
    list.InsertFirst(item) ;
    list.Display();

    cout<<"ENTER THE ITEM YOU WANT TO INSERT :"<<endl;
    cin>>item;
    list.InsertFirst(item) ;
    list.Display();

    cout<<"ENTER THE ITEM YOU WANT TO INSERT :"<<endl;
    cin>>item;
    list.InsertFirst(item) ;
    list.Display();
    list.counter();

    int searcheditem ;
    cout<<"ENTER ITEM YOU ARE LOOKING FOR :";
    cin>>searcheditem;
    list.IsFound(searcheditem);

    if(list.IsFound(searcheditem))
        cout<<"THE ITEM WAS FOUND"<<endl;
    else
    {
        cout<<"THE ITEM WAS NOT FOUND"<<endl;
    }
    
        cout<<endl;

       cout<<"ENTER THE ITEM YOU WANT TO INSERT BEFORE AND THE NEW ITEM :" ;
       int newitem ;
       cin>> item ;
       cin>> newitem ;
       list.InsertBefore(item , newitem);
       list.Display();
       list.counter();
        // remember to make a counter in main fun ,
       // before any insertion we have to make a new node and fill the data part ---> newnode->data = newvalue ,
       // if we have to traverse on all the elements on the linked list we have to make a temp ---> node*temp = head ,
       // when we want to loop all the linked list and go out the list to count or use or take the last element ---> we use (temp != null)
       // but when we want the next of an item and stop at it we write ---> (temp->next != null)
       //

        cout<<endl;

       cout<<"ENTER THE VALUE YOU WANNA APPEND :" ;
       cin>>newitem ;
       list.Append(newitem) ;
       list.Display();
       list.counter();

       return 0 ;
}



// #include <iostream>
#include <string>
using namespace std;

class branch // hospital
{
public:
    string name, location;
    int ID;
    branch* next;
    branch()
    {
        next = NULL;
        ID = 0;
    }
}; // branch (name, location and ID)


class lincked
{
public:
    branch* head; 
    lincked()
    {
        head = NULL;
    }
    

    bool isfull()
    {
        branch* newbranch = new branch();
        if (newbranch == NULL)
            return true;
        else
            return false;
    } // isfull

    
    bool isempty()
    {

        if (head == NULL)
            return true;
        else
            return false;
    } // isempty

    void insertbranch_F(string stringname, string stringlocation, int enterid)
    {

        branch* newbranch = new branch();
        newbranch->name = stringname;
        newbranch->location = stringlocation;
        newbranch->ID = enterid;
        if (isempty())
        {
            newbranch->next = NULL;
            head = newbranch;
        }
        else
        {
            newbranch->next = head;
            head = newbranch;
        }
        cout << "branch added at first" << endl;
    } // insert at first

    void insertbranch_L(string stringname, string stringlocation, int enterid)
    {
        branch* newbranch = new branch();
        newbranch->name = stringname;
        newbranch->location = stringlocation;
        newbranch->ID = enterid;
        branch* temp = head;

        if (isempty())
        {
            newbranch->next = NULL;
            head = newbranch;
        }
        else
        {
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            newbranch->next = NULL;
            temp->next = newbranch;
        }
        cout << "branch added at last" << endl;
    } //insert at last 


    void Display_data_for_branch()
    {
        branch* temp = head;
        while (temp != NULL)
        {
            cout << "name = " << temp->name << endl << "location = " << temp->location << endl << "ID = " << temp->ID << endl;
            temp = temp->next;
        }
        cout << "end" << endl;
    }//display


    bool search(int searchID)
    {
        branch* temp = head;
        while (temp != NULL)
        {
            if (temp->ID == searchID)
                return true;
            temp = temp->next;
        }
        return false;
    } // search
}; // end linked list

int main()
{
    lincked l;
    string stringname;
    string stringlocation;
    int enterid;

    l.insertbranch_F(stringname, stringlocation, enterid);

    return 0;
}