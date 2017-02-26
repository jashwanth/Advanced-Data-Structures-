#include "minheapPQ.h"
#include "smoothsort.h"

void testcase10()
{
  leonardoHeap *myleo = new leonardoHeap();
  cout << endl << endl << "*****Begin of Testcase10 Execution*****" << endl << endl;
  for (int i = 1; i <= 5166 ;i++)
  {
    myleo->arr.push_back(rand()%10000);
  }
  myleo->smoothsort();
  cout << "Total number of comparisons among elements performed = " << myleo->comp << endl;
  myleo->printtwenthelem();
  cout << endl << endl << "*****End of Testcase10 Execution*****" << endl;

}

void testcase9()
{
  leonardoHeap *myleo = new leonardoHeap();
  cout << endl << endl << "*****Begin of Testcase9 Execution*****" << endl << endl;
  for (int i = 1; i <= 3193 ;i++)
  {
    myleo->arr.push_back(rand()%10000);
  }
  myleo->smoothsort();
  cout << "Total number of comparisons among elements performed = " << myleo->comp << endl;
  myleo->printtwenthelem();
  cout << endl << endl << "*****End of Testcase9 Execution*****" << endl;
}

void testcase8()
{
  leonardoHeap *myleo = new leonardoHeap();
  cout << endl << endl << "*****Begin of Testcase8 Execution*****" << endl << endl;

  for (int i = 1; i <= 2000 ;i++)
  {
    myleo->arr.push_back(i);
  }

  for (int i = 0; i < 20; i++)
  {
    int swap1 = rand()%1000;
    int swap2 = rand()%1000;
    int swap3 = rand()%1000;
    cout << "Before permuting arr[" << swap1 << "] = " << myleo->arr[swap1] << ",  arr["
      <<  swap2 << "] = " << myleo->arr[swap2] << ", arr["
      <<  swap3 << "] = " << myleo->arr[swap3] << endl;
    myleo->permute(swap1, swap2, swap3);
    cout << "After permuting arr[" << swap1 << "] = " << myleo->arr[swap1] << ",  arr[" 
      <<  swap2 << "] = " << myleo->arr[swap2] << ", arr["
      <<  swap3 << "] = " << myleo->arr[swap3] << endl;
  }
  myleo->smoothsort();
  cout << "Total number of comparisons among elements performed = " << myleo->comp << endl;
  myleo->printtwenthelem();
  cout << endl << endl << "*****End of Testcase8 Execution*****" << endl;
}

void testcase7()
{
  leonardoHeap *myleo = new leonardoHeap();
  cout << endl << endl << "*****Begin of Testcase7 Execution*****" << endl << endl;
  for (int i = 1; i <= 2000 ;i++)
  {
    myleo->arr.push_back(i);
  }
  /* Randomly select 20 numbers between 1 and 2000
     swap i1, i2 
     swap i3, i4 etc.. */  
  for (int i = 0; i < 10; i++)
  {
    int swap1 = rand()%2000;
    int swap2 = rand()%2000;
    cout << "swapping arr[" << swap1 << "] = " << myleo->arr[swap1] << ",  arr[" <<  swap2 << "] = " 
      << myleo->arr[swap2] << endl;
    myleo->swap(swap1, swap2);
    //  cout << "swapping arr[" << swap1 << "] = " << myleo->arr[swap1] << ",  arr[" <<  swap2 << "] = " 
    //       << myleo->arr[swap2] << endl;
  }
  myleo->smoothsort();
  cout << "Total number of comparisons among elements performed = " << myleo->comp << endl;
  myleo->printtwenthelem();
  cout << endl << endl << "*****End of Testcase7 Execution*****" << endl;
}


void testcase6()
{
  leonardoHeap *myleo = new leonardoHeap();
  cout << endl << endl << "*****Begin of Testcase6 Execution*****" << endl << endl;
  for (int i = 1000; i>=1 ;i--)
  {
    myleo->arr.push_back(i);
  }
  myleo->smoothsort();
  cout << "Total number of comparisons among elements performed = " << myleo->comp << endl;

  /* for (int i = 0; i < myleo->arr.size(); i++ )
     {
     cout << myleo->arr[i] << " ";
     }
     cout << endl;*/
  myleo->printtwenthelem();
  cout << endl << endl << "*****End of Testcase6 Execution*****" << endl;
}


void testcase5()
{
  cout << endl << endl << "*****Begin of Testcase5 Execution*****" << endl;
  priority_queue mypq5;
  /*  int testcase = 1;
      cout << endl << "Inserting 100 random elements [i, j] 10 <= i,j <= 100 to PQ" << endl;
      while (testcase <= 100)
      {
      element newdata;
      newdata.key = 10 + (rand() % 91);*/
  /* Generate random numbers between 10 and 100 
     newdata.data = rand() % 100;
     cout << "[" << newdata.key << ", " << newdata.data << "]";
     (testcase == 100) ? cout << endl << endl : cout << " ";
     mypq.insert(newdata);
     testcase++;
     } */
  cout << endl << "Performing 100 Random Operations on PQ " << endl;
  for (int i = 1; i <= 100; i++)
  {
    int operation = rand() % 4;
    if (operation == 0)
    {
      cout << endl <<  "#" << i << ": " << "Insert Operation" << endl;
      element newdata;
      newdata.key  = rand() % 100;
      newdata.data = rand() % 100;
      cout << "Inserting random element : " << "[" << newdata.key << ", "
	<< newdata.data << "]" << "to PQ " << endl; 
      mypq5.insert(newdata);
    }
    if (operation == 1)
    {
      cout << endl << "#" << i << ": " << "AllMin Operation" << endl;
      mypq5.AllMinOp(0);
    }
    if (operation == 2)
    {
      cout <<  endl << "#" << i << ": " << "Extract-All-Min Operation" << endl;
      mypq5.ExtractMinAll();
    }
    if (operation == 3)
    {
      cout << endl << "#" << i << ": " << "Decrease-Key Operation" << endl;
      if (mypq5.arr.empty())continue;
      int randIndex = rand() % mypq5.arr.size();
      cout << " Decreasing the key of random element: " << "[" << mypq5.arr[randIndex].key << ", " 
	<< mypq5.arr[randIndex].data << "]" << endl;
      if ((mypq5.arr[0].key != 0))
      {
	mypq5.arr[randIndex].key = rand() % (mypq5.arr[0].key);
      }
      else
      {
	mypq5.arr[randIndex].key = 0; 
      }
      cout << "New Element after changing key is: " << "[" << mypq5.arr[randIndex].key << ", " 
	<< mypq5.arr[randIndex].data << "]" << endl;
      mypq5.percolateUp(randIndex);
    }
    if (i %20 == 0)
    {
      cout << endl << endl << "Printing the list after 20 operations " << endl;
      mypq5.print();
    }
  }

  cout << endl << endl << "*****End of Testcase5 Execution*****" << endl;

}

void testcase4()
{
  cout << endl << endl << "*****Begin of Testcase4 Execution*****" << endl;
  priority_queue mypq4;
  int testcase = 1;
  cout << endl << "Inserting 500 random elements to PQ" << endl;
  while (testcase <= 500)
  {
    element newdata;
    newdata.key = (rand() % 991); /* Generate random numbers between 0 and 990 */
    newdata.key += 10; /* Generate random numbers between 10 and 1000 */
    newdata.data = 10 + (rand() % 991);
    cout << "[" << newdata.key << ", " << newdata.data << "]";
    (testcase == 500) ? cout << endl << endl : cout << " ";
    mypq4.insert(newdata);
    testcase++;
  }
  cout << endl << "Performing 10 Decrease-Key Operation on PQ " << endl;
  for (int i = 1; i <= 10; i++)
  {
    cout << endl << "#" << i <<": " << "Performing Decrese-Key Operation" << endl;
    int randIndex = rand() % 500; /* Randomly select index from 0 to 499 */
    int randKey = rand()%10; /* Generate key between 0 to 9 */
    cout << " Decreasing the key of random element: " << "[" << mypq4.arr[randIndex].key << ", " 
      << mypq4.arr[randIndex].data << "]" << endl;
    mypq4.arr[randIndex].key = randKey;
    cout << "New Element after changing key is: " << "[" << mypq4.arr[randIndex].key << ", " 
      << mypq4.arr[randIndex].data << "]" << endl;
    mypq4.percolateUp(randIndex);
  }

  cout << endl << "Performing 10 Extract-Min Operations on PQ " << endl;
  for (int i = 1; i <= 10; i++)
  {
    cout << endl << "#" << i <<": " << "Performing Extract-All-Min Operation" << endl;
    mypq4.ExtractMinAll();
  }

  cout << endl << endl << "*****End of Testcase4 Execution*****" << endl;
}



void testcase3()
{
  cout << endl << endl << "*****Begin of Testcase3 Execution*****" << endl;
  priority_queue mypq3;
  int testcase = 1;
  cout << "Inserting 500 random elements to PQ" << endl;
  while (testcase <= 500)
  {
    element newdata;
    newdata.key = (rand() % 991); /* Generate random numbers between 0 and 990 */
    newdata.key += 10; /* Generate random numbers between 10 and 1000 */
    newdata.data = 10 + (rand() % 991);
    cout << "[" << newdata.key << ", " << newdata.data << "]";
    (testcase == 500) ? cout << endl << endl : cout << " ";
    mypq3.insert(newdata);
    testcase++;
  }
  cout << endl << "Applying Extract-all-min Operation 5 times " << endl;
  for (int i = 1 ; i<=  5; i++)
  {
    cout << endl << "#" << i << ": " << "Applying the Extract-All-Min operation to PQ" << endl;
    mypq3.ExtractMinAll();
  }
  int randIndex = rand() % 495;
  cout << endl << "Randomly select an element from PQ [" <<  mypq3.arr[randIndex].key << ", ";
  cout << mypq3.arr[randIndex].data << "]" << endl;
  mypq3.arr[randIndex].key = 5;
  cout << endl << "Reducing the key to 5 [" << mypq3.arr[randIndex].key << ", ";
  cout << mypq3.arr[randIndex].data << "]" << endl;
  mypq3.percolateUp(randIndex);
  cout << endl << "Applying the All-Min operation to PQ" << endl;
  mypq3.AllMinOp(0);
  cout << endl << endl << "*****End of Testcase3 Execution*****" << endl;
}





void testcase2()
{
  cout << endl << endl << "*****Begin of Testcase2 Execution*****" << endl;
  priority_queue mypq2;
  cout << endl << "Inserting the below elements to the PQ" << endl;
  int key = 1000, val = 1;
  while (val <= 1000)
  {
    element newdata;
    newdata.key = key;
    newdata.data = val;
    cout << "[" << key << ", " << val << "]";
    (val == 1000) ? cout << endl << endl : cout << " ";
    key--, val++;
    mypq2.insert(newdata);
  }
  //  mypq.print();
  cout << endl << endl;
  cout << "Applying the Extract-All-Min operation to PQ" << endl;
  mypq2.ExtractMinAll();
  //  mypq.print();
  key = 1, val = 1;
  cout << endl << "Inserting the below elements to the PQ" << endl;
  while (val <= 30)
  {
    element newdata;
    newdata.key = key;
    newdata.data = val;
    mypq2.insert(newdata);
    cout << "[" << key << ", " << val << "]" ;
    (val == 30) ? cout << endl : cout << "  ";
    val++;
  }
  //  mypq.print();
  /*  cout << "Applying the All-Min operation to PQ" << endl;
      mypq.AllMinOp(0);*/
  cout << endl << "Applying the Extract-All-Min operation to PQ" << endl;
  mypq2.ExtractMinAll();
  //  mypq.print();
  cout << endl << "Applying the All-Min operation to PQ" << endl;
  mypq2.AllMinOp(0);
  cout << endl << endl << "*****End of Testcase2 Execution*****" << endl;

}

void testcase1()
{
  cout << endl << endl << "*****Begin of Testcase1 Execution*****" << endl;
  priority_queue mypq1;
  cout << endl << "Inserting the below elements to the PQ" << endl;
  int key = 100, val = 1;
  while (val <= 100)
  {
    element newdata;
    newdata.key = key;
    newdata.data = val;
    cout << "[" << key << ", " << val << "]" ;
    (val == 100) ? cout << endl : cout << "  ";
    key--, val++;
    mypq1.insert(newdata);
  }
  //  mypq.print();
  cout << endl << endl;
  cout << "Applying the Extract-All-Min operation to PQ" << endl;
  mypq1.ExtractMinAll();
  //  mypq.print();
  cout << endl << endl << "Inserting the data [1,0] to the PQ" << endl;
  elem temp1;
  temp1.key = 1, temp1.data = 0;
  mypq1.insert(temp1);
  //  mypq.print();
  cout << endl << "Applying the Extract-All-Min operation to PQ" << endl;
  mypq1.ExtractMinAll();
  //  mypq.print();
  cout << endl << endl << "*****End of Testcase1 Execution*****" << endl;

}

int main()
{
  testcase1();
  testcase2();
  testcase3();
  testcase4();
  testcase5();
  testcase6();
  testcase7();
  testcase8();
  testcase9();
  testcase10();
}
