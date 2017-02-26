#include <iostream>
#include <cstdlib>
using namespace std;

typedef struct node
{
  int data;
  struct node* Next;
}node;

node *head = NULL;

int ListLength()
{
  int length = 0;
  if (head == NULL)
  {
    return length;
  }
  node* temp = head;
  while(temp != NULL)
  {
    temp = temp->Next;
    length++;
  }
  return length;
}

node* reverseSll(node* head)
{
  if (head == NULL)return head;
  node *temp1 = head;
  node *temp2 = NULL;
  node *temp3 = NULL;
  while (temp1 != NULL)
  {
    temp2 = temp1;
    temp1 = temp1->Next;
    temp2->Next = temp3;
    temp3 = temp2;
  }
  head = temp2;
  return head;
}

/*node* InsertAtStart(node* head, int data)
{
  node *newNode = new singleNode(data, NULL);
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
}*/

node* InsertAtEnd(node *head, int data)
{
  node *newNode =  (node *)malloc(sizeof(node));
  newNode->data = data;
  newNode->Next = NULL;

  node* temp = head;
  
  if (temp == NULL)
  {
    return newNode;
  }

  while (temp->Next != NULL)
  {
    temp = temp->Next;
  }
  
  temp->Next = newNode;
  return head;
}

void printList(node* head)
{
 node* temp = head;
 if (temp == NULL)
 {
   cout << "==============" << endl;
   cout << "Empty list...." << endl;
   cout << "==============" << endl;
 }
 cout << "Head --> ";
 while(temp != NULL)
 {
   cout << temp->data;
   cout << " --> ";
   temp = temp->Next;
   if (temp == NULL)
   {
     cout << "NULL" << endl;
   }
 }
 cout << endl;
}

void printListByFour(node* head)
{
  node *temp = head;
  int fourElemCount = 0;

  if (temp == NULL)
  {
    cout << "==============" << endl;
    cout << "Empty list...." << endl;
    cout << "==============" << endl;
  }

  while (temp != NULL)
  {
    cout << temp->data;
    cout << ",";
    fourElemCount++;
    if (fourElemCount == 4)
    {
      fourElemCount = 0;
      cout << endl;
    }
    temp = temp->Next;
  }
  
}

node* ReturnKthNode(node* cur, int len)
{
  int i = 0;
  node* temp = head;
  if (len < 0)
  {
/*    while ((temp->Next != NULL) && (temp->Next != cur))
    {
       temp = temp->Next;
    }
    if (temp != cur)
    {
      return temp;
    }
    else */
    return NULL;
  }
  temp = cur;
  while ((i < len) && (temp != NULL)) temp = temp->Next,i++;
  return temp;
}

node* sortbyfour(node* cur)
{
  return NULL;
}

node* sort(node* cur, int len)
{
  if(cur == NULL)return NULL;
  int i, j, index;
  node *temp1 = NULL;
  node *temp2 = NULL;
  node *temp3 = NULL;
  node *temp4 = NULL;
  node *temp5 = NULL;
  node *temp6 = NULL;
  for(i = 0; i < len; i++)
  {
    temp1 = ReturnKthNode(cur, i);
    index = i;
    for ( j = i+1; j < len; j++)
    {
      temp2 = ReturnKthNode(cur, j);
      if ((temp1 != NULL) && (temp2 != NULL) && (temp2->data < temp1->data))
      {
	index = j;
	temp1 = ReturnKthNode(cur, index);
      }
    }
    /* swap at i and index */
    temp1 = ReturnKthNode(cur, i);
    temp2 = ReturnKthNode(cur, index);
    temp3 = ReturnKthNode(cur, index-1);
    temp4 = ReturnKthNode(cur, i-1);
    temp5 = ReturnKthNode(cur, index+1);
    temp6 = ReturnKthNode(cur, i+1);

    /*-------currentNode----------------SwapNode-------- 
               ^                         ^               
    	       |                         |               
     temp4->temp1->temp6->.....temp3->temp2->temp5->..... */
    
    /*Make the previous of index node next as current Node */
    if (temp3 != NULL) 
    {
      /*To prevent pointing back to same node causing loop */
      if (temp3 != temp1)
      temp3->Next = temp1;
    }
    /*Make the next of current node as next of index Node */
    if (temp1 != NULL) temp1->Next = temp5;
    /*Make the next of previous Node of current as index Node */
    if (temp4 != NULL) temp4->Next = temp2;
    /*Make the next of index Node as next of current Node */
    if (temp2 != NULL) 
    {
      /*To prevent pointing back to same node causing loop */
      if (temp2 != temp6)
      temp2->Next = temp6;
    }
    if ((temp1 != NULL) && (temp2 != NULL))
    {
      /* Special case when temp1= temp3 and temp2= temp6 this logic is
       needed to not break the chain */
      if ((temp1 == temp3) && (temp2 == temp6))
      temp2->Next = temp1;
    }
    if (i == 0)cur = temp2;    
  }
  return cur;
}

int main()
{
  int tc, data;
  cin >> tc;
  node *temp = NULL;
  node *temp2 = NULL;
  while(tc -- )
  {
    cin >> data;
    head = InsertAtEnd(head, data);
  }
//  printList(head);
  
  cout << "****Before Single linkedlist Reverse operation ********" << endl;
  printListByFour(head);
  cout << endl << endl;

  cout << "****After Single linkedlist Reverse operation********" << endl;
  head = reverseSll(head);
  printListByFour(head);
  cout << endl << endl;
  
  int len = ListLength();
  int i = 0;
  /* split the elements by 4 each and send to sort function */
  while ( i < len)
  {
    temp = sort(ReturnKthNode(head,i), 4);
    /* We need to maintain start of list always */
    if (i < 4)
    {
      head = temp;
    }
    else
    {
      temp2 = ReturnKthNode(head,i-1);
      if ( temp2 != NULL)
      {
	temp2->Next = temp;
      }
    }
    i += 4;
  }
  cout << "****After Single linkedlist sort operation********" << endl;
  printListByFour(head);
  cout << endl << endl;
  return 0;
}
