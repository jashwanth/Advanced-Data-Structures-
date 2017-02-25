#include "bst.h"
#include <string>
#include <sstream>
using namespace std;

void binarySearchTree::resetCounter()
{
  emptyNodeCount = 0;
}

void binarySearchTree::searchKeyInBst(node* cur, int key, vector<bstElem> &storeKeys)
{
  if (cur == NULL)
    return ;
  if (cur->elem.key == key)
  {
    storeKeys.push_back(cur->elem);
  }
  /* Search for the key in left and right subtree */
  if (cur->elem.key >= key)
  {
    searchKeyInBst(cur->left, key, storeKeys);
  }
  if(cur->elem.key <= key)
  {
    searchKeyInBst(cur->right, key, storeKeys);
  }
}

void binarySearchTree::showDotFile(node* cur)
{
  if (cur == NULL)
  {
    return;
  }
  if (cur->left != NULL)
  {
    ss << "   " << "\"" << cur->elem.key << "," << cur->elem.data << "\"" << " -> " 
       << "\"" << cur->left->elem.key << "," << cur->left->elem.data << "\"" << ";" << endl;
    showDotFile(cur->left);
  }
  else
  {
    ss << "null" << emptyNodeCount << "[shape=point];" << endl;
    ss << "   " << "\"" << cur->elem.key << "," << cur->elem.data << "\"" << " -> " 
       << "null" << emptyNodeCount << " ;" << endl;
    emptyNodeCount++;
  }
  if (cur->right != NULL)
  {
    ss << "   " << "\"" << cur->elem.key << "," << cur->elem.data << "\"" << " -> "
       << "\"" << cur->right->elem.key << "," << cur->right->elem.data << "\"" << ";" << endl;
  //  ss << "   " << cur->elem.key << " -> " << cur->right->elem.key << ";" << endl;
    showDotFile(cur->right);
  }
  else
  {
    ss << "null" << emptyNodeCount << "[shape=point];" << endl;
    ss << "   " << "\"" << cur->elem.key << "," << cur->elem.data << "\"" << " -> " 
       << "null"  << emptyNodeCount << " ;" << endl;
    emptyNodeCount++;
  }
}

int binarySearchTree::ElementEquals(node* cur, bstElem elem)
{
  if (cur == NULL)return 0;
  else
  {
    if ((cur->elem.key == elem.key) && (cur->elem.data == elem.data))
	return 1;
  }
  return 0;
}

node* binarySearchTree::FindInorderSuccessor(node* cur)
{
  if (cur == NULL)return NULL;
  while(cur->left != NULL)
  {
    cur = cur->left;
  }
  return cur;
}

void binarySearchTree::ReplaceCurrentNodeWithSuccessor(node* cur, node* temp)
{
  if ((cur == NULL) || (temp == NULL))return;
  cur->elem.key  = temp->elem.key;
  cur->elem.data = temp->elem.data;
}

node* binarySearchTree::deleteBstNode(node* cur, bstElem elem)
{
  if (cur == NULL)return NULL;
  if (cur->elem.key < elem.key)
  {
   cur->right = deleteBstNode(cur->right, elem);
   return cur;
  }
  else if(cur->elem.key >= elem.key)
  {
   /* Found the element . 
    Check if it has one/two/no children */
   if (ElementEquals(cur, elem) == 1)
   {
     if ((cur->left == NULL) && (cur->right != NULL))
     {
       node* temp = cur->right;
       delete(cur);
       return temp;
     }
     else if ((cur->right == NULL) && (cur->left != NULL))
     {
       node* temp = cur->left;
       delete(cur);
       return temp;
     }
     else if ((cur->left == NULL) && (cur->right == NULL))
     {
       delete(cur);
       return NULL;
     }
     else if ((cur->left != NULL) && (cur->right != NULL))
     {
       /* Two children are not NULL 
         We replace the current node with the minimum element in
         the right subtree */
        node* temp = FindInorderSuccessor(cur->right);
        ReplaceCurrentNodeWithSuccessor(cur, temp);
        bstElem myElem;
        myElem.key  = temp->elem.key;
        myElem.data = temp->elem.data;
        cur->right = deleteBstNode(cur->right, myElem);
	return cur;
     }
   }
   else
   {
     cur->left = deleteBstNode(cur->left, elem);
     return cur;
   }
  }
}

node* binarySearchTree::addToTree(node* cur, node* newNode)
{
  if (cur == NULL)return newNode;
  if (cur->elem.key >= newNode->elem.key)
  {
    cur->left = addToTree(cur->left, newNode);
  }
  else
  {
    cur->right = addToTree(cur->right, newNode);
  }
  return cur;
}

void binarySearchTree::insertIntoBst(node* newNode)
{
  if (root == NULL)
  {
    root = newNode;
    return;
  }
  root = addToTree(root, newNode);
}

void binarySearchTree::printInorderTree(node* cur)
{
  if (cur != NULL)
  {
    printInorderTree(cur->left);
    cout << "[" << cur->elem.key << ", " << cur->elem.data << "] " ;
    printInorderTree(cur->right);
  }
}

int  binarySearchTree::heightOfBST(node* cur)
{
  /*Empty tree return height of -1 */
  if (cur == NULL)return -1;
  else
  {
     return (max(heightOfBST(cur->left), heightOfBST(cur->right))+1);
  }
}
