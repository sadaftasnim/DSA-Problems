#include <iostream>
#include "Binary_Tree.h"
#include "BST_class.h"
#include <queue>
#include <vector>
using namespace std;

void print(BinaryTree<int>* root)
{

    if(root == nullptr)
        return ;

    cout<<root->data<<" : " ;

    if(root->left != nullptr)
        cout << "L"<<root->left->data <<" ";

     if(root->right != nullptr)
        cout << "R"<<root->right->data;

        cout<<endl;
        print(root->left);
        print(root->right);
}



//printing levelwise
void printLevelWise(BinaryTree<int>* root)
{
    if(root == nullptr)
        return;

    queue<BinaryTree<int>*> pendingNode;
    pendingNode.push(root);


    while(pendingNode.size() != 0)
    {

         BinaryTree<int>* front = pendingNode.front();

         cout<<front->data <<" : " ;
          pendingNode.pop();

         if(front->left != nullptr)
         {

             cout<<"L"<< front->left->data << " ";
             pendingNode.push(front->left);
         }
         if(front->right != nullptr )
         {

             cout<< "R" << front->right->data;
             pendingNode.push(front->right);
         }
         cout<<endl;

    }

}





// taking input

BinaryTree<int>* takeInput()
{
    int rootData ;
    cout<< "Enter Data: " <<endl;
    cin>>rootData;

    if(rootData == -1)
        return nullptr;

    BinaryTree<int>* root = new BinaryTree<int>(rootData);
     BinaryTree<int>* leftChild = takeInput();
      BinaryTree<int>* rightChild = takeInput();

      root->left = leftChild;
      root->right = rightChild;

      return root;

}



//taking input level wise

BinaryTree<int>* takeInputLevelwise()
{
    int rootData ;
    cout<< "Enter Root Data: " <<endl;
    cin>>rootData;

    if(rootData == -1)
        return nullptr;

    BinaryTree<int>* root = new BinaryTree<int>(rootData);
    queue<BinaryTree<int>*> pendingNode;
    pendingNode.push(root);

    while(pendingNode.size() != 0)
    {
         BinaryTree<int>* front = pendingNode.front();
         pendingNode.pop();

         cout << "Enter Left child of "<< front->data << endl;

         int leftchild ;
         cin>>leftchild;
         if(leftchild != -1)
          {
            BinaryTree<int>* child = new BinaryTree<int>(leftchild);
            front->left = child;
            pendingNode.push(child);
          }

         cout << "Enter Right child of "<<front->data << endl;
         int rightchild ;
         cin>>rightchild;
         if(rightchild != -1)
          {
            BinaryTree<int>* child = new BinaryTree<int>(rightchild);
            front->right = child;
            pendingNode.push(child);
          }
    }

    return root;
}





// finding number of nodes

int numNodes(BinaryTree<int>* root)
{
    if(root == nullptr)
    {
        return 0;
    }

     //1st approach
    //return 1 + numNodes(root->left) + numNodes(root->right);


    // 2nd approach
    int count = 1;
    if(root->left != nullptr)
    {
        count+= numNodes(root->left);
    }
    if(root->right != nullptr)
    {
        count+= numNodes(root->right);
    }

    return count;
}




// Inorder traversal method

void InOrderTraversal(BinaryTree<int>* root) // 1st LeftNode then root then rightNode
{
    if(root == nullptr)
        return;

    InOrderTraversal(root->left);
    cout<<root->data << " ";
    InOrderTraversal(root->right);
}




// PreOrder traversal method

void PreOrderTraversal(BinaryTree<int>* root) // 1st root then leftNode then rightNode
{
    if(root == nullptr)
        return;

    cout<<root->data << " ";
    PreOrderTraversal(root->left);
    PreOrderTraversal(root->right);
}





// PostOrder traversal method

void PostOrderTraversal(BinaryTree<int>* root) // 1st leftNode then rightNode then root
{
    if(root == nullptr)
        return;

    PostOrderTraversal(root->left);
    PostOrderTraversal(root->right);
    cout<<root->data << " ";
}



BinaryTree<int>* findNode(BinaryTree<int>* root , int ele)
{
    if(root == nullptr)
    {
        return nullptr;
    }

    if(root-> data == ele)
        return root;

    else if(ele > root->data)
    {
        findNode(root->right , ele);
    }
    else if(ele < root->data )
    {
        findNode(root->left , ele);
    }
    else
        return nullptr;

}





void printNodeBetweenTwoRange(BinaryTree<int>* root , int k1 , int k2)
{

    if(root == nullptr)
        return ;
    if(root->data >= k1 && root->data <= k2)
    {

        cout<< root->data <<" ";
    }

    if(root->data > k1)
    {
        printNodeBetweenTwoRange(root->left , k1 , k2);
    }

    if(root->data <= k2)
    {
        printNodeBetweenTwoRange(root->right , k1 , k2);
    }
}




//create a BST from sorted array

 BinaryTree<int>* createBST_fromSortedArray(int* arr , int S_Index , int E_Index)
 {
     if(S_Index > E_Index)
        return nullptr;

     int mid = (S_Index + E_Index)/2;

     BinaryTree<int>* root = new BinaryTree<int>(arr[mid]);
     BinaryTree<int>* leftNode = createBST_fromSortedArray(arr , S_Index , mid-1);
     BinaryTree<int>* rightNode = createBST_fromSortedArray(arr , mid+1 , E_Index);

     root->left = leftNode;
     root->right = rightNode;


     return root;
 }




 //checking a given tree is BST or not
 bool Is_BST(BinaryTree<int>* root , int min = INT_MIN , int max = INT_MAX)
 {

     if(root == nullptr)
        return true;

        if(root->data < min || root->data > max)
            return false;

        bool leftIsOk = Is_BST(root->left , min , root->data-1);
        bool rightIsOk = Is_BST(root->right , root->data , max);


     return leftIsOk && rightIsOk ;

 }



// create sorted Linked list from a BST
template <typename T>

 class Node              // structure for create linked list
 {
    public:
     T data ;
     Node<T>* next;

     Node(int data)
     {
         this->data = data;
         next = nullptr;

     }
 };


template <typename T>
 Node<T>* BSTtoSortedLL(BinaryTree<T>* root , Node<T>*& head , Node<T>*& tail)
 {

     if(root == nullptr)
        return nullptr;



     BSTtoSortedLL(root->left ,head , tail );


     Node<T>* newNode = new Node<T>(root->data);

     if(head == nullptr)
     {
         head = newNode;
         tail = newNode;
     }
     else
     {
        tail->next = newNode;
        tail = tail->next;
     }

    BSTtoSortedLL(root->right , head , tail);


     return head;

 }


//for print converted linked list from BST
 template <typename T>
 void printLinkedList(Node<T>* head)
 {
     Node<T>* temp = head;
     while(temp != nullptr)
     {
         cout<<temp->data << " -> ";
         temp = temp->next;
     }
     cout <<"NULL" <<endl;
 }




 // Get root to given node path

 vector<int>* getRootToNodePath(BinaryTree<int>* root , int data)
 {
     if(root == nullptr)
        return nullptr;

     if(root->data == data)
     {
         vector<int>* output = new vector<int>();
         output->push_back(root->data);
         return output;
     }

     vector<int>* leftOutput = getRootToNodePath(root->left , data);

     if(leftOutput != nullptr)  // if required data present in left of tree
     {
         leftOutput->push_back(root->data);
         return leftOutput;
     }

      vector<int>* rightOutput = getRootToNodePath(root->right , data);

     if(rightOutput != nullptr)  // if required data present in right of tree
     {
         rightOutput->push_back(root->data);
         return rightOutput;
     }

     else
     {
         return nullptr;  // if data not present in a tree
     }
 }





int main() //1 2 3 4 5 6 7 8 9 10 11 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1
{
    /*BinaryTree<int>* root = new BinaryTree<int> (10);
    BinaryTree<int>* node1 = new BinaryTree<int> (20);
    BinaryTree<int>* node2 = new BinaryTree<int> (30);
    root->left = node1;
    root->right = node2;*/
     //BinaryTree<int>* root = takeInput();

    /*BinaryTree<int>* root = takeInputLevelwise();
    printLevelWise(root);
    int k1 , k2;
    cout<<"Please enter two number for range"<<endl;
    cin >>k1>>k2;
    printNodeBetweenTwoRange(root , k1 , k2);*/


    /*int arr[] = {1,2,3,4,5,6,7};
    BinaryTree<int>* root = createBST_fromSortedArray(arr , 0 , 6);
    printLevelWise(root);*/

    //BinaryTree<int>* root = takeInputLevelwise();
    //
    //cout<<Is_BST(root)<<endl ;




    /*int ele;
    cout<< "Enter element for search : " <<endl;
    cin >>ele;
    root = findElement(root , ele);
    printLevelWise(root);*/

    //cout<< "Number of nodes in a Binary tree : "<< numNodes(root)<<endl;


    //InOrderTraversal(root);
     //PreOrderTraversal(root);
     //PostOrderTraversal(root);


     /*Node<int>* head = nullptr;
     Node<int>* tail = nullptr;
      BinaryTree<int>* root = takeInputLevelwise();
      Node<int>* result= BSTtoSortedLL(root , head, tail);
      printLinkedList(result);*/

     /*BinaryTree<int>* root = takeInputLevelwise(); // for getRootNodePath
     vector<int>* result = getRootToNodePath(root , 3);
     for(int i = 0 ; i < result->size() ; i++)
     {
         cout<< result->at(i) <<endl;
     }*/



     BST b;
     b.insertNode(10);
     b.insertNode(5);
     b.insertNode(20);
     b.insertNode(7);
     b.insertNode(3);
     b.insertNode(15);
     b.print_BST();
     b.deleteNode(10);
     b.deleteNode(100);
     b.print_BST();

    return 0;
}
