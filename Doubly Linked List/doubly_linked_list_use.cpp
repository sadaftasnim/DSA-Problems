#include <iostream>
using namespace std;
#include "doubly_linked_list.h"

node* create_node()
{
   int data;
   cin>>data;
   node* head = nullptr;
   node* tail = nullptr;

   while(data != -1)
   {
      node* newNode = new node(data);
      if(head == nullptr)
      {
          head = newNode;
          tail = newNode;
      }
      else
      {
          tail->next = newNode;
          newNode->prev = tail;
          tail = newNode;
      }
    cin>>data;

   }
   return head;
}
// insertion
node* insert_node(node* head , int pos , int ele)
{
    node* newNode = new node(ele);
    int count = 0;
    node* temp = head;
        if(pos == 0) // insert ele at 0th position
        {
            newNode->next = head;
            head = newNode;
            return head;
        }

        else
          {
            while(temp != nullptr && count < pos-1) //temp != nullptr , protects our program to crash when we enter the pos grater than  the size of the linkedlist
            {
                 temp = temp->next;
                 count++;
            }
             if( temp != nullptr && temp->next != nullptr)  //this body will not execute when we enter the pos grater than  the size of the linkedlist
              {
                temp->next->prev = newNode;
                newNode->next = temp->next;
                temp->next= newNode;          //insert ele at middle of the linked list
                newNode->prev = temp;
              }
            if( temp != nullptr && temp -> next == nullptr)   //this body will not execute when we enter the pos grater than  the size of the linkedlist

                {
                    newNode->prev = temp;         // insert ele at last position
                    temp->next = newNode;
                    newNode->next = nullptr;
                }
          }

        return head;

}

node* insertNode_recursively(node* head , int pos , int ele)
{

    if(head == nullptr)// insert ele at last node
    {
        node* newNode = new node(ele);
        newNode->next = head;
        head = newNode;
        return head;
    }
    if(pos == 0)      //insert ele at 0th and middle of the linked list
    {
        node* newNode = new node(ele);
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
        return head;
    }

    node* ans = insertNode_recursively(head->next , pos-1 ,ele );


    head->next = ans ;
    ans->prev = head;

   return head;
}









//deletion

node* deleteNode(node* head , int pos)
{
    node* temp = nullptr;
    temp = head;
    int count = 0;
    if(pos == 0)
    {
        head = head->next;
        head->prev = nullptr;
        delete temp;
        return head;
    }

    else

     {
        while(temp != nullptr && count < pos-1)
        {
            temp = temp->next;
            count++;
        }
        if(temp != nullptr && temp ->next->next  != nullptr)
        {
            node* a = temp->next;
            temp->next = temp->next->next;// temp->next = a->next;
            temp->next->next->prev = temp;
            delete a;
        }
        if(temp != nullptr && temp->next->next == nullptr)
        {
            node* a = temp->next;
            temp->next = nullptr;

            delete a;
        }
     }
    return head;
}


void print(node* head)
{
    node* temp = head;

    while(temp != nullptr)
    {

        cout <<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}


// reverse


node* reverse_node_recursively(node* head) //with o(n)
{

    if(head->next == nullptr)
    {

        return head;
    }


    node* small_ans = reverse_node_recursively(head->next);

    node* tail = head->next;
    tail->next = head;
    head->prev = tail;
    head->next = nullptr;
   return small_ans;
}


int main()
{

    node* head = create_node();
    print(head);

    //int pos = 0;
    //cin>>pos;
    //head = deleteNode(head , pos);
    int i , ele;
    cin>>i>>ele;
    head = insertNode_recursively(head ,i, ele);
    //head = insert_node(head , i , ele);
    //head = reverse_node_recursively(head);
    print(head);
    return 0;
}
