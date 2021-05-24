#include <iostream>
using namespace std;

struct Queue
{
    int size;
    int front;
    int rear;
    int *Q;
};
void create(struct Queue *q, int size)
{
    q->size=size;
    q->front=q->rear=0;
    q->Q=new int [q->size];
}
void enqueue(struct Queue *q, int x)
{
    if ((q->rear+1)%q->size==q->front)// Full condition of the circular queue. iSka matlab agar koi element add hoga toh rear aur front pointer same hojayenge jo ki possible nahi hai isliye circular queue full hai
    {
        cout <<"Queue is Full\n";
    }
    else
    {
        q->rear=(q->rear+1)%q->size;
        q->Q[q->rear]=x;
    }
}
int dequeue(struct Queue *q)
{
    int x=-1;
    if (q->front==q->rear)// Empty condition of the queue
    {
        cout <<"Queue is Empty\n";
    }
    else
    {
        q->front=(q->front+1)%q->size;
        x=q->Q[q->front];
    }
    return x;
}
void display(struct Queue q)
{
   int i=q.front+1;
   do
   {
       cout <<q.Q[i]<<" ";
       i=(i+1)%q.size;
   } while (i!=(q.rear+1)%q.size);
    cout <<endl;
}
int main()
{
    struct Queue q;
    create(&q,5);// Craeting the Queue

    enqueue(&q,10);
    enqueue(&q,20);
    enqueue(&q,30);
    enqueue(&q,40);
    enqueue(&q,50);
    enqueue(&q,60);
    display(q);

    cout <<"Jo phele aya wo phele gaya according to FIFO\n";
    dequeue(&q);
    display(q);
    return 0;
}
