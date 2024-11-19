#include <iostream>
#include "tree.h"
#include <queue>

using namespace std;

void printNode(treeNode<int>* root)  //for 1st impletation
{
    /*                            OUTPUT
                1                 1
               / \                2
              2   3               4
             / \                  5
            4   5                 3*/

    if(root == nullptr)
        return;
    cout << root->data <<endl;
    for(int i = 0 ; i < root->children.size() ; i++)
    {
        printNode(root->children[i]);
    }

}


/*****************************************************************
                1                 1:2 3
               / \                2:4 5
              2   3               4:
             / \                  5:
            4   5                 3:

******************************************************************/


void printNode_2(treeNode<int>* root)
{
    if(root == nullptr)
        return;
    cout << root->data << ":";
    for(int i = 0 ; i < root->children.size() ; i++)
    {
        cout << root->children[i]->data << " ";
    }

    cout <<endl;
    for(int i = 0 ; i < root->children.size() ; i++)
    {

        printNode_2(root->children[i]);
    }

}


treeNode<int>* takeInput() // depth wise using recursion
{

    int rootData = 0;
    cout <<"Enter Data"<<endl;
    cin>>rootData;
    treeNode<int>* root = new treeNode<int>(rootData);

    int n ;
    cout<<"Enter the number of children of " << rootData<<endl;
    cin>>n;

    for(int i = 0 ; i < n ; i++)
    {

        treeNode<int>* child = takeInput();
        root->children.push_back(child);
    }
    return root;

}


// take input in level wise

treeNode<int>* takeInput_levelWise()
{

    int rootData = 0;
    cout <<"Enter root data"<<endl;
    cin>>rootData;
    treeNode<int>* root = new treeNode<int>(rootData);

    queue<treeNode<int>*> pendingNode; // using inbuilt queue
    pendingNode.push(root);

    while(pendingNode.size() != 0)
    {
        treeNode<int>* front = pendingNode.front();
        pendingNode.pop();

        cout<< "Enter the number of children of " <<front->data <<endl;
        int n  ;
        cin >> n;

        for(int i = 0 ; i < n ; i++)
        {
            cout<<"Enter "<< i <<"th element of " << front->data << endl;

            int childData ;
            cin >> childData;

            treeNode<int>* child = new treeNode<int>(childData);
            front->children.push_back(child);
            pendingNode.push(child);
        }
    }

        return root;
}

/*****************************************************************
               Tree               Expected output

    -->         1                 1:2 3
               / \                2:4 5
    -->       2   3               3:
             / \                  4:
    -->     4   5                 5:

******************************************************************/



void printNode_levelWise(treeNode<int>* root)
{
    if(root == nullptr)
        return;

    queue<treeNode<int>*> pendingNode; // Creating queue named pendingNode
    pendingNode.push(root); // Pushing root node in the queue

    while(pendingNode.size() != 0) //checking if queue is not empty
    {

        treeNode<int>* front = pendingNode.front();   //getting the 1st ele from the queue
        pendingNode.pop();                            // removing the front ele from the queue


        if(front->children.size() == 0)       //checking if front node don't have children
        {

            cout << front->data <<":" ;
        }

        else                                 // here front node have children
        {
             cout << front->data <<":" ;

            for(int i = 0 ; i < front->children.size() ; i++)  //iterating over all children node
            {
                cout << front->children[i]->data << " ";     //printing children node data
                pendingNode.push(front->children[i]);        //pushing children node to the queue
            }
        }

        cout <<endl;
    }

}



int countNodes(treeNode<int>* root)
{

    if(root == nullptr) //edge case
         return 0 ;

    int ans = 1;       //1 is the count of root node

    for( int i = 0 ; i < root->children.size() ; i++)
    {
        ans += countNodes(root->children[i]);
    }
    return ans;
}

int findHeight(treeNode<int>* root) {
    if (root == nullptr) {
        return 0; // Empty tree has height 0
    }

    // If node has no children, its height is 0
    if (root->children.size() == 0) {
        return 1;
    }

    int maxChildHeight = 0;

    // Traverse all children to find the maximum height among them
    for (int i = 0; i < root->children.size(); i++) {
        int childHeight = findHeight(root->children[i]);
        maxChildHeight = max(maxChildHeight, childHeight);
    }

    // The height of the current node is 1 + max height of its children
    return 1 + maxChildHeight;
}


int countLeafNodes(treeNode<int>* root)
{
    if(root == nullptr)
        return 0;

    if(root->children.size() == 0)
    {
        return 1;

    }

    int countLeaf = 0;
    for(int i = 0 ; i < root->children.size() ; i++)
     {
          countLeaf += countLeafNodes(root->children[i]);
     }
     return countLeaf;
}


void printAtLevelK(treeNode<int>* root , int k)
{
    if(k == 0)
    {
        cout << root->data <<" " ;
         return ;
    }

    for(int i = 0 ; i < root->children.size() ; i++)
    {
        printAtLevelK(root->children[i] , k-1);
    }
      return;
}


//pre Order printing

void printTreePreOrder(treeNode<int>* root) // first parent then children
{
    if(root == nullptr)
        return;
    cout << root->data <<" ";
    for(int i = 0 ; i < root->children.size() ; i++)
    {
        printTreePreOrder(root->children[i]);
    }

}



//post Order Printing

void printTreePostOrder(treeNode<int>* root) {   // first children then parent
    if (root == nullptr) {
        return;
    }

    // Traverse the children first
    for (int i = 0; i < root->children.size(); i++)
    {
        printTreePostOrder(root->children[i]);
    }


    cout << root->data << " ";  //when node have no children
}

//deletion

void deleteTree(treeNode<int>* root) //2nd method ,1st is destructor
{
    for(int i = 0 ; i < root->children.size() ; i++)
    {
        deleteTree(root->children[i]);
    }
    delete root;
}









int main() //1 2 2 3 2 4 5 2 6 7 2 8 9 0 0 0 0 0
{
     // 1st impletation
   /* treeNode<int>* root = new treeNode<int>(10);
    treeNode<int>* node1 = new treeNode<int>(20);
    treeNode<int>* node2 = new treeNode<int>(30);
    root->children.push_back(node1);
    root->children.push_back(node2);
    printNode(root);
    */
    //treeNode<int>* root = takeInput_levelWise();
   // printNode_levelWise(root);
    //cout<<countNodes(root) << endl;

    //int res = countLeafNodes(root);
    //cout<< "Number of leaf Nodes : " << res << endl;

      treeNode<int>* root = takeInput();
      printNode_levelWise(root);
      //int k = 2;
      //printAtLevelK(root , k);
     // int countLeaf = findHeight(root);
     // cout <<"Number of leaf nodes : " << countLeaf<<endl;


      //int height = findHeight(root);
      //cout <<"Height of a tree : " << height << endl;;

   //printTreePreOrder(root);

      //deleteTree(root);
       //printTreePreOrder(root);

       //delete root; // for destructor call or cleaning the memory


   return 0;
}
