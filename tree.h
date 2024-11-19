#include <vector>
using namespace std;
template <typename T>

class treeNode{
public:
    T data;
    vector<treeNode<T>*> children;

    //constructor
    treeNode(int data)
    {

        this->data = data;
    }

    //destructor
    ~treeNode()
    {
        for(int i = 0 ; i < children.size() ; i++)
        {
            delete children[i];
        }
    }
    // to call this destructor() we need to write "delete root;" at the last in the main()
};

