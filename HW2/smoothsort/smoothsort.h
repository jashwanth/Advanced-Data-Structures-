#include <iostream>
#include <vector>
#include <cstdlib>
#include <bitset>
#include <algorithm>
using namespace std;

typedef struct leonardoheap
{
  int num[20];
  std::bitset<20> sb;
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
    int rightchildInd(int);
    int leftchildInd(int ,int );
    leonardoHeap();
    void smoothsort();
    void swap(int , int);
    void permute(int,int,int);
    void heapify(int);
    void insertionSortRoots(int );
    void smoothadd(int );
    void extractmin(int );
    void printtwenthelem();
};
