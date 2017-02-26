#include "kdtree.h"

/* Hold key and data in each node */
/*struct kdElem
{
  int arr[2];
  int data;
};*/

/* For each node hold data and pointers to it's children
   left and right */
/*struct Knode
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
};*/

/*class kdSearchTree
{
    public:
    Knode* root;
    //needed to draw a DotFile 
    std::stringstream ss;
    void insertIntoKdTree(Knode* newNode);
   // utility function to recursively check and addtoKdTree 
//  Knode* addToKdTree(node* cur, node* newNode);
    void printInorderKdTree(Knode* cur);
    int heightOfKdTree(Knode* );
//    void showDotFile(Knode* );
};*/
/* Here align parameter is to find whether the current node to be inserted
 based on X alignment or Y alignment */

void kdSearchTree::resetCounter()
{
  emptyNodeCount = 0;
}

void kdSearchTree::showDotFile(Knode* cur)
{
  if (cur == NULL)
    return;
  if (cur->left != NULL)
  {
    ss << "   " << "\"" << cur->elem.arr[0] << "," << cur->elem.arr[1] << ","
       << cur->elem.data << "\"" << " -> " << "\"" << cur->left->elem.arr[0] << ","
     << cur->left->elem.arr[1] << "," << cur->left->elem.data << "\"" << ";" << endl;
    showDotFile(cur->left);
  }
  else
  {
    ss << "null" << emptyNodeCount << "[shape=point];" << endl;
    ss << "   " << "\"" << cur->elem.arr[0] << "," << cur->elem.arr[1] << ","
       << cur->elem.data << "\"" << " -> " << "null" << emptyNodeCount << " ;" << endl;
    emptyNodeCount++;
  }
  if (cur->right != NULL)
  {
    ss << "   " << "\"" << cur->elem.arr[0] << "," << cur->elem.arr[1] << ","
       << cur->elem.data << "\"" << " -> " << "\"" << cur->right->elem.arr[0] << ","
       << cur->right->elem.arr[1] << "," << cur->right->elem.data << "\"" << ";" << endl;
    showDotFile(cur->right);
  }
  else
  {
    ss << "null" << emptyNodeCount << "[shape=point];" << endl;
    ss << "   " << "\"" << cur->elem.arr[0] << "," << cur->elem.arr[1] << ","
       << cur->elem.data << "\"" << " -> " << "null" << emptyNodeCount << " ;" << endl;
    emptyNodeCount++;
  }
}

int kdSearchTree::searchKeyInKdtree(Knode* cur, kdElem elem)
{
  if (cur == NULL)
    return 0;
   return (ElementEquals(cur, elem) || 
           searchKeyInKdtree(cur->left, elem) ||
           searchKeyInKdtree(cur->right, elem));
}

int kdSearchTree::ElementEquals(Knode* cur, kdElem elem)
{
  if (cur == NULL)return 0;
  else
  {
    if ((cur->elem.arr[0] == elem.arr[0]) && (cur->elem.arr[1] == elem.arr[1])
	&& (cur->elem.data == elem.data))
      return 1;
  }
  return 0;
}

Knode* minNodeAmongKDimension(Knode* root, Knode* left, Knode* right, int align)
{
  Knode* temp = root;
  if ((left != NULL) && (root != NULL) && (left->elem.arr[align] <= root->elem.arr[align]))
  {
    temp = left;
  }
  if ((right != NULL) && (temp != NULL) && (right->elem.arr[align] <= temp->elem.arr[align]))
  {
    temp = right;
  }
  return temp;
}

Knode* kdSearchTree::findMinKnode(Knode* cur, int align, int curDepth)
{
  if (cur==NULL)return NULL;
  if (align == curDepth)
  {
    if (cur->left == NULL)
      return cur;
    return findMinKnode(cur->left, align, (curDepth+1)%2);
  }
  /* If current dimension is different from the required dimension
   search in all possible directions */
  else
  {
    return minNodeAmongKDimension(cur, findMinKnode(cur->left,  align, (curDepth+1)%2), 
	                          findMinKnode(cur->right, align, (curDepth+1)%2), align);
  }
}

void kdSearchTree::ReplaceCurrentNodeWithSuccessor(Knode* cur,Knode* replace)
{
  if ((cur == NULL) || (replace == NULL))
  {
    return;
  }
  cur->elem.arr[0] = replace->elem.arr[0];
  cur->elem.arr[1] = replace->elem.arr[1];
  cur->elem.data   = replace->elem.data;
}

Knode* kdSearchTree::deleteKdNode(Knode* cur, kdElem elem, int align)
{
  if (cur == NULL)return NULL;
  if (ElementEquals(cur, elem) == 1)
  {
    if (cur->right != NULL)
    {
      Knode* temp = findMinKnode(cur->right, align, (align+1)%2);
      ReplaceCurrentNodeWithSuccessor(cur, temp);
      /* Verify if need to do null check for temp or
         taken care automatically */
      cur->right = deleteKdNode(cur->right, temp->elem, (align+1)%2);
    }
    else if(cur->left != NULL)
    {
      Knode* temp = findMinKnode(cur->left, align, (align+1)%2); 
      ReplaceCurrentNodeWithSuccessor(cur, temp);
      /* Verify if need to do null check for temp or
         taken care automatically */
      /* Swap the left and right nodes */
      cur->right = deleteKdNode(cur->left, temp->elem, (align+1)%2);
      cur->left = NULL;
    }
    else
    {
      delete(cur);
      return NULL;
    }
    return cur;
  }
  else if (elem.arr[align] <= cur->elem.arr[align])
  {
     cur->left = deleteKdNode(cur->left, elem, (align+1)%2);
  }
  else
  {
    cur->right = deleteKdNode(cur->right, elem, (align+1)%2);
  }

  return cur;
}

void kdSearchTree::printInorderKdTree(Knode* cur)
{
  if (cur != NULL)
  {
    printInorderKdTree(cur->left);
    cout << "[" << cur->elem.arr[0] << "," << cur->elem.arr[1] << "," << cur->elem.data << "] ";
    printInorderKdTree(cur->right);
  }
}

Knode* kdSearchTree::addToKdTree(Knode* cur, Knode* newNode, int align)
{
  if (cur == NULL)return newNode;
  if (cur->elem.arr[(align%2)] >= newNode->elem.arr[(align%2)])
  {
    cur->left = addToKdTree(cur->left, newNode, (align+1)%2);
  }
  else
  {
    cur->right = addToKdTree(cur->right, newNode, (align+1)%2);
  }
}

void kdSearchTree::insertIntoKdTree(Knode* newNode)
{
  if (root == NULL)
  {
    root = newNode;
    return;
  }
  root = addToKdTree(root, newNode, 0);
}

int kdSearchTree::heightOfKdTree(Knode* cur)
{
  /* Return -1 for any empty tree */
  if (cur == NULL)return -1;
  else
  {
    return (max(heightOfKdTree(cur->left), heightOfKdTree(cur->right))+1);
  }
}

