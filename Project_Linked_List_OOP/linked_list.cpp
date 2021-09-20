#include "linked_list.hpp"
#include <iostream>

using namespace std;

linked_list::linked_list() : head(nullptr) {}

// copy constructor
linked_list::linked_list(const linked_list &ll)
{
    head = nullptr;
   *this=ll;
}

linked_list::~linked_list()
{
    node *current = head;
    while (current != nullptr)
    {
        node *temp = current->next;
        delete current;
        current = temp;
    }
}

node *linked_list::front()
{
    return head;
}

void linked_list::push_front(int d)
{
    node *new_node = new node;
    new_node->data = d;
    new_node->next = head;
    head = new_node;
}

void linked_list::print()
{
    node *current = head;
    while (current != nullptr)
    {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

int linked_list::length()
{
    int c=0;
    node *current=head;
    while(current!=nullptr)
    {
        c++;
        current=current->next;
    }
    return c;
}

int linked_list::sum()
{
    int sum=0;
    node *current=head;
    while (current!=nullptr) {
       sum+= current->data;
       current = current->next;
   }
   return sum;
}

void linked_list::erase_front()
{
    node *current=new node;
    current=head;
    head=head->next ;
    delete current;
}

void linked_list::push_back(int d)
{
    node *current=new node;
    current->data = d;
    current->next=nullptr;

    node *ptr=head;
    if(head==nullptr)
    {
        head=current;
    }
    while(ptr->next!=nullptr)
    {
        ptr=ptr->next;
    }
    ptr->next=current;
}

void linked_list::bubble_sort()
{
    int cnt=0,temp=0,y=0;
    int A[100];
    node *current=head;
    int i=0;
    while (current!=nullptr){
       A[cnt]= current->data;
       current = current->next;
       cnt++;
   }
   for(i=0;i<cnt;i++)
   {
      for(y=i+1;y<cnt;y++)
      {
          if(A[y]<A[i])
          temp=A[i];
          A[i]=A[y];
          A[y]=temp;     
      }
   }
   for(i = 0; i<10; i++) 
   {
   cout <<A[i]<<"\n";
   }
}