#include <iostream>
using namespace std;
#include "linked_list_class.h"




node* take_input()
{
    int data;
    cin>>data;
    node* head = NULL;
    node* tail = NULL;
    while(data != -1)
    {
        node* newNode = new node(data);

        if(head == NULL)
        {
            head = newNode;
            tail = newNode;
        }

        else
        {
            tail->next = newNode;
            tail = newNode ;
        }
        cin>>data;

    }
    return head;
}



node* insertNode(node* head , int pos , int ele)
{
    node* newNode = new node(ele);
    node* temp = head;
    int count = 0;
    if(pos == 0)
     {
         newNode->next= head;
         head = newNode;
         return head;
     }
    while(temp != nullptr && count < pos-1)   //temp != nullptr , protects our program to crash when we enter pos grater than  the size of the linkedlist
    {
        temp = temp->next;
        count++;
    }
      if(temp != nullptr)
      {
        newNode->next = temp->next;  // this body will not execute when we enter the pos grater than  the size of the linkedlist
        temp->next = newNode;
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
        head = newNode;
        return head;
    }

    node* ans = insertNode_recursively(head->next , pos-1 ,ele );


    head->next = ans ;

   return head;
}



node* deleteNode_recursively(node* head , int pos)
{
    node* temp = head;
    if(head == NULL)
    {
        return head;
    }
    if(pos == 0)
    {
       head = head->next;
       delete temp;
       return head;
    }
    node* ans = deleteNode_recursively(head->next , pos-1);
    head->next = ans;
    return head;

}




int find_mid_ele(node* head)
{
    node* slow = head;
    node* fast = head->next;
    while(fast != NULL && fast->next!= NULL ) // for odd number of nodes (fast!=null) and for even number of nodes (fast->next != null) condition is necessary
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow->data;
}




node* deleteNode(node* head , int pos)
{
    node* temp = NULL;
    temp = head;
    int count = 0;
    if(pos == 0)
    {
        head = head->next;
        delete temp;
        return head;
    }
    while(temp != NULL && count < pos-1)
    {
        temp = temp->next;
        count++;
    }
    if(temp != NULL)
    {
        node* a = temp->next;
        temp->next = temp->next->next;// temp->next = a->next;
        delete a;
    }
    return head;
}



node* merge_two_sorted_ll(node* head_1 , node* head_2)
{
    node* fh = NULL;
    node* ft = NULL;
    node* h1 = head_1;
    node* h2 = head_2;
    if(h1->data < h2->data)
    {
        fh = h1;
        ft = h1;
        h1 = h1->next;
    }
    else
    {
        fh = h2;
        ft = h2;
        h2 = h2->next;
    }
    while(h1 != NULL && h2 != NULL)
    {
        if((h1->data) < ( h2->data))
        {
            ft->next = h1;
            ft = h1;
            h1 = h1->next;
        }
        else
        {
            ft->next = h2;
            ft = h2;
            h2 = h2->next ;
        }

    }
    if(h1 != NULL)
    {

        ft->next = h1;
    }
    else
    {

        ft->next = h2;
    }
    return fh;
}



node* merge_two_sorted_ll_recursively(node* h1 , node* h2)
{

    if(h1 == nullptr)
        return h2;
    if(h2 == nullptr)
        return h1;
    node *h3 = nullptr;
    if(h1->data < h2->data)
    {
        h3 = h1;
        h3->next = merge_two_sorted_ll_recursively(h1->next , h2);
    }
    else
    {
        h3 = h2;
        h3->next = merge_two_sorted_ll_recursively(h1 , h2->next);
    }
    return h3;
}


//implementing merge sort


void split_list(node* head , node** firstHalf , node** second_half)
{

    node* slow = head;
    node* fast = head->next;
    while(fast != nullptr && fast->next != nullptr)
    {

        slow = slow->next;
        fast = fast->next->next;
    }
    *firstHalf = head;           // 1st half starts from the head
    *second_half = slow->next;  //2nd half starts after slow
    slow->next = nullptr;     //end the first half
}



node* merge_sort(node* head)
{
    if(head == nullptr || head->next == nullptr) // base case if list has 0 or 1 element
    {
        return head;
    }
    node* firstHalf = nullptr;
    node* secondHalf = nullptr;

    split_list(head , &firstHalf , &secondHalf);

    firstHalf = merge_sort(firstHalf);
    secondHalf = merge_sort(secondHalf);

    return merge_two_sorted_ll_recursively(firstHalf , secondHalf);

}




void print(node* head)
{
    while(head != NULL)
    {
        cout << head->data;
        if(head->next != NULL)
        {
            cout <<"->";
        }
        head = head->next;
    }
    cout<<endl;
}

//1st method
node* reverse_node_recursively(node* head) //with O(n2)
{

    if(head->next == nullptr)
    {

        return head;
    }
    node* small_ans = reverse_node_recursively(head->next);
    node* temp = small_ans;
    while(temp->next != nullptr)
    {
        temp = temp->next;
    }
    temp->next = head;
    head->next = nullptr;
    return small_ans;
}


//2nd method
node* reverse_node_iteratively(node* head)
{
     node* prev = nullptr;
     node* nextt = nullptr ;
     node* current = head;
     while(current != nullptr)
     {
         nextt = current->next;
         current->next = prev;
         prev = current;
         current = nextt;
     }

    return prev ;
}

// 3rd reverse method with O(n) by recursion

class Pair{
  public:
    node* head;
    node* tail;
};

Pair reverse_ll_2(node* head)
{

    if(head == nullptr || head->next == nullptr)
    {

        Pair ans;
        ans.head = head;
        ans.tail = head;
        return ans ;
    }

    Pair small_ans = reverse_ll_2(head->next);

    small_ans.tail->next = head;
    head -> next = nullptr;

    Pair ans;
    ans.head = small_ans.head;
    ans.tail = head;
    return ans;
}

node* reverse_ll_better(node* head)
{

    return reverse_ll_2(head).head ;
}

//4th method

node* reverse_node_recursively_3(node* head) //with o(n)
{

    if( head == nullptr || head->next == nullptr)
    {

        return head;
    }

    node* small_ans = reverse_node_recursively_3(head->next);

    node* tail = head->next;

    tail->next = head;
    head->next = nullptr;
   return small_ans;
}


int main()
{
    node* head = take_input();
    print(head);
    //node* head_2 = take_input();
   // print(head_1);
    //print(head_2);
    //node* head_3 = merge_two_sorted_ll(head_1 , head_2);
   // head_1 = merge_two_sorted_ll_recursively(head_1 , head_2);
   // print(head_1);

   // int ans = find_mid_ele(head);
    //cout<<ans<<endl;
   /*int i,ele;
   cin>>i>>ele;
    head = insertNode(head , i ,ele);*/
    head = reverse_node_recursively_3(head);
   //head = insertNode_recursively(head , i , ele);
   /*print (head);*/
    /*int pos;
    cin>>pos;
    //head = deleteNode(head ,pos);
    head = deleteNode_recursively(head ,pos);

    print(head);*/
    // for merge sort
   /* node* head = take_input();
    head = merge_sort(head);
    print(head);*/
    //head = reverse_node_recursively_3(head);
   //head = reverse_node_iteratively(head);
    print(head);
  //  head = reverse_ll_better(head);
  //  print(head);
    return 0;
}
