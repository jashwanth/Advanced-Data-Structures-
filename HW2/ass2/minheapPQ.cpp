#include "minheapPQ.h"

/* Left and Right child indices */
#define left(i)   2*i+1
#define right(i)  ((2*i)+2)

/* parent index of a node */
#define parent(i) ((i % 2 == 0) ? (i-1)/2 : i/2)

priority_queue::priority_queue()
{
  arr.clear();
}

void priority_queue::print()
{
  for (int i = 0; i < arr.size() ; i++)
  {
    cout << "[" << arr[i].key << "," << arr[i].data << "] " ;
    (i == (arr.size()-1)) ? cout << endl : cout << " " ;
  }
  cout << endl;
}

void priority_queue::minHeapify(int index)
{
  if (index == 0)return;
  int parentInd = parent(index);
  /* Swap the parent with greater of the two children */
  while ((parentInd >= 0) && (arr[parentInd].key > arr[index].key))
  {
    elem swap = arr[parentInd];
    arr[parentInd] = arr[index];
    arr[index] = swap;
    index = parentInd;
    parentInd = parent(index);
  }
}

void priority_queue::insert(element node)
{
  arr.push_back(node);
  minHeapify(arr.size()-1);
}

void priority_queue::percolateUp(int index)
{
  if (arr.empty())return;
  minHeapify(index);
}

void priority_queue::percolateDown(int index)
{
  if (arr.empty())return;
  int leftInd = left(index);
  int rightInd = right(index);
  int smaller = index;
  if ((leftInd < arr.size()) && (arr[index].key > arr[leftInd].key))
  {
    smaller = leftInd;
  }
  if ((rightInd < arr.size()) && (arr[smaller].key > arr[rightInd].key))
  {
    smaller = rightInd;
  }
  elem swap = arr[index];
  arr[index] = arr[smaller];
  arr[smaller] = swap;
  if (index != smaller)
    percolateDown(smaller);

}

void priority_queue::AllMinOp(int index)
{
  if (arr.empty())return;
   cout << "Min Element is : " << "[ " << arr[index].key << ", " << arr[index].data << "]" << endl;
   int leftInd = left(index);
   if ((leftInd < arr.size()) && (arr[leftInd].key == arr[index].key))
   {
     AllMinOp(leftInd);
   }
   int rightInd = right(index);
   if ((rightInd < arr.size()) && (arr[rightInd].key == arr[index].key))
   {
     AllMinOp(rightInd);
   }
}

void priority_queue::ExtractMinAll()
{
  if (arr.empty())return;
  int storeKey = arr[0].key;
  while ((arr[0].key == storeKey) && (arr.size() > 0))
  {
    cout << "Min Element Extracted is : " << "[ " << arr[0].key << ", " << arr[0].data << "]" << endl;
    arr[0] = arr[arr.size()-1];
    arr.erase(arr.begin() + arr.size() - 1);
    percolateDown(0); 
  }
}
