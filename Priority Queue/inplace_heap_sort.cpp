#include <iostream>
using namespace std;

void inplaceHeapSort(int* input , int n) // no use another vector as like priority queue(heap sort)
{
                    // inplace algorithm used for sorting which doesnot take extra space apart from given input and their space comlexity almost O(1)
    //build the min heap in input array

    for(int i = 1 ; i < n ; i++)    // start from 1st index b'coz we assumed 0th index already sorted
    {
        int child_index = i;
        while(child_index > 0)
        {

            int parent_index = (child_index-1)/2;

            if(input[child_index] < input[parent_index])
            {
                int temp = input[child_index];                       // sort in ascending order
                input[child_index] = input[parent_index];
                input[parent_index] = temp;
            }
            else
            {
                break;
            }

            child_index = parent_index; // for up heapify
        }
    }       // half sorting is completed here and another half sorting will be completed when we will remove element


    //Remove element

    int size = n;

    while(size > 1)
    {
        int temp = input[0];
        input[0] = input[size - 1];
        input[size-1] = temp;

        size--;

        int parent_index = 0;
        int leftChild_index = 2*parent_index + 1;
        int rightChild_index = 2*parent_index + 2;

        while(leftChild_index < size)   // if left child is out of size then right child is also out of size
        {
            int min_index = parent_index;

            if(input[min_index] > input[leftChild_index])
              {
                min_index = leftChild_index;
              }

            if( rightChild_index < size && input[min_index] > input[rightChild_index])  //check for (rightChild_index < pq.size()) if parent have only left child
              {
                min_index = rightChild_index;
              }

            if(min_index == parent_index)
              {
                break;        // when parent ele less than from their both children
              }

            int temp = input[parent_index];
            input[parent_index] = input[min_index];
            input[min_index] = temp;


            parent_index = min_index;                // update parent , left child , right child for down heapify
            leftChild_index = 2*parent_index + 1;
            rightChild_index = 2*parent_index + 2;

       }
    }

}


int main()
{
    int input[] = {5,1,2,0,8};
    inplaceHeapSort(input , 5);
    for(int i = 0 ; i < 5 ; i++)
    {
        cout << input[i] << " ";   // output = 8 , 5 , 2 , 1 ,0  bcoz we performed these above operation based on min heap if we want output in ascending order we will have to perform these above operation based on max heap
    }
    cout << endl;

}
