#include "doubleLinkedList.h"
doubleNode::doubleNode(int item, doubleNode* prev, doubleNode* next)
{ 
  this->data = item;
  this->prev = prev;
  this->next = next;
}

int doubleNode::getNodeData()
{
  return this->data;
}

doubleNode* doubleNode::getPrevNode()
{
  return this->prev;
}

doubleNode* doubleNode::getNextNode()
{
  return this->next;
}

void doubleNode::setNodeData(int item)
{
   this->data = item;
}

void doubleNode::setPrevNode(doubleNode* prev)
{
   this->prev = prev;
}

void doubleNode::setNextNode(doubleNode* next)
{
   this->next = next;
}

void doubleNode::displayData()
{
  cout << getNodeData();
}

dll::dll()
{
  head = NULL;
}

void dll::createdll(int *arr, int num)
{
  int i = 0;
  head = NULL;
  for ( i = 0; i < num ; i++)
  {
    InsertAtEnd(arr[i]);
  }
}

int dll::ListLength()
{
  int length = 0;
  if (head == NULL)
  {
    return length;
  }
  doubleNode* temp = head;
  while(temp != NULL)
  {
    temp = temp->getNextNode();
    length++;
  }
  return length;
}

/* Return node which is len away from head node
   if len is less than zero return null */
doubleNode* dll::ReturnKthNode(int len)
{
  int i = 0;
  doubleNode* temp = head;
  if (len < 0)
  {
    return NULL;
  }
  while ((i < len) && (temp != NULL)) temp = temp->getNextNode(),i++;
  return temp;
}


/*void dll::sortListByFour()
{
  if (head == NULL)
  {
    return;
  }
  doubleNode* temp1 = head;
  doubleNode* temp2 = NULL;
  doubleNode* temp3 = NULL;
  doubleNode* temp4 = NULL;
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

void dll::mySort(int pos, int len)
{
  doubleNode* cur = ReturnKthNode(pos);
  if(cur == NULL)return;
  int i, j, index;
  doubleNode *temp1 = NULL;
  doubleNode *temp2 = NULL;
  doubleNode *temp3 = NULL;
  doubleNode *temp4 = NULL;
  doubleNode *temp5 = NULL;
  doubleNode *temp6 = NULL;

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
    temp3 = temp4 = temp5 = temp6 = NULL;
    if (temp2 != NULL)temp3 = temp2->getPrevNode();
    if (temp1 != NULL)temp4 = temp1->getPrevNode();
    if (temp2 != NULL)temp5 = temp2->getNextNode();
    if (temp1 != NULL)temp6 = temp1->getNextNode();

    /*-------currentNode---------------------SwapNode-------- 
                 ^                               ^               
                 |                               |               
    temp4 <=> temp1 <=> temp6 <=>.....temp3 <=> temp2 <=> temp5 <=>..... */
    /*Make the previous of index node next as current Node 
     and prev of current node resp */
    if (temp3 != NULL) 
    {
      /*To prevent pointing back to same node causing loop */
      if ((temp3 != temp1) && (temp1 != NULL))
	temp3->setNextNode(temp1);
    }
    if (temp1 != NULL)
    {
      if (temp1 != temp3)
       temp1->setPrevNode(temp3);
      temp1->setNextNode(temp5);
    }
    /*Make the next of current node as next of index Node */
    if (temp5 != NULL)temp5->setPrevNode(temp1);
    /*Make the next of previous Node of current as index Node */
    if (temp4 != NULL) 
    {
      temp4->setNextNode(temp2);
    }
    /*Make the next of index Node as next of current Node */
    if (temp2 != NULL)
    {
      temp2->setPrevNode(temp4);
      /*To prevent pointing back to same node causing loop */
      if (temp2 != temp6)
      {
        temp2->setNextNode(temp6);
      }
    }
    if (temp6 != NULL)
    {
      if (temp2 != temp6)
      {
        temp6->setPrevNode(temp2);
      }
    }
    if ((temp1 != NULL) && (temp2 != NULL))
    {
      /* Special case when temp1= temp3 and temp2= temp6 this logic is
	 needed to not break the chain */
      if ((temp1 == temp3) && (temp2 == temp6))
      {
        temp2->setNextNode(temp1);
	temp1->setPrevNode(temp2);
      }
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
}

void dll::shuffleDll()
{
  if (head == NULL)return;
  int len = ListLength();
  if (len == 1)return;

  int k =  ((len%2) == 0) ? len/2: (len+1)/2, i = 0, j = 0;
  doubleNode *temp1 = head;
  doubleNode *temp2 = head;
  doubleNode *temp3 = head; /* Contains head after which kth elem is to be inserted */
  doubleNode *temp4 = head;
  
  while ((i < k) && (temp1 != NULL)) 
  {
    temp1 = temp1->getNextNode();
    i++;
  }
  /* Store prev and next of kth element */
  temp2 = temp1->getPrevNode();
  temp4 = temp1->getNextNode();
//  cout << "kth elem is " << temp1->getNodeData() << " " << endl;
 
  while ((temp1 != NULL) && (temp2 != NULL) &&
         (temp3 != NULL))
  {
   /* Remove the kth element from current position */

   /* Point the prev of kth elem to next of Kth elem */
   temp2->setNextNode(temp4);
   /* Point the next of kth elem to prev of kth elem */
   if (temp4 != NULL)temp4->setPrevNode(temp2);

   /* Point the kth elem Next to the next of current head */
   temp1->setNextNode(temp3->getNextNode());
   /* Point the prev of next of current head to kth elem */
   if (temp3->getNextNode())temp3->getNextNode()->setPrevNode(temp1);
   /* Point the kth elem Previous to the current head */
   temp1->setPrevNode(temp3);
   /* Point the next of current head to its kth elem */
   temp3->setNextNode(temp1);
   /* Update the current head to insert next Kth elem */
   temp3 = temp1->getNextNode();
   /* Update the next kth elem for current head  */
   temp1 = temp2->getNextNode();
   /* Update next elem of current Kth elem */
   if (temp1 != NULL)temp4 = temp1->getNextNode();
  }
}

void dll::reverseDll()
{
  if (head == NULL)return;
  int len = ListLength();
  if (len == 1)return;
  
  doubleNode *temp1 = head;
  doubleNode *temp2 = head;
  
  while (temp1 != NULL)
  {
    temp2 = temp1->getPrevNode();
    temp1->setPrevNode(temp1->getNextNode());
    temp1->setNextNode(temp2);
    temp1 = temp1->getPrevNode();
  }
  
  head = temp2->getPrevNode();
}

void dll::InsertAtStart(int data)
{
  doubleNode *newNode = new doubleNode(data, NULL, NULL);
  if (head == NULL)
  {
    head = newNode;
    return;
  }
  else
  {
    newNode->setNextNode(head);
    head->setPrevNode(newNode);
    head = newNode;
  }
}

void dll::InsertAtEnd(int data)
{
  doubleNode* newNode = new doubleNode(data, NULL, NULL);
  doubleNode* temp = head;
  
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
  newNode->setPrevNode(temp);
}

void dll::printList()
{
 doubleNode* temp = head;
 if (temp == NULL)
 {
   cout << "==============" << endl;
   cout << "Empty list...." << endl;
   cout << "==============" << endl;
 }
 cout << "Head --> ";
 while (temp != NULL)
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

void dll::printListByFour()
{
  doubleNode *temp = head;
  int fourElemCount = 0;

  if (temp == NULL)
  {
    cout << "==============" << endl;
    cout << "Empty list...." << endl;
    cout << "==============" << endl;
  }

  while (temp != NULL)
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

void dll::printFirstHalfByFour()
{
  doubleNode *temp = head;
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
 

void dll::printSecondHalfByFour()
{
  doubleNode *temp = head;
  if (head == NULL)return;
  int len = ListLength(), i = 0, fourElemCount = 0;
  int firsthalf = ( (len%2)==0  ? (len/2) : (len+1)/2 );
  int secondhalf = len - firsthalf;
  while ( i < firsthalf)i++, temp = temp->getNextNode();
  i = 0;
  while ( (i < secondhalf) && (temp != NULL))
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

/*int main()
{
  int tc, data, i =0;
  dll mydll;
  cin >> tc;
  while(tc -- )
  {
    cin >> data;
    mydll.InsertAtEnd(data);
//    mysll.printList();
  }
  
  cout << "****Before Double linkedlist Reverse operation ********" << endl;
  mydll.printListByFour();
  cout << endl << endl;

  cout << "****After Double linkedlist Reverse operation********" << endl;
  mydll.reverseDll();
  mydll.printListByFour();
  cout << endl << endl;
  
  cout << "****Before Double linkedlist Shuffle operation*****" << endl;
  mydll.printListByFour();
  cout << endl << endl;

  cout << "****After Double linkedlist Shuffle operation*****" << endl;
  mydll.shuffleDll();
  mydll.printListByFour();
  cout << endl << endl;
  
  cout << "****Before single linked list Four Operation*****" << endl;
  mydll.printListByFour();
  cout << endl << endl;
  
  cout << "****After single linked list Four Operation*****" << endl;
  int len = mydll.ListLength();
  while (i < len)
  {
    mydll.mySort(i, 4);
    i+=4;
  }
  mydll.printListByFour();
  cout << endl << endl;

  return 0;
} */
