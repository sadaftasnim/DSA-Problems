template <typename T>
class BinaryTree
{
  public:
    T data;
    BinaryTree* left;
    BinaryTree* right;

    BinaryTree(int data)
    {
        this->data = data;
        left = nullptr;
        right = nullptr;
    }

    ~BinaryTree()
    {
        delete left ;
        delete right;
    }
};
