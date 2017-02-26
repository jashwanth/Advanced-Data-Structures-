#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;
/*Each element has a key and data
 the heap is maintained as Priority queue
 based on min heap. Min Key element has 
 highest priority */
typedef struct element
{
  int key;
  int data;
}elem;
class priority_queue
{
  public :
  vector<elem> arr;
  /* Default costructor */
  priority_queue();
  /* heapify the heap to maitain heap
   property at each node */
  void minHeapify(int );
  void insert(elem );
  void ExtractMinAll();
  void AllMinOp(int );
  /* Move the element up the heap if the value decreases */
  void percolateUp(int );
  /* same as heapify which is moving down */
  void percolateDown(int );
  void print();
};
