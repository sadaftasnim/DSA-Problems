#include <iostream>
using namespace std;


class node{
public:
    int data;
    node* next;

    node(int data)
    {
        this->data = data;
        next = nullptr;
    }


};

node* create_node()
{
    node* head = nullptr;
    node* tail = nullptr;
    int data;
    cin>> data;

    while(data != -1)
    {

        node* newNode = new node(data);
        if(head == nullptr)
        {

            head = newNode;
            newNode->next = head;
            tail = newNode;
        }

        else
        {
            tail->next = newNode;
            tail = newNode;
            newNode->next = head;
        }
        cin>>data;
    }
    return head;
}



node* insertNode(node* head , int pos , int ele)
{
   node* newNode = new node(ele);
   int count = 0;

  if(pos == 0) // at first index
  {
      node* tail = head;
      while(1)
      {
        tail = tail->next;
        if(tail->next == head)
        {
           break;
        }
      }
      newNode->next = head;
      head = newNode;
      tail->next = newNode;
      return head;
  }

      node* temp = head;
      while(temp->next != head && count < pos-1)
      {
          temp = temp->next;
          count++;
      }
      if(temp->next != head) //insert at any index
      {
          newNode->next = temp->next;
          temp->next = newNode;
      }
       else if(((pos-1)-count) > 0)
      {
          cout <<"Invalid Index"<<endl;
          return head;
      }
      else if(temp->next == head) //insert at last node
      {
          temp->next = newNode;
          newNode->next = head;
      }


  return head;
}

node* deleteNode(node* head , int pos )
{

     int count = 0;
      node* temp = head;
      if(pos == 0) // at first index
      {
          node* tail = head;
          while(1)
          {
            tail = tail->next;
            if(tail->next == head)
            {
               break;
            }
          }
         // node* temp = head;
          head = head->next;
          delete temp;
          tail->next = head;
          return head;
      }

      while(temp->next != head && count < pos-1)
      {

          temp = temp->next;
          count++;
      }
     if(temp->next != head)
      {

      node* a = temp->next;
      temp->next = a->next;
      delete a;

      }

     else if(temp->next == head && !(((pos-1)-count) >=  0))
     {
         node* tail = head;
          while(tail->next->next != head)
          {
              tail = tail->next;
          }
          node* a  = tail->next;
          delete a;
          tail->next = head;

     }


    return head;
}







void print(node* head)
{

    node* temp = head;
    while(1)
    {
        cout<<temp->data<<" ";
        temp = temp->next;
        if(temp == head)
        {
            break;
        }

    }
    cout<<endl;

}



int main()
{

    node* head = create_node();
    print(head);
    int pos;
    cin>>pos;
    head = deleteNode(head , pos);
    print(head);
    //int pos  ,ele;
    //cin>>pos >>ele;
    //head = insertNode(head , pos , ele);
    //print(head);
    return 0;
}
