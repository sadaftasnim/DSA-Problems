#include <string>
#include "TrieNode.h"

using namespace std;

class Trie
{

     TrieNode *root;

     public:
       Trie()
       {
           root = new TrieNode('\0');
       }

       // insertion
       void insertWord(TrieNode *root , string word) // helper function
       {

           if (word.size() == 0)
           {
             root->isTerminal = true;
             return ;

           }

           int index = word[0] - 'a';
           TrieNode *child;
           if(root->children[index] != nullptr)
           {
               child = root->children[index];
           }

           else{
            child = new TrieNode(word[0]);
            root->children[index] = child;
           }

           insertWord(child , word.substr(1));
       }

       void insertWord(string word) // calling by user
       {
            insertWord(root , word);
       }


      /************************************************/
       // searching
       bool searchWord(TrieNode *root , string word)
       {

           if (word.size() == 0)
           {
             return root->isTerminal ;

           }

           int index = word[0] - 'a';
           TrieNode *child;
           if(root->children[index] != nullptr) // character exist
           {
               child = root->children[index];
           }

           else
           {
            return false ;
           }

          return searchWord(child ,word.substr(1));


       }

       bool searchWord(string word) // for user
       {
           
           return searchWord(root , word);
       }



       /************************************************/
       // deletion
       void removeWord(TrieNode *root , string word)
       {

           if (word.size() == 0)
           {
             root->isTerminal = false;
             return ;

           }

           int index = word[0] - 'a';
           TrieNode *child;
           if(root->children[index] != nullptr) // character exist
           {
               child = root->children[index];
           }

           else
           {
            return ;
           }

          removeWord(child , word.substr(1));


          // delete child if it is useless
          if(child -> isTerminal == false)
          {
              for(int i = 0 ; i < 26 ; i++)
              {
                  if(child->children[i] != nullptr)
                  {
                      return;
                  }
              }
              delete child;
              root->children[index] = nullptr;

          }



       }

       void removeWord(string word) // for user
       {
            removeWord(root , word);
       }

      
};




