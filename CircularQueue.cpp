#include<iostream>
using namespace std ;

#define size 5 
int circularq[size] ;
int front = -1 ;
int rear = -1 ;

bool isFull();
bool isEmpty();
void EnQueue(int newvalue);
int DeQueue();

bool isFull()
{
    if(front == 0 && rear == size - 1 )
    return true;
    else if(front == rear + 1)

    return true ;
    else 
    return false;
}


bool isEmpty()
{
    if(rear == -1 && front == -1)
    return true ;
    else
    return false ;
}


void EnQueue(int newvalue)
{
    if(isFull())
    cout<<"QUEUE IS FULL.";
    else
    {
        if(isEmpty())
        {
            front ++;
            rear++;
            circularq[rear] = newvalue ;
        }
        else
        {
            rear++ ;
            circularq[rear] = newvalue ;
        }
    }
}


int DeQueue()
{
    int deletedvalue ;
    if(isEmpty())
        cout<<"QUEUE IS EMPTY.";
        else
        {
            deletedvalue = circularq[rear] ;

            if(front == rear)
            front = rear = -1 ; 
            else
            front++ ;
        }
}


int main()
{
}