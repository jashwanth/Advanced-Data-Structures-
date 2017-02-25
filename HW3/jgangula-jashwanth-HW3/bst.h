#ifndef bst_h
#define bst_h

#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <sstream>
#include <fstream>
#include <cmath>
#include <vector>

using namespace std;

/* Hold key and data in each node */
struct bstElem
{
  int key;
  int data;
};
/* For each node hold data and pointers to it's children
   left and right */
struct node
{
  bstElem elem;
  struct node* left;
  struct node* right;
  node(bstElem elem)
  {
    this->elem = elem;
    this->left = NULL;
    this->right = NULL;
  }
};

class binarySearchTree
{
    public:
    node* root;
    /* Useful to print null nodes in dot file */
    int emptyNodeCount;
    /*needed to draw a DotFile */
    std::stringstream ss;
    void resetCounter();
    void insertIntoBst(node* newNode);
    /* utility function to recursively check and addtoTree */
    node* addToTree(node* cur, node* newNode);
    void printInorderTree(node* cur);
    int heightOfBST(node* );
    void showDotFile(node* );
    /* This function deletes the element from the tree with start node cur
     and returns the root of that tree after deletion of bstElem in the tree */
    node* deleteBstNode(node* cur, bstElem );
    /*Check if the current node is same as element to be deleted/searched  */
    int ElementEquals(node* ,bstElem );
    /* To find the minimum element in the right subtree, to replace it with current
     node during deletion */
    node* FindInorderSuccessor(node *);
    void ReplaceCurrentNodeWithSuccessor(node* , node* );
    /* Search for the key in the current subtree with root node */
    void searchKeyInBst(node* , int, vector<bstElem>& );
};

#endif
