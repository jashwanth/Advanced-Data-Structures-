#include "bst.h"
#include "kdtree.h"
#include <cstring>

/*
void testcase9()
{
  cout << endl << endl << "*****Begin of Testcase9 Execution*****" << endl << endl;
  kdElem store[6];
  store[0].arr[0] = 500, store[0].arr[1] = 0, store[0].data = 1;
  store[1].arr[0] = 250, store[1].arr[1] = 250, store[1].data = 2;
  store[2].arr[0] = 375, store[2].arr[1] = 125, store[2].data = 3;
  store[3].arr[0] = 312, store[3].arr[1] = 188, store[3].data = 4;
  store[4].arr[0] = 343, store[4].arr[1] = 157, store[4].data = 5;
  store[5].arr[0] = 327, store[5].arr[1] = 173, store[5].data = 6;
  
  kdSearchTree* mykd9 = new kdSearchTree();
  for (int i = 0; i < 6; i++)
  {
    mykd9->insertIntoKdTree(new Knode(store[i]));
  }
  while (mykd9->root != NULL)
  {
    cout << endl << "root is " << "[" << mykd9->root->elem.arr[0] << "," << 
         mykd9->root->elem.arr[1] << "," << mykd9->root->elem.data << "]" << endl;
    mykd9->root = mykd9->deleteKdNode(mykd9->root, mykd9->root->elem, 0);
    cout << "Deleted the root and updated the tree" << endl;
  }
  cout << endl << endl << "*****End of Testcase9 Execution*****" << endl << endl;
}*/

void testcase8()
{
  cout << endl << endl << "*****Begin of Testcase8 Execution*****" << endl << endl;
  kdElem store[19];
  store[0].arr[0] = 0, store[0].arr[1]=0, store[0].data = 0; 
  store[1].arr[0] = 500, store[1].arr[1]=0, store[1].data = 1; 
  store[2].arr[0] = 250, store[2].arr[1]=250, store[2].data = 2;
  int i;
  for (i = 3; i <= 18; i++)
  {
    store[i].arr[0] = (store[i-1].arr[0] + store[i-2].arr[0])/2;
    store[i].arr[1] = 500 - store[i].arr[0];
    store[i].data   = i;
  }
  for (i = 13; i <= 18; i++)
  {
    store[i].arr[0] = store[i-6].arr[0];
    store[i].arr[1] = store[i-12].arr[1];
  }
  for (i = 7; i <= 12; i++)
  {
    store[i].arr[0] = store[i-6].arr[0];
  }
  cout << "Test data is : " << endl;
  for ( i= 1; i <= 18; i++)
  {
    cout << "[" << store[i].arr[0] << "," << store[i].arr[1] << "," << store[i].data << "]";
    if (i%6 == 0)cout << endl;
  }

  kdSearchTree* mykd8 = new kdSearchTree();
  mykd8->resetCounter();
  for (i = 1; i <= 18; i++)
  {
    mykd8->insertIntoKdTree(new Knode(store[i]));
  }

  i = 0;
  while (mykd8->root != NULL)
  {
    cout << endl << "root is " << "[" << mykd8->root->elem.arr[0] << "," << 
         mykd8->root->elem.arr[1] << "," << mykd8->root->elem.data << "]" << endl;
    mykd8->root = mykd8->deleteKdNode(mykd8->root, mykd8->root->elem, 0);
    cout << "Deleted the root and updated the tree" << endl;
    cout << "Searching for element " << "[" << store[i].arr[0] << "," << store[i].arr[1] << "," << store[i].data << "]"
          << " in the tree" << endl;
    if (mykd8->searchKeyInKdtree(mykd8->root, store[i]) == 1)
    {
      cout << "ELement " << "[" << store[i].arr[0] << "," << store[i].arr[1] << "," << store[i].data << "]"
           << " is present in the Kd tree" << endl;
    }
    else
    {
      cout << "ELement " << "[" << store[i].arr[0] << "," << store[i].arr[1] << "," << store[i].data << "]"
           << " is not found in the Kd tree" << endl;

    }
    /* construct t8a.dot file*/
    if (i == 5)
    {
      fstream fsa8;
      remove("t8a.dot");
      fsa8.open("t8a.dot", std::fstream::in|std::fstream::out|std::fstream::app);
      mykd8->ss << "digraph G { " << endl;
      mykd8->showDotFile(mykd8->root);
      mykd8->ss <<  "}" << endl; 
      fsa8 << mykd8->ss.str() ;
      cout << "printing the dot file when there are 12 elements in the tree " << endl;
      cout << endl << mykd8->ss.str() << endl;
      fsa8.close();
    }
    /* Construct t8b.dot file */
    if (i == 11)
    {
      fstream fsb8;
      remove("t8b.dot");
      fsb8.open("t8b.dot", std::fstream::in|std::fstream::out|std::fstream::app);
      mykd8->ss.str("");
      mykd8->ss << "digraph G { " << endl;
      mykd8->showDotFile(mykd8->root);
      mykd8->ss <<  "}" << endl; 
      fsb8 << mykd8->ss.str() ;
      cout << "printing the dot file when there are 6 elements in the tree " << endl;
      cout << endl << mykd8->ss.str() << endl;
      fsb8.close();
    }
    i++;
  //  cout << "value of i is " << i << endl;
  //  if ( i > 18)break;
  }
  cout << endl << endl << "*****End of Testcase8 Execution*****" << endl << endl;
}

void testcase7()
{
  cout << endl << endl << "*****Begin of Testcase7 Execution*****" << endl << endl;
  bstElem arr[21];
  int first = 0, last = 1000, i, flag = 0;
  arr[1].key = 1000, arr[1].data = 1;
  arr[2].key = 500; arr[2].data = 2;
  for (i = 3; i <= 20; i++)
  {
    if ( i <= 10)
    {
      arr[i].key = (arr[i-1].key + arr[i-2].key)/2;
    }
    else if(i > 10)
    {
      arr[i].key = arr[i-10].key;
    }
    arr[i].data = i;
  }
  cout << endl << "Testdata is " << endl;
  for (i = 1; i <= 20; i++)
  {
    cout << "[" << arr[i].key << "," << arr[i].data << "] ";
  }
  cout << endl;
  binarySearchTree* mybst7 = new binarySearchTree();
  mybst7->resetCounter();
  for (i = 1; i <= 20;i++)
    mybst7->insertIntoBst(new node(arr[i]));
  cout << endl << "print inorder traversal before deletion " << endl;
  mybst7->printInorderTree(mybst7->root);
  cout << endl << "end of inorder traversal before deletion " << endl;
  cout << "---------------------------------------------------------------------------------" << endl;
  cout << " stage   data item at root  the root(after deletion)     search for data with key" << endl;
  cout << "---------------------------------------------------------------------------------" << endl;
  for (i = 0; i <= 20 ;i++)
  {
    cout.width(6); cout << i;
    if (mybst7->root != NULL)
    {
      bstElem storekey = mybst7->root->elem;
      stringstream mystr;
      mystr.clear();
      mystr <<  "[" << mybst7->root->elem.key << "," << mybst7->root->elem.data << "]";
      cout.width(20); cout << mystr.str();
//      cout << mybst7->root->elem.key << "," << mybst7->root->elem.data << "]";
      mybst7->root = mybst7->deleteBstNode(mybst7->root, mybst7->root->elem);
      if (mybst7->root != NULL)
      {
        stringstream mystr2;
        mystr2.clear();
        mystr2 <<  "[" << mybst7->root->elem.key << "," << mybst7->root->elem.data << "]";
        cout.width(26); cout << mystr2.str();
        vector<bstElem> myvector;
        myvector.clear();
//      searchKeyInBst(node* cur, int key, vector<bstElem> &storeKeys);
        mybst7->searchKeyInBst(mybst7->root, storekey.key, myvector);
        stringstream mystr3;
        mystr3.clear();
        for (int j = 0; j < myvector.size(); j++)
        {
          mystr3 << "[" << myvector[j].key << "," << myvector[j].data << "]";
          flag = 1;
        }
        if (flag == 1)
        {
          flag = 0;
          cout.width(29);cout << mystr3.str();
        }
	else
	{
	  cout.width(29);cout << "nil";
	}
      }
      else
      {
	cout.width(26); cout << "nil";
	cout.width(29); cout << "nil";
      }
    }
    else
    {
      cout.width(20);cout << "nil";
      cout.width(26); cout << "nil";
      cout.width(29); cout << "nil";
    }
    /* Print dot file after stage 10 */
    if (i == 10)
    {
       fstream fs7;
       remove("t7.dot");
       fs7.open("t7.dot", std::fstream::in|std::fstream::out|std::fstream::app);
       mybst7->ss << "digraph G { " << endl;
       mybst7->showDotFile(mybst7->root);
       mybst7->ss <<  "}" << endl; 
       fs7 << mybst7->ss.str() ;
       fs7.close();
   //    cout << "Printing the tree after stage 10 " << endl;
   //    cout << endl << mybst7->ss.str() << endl;
       mybst7->ss.str("");
    }
    cout << endl;
  }
  cout << "---------------------------------------------------------------------------------" << endl;
  cout << endl << endl << "*****End of Testcase7 Execution*****" << endl << endl;
}


void testcase6()
{
  cout << endl << endl << "*****Begin of Testcase6 Execution*****" << endl << endl;
  kdElem store[16];
  int i;
  store[0].arr[0] = 0  , store[0].arr[1] = 500 - store[0].arr[0], store[0].data = 0;
  store[1].arr[0] = 500, store[1].arr[1] = 500 - store[1].arr[0], store[1].data = 1;
  for (i = 2; i <= 15; i++)
  {
    store[i].arr[0] = (store[i-1].arr[0] + store[i-2].arr[0])/2;
    store[i].arr[1] = 500 - store[i].arr[0];
    store[i].data = i;
  }
  /* Use reservoir sampling to select 10 items randomly from the above list */
  kdElem reserve[10];
  for (i = 0; i < 10; i++)
  {
    reserve[i] = store[i];
  }
  for (; i < 16; i++)
  {
    int j = rand()%(i+1);
    if ( j < 10)reserve[j] = store[i];
  }
/*  kdElem reserve[10] = {{0,500,0}, {500,0,1}, {332,168,2}, {375,125,3}, {312,188,4}, {332,168,5}, 
                        {332,168,6}, {335,165,7}, {331,169,8}, {333,167,9}};*/
  kdSearchTree* mykd6 = new kdSearchTree();
  mykd6->resetCounter();
  cout << endl << "reserve array is " << endl;
  for (int i = 0; i < 10; i++)
  {
    cout << "[" << reserve[i].arr[0] << "," << reserve[i].arr[1] << "," << reserve[i].data << "]";
    mykd6->insertIntoKdTree(new Knode(reserve[i]));
  }
  cout << endl << "print inorder traversal before deletion " << endl;
  mykd6->printInorderKdTree(mykd6->root);
  cout << endl << "end of inorder traversal before deletion " << endl;
  fstream fsa6;
  remove("6a.dot");
  fsa6.open("6a.dot", std::fstream::in|std::fstream::out|std::fstream::app);
  mykd6->ss << "digraph G { " << endl;
  mykd6->showDotFile(mykd6->root);
  mykd6->ss <<  "}" << endl; 
  fsa6 << mykd6->ss.str() ;
  fsa6.close();
  cout << endl << mykd6->ss.str() << endl;
  mykd6->ss.str("");
//  mybst5->ss.str(std::string());
  cout << "Deleting the root node.. " << endl;
  mykd6->root = mykd6->deleteKdNode(mykd6->root, mykd6->root->elem, 0);
  cout << "print inorder traversal after deletion " << endl;
  mykd6->printInorderKdTree(mykd6->root);
  fstream fsb6;
  remove("6b.dot");
  fsb6.open("6b.dot", std::fstream::in|std::fstream::out|std::fstream::app);
  mykd6->ss << "digraph G { " << endl;
  mykd6->showDotFile(mykd6->root);
  mykd6->ss <<  "}" << endl; 
  fsb6 << mykd6->ss.str();
  fsb6.close();
  cout << endl << mykd6->ss.str() << endl;
  cout << endl << "end of inorder traversal after deletion " << endl;
  cout << endl << endl << "*****End of Testcase6 Execution*****" << endl << endl;
}

void testcase5()
{
  cout << endl << endl << "*****Begin of Testcase5 Execution*****" << endl << endl;
  bstElem arr[16];
  int first = 0, last = 1000, i;
  arr[0].key = first, arr[0].data = 0;
  arr[1].key = last, arr[1].data = 1;
  for (i = 2; i <= 15; i++)
  {
    arr[i].key  = (arr[i-1].key + arr[i-2].key)/2;
    arr[i].data = i;
  }
  /* Use reservoir sampling to select 10 items randomly from the above list */
  bstElem reserve[10];
  for (i = 0; i < 10; i++)
  {
    reserve[i] = arr[i];
  }
  for (; i < 16; i++)
  {
    int j = rand()%(i+1);
    if ( j < 10)reserve[j] = arr[i];
  }
/*  for (i = 0; i < 10; i++)
  {
    cout << "[" << reserve[i].key << "," << reserve[i].data << "] ";
  }*/
  cout << endl << " Performed reservoir sampling to fetch 10 elements from List1 " << endl;
  binarySearchTree* mybst5 = new binarySearchTree();
  mybst5->resetCounter();
  for (i = 0; i < 10;i++)
    mybst5->insertIntoBst(new node(reserve[i]));

  cout << "Inorder traversal before removing root" << endl;
  mybst5->printInorderTree(mybst5->root);
  remove("5a.dot");
  fstream fsa5;
  fsa5.open("5a.dot", std::fstream::in|std::fstream::out|std::fstream::app);
  mybst5->ss << "digraph G { " << endl;
  mybst5->showDotFile(mybst5->root);
  mybst5->ss <<  "}" << endl; 
  fsa5 << mybst5->ss.str() ;
  fsa5.close();
  cout << endl << mybst5->ss.str() << endl;
//  mybst5->ss.str(std::string());
//  mybst5->ss.empty();
  mybst5->ss.str("");

  cout << endl << "Deleting the root node" << endl;
  mybst5->root = mybst5->deleteBstNode(mybst5->root, reserve[0]);
  cout << endl << "Inorder traversal after removing root" << endl;
  mybst5->printInorderTree(mybst5->root);
  remove("5b.dot");
  fstream fsb5;
  fsb5.open("5b.dot", std::fstream::in|std::fstream::out|std::fstream::app);
  mybst5->ss << "digraph G { " << endl;
  mybst5->showDotFile(mybst5->root);
  mybst5->ss <<  "}" << endl; 
  fsb5 << mybst5->ss.str() ;
  fsb5.close();
  cout << endl << mybst5->ss.str() << endl;

  cout << endl << endl << "*****End of Testcase5 Execution*****" << endl << endl;
}

void testcase4()
{
  kdSearchTree* mykd4 = new kdSearchTree();
  mykd4->resetCounter();
  kdElem elem;
  cout << endl << endl << "*****Begin of Testcase4 Execution*****" << endl << endl;
  srand(time(NULL));
  elem.arr[0] = 0, elem.arr[1]=0, elem.data = 0;
  cout << "----------------------------------------------------------------------" << endl;
  cout << "n = No. of Nodes in the tree    Height of BST T4      lg n    sqrt(n) " << endl;
  cout << "----------------------------------------------------------------------" << endl;
  for (int i = 0; i<= 200; i++)
  {
    elem.arr[0] = (rand()%50);
    elem.arr[1] = (rand()%50);
    elem.data = i;
    if (i % 20 == 0)
    {
      cout.width(28); cout << i;
      cout.width(20);cout << mykd4->heightOfKdTree(mykd4->root);
      cout.width(10);((i == 0) ? cout << "N.A." : cout << log(i));
      cout.width(11);cout << sqrt(i) << endl;
    }
    mykd4->insertIntoKdTree(new Knode(elem)); 
  }
  cout << endl << endl << "*****End of Testcase4 Execution*****" << endl << endl;
}

void testcase3()
{
/*  wchar_t *sqrootsymbol = (wchar_t *)calloc(20, sizeof(wchar_t));
  strcpy(sqrootsymbol, (wchar_t *)"\u221A");*/
//  wchar_t *sym = L"221A";
//  wstring ws(L"221A");
//  string sqrtsym(ws.begin(), ws.end());
  cout << endl << endl << "*****Begin of Testcase3 Execution*****" << endl << endl;
  cout << "----------------------------------------------------------------------" << endl;
  cout << "n = No. of Nodes in the tree    Height of BST T3      lg n    sqrt(n) " << endl;
  cout << "----------------------------------------------------------------------" << endl;
  binarySearchTree* mybst3 = new binarySearchTree();
  mybst3->resetCounter();
  bstElem elem = {0,0};
  for (int i = 0; i <= 200; i++)
  {
    if (i % 20 == 0)
    {
      cout.width(28); cout << i;
      cout.width(20);cout << mybst3->heightOfBST(mybst3->root);
      cout.width(10);((i == 0) ? cout << "N.A." : cout << log(i));
      cout.width(11);cout << sqrt(i) << endl;
    }
    elem.key = rand();
    elem.data++;
    mybst3->insertIntoBst(new node(elem));
  }
  cout << endl << endl << "*****End of Testcase3 Execution*****" << endl << endl;
}

void testcase2()
{
  kdSearchTree* mykd2 = new kdSearchTree();
  mykd2->resetCounter();
  cout << endl << endl << "*****Begin of Testcase2 Execution*****" << endl << endl;
  kdElem store[16];
  store[0].arr[0] = 0  , store[0].arr[1] = 500 - store[0].arr[0], store[0].data = 0;
  store[1].arr[0] = 500, store[1].arr[1] = 500 - store[1].arr[0], store[1].data = 1;
  for (int i = 2; i <= 15; i++)
  {
    /* New x value of element is the floor of
     average of previous two x elements 
     and y value is always 500 - xvalue as per test case */
    store[i].arr[0] = (store[i-1].arr[0] + store[i-2].arr[0])/2;
    store[i].arr[1] = 500 - store[i].arr[0];
    store[i].data = i;
  }
  for (int i = 0; i <= 15; i++)
  {
    mykd2->insertIntoKdTree(new Knode(store[i]));
  }
  cout << "print inorder traversal " << endl;
  mykd2->printInorderKdTree(mykd2->root);
  cout << endl << "end of inorder traversal " << endl;
  mykd2->ss << "digraph G { " << endl;
  mykd2->showDotFile(mykd2->root);
  mykd2->ss <<  "}" << endl; 
  remove("t2.dot");
  fstream fs2;
  fs2.open("t2.dot", std::fstream::in|std::fstream::out|std::fstream::app);
  fs2 << mykd2->ss.str() ;
  fs2.close();
  cout << endl << mykd2->ss.str() << endl;

  cout << endl << endl << "*****End of Testcase2 Execution*****" << endl << endl;
}

void testcase1()
{
  binarySearchTree* mybst1 = new binarySearchTree();
  mybst1->resetCounter();
  cout << endl << endl << "*****Begin of Testcase1 Execution*****" << endl << endl;
  /* Insert elements for n=0,1*/
  bstElem arr[16];
  int first = 0, last = 1000, i;
  arr[0].key = first, arr[0].data = 0;
  arr[1].key = last, arr[1].data = 1;
  for (i = 2; i <= 15; i++)
  {
    arr[i].key  = (arr[i-1].key + arr[i-2].key)/2;
    arr[i].data = i;
  }
  for (int i = 0; i <= 15; i++)
  {
    mybst1->insertIntoBst(new node(arr[i]));
  }
//  cout << "print inorder traversal " << endl;
  mybst1->printInorderTree(mybst1->root);
//  cout << endl << "end of inorder traversal " << endl;
  mybst1->ss << "digraph G { " << endl;
//  cout << endl << mybst1->ss.str() << endl;
  mybst1->showDotFile(mybst1->root);
  mybst1->ss <<  "}" << endl; 
  remove("t1.dot");
  fstream fs1;
  fs1.open("t1.dot", std::fstream::in|std::fstream::out|std::fstream::app);
  fs1 << mybst1->ss.str() ;
  fs1.close();
  cout << endl << mybst1->ss.str() << endl;
//  cout << endl << mybst1->ss.rdbuf() << endl;
  cout << endl << endl << "*****End of Testcase1 Execution*****" << endl << endl;
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
 // testcase9();
}
