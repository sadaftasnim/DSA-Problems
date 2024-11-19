#include <iostream>
using namespace std;
#include <queue>


void kSmallestEle(int* input , int n , int k)  // k spacify how many smallest ele that we want from array
{
    priority_queue <int> pq;        // inbuild priority queue that is always max priority queue

    for(int i = 0 ; i <k ; i++)
    {
        pq.push(input[i]);        // k elements are pushed in descending order
    }

    for(int i = k ; i < n ; i++)
    {
        int max_ele = pq.top();    // pq.pop() will give largest element


        if(input[i] < max_ele)
        {
            pq.pop();
            pq.push(input[i]);
        }
    }


    for(int i = 0 ; i < k ; i++)
    {
        input[i] = pq.top();
        pq.pop();
    }

}



void kLargestEle(int* input , int n , int k)
{
    priority_queue <int , vector<int> , greater<int> > pq; //syntax for min priority queue b'coz inbuilt priority queue is by default max priority queue

    for(int i = 0 ; i <k ; i++)
    {
        pq.push(input[i]);
    }

    for(int i = k ; i < n ; i++)
    {
        int min_ele = pq.top();


        if(input[i] > min_ele)
        {
            pq.pop();
            pq.push(input[i]);
        }
    }


    for(int i = 0 ; i < k ; i++)
    {
        input[i] = pq.top();
        pq.pop();
    }

}

int main()
{
    int input[] = {5,6,9,12,3,13,2};
    int k= 4;


   /* kSmallestEle(input ,7,k);
    for(int i = 0 ; i < k ; i++)
    {
        cout<< input[i] << " ";
    }
    cout<< endl;*/


    kLargestEle(input ,7,k);
    for(int i = 0 ; i < k ; i++)
    {
        cout<< input[i] << " ";
    }
    cout<< endl;
}
