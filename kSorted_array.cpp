/*A k-sorted array (also known as a nearly sorted array) is an array in which each element is k-1(left or right) positions away from its target position before sorted in descending order.
 This means if we were to sort the array in descending order, any element at index i could only be found between positions i−k and i+k */

 #include <iostream>
 using namespace std;
 #include <queue>

 void kSorted_array(int* input , int n , int k)
 {
     priority_queue<int> pq;    // max priority queue

     for(int i = 0 ; i < k ; i++ )
     {
         pq.push(input[i]);  // pushing just like largest element comes at 0th index bcoz it is a max priority queue
     }

     int j = 0;

     for(int i= k ; i < n ; i++)
     {
         input[j] = pq.top();    // largest ele comes at 0th index of input array
         pq.pop();
         pq.push(input[i]);
         j++;
     }

     while(!pq.empty())    // for resting k elements
     {
         input[j] = pq.top();
         pq.pop();
         j++;
     }
 }



 int main()
 {


    int input[] = {10 , 12 , 6, 7 ,5};
    int k = 2;
    kSorted_array(input , 5 , k);

     for(int i = 0 ; i < 5 ; i++)
     {
         cout << input[i] << " ";
     }

     cout << endl;

     return 0;



 }
