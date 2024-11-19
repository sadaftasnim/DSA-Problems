#include <iostream>
using namespace std;
#include "priority_queue(heap_sort).h"

int main()
{
    priority_queue pq;

    pq.insert(10);
    pq.insert(1);
    pq.insert(5);
    pq.insert(12);
    pq.insert(16);
    pq.insert(7);

    cout << pq.isEmpty() << endl;
    cout << pq.getSize() << endl;
    cout << pq.getMin() << endl;

    while(!pq.isEmpty())
    {
        cout << pq.remove() << " ";
    }

    cout << endl;

}
