#include <iostream>
#include "Trie.h"

using namespace std;


int main()
{
   
    Trie t;
    t.insertWord("abc");
    t.insertWord("are");
    t.insertWord("dog");

    cout << t.searchWord("are") << endl;
    t.removeWord("are");
    cout << t.searchWord("are") << endl;
    return 0;
}
