#include <string.h>
using namespace std;

template <typename V>
class MapNode{
public:
    string key;
    V value;
    MapNode* next;

    MapNode(string key  , V value)
    {
        this->key = key;
        this->value = value;
        next = nullptr;
    }

    ~MapNode()
    {
        delete next;
    }
};


template <typename V>
class OurMap{

    MapNode<V>** buckets;  // array that store the address of head in each index
    int count;
    int numBuckets;

public:
    OurMap()
    {
      count = 0;
      numBuckets = 5;
      buckets = new MapNode<V>*[numBuckets];

      for(int i = 0 ; i < numBuckets ; i++)
      {
          buckets[i] = nullptr;
      }
    }

    ~OurMap()
    {
        for(int i = 0 ; i < numBuckets ; i++)
        {
            delete buckets[i];
        }

        delete [] buckets;
    }

private:
    int getBucketsIndex(string key)
    {
        int hashCode = 0;
        int currentCoeff = 1;
        for(int i = key.length()-1 ; i <= 0 ; i--)
        {
            hashCode += key[i] * currentCoeff;   //(key = abc)(c*p0 + b*p1 + a*p2) where p = 37 (any prime number)  p0 = 1
            hashCode = hashCode % numBuckets;
            currentCoeff *= 37;
            currentCoeff = currentCoeff % numBuckets;
        }

        return hashCode % numBuckets;
    }




    void reHash()
    {
        MapNode<V>** temp = buckets;
        buckets = new MapNode<V>*[2*numBuckets];

        for(int i = 0; i < 2 * numBuckets ; i++)
        {
            buckets[i] = nullptr;
        }

        int oldBuckets = numBuckets;
        numBuckets *= 2;
        count = 0;

        for(int i = 0 ; i < oldBuckets ; i++)
        {
            MapNode<V>* head = temp[i];

            while(head != nullptr)
            {

                string key = head->key;
                V value = head->value;
                insert(key , value);

                head = head->next;
            }
        }

        for(int  i = 0 ; i < oldBuckets ; i++)
        {
            MapNode<V>* head = temp[i];  // delete linkedList of old array
            delete head;
        }
        delete [] temp;     // delete old array
    }


public:


double getLoadFactor ()
{
    return (1.0 * count)/numBuckets;
}

 int size()
 {
     return count;
 }


 void insert(string key , V value)
 {
    int bucketsIndex = getBucketsIndex(key);
    MapNode<V>* head = buckets[bucketsIndex];

    while(head != nullptr)
    {
        if(head->key == key)
        {
            head->value = value;
            return;
        }
        head = head->next;

    }
    head = buckets[bucketsIndex];
    MapNode<V>* node = new MapNode<V>(key , value);
    node->next = head;
    buckets[bucketsIndex] = node;
    count++;

    double loadfactor = (1.0 * count)/numBuckets;

    if(loadfactor > 0.7)
    {
        reHash();
    }

 }



V remove(string key)
{
    int bucketsIndex = getBucketsIndex(key);
     MapNode<V>* head = buckets[bucketsIndex];
     MapNode<V>* prev = nullptr;

     while(head != nullptr)
     {
         if(head->key == key)
         {
             if(prev == nullptr)                 // delete 1st node of linkedList
             {
                 buckets[bucketsIndex] = head->next;
             }

             else
             {
                 prev->next = head->next;       // delete any node after 1st node
             }

             V value = head->value;    // storing value before delete
             head->next = nullptr;     // delete node which contain given key
             delete head;
             count--;
             return value;              //return value of deleted node
         }

         prev = head;
         head = head->next;
     }

     return 0;      //if we do not found given key

}

V getValue(string key)
{
   int bucketsIndex = getBucketsIndex(key);
   MapNode<V>* head = buckets[bucketsIndex];

   while(head != nullptr)
   {
       if(head->key  == key)
       {
           return head->value;
       }
       head = head->next;
   }

   return 0;        //if given key is not present
}

};





