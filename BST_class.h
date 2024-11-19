#include <iostream>
using namespace std;

class BST{

private:
    BinaryTree<int>* root;

 public:

     BST()
     {
         root = nullptr;
     }

     ~BST()
     {
         delete root;
     }


  //helper function for hasData
 private:
  bool hasData(int data , BinaryTree<int>* node)
  {
      if(node == nullptr)
        return false;

      if(node->data == data)
        return true;

      else if(node->data > data)
         return hasData(data , node->left); //if data present in left side it will return true

      else
        return hasData(data , node->right);//if data present in right side it will return true


  }

  // searching for a data in a given tree
  public:
  bool hasData(int data)
  {
      return hasData(data , root);  //calling helper function b'coz it is taking only one argument but
                           //for searching we have to go and check left nodes as well as right nodes if required data not present in root
  }



  // helper function for insertNode()

  BinaryTree<int>* insertNode(int data , BinaryTree<int>* node)
  {
      if(node == nullptr)
      {
        BinaryTree<int>* newNode = new BinaryTree<int>(data);
        return newNode;
      }


      if(data < node->data)
      {
          node->left = insertNode(data , node->left);
      }

      else
      {
          node->right = insertNode(data , node->right);
      }

     return node;
  }


  //insert a node in a given tree

  void  insertNode(int data)
  {
       this->root = insertNode(data , this->root);
  }



  //helper function for deleteNode()
  BinaryTree<int>* deleteNode(int data , BinaryTree<int>* node)
  {

      if(node == nullptr)
        return nullptr;

      if(data < node->data)
      {
          node->left = deleteNode(data , node->left);
          return node;
      }

      else if(data > node->data)
      {
          node->right = deleteNode(data , node->right);
          return node;
      }

      else if(node->left == nullptr && node->right == nullptr) //if required data present in node(root) and right are left both are null
      {
          delete node;
          return nullptr;
      }

      else if(node->left == nullptr)      //if required data present in node(root) but left is null
      {
          BinaryTree<int>* temp = node->right;
          node->right = nullptr;
          delete node;
          return temp;
      }
      else if(node->right == nullptr)     ////if required data present in node(root) but right is null
      {
          BinaryTree<int>* temp = node->left;
          node->left = nullptr;
          delete node;
          return temp;
      }


      else          // if we delete root but leftNode and rightNode are present then we will have to find max from left and min from right for replacement with root
      {
          BinaryTree<int>* minNode = node->right; //finding minimum ele from left of right
          while(minNode->left != nullptr)
          {
              minNode = minNode->left;
          }
          int rightMin = minNode->data;
          node->data = rightMin;          // replacement node data to rightMin
          node->right = deleteNode(rightMin , node->right);   // after replacement delete rightMin from right
          return node;
      }


  }

  // delete Node
  public:
    void deleteNode(int data)
    {
        root = deleteNode(data , root);
    }



    //helper function of print_BST()
   private:
    void print_BST(BinaryTree<int>* node)
{

    if(node == nullptr)
    {
         return ;
    }


    cout<<node->data<<" : " ;

    if(node->left != nullptr)
    {
        cout << "L"<<node->left->data <<" ";
    }


     if(node->right != nullptr)
     {
         cout << "R"<<node->right->data;
     }


        cout<<endl;
        print_BST(node->left);
        print_BST(node->right);
}


   public:
    void print_BST()
    {
        print_BST(root);
    }

   // these above 4 function are calling from BinaryTreeUse.cpp file

};
