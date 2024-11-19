#include <vector>

class priority_queue{   //  implementing min priority queue

    vector<int> pq;

    public:

        priority_queue()
        {

        }


        bool isEmpty()
        {
            return pq.size() == 0;
        }


        int getSize()
        {
            return pq.size();
        }

        int getMin()
        {
            if(isEmpty())
            {
                return 0;
            }

            return pq[0];
        }


        void insert(int ele)       // up heapify
        {

            pq.push_back(ele);

            int child_Index = pq.size()-1;

            while(child_Index != 0)
            {
                int parent_Index = (child_Index -1)/2;

                if(pq[child_Index] < pq[parent_Index])
                {
                    int temp = pq[child_Index];
                    pq[child_Index] = pq[parent_Index];
                    pq[parent_Index]  = temp;
                }

                else
                {
                    break;   // if parent less than its child
                }

                child_Index = parent_Index ;

            }
        }



        int remove()    // down heapify
        {
            int ans = pq[0];    // return deleted ele which stored in ans because after down heapify , minimum ele will always come at root (pq[0])
            pq[0] = pq[pq.size()-1];
            pq[pq.size()-1] = ans ;

            pq.pop_back();  // delete smallest ele which stored at pq[0] before swapping

            int parent_index = 0;
            int leftChild_index = 2*parent_index + 1;
            int rightChild_index = 2*parent_index + 2;

            while(leftChild_index < pq.size())   // if left child is out of size then right child is also out of size
            {
                int min_index = parent_index;

                if(pq[min_index] > pq[leftChild_index])
                {
                    min_index = leftChild_index;
                }

                if( rightChild_index < pq.size() && pq[min_index] > pq[rightChild_index])  //check for (rightChild_index < pq.size()) if parent have only left child
                {
                    min_index = rightChild_index;
                }

                if(min_index == parent_index)
                {
                    break;        // when parent ele less than from their both children
                }

                int temp = pq[parent_index];
                pq[parent_index] = pq[min_index];
                pq[min_index] = temp;


                parent_index = min_index;                // update parent , left child , right child for down heapify
                leftChild_index = 2*parent_index + 1;
                rightChild_index = 2*parent_index + 2;

            }
                return ans;


        }



};
