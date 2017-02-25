#include <iostream>
#include <vector>
#include <cstdlib>
#include <bitset>
#include <algorithm>
using namespace std;

typedef struct leonardoheap
{
  /*To store the leonardo numbers in the array */
  int num[20];
  /* This contains bit information about the current heaps
   of leonardo sequence . For Example if bitset[0] = 1 
   and bitset[1] = 1 , bitset[3] = 1. The current sequence has
   3 heaps of order size 0 , 1, and 3 respectively .*/
  std::bitset<20> sb;
  /* To store the information of the smallest heap size */
  int smallsize;
}ll;

class leonardoHeap
{
  public:
  /* To check total number of comparisions */
    int comp;
    vector<int> arr;
    ll lh; /*leonardo heap structure to store information about heap size 
	    and extract root information from them */
    /* To get the rightchild of root of a heap */
    int rightchildInd(int);
    /* To get the left child of root of heap */
    int leftchildInd(int ,int );
    /* Default constructor */
    leonardoHeap();
    /* Apply smoothsort alogirthm */
    void smoothsort();
    /* Generic swap to swap two elements with their indices */
    void swap(int , int);
    /* Permute 3 elements to get the new permutation */
    void permute(int,int,int);
    /* heapify the current heap based on index */
    void heapify(int);
    /* Always maitain sequence property of the roots */
    void insertionSortRoots(int );
    /* Add the new element to the current heap and maitain 
     sequene property of heaps, heap property on each heap */
    void smoothadd(int );
    /* Extract min element */
    void extractmin(int );
    /* print every 20 elements if the array is big */
    void printtwenthelem();
};
