#include<iostream>
using namespace std ;

#define size 5 
int queue[size] ;
int front= -1 ;
int rear= -1 ;


void enqueue(int item);
void dequeue();
void display();

int main()
{
enqueue(5);
enqueue(10);
enqueue(15);
display();
dequeue();
display();

}



int isfull()
{
    if(front == 0 && rear==size - 1)
    return true ;
    else
    return false ;
}

int isempty()
{
    if(front == -1 && rear == -1 && front > rear )
    return true ;
    else
    return false ;
}

void enqueue(int item)
{
    if(isfull())
    cout<<"the queue is full"<<endl;
    else
    {
        if(front== -1 && rear==-1 )
        {
            front++ ;
            rear++ ;
            queue[front] = item ; 
        }
        else
        {
            rear++ ;
            queue[rear] = item ;
        }
    }
}

void dequeue()
{
    if(isempty())
    cout<<"the queue is empty"<<endl;
    else
    {
        front++ ;
    }
}

void display()
{
    cout<<"we will display the queue items :"<<endl;

    if(isempty())
        cout<<"Sorry, The Queue is empty"<<endl;
    else
    {
        for(int i=front ; i<=rear ; i++)
        cout<<"["<<i<<"] = " << queue[i]<<endl;
    }
    cout<<endl;
}
