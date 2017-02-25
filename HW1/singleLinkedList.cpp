#include "singleLinkedList.h"

singleNode::singleNode(int item, singleNode* next)
{ 
  this->data = item;
  this->next = next;
}

int singleNode::getNodeData()
{
  return this->data;
}

singleNode* singleNode::getNextNode()
{
  return this->next;
}

void singleNode::setNodeData(int item)
{
   this->data = item;
}

void singleNode::setNextNode(singleNode* next)
{
   this->next = next;
}

void singleNode::displayData()
{
  cout << getNodeData();
}

void sll::createsll(int *arr, int num)
{
  int i = 0;
  head = NULL;
  for (i = 0; i < num; i++)
  {
    InsertAtEnd(arr[i]);
  }
}

sll::sll()
{
  head = NULL;
}

/*void sll::sortListByFour()
{
  if (head == NULL)
  {
    return;
  }
  
  singleNode* temp1  = head;
  singleNode* temp2  = NULL;
  singleNode* temp3  = NULL;
  singleNode* temp4  = NULL;
  singleNode* sorted = NULL;
  int size = 1;
  while (temp1 != NULL)
  {
    temp2 = temp1->getNextNode();
    if(temp2 != NULL)
    {
      size++;
      temp3 = temp2->getNextNode();
      if (temp3 != NULL)
      {
	size++;
        temp4 = temp3->getNextNode();
        if (temp4 != NULL)
        {
	  size++;
        }
      }
     }
    temp1 = sort(temp1, size);
    temp1 = temp1->getNextNode();
   }
}*/

/*void sll::sortListByFour()
{
  if (head == NULL)
  {
    return;
  }
  singleNode* temp1 = head;
  singleNode* temp2 = NULL;
  singleNode* temp3 = NULL;
  singleNode* temp4 = NULL;
  int sortElem[4];
  for (int i=0;i<4;i++)sortElem[i] = INT_MAX;
  int minIndex = 0;
  while (temp1 != NULL)
  {
    sortElem[0] = temp1->getNodeData();
    if ( (temp2 = temp1->getNextNode()) != NULL)
    {
      sortElem[1] = temp2->getNodeData();
      if ((temp3 = temp2->getNextNode()) != NULL)
      {
	sortElem[2] = temp3->getNodeData();
	if ((temp4 = temp3->getNextNode()) != NULL)
	{
	  sortElem[3] = temp4->getNodeData();
	}
      }
    }
    for (int i = 0; i < 4; i++)
    {
      minIndex = i;
      for (int j = i+1; j < 4; j++)
      {
	if (sortElem[j] <= sortElem[minIndex])
	{
	  minIndex = j;
	}
      }
      int swap = sortElem[i];
      sortElem[i] = sortElem[minIndex];
      sortElem[minIndex] = swap;
    }
    temp1->setNodeData(sortElem[0]);
    if (temp2 != NULL)
    {
      temp2->setNodeData(sortElem[1]);
    }
    if (temp3 != NULL)
    {
      temp3->setNodeData(sortElem[2]);
    }
    if (temp4 != NULL)
    {
      temp4->setNodeData(sortElem[3]);
    }
    for (int i =0; i< 4; i++)sortElem[i] = INT_MAX ;
    if (temp4 != NULL)temp1 = temp4->getNextNode();
    else
    {
      if (temp3 != NULL)temp1 = temp3->getNextNode();
      else
      {
	if (temp2 != NULL)temp1 = temp2->getNextNode();
	else break;
      }
    }
    temp2 = NULL;
    temp3 = NULL;
    temp4 = NULL;
  }
}*/
int sll::ListLength()
{
  int length = 0;
  if (head == NULL)
  {
    return length;
  }
  singleNode* temp = head;
  while(temp != NULL)
  {
    temp = temp->getNextNode();
    length++;
  }
  return length;
}

void sll::shuffleSll()
{
  if (head == NULL)return;
  int len = ListLength();
  if (len == 1)return;

  int k =  ((len%2) == 0) ? len/2: (len+1)/2, i = 0, j = 0;
  singleNode *temp1 = head;
  singleNode *temp2 = head;
  singleNode *temp3 = head;
  
  while ((i < k) && (temp1 != NULL)) 
  {
    temp2 = temp1;
    temp1 = temp1->getNextNode();
    i++;
  }

//  cout << "kth elem is " << temp1->getNodeData() << " " << endl;
 
  while ((temp1 != NULL) && (temp3 != NULL) && (temp2 != NULL))
  {
   temp2->setNextNode(temp1->getNextNode());
   temp1->setNextNode(temp3->getNextNode());
   temp3->setNextNode(temp1);
   temp3 = temp1->getNextNode();
   temp1 = temp2->getNextNode();
  }
  
}

/* Sort all len nodes from cur node and return the start
 of sorted list */
void sll::mySort(int pos, int len)
{
  singleNode* cur = ReturnKthNode(pos);
  if(cur == NULL)return;
  int i, j, index;
  singleNode *temp1 = NULL;
  singleNode *temp2 = NULL;
  singleNode *temp3 = NULL;
  singleNode *temp4 = NULL;
  singleNode *temp5 = NULL;
  singleNode *temp6 = NULL;

  for(i = 0; i < len; i++)
  {
    temp1 = ReturnKthNode(i+pos);
    index = i;
    for ( j = i+1; j < len; j++)
    {
      temp2 = ReturnKthNode(j+pos);
      if ((temp1 != NULL) && (temp2 != NULL) && (temp2->getNodeData() < temp1->getNodeData()))
      {
	index = j;
	temp1 = ReturnKthNode(index+pos);
      }
    }
     /* swap at i and index */
    temp1 = ReturnKthNode(i+pos);
    temp2 = ReturnKthNode(index+pos);
    temp3 = ReturnKthNode(index+pos-1);
    temp4 = ReturnKthNode(i+pos-1);
    temp5 = ReturnKthNode(pos+index+1);
    temp6 = ReturnKthNode(pos+i+1);
    
    /*-------currentNode--------------SwapNode-------- 
               ^                        ^               
               |                        |               
     temp4->temp1->temp6->.....temp3->temp2->temp5->..... */
    /*Make the previous of index node next as current Node */
    if (temp3 != NULL) 
    {
      /*To prevent pointing back to same node causing loop */
      if (temp3 != temp1)
	temp3->setNextNode(temp1);
    }
    /*Make the next of current node as next of index Node */
    if (temp1 != NULL) 
      temp1->setNextNode(temp5);
    /*Make the next of previous Node of current as index Node */
    if (temp4 != NULL) temp4->setNextNode(temp2);
    /*Make the next of index Node as next of current Node */
    if (temp2 != NULL) 
    {
      /*To prevent pointing back to same node causing loop */
      if (temp2 != temp6)temp2->setNextNode(temp6);
    }
    if ((temp1 != NULL) && (temp2 != NULL))
    {
      /* Special case when temp1= temp3 and temp2= temp6 this logic is
	 needed to not break the chain */
      if ((temp1 == temp3) && (temp2 == temp6))
	temp2->setNextNode(temp1);
    }
    if (i == 0)
    {
      cur = temp2;
      if (pos == 0)head = cur;
    }
  }
  /* We always mantain start of list 
   so if this is the first time sort is called 
   modify head to the sorted list */
  if (pos == 0)
  {
    head = cur;
  }
 // if (ReturnKthNode(i-1)) ReturnKthNode(i-1)->setNextNode(ReturnKthNode(i));
}


void sll::reverseSll()
{
  if (head == NULL)return;
  singleNode *temp1 = head;
  singleNode *temp2 = NULL;
  singleNode *temp3 = NULL;
  while (temp1 != NULL)
  {
    temp2 = temp1;
    temp1 = temp1->getNextNode();
    temp2->setNextNode(temp3);
    temp3 = temp2;
  }
  head = temp2;
}

void sll::InsertAtStart(int data)
{
  singleNode *newNode = new singleNode(data, NULL);
  if (head == NULL)
  {
    head = newNode;
    return;
  }
  else
  {
    newNode->setNextNode(head);
    head = newNode;
  }
}

void sll::InsertAtEnd(int data)
{
  singleNode* newNode = new singleNode(data, NULL);
  singleNode* temp = head;
  
  if (temp == NULL)
  {
    head = newNode;
    return;
  }

  while (temp->getNextNode() != NULL)
  {
    temp = temp->getNextNode();
  }
  
  temp->setNextNode(newNode);
}

/* Return node which is len away from head node
 if len is less than zero return null */
singleNode* sll::ReturnKthNode(int len)
{
  int i = 0;
  singleNode* temp = head;
  if (len < 0)
  {
    return NULL;
  }
  while ((i < len) && (temp != NULL)) temp = temp->getNextNode(),i++;
  return temp;
}


void sll::printList()
{
 singleNode* temp = head;
 if (temp == NULL)
 {
   cout << "==============" << endl;
   cout << "Empty list...." << endl;
   cout << "==============" << endl;
 }
 cout << "Head --> ";
 while(temp != NULL)
 {
   temp->displayData();
   cout << " --> ";
   temp = temp->getNextNode();
   if (temp == NULL)
   {
     cout << "NULL" << endl;
   }
 }
 cout << endl;
}

void sll::printFirstHalfByFour()
{
  singleNode *temp = head;
  if (temp == NULL)
  {
    cout << "==============" << endl;
    cout << "Empty list...." << endl;
    cout << "==============" << endl;
  }
  int len = ListLength(), i = 0, fourElemCount = 0;
  int firsthalf = ( (len%2)==0  ? (len/2) : (len+1)/2 );
  while( (i < firsthalf)) 
  {
    temp->displayData();
    cout << ",";
    fourElemCount++;
    i++;
    if (fourElemCount == 4)
    {
      fourElemCount = 0;
      cout << endl;
    }
    temp = temp->getNextNode();
  }
}

void sll::printSecondHalfByFour()
{
  singleNode *temp = head;
   
  if (temp == NULL)return;
  int len = ListLength(), i = 0, fourElemCount = 0;
  int firsthalf = ( (len%2)==0  ? (len/2) : (len+1)/2 );
  int secondhalf = len - firsthalf;
  while ( i < firsthalf)i++, temp = temp->getNextNode();
  i = 0;
  while (( i < secondhalf) && (temp != NULL))
  {
    temp->displayData();
    cout << ",";
    fourElemCount++;
    i++;
    if (fourElemCount == 4)
    {
      fourElemCount = 0;
      cout << endl;
    }
    temp = temp->getNextNode(); 
  }
}

void sll::printListByFour()
{
  singleNode *temp = head;
  int fourElemCount = 0;

  if (temp == NULL)
  {
    cout << "==============" << endl;
    cout << "Empty list...." << endl;
    cout << "==============" << endl;
  }

  while ((temp != NULL))
  {
    temp->displayData();
    cout << ",";
    fourElemCount++;
    if (fourElemCount == 4)
    {
      fourElemCount = 0;
      cout << endl;
    }
    temp = temp->getNextNode();
  }
  
}


/*int main()
{
  int tc, data, i = 0;
  sll mysll;
  singleNode *temp1 = NULL;
  singleNode *temp2 = NULL;
  cin >> tc;
  while(tc -- )
  {
    cin >> data;
    mysll.InsertAtEnd(data);
//    mysll.printList();
  }
  
  cout << "****Before Single linkedlist Reverse operation ********" << endl;
  mysll.printListByFour();
  cout << endl << endl;

  cout << "****After Single linkedlist Reverse operation********" << endl;
  mysll.reverseSll();
  mysll.printListByFour();
  cout << endl << endl;
  
  cout << "****Before single linkedlist Shuffle operation*****" << endl;
  mysll.printListByFour();
  cout << endl << endl;

  cout << "****After single linkedlist Shuffle operation*****" << endl;
  mysll.shuffleSll();
  mysll.printListByFour();
  cout << endl << endl;
  
  cout << "****Before single linked list Four Operation*****" << endl;
  mysll.printListByFour();
  cout << endl << endl;
  
  cout << "****After single linked list Four Operation*****" << endl;
  int len = mysll.ListLength();
  // split the elements by 4 each and send to sort function 
  while ( i < len)
  {
    mysll.mySort(i, 4);
    i += 4;
  }
//  mysll.sortListByFour();
  mysll.printListByFour();
  cout << endl << endl;

//  singleNode node1 (5, NULL);
//  singleNode node2 (10, &node1);
//  singleNode *ptr1;
//  ptr1 = new singleNode(15, &node2);
//  ptr1->displayData();
//  ptr1->setNodeData(20);
//  ptr1->displayData();
//  ptr1->getNextNode()->displayData();
//  ptr1->setNextNode(&node1);
//  ptr1->getNextNode()->displayData();
//  ptr1->getNextNode()->getNextNode()->displayData();
//  node1.displayData();
//  node2.displayData();
  return 0;
}*/
