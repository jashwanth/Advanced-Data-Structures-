#include <iostream>
#include <climits>
using namespace std;

class singleNode
{
  private:
    int data;
    singleNode* next;
  public:
   singleNode(int , singleNode* );
   int getNodeData();
   singleNode* getNextNode();
   void setNodeData(int );
   void setNextNode(singleNode* );
   void displayData();
};

class sll
{
  private:
  singleNode* head;
  /* return kth node from head node */
  singleNode* ReturnKthNode( int );
  public:
  sll();
  void createsll(int *, int);
  int ListLength();
  void reverseSll();
  void shuffleSll();
  void printList();
  void printListByFour();
  void printFirstHalfByFour();
  void printSecondHalfByFour();
  void InsertAtEnd(int );
  void InsertAtStart(int );
  /* Sort all the elements from current node for length number of nodes as argument
   and return the start of sorted list */
  void mySort(int , int );
};
