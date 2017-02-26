#include <iostream>
#include "singleLinkedList.h"
#include "doubleLinkedList.h"
#include <cstdlib>
using namespace std;

int main()
{
  int numNodes, i, item;
  sll mysll1;
  sll mysll2;
  sll mysll3;
  dll mydll1;
  dll mydll2;
  dll mydll3;
  dll mydll4;

  cin >> numNodes;
  cout << "===========================================" << endl;
  cout << "Total Number of Nodes:  " << numNodes << endl;
  cout << "===========================================" << endl << endl;
  int *arr = (int *)malloc(numNodes*sizeof(int));
  for (int i = 0; i< numNodes; i++)
  {
    cin >> arr[i];
  }

  
  mysll1.createsll(arr, numNodes);
  cout << "****Before the Operation ********" << endl;
  mysll1.printListByFour();
  cout << endl << endl;


  cout << "****After the team of four Operation*****" << endl;
  int len = mysll1.ListLength();
  /* split the elements by 4 each and send to sort function */
  while ( i < len)
  {
    mysll1.mySort(i, 4);
    i += 4;
  }
  mysll1.printListByFour();
  cout << endl << endl;

  mysll2.createsll(arr, numNodes);
  cout << "****Before the Operation ********" << endl;
  mysll2.printListByFour();
  cout << endl << endl;
  
  cout << "After Single linkedlist Reverse operation********" << endl;

  mysll2.reverseSll();
  mysll2.printListByFour();
  cout << endl << endl;
  
  mysll3.createsll(arr, numNodes);
  
  cout << "****Before the Single Linked List Operation ********" << endl;
  cout << "** first half **" << endl;
  mysll3.printFirstHalfByFour();
  cout << endl << endl;
  cout << "** second half **" << endl;
  mysll3.printSecondHalfByFour();
  cout << endl << endl;

  cout << "****After single linkedlist Shuffle operation*****" << endl;
  mysll3.shuffleSll();
  mysll3.printListByFour();
  cout << endl << endl;
 
  cout << "******End of single Linked List operations**********" << endl;
  cout << endl << endl;

  cout << "******Begin of double Linked List operations********" << endl << endl;

  mydll1.createdll(arr, numNodes);
  cout << "****Before the Operation ********" << endl;
  mydll1.printListByFour();
  cout << endl << endl;

  cout << "****After the team of four Operation*****" << endl;
  len = mydll1.ListLength(), i =0;
  /* split the elements by 4 each and send to sort function */
  while ( i < len)
  {
    mydll1.mySort(i, 4);
    i += 4;
  }
  mydll1.printListByFour();
  cout << endl << endl;

  mydll2.createdll(arr, numNodes);
  cout << "****Before the Double Linkedlist operation*******" << endl; 
  mydll2.printListByFour();
  cout << endl << endl;
  
  cout << "After Double linkedlist Reverse operation********" << endl;

  mydll2.reverseDll();
  mydll2.printListByFour();
  cout << endl << endl;
  
  mydll3.createdll(arr, numNodes);
  
  cout << "****Before the Double Linked List Operation ********" << endl;
  cout << "** first half **" << endl;
  mydll3.printFirstHalfByFour();
  cout << endl << endl;
  cout << "** second half **" << endl;
  mydll3.printSecondHalfByFour();
  cout << endl << endl;

  cout << "****After Double linkedlist Shuffle operation*****" << endl;
  mydll3.shuffleDll();
  mydll3.printListByFour();
  cout << endl << endl;
  cout << "******End of double Linked List operations********" << endl << endl;
  return 0;
}
