#ifndef Kdtree_h
#define Kdtree_h

#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <algorithm>
#include <sstream>
#include <fstream>

using namespace std;

/* Hold key and data in each node */
struct kdElem
{
  /* array of dimension k here
   we are restricted to 2D trees */
  int arr[2];
  int data;
};
/* For each node hold data and pointers to it's children
   left and right */
struct Knode
{
  kdElem elem;
  struct Knode* left;
  struct Knode* right;
  Knode(kdElem elem)
  {
    this->elem = elem;
    this->left = NULL;
    this->right = NULL;
  }
};

class kdSearchTree
{
    public:
    Knode* root;
    int emptyNodeCount;
    /*needed to draw a DotFile */
    std::stringstream ss;
    void resetCounter();
    void insertIntoKdTree(Knode* newNode);
    /* utility function to recursively check and addtoKdTree */
    Knode* addToKdTree(Knode* , Knode* , int);
    void printInorderKdTree(Knode* cur);
    int heightOfKdTree(Knode* );
    /* Delete the KElem in the tree with current node Knode* . Also
     pass alignement for correct processing */
    Knode* deleteKdNode(Knode* , kdElem, int );
    /*Check if the node at current element is same as passed element */
    int ElementEquals(Knode* ,kdElem );
    /* Find the min Knode in the given subtree along with the alignment
     information for correct processing */
    Knode* findMinKnode(Knode* ,int ,int );
    void ReplaceCurrentNodeWithSuccessor(Knode*, Knode* );
    void showDotFile(Knode* );
    /* Search if the element exists in the tree */
    int searchKeyInKdtree(Knode* , kdElem);
};
#endif
