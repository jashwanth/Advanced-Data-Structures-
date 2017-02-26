#include <iostream>
#include <climits>
using namespace std;

class doubleNode
{
  private:
    int data;
    doubleNode* prev;
    doubleNode* next;
  public:
   doubleNode(int , doubleNode* , doubleNode* );
   int getNodeData();
   doubleNode* getPrevNode();
   doubleNode* getNextNode();
   void setNodeData(int );
   void setNextNode(doubleNode* );
   void setPrevNode(doubleNode* );
   void displayData();
};

class dll
{
  private:
  doubleNode* head;
  /* Return Kth Node from head */
  doubleNode* ReturnKthNode(int);
  public:
  dll();
  void createdll(int *, int);
  int ListLength();
  void reverseDll();
  void shuffleDll();
  void printList();
  void printListByFour();
  void printFirstHalfByFour();
  void printSecondHalfByFour();
  /*Insert at end of list */
  void InsertAtEnd(int );
  /*Insert at start of list */
  void InsertAtStart(int );
  /* Sort all the elements from current node for length number of nodes as argument
     and return the start of sorted list */
  void mySort(int, int);
};
