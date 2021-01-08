#ifndef QUEUE_H_INCLUDED
#define QUEUE_H_INCLUDED
#include <iostream>
using namespace std;
const int maxQueue = 200;

template < class queueElementType >
class Queue {
public:
   Queue();
   bool enqueue(queueElementType e, bool & dump);
   bool dequeue(queueElementType &e);
   bool Front(queueElementType &e);
   bool isEmpty();
   bool Search(queueElementType e);
private:
   struct node;
   typedef node* link;
   struct node
   {
       queueElementType data ;
        link next;
   };
   link r,f;
};

template < class queueElementType >
Queue < queueElementType >::Queue()
{
   f = NULL;
   r = NULL;
}

template < class queueElementType >
bool Queue < queueElementType > :: enqueue(queueElementType e,bool &dump)
{
   link location;
   location= new node;
   if(location==NULL) return false ;

   location->data=e;
   if(f==NULL)
    {
        f=location;
        r=location;
        location->next=NULL;
    }
    else if(f->data>e)
    {
        location->next=f;
        f=location;
    }
    else if(f->data==e)
    {
        dump=true;
    }

   else
   {    link ptr=f;
   while(ptr->next!=NULL&&ptr->next->data<e)
    ptr=ptr->next;

    if(ptr->next==NULL)
   {
       r->next=location;
       r=location;
       location->next=NULL;
   }

    else if(ptr->next!=NULL&&ptr->next->data==e)
   {
       dump=true;
   }
   else
        {
            location->next=ptr->next;
            ptr->next=location;
        }
   }
   return true;
   }




template < class queueElementType >
bool Queue < queueElementType >::dequeue(queueElementType & e)
{
   if(f==NULL) return false ;
   link deletednode;
   e=f->data;
   deletednode=f;
   f=f->next;
   delete deletednode;
   return true;

}


template < class queueElementType >

bool Queue < queueElementType >::Front(queueElementType &e)
{
  if(f==NULL) return false;
  e=f->data;
  return true;
}

template < class queueElementType >
bool Queue < queueElementType >::isEmpty()
{
   return bool(f == NULL);
}

template < class queueElementType >
bool Queue < queueElementType >::Search(queueElementType e)
{
   link ptr=f;
   while(ptr!=NULL)
   {
       if(ptr->data==e)
        return true;
   }
   return false;
}

#endif // QUEUE_H_INCLUDED
