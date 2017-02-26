#include <iostream>
#include <vector>
#include <cstdlib>
#include <bitset>
using namespace std;

int comparison = 0;

typedef struct leonardoheap
{
  int num[20];
  std::bitset<20> sb;
  int smallsize;
}ll;

int rightchildInd(int index, ll *lh)
{
  return index-1;
}

int leftchildInd(int index, ll *lh, int size)
{
  return rightchildInd(index, lh) - lh->num[size-2];
}

void leonardoInit(ll *lh)
{
  for (int i = 0; i < 20; i++)
  {
    if ((i == 0) || (i == 1))lh->num[i] = 1;
    else lh->num[i] = lh->num[i-1] + lh->num[i-2] + 1;
    lh->sb[i] = 0;
  }
  lh->smallsize = 0;
}

void swap(vector<int>&arr, int i, int j)
{
  comparison++;
  int temp = arr[i];
  arr[i] = arr[j];
  arr[j] = temp;
}

void heapify(int index, vector<int>& arr, ll *lh)
{
  int size = lh->smallsize;
  int swapIndex = index;
  int sizechange = 0;
  while (size > 1)
  {
    int leftchild = leftchildInd(index, lh, size);
    int rightchild = rightchildInd(index, lh);
    int largechild = index;
    if ((leftchild >= 0) && (rightchild >= 0))
    {
      /* swap root with bigger of left and right and continue */
      (arr[rightchild] > arr[leftchild] ) ? (swapIndex = rightchild, sizechange = size-2) :
	                                    (swapIndex = leftchild, sizechange = size-1);
      if (arr[index] > arr[swapIndex])return;
      else
      {
         swap(arr, index, swapIndex);
	 size = sizechange;
	 index = swapIndex;
      }
    }
  }
}

void insertionSortRoots(int index, vector<int>&arr, ll *lh)
{
  ll newlh = *lh;
  while (1)
  {
    /* If the new heap formed is same as size of smallest heap size
     simply return */
    if ((index == (newlh.num[newlh.smallsize]-1)))
      break;
    int largeInd = index;
    if (newlh.smallsize > 1) {
      int rightchild = rightchildInd(index, &newlh);
      int leftchild = leftchildInd(index, &newlh, newlh.smallsize);
      if (leftchild >= 0)
      {
        if (arr[leftchild] > arr[index])
        {
	  largeInd = leftchild;
        }
      }
      if (rightchild >= 0)
      {
        if (arr[rightchild] > arr[largeInd])
        {
	  largeInd = rightchild;
        }
      }
    }
    int previousroot = index - newlh.num[newlh.smallsize];
    /* If the previous root is greater than current root
       and its children swap them */
    if (previousroot < 0)break;
    if (arr[previousroot] < arr[largeInd])break;
    
    swap(arr, previousroot, index);

    index = previousroot;
    /* Now if our bitset contains any trailing zeros we 
       remove them to get to the root of prior tree */
    do
    {
      newlh.sb >>= 1;
      newlh.smallsize++;
    }while(newlh.sb[0] == 0);
  }
  /* end of while loop
   now we need to heapify only the last tree 
   that is partly heapified (except the root) */
  heapify(index, arr, &newlh);
}

void smoothadd(int index, vector<int>& arr, ll *lh)
{
  /* Initially empty add one element */
  if (lh->sb[0] == 0)
  {
    lh->sb[0] = 1;
    lh->smallsize = 1;
  }
  else if (lh->sb[0] && lh->sb[1])
  {
    lh->sb >>= 2;
    lh->sb[0] = 1;
    lh->smallsize += 2; /*we are merging two lower levels with this */
  }
  else if (lh->smallsize == 1)
  {
    lh->sb <<= 1;
    lh->sb[0] = 1;
    lh->smallsize = 0;
  }
  else
  {
    lh->sb <<= lh->smallsize-1;
    lh->sb[0] = 1;
    lh->smallsize = 1;
  }
  /* Go for optimisation 
   If the new element added becomes a part of some
   final heap then no need of applying insertion sort alogrithm
   immediately, just heapify the heap and continue . */
  /* To findout if the element will be part of bigger heap
   we can check that if the number of elements that are yet left to be added 
   into the heap is greater than leonum[smallsize]+1 then we
   will merge leonum[smallsize] , leonum[smallsize+1] to a new heap . In
   this case we apply insertion sort on the roots of heaps since
   we have a new heap formed just now. */
  /* */
  if (((lh->smallsize == 0) && (index == arr.size()-1)) || 
      ((lh->smallsize == 1) && 
       ((index == arr.size()-1) || ((index == arr.size()-2) && (lh->sb[1] == 0)))) || 
      ((lh->smallsize > 1) && ((arr.size() - index-1) < (lh->num[lh->smallsize-1] + 1))))
  {
    /*if index is last element or
      index is last before element and its not leo tree of size 1 or
     the number of elements after index are not enough so that
     num[smallsize] and num[smallsize-1] and extra element are not
     present to form them as heap , in all these cases 
     last heap is already formed , so apply thr insertion sort before
     heapifying */
     insertionSortRoots(index, arr, lh);
  }
  else
  {
     heapify(index, arr, lh);
  }
}

void extractmin(int index, vector<int>&arr, ll* lh)
{
  if (index < 0)return;
  cout << " min extracted: " << arr[index] << endl;
//  arr.erase(arr.begin()+index);
  if (lh->smallsize <= 1)
  {
    do
    {
      lh->sb >>= 1;
      lh->smallsize++;
    }while(lh->sb.any() && (lh->sb[0]==0));
    return;
  }
  /* Here smallest tree is >= 2 
     After we split we get two child trees left tree and right tree.
     First we need to maintain heap property(including on roots) on left child 
     and then go for right child . */
  int storesize = lh->smallsize;
  lh->sb[0] = 0;
  lh->sb <<= 2;
  lh->sb[0] = 1, lh->sb[1]=1;
  lh->smallsize -= 2;

  int leftchild  = leftchildInd(index, lh, storesize);
  int rightchild = rightchildInd(index, lh);
  ll newlh = *lh;

  /* Since the smallsize corresponds to right 
   tree and we have to increment the size by 1 
   to get order of left tree which is smallest
   by leonardo heap property. */
  newlh.smallsize++;
  /* Now right shift to remove the right child
   tree so that left tree is at position zero. */
  newlh.sb >>= 1;

  /* First we maintain heap on the left child tree
     we pretend as if there is no right tree and 
     then we perform heapify on the right tree */
  insertionSortRoots(leftchild, arr, &newlh);
//  heapify(leftchild, arr, &newlh);
  /* now heapify the right tree with the 
     original leonardo heap structure */
  insertionSortRoots(rightchild, arr, lh);
//  heapify(rightchild, arr, lh);

}


void smoothsort(vector<int> &arr)
{
  ll lh;
  leonardoInit(&lh);
  for (int i = 0; i < arr.size(); i++)
  {
    smoothadd(i , arr, &lh);
  }
  for (int i = arr.size()-1; i >= 0; i--)
  {
    extractmin(i, arr, &lh);
  }
/*  for (int i = 0; i < arr.size(); i++)
  {
    cout << arr[i];
    (i == arr.size()-1) ? cout << endl : cout << " ";
  }
  for (int i = 0; i < 20; i++)
  {
    cout << "Leonardo #" << i << " " << lh.num[i] << endl;
  }
  for (int i = 0; i < 20; i++)
  {
    cout << "Bit set #" << i << " " << lh.sb[i] << endl;
  } */
}

void testcase1()
{
  cout << endl << endl << "*****Begin of Testcase1 Execution*****" << endl;
  vector<int> arr;
  for (int i = 10; i>0 ;i--)
  {
    arr.push_back(i);
  }
  smoothsort(arr);
  cout << "totla comp = " << comparison << endl;

  for (int i = 0; i < arr.size(); i++ )
  {
    cout << arr[i] << " ";
  }
  cout << endl;
}

int main()
{
  testcase1();
}
