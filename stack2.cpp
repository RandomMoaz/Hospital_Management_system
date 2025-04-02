#include <iostream>
using namespace std;

#define size 5
int top = -1;
int stack[size];
int length = 0;

void push(int item);
bool isempty();
bool isfull();
int pop();
void display();
int getlength();
int search(int searched_item);
void Gettop();

int main() 
{
push(10);
push(15);
push(20);
display();
cout<<"the length of the stack = " ;
getlength();
pop();
display();
cout<<"the length of the stack = " ;
getlength();
Gettop();
int searched_item ;
cout<<"enter the item tou want to search for :";
cin>>searched_item;
search(searched_item);

    return 0;
}

// isfull() , isempty() , push() , pop() , display() , getlength() , gettop() , search() .


bool isfull()
{
    if(top== size - 1)
    return true ;
    else 
    return false ;
}

bool isempty()
{
    if(top == -1)
    return true ;
    else 
    return false ;
}


void push(int item)
{
    if(isfull())
    cout<<"stack overflow"<<endl;
    else
    {
        top=top+1 ;
        stack[top]= item ;
        length++ ;
    }
}

int pop()
{
    int item ;
    if(isempty())
        cout<<"stack underflow"<<endl;
    else
    {
        item = stack[top] ;
        top-- ;
        length--;
        return item ;
    }
    return 0 ;
}

void display()
{
    if(isempty())
            cout<<"stack underflow"<<endl;
    else
    {
        cout<<"we will display the stack items :"<<endl;
        for(int i=top ; i>=0 ; i--)
        {
            cout<<"["<<i<<"] = "<<stack[i]<<endl;
        }
    }
}

int getlength()
{
    return length ;
}


int search(int searched_item)
{
    int index = -1 ;
    if(isempty())
        cout<<"under flow"<<endl;
    else
    {
        for(int i= top ; i>=0 ; i--)
        {
            if(stack[i] == searched_item)
            index = i ;
        }
    }
    return index ;
    }


void Gettop()
{
    if(top!= -1)
    cout<<"the top = "<< stack[top]<<endl;
    else
    cout<<"stack underflow"<<endl;
}