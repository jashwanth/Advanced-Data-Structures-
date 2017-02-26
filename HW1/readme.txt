This file contains the implementation details of single and double linked list operations
for each of the test cases namely team of four sort operation , reverse , shuffle operation.

Linked List Operations:
   The singlelinkedlist.h contains definitions for both single nodes and single linkedlist class declarations.
   The doublelinkedlist.h contains definitions for both double nodes and double linkedlist class declarations.
   We always maintain head of the list . This always helps to know about the list members just by iterating
   through the head. Some utility functions are provided like to get kth element from the start which was 
   used by needed operations.

   The main.cpp accepts as input number of nodes and the corresponding nodes. The same nodes we used 
   for each of the operations. I didnot use the output of one operation to be provided as input for
   next operations. All the operations work on the same test case. 

   PrintListByFour function simply iterates the list and breaks the line after every four elements.

   PrintFirstHalfByFour does the same till first half of elements. 
   PrintSecondHalfByFour does the same after iterating the first half of elements.
   These functions are used to display before the shuffle operation shuffles the list for ease
   of seeing the corresponding second half element to be arranged after each of first half element.
   
  a) Team of Four Operation: 
     mySort functions takes as argument the node and the number of nodes after it to be inserted. This is 
     a generic function and hence team of four operations send the argument to sort only 4 elements. I have used
     the logic of selection sort where after every k iterations we have first k elements sorted. Swapping the elements
     was a bit challenging using selection sort.

       -------currentNode------------------SwapNode--------
                     ^                        ^
		     |                        |            
            temp4->temp1->temp6->.....temp3->temp2->temp5->.....
     We maintain the previous and next node of currentnode along with the
     Swap Node and exchange their positions. All the cases were handled like what happens if
     temp1 = temp2, temp3 = temp6, temp4 = NULL etc.. The code worked fine for corner test cases like
     1 , 2, 3 elements etc..

  b) Reverse Operation
     The logic consists of maitaining three pointers 1->2->3 . As we move 3 forward, 1 becomes 2 ,2 becomes 3, 3 becomes next.
     Now Point 2 back to 1 , 3 back to 2. 1<-2<-3. 
  c) Shuffle Operation:
     First we iterate to half of the list and find the element to be inserted after the first element of first half.
     We remove this second half element from the second half list and insert it after the first element. Now the first half 
     moves to the next element in its list , the corresponding pairing element is updated. This is repeated.

  We have two files S1.txtx and S2.txt which are test files that are tested against main.cpp executable.
  S1 contains elements from 1 to 100 and S2 contains random elements generated using rand() function of stdlib 
  library. This program is not included in this attachment.

  The output.txt contains the output for both of these test cases. 
  output.txt is generated as follows. 
  1) g++ *.cpp -o main 
  2)./main > S1.txt < output.txt 
  3)./main < S2.txt >> output.txt

  The logic maintained for single and double linked list remains the same, except that for DLL , the previous node
  needs to be updated for all the operations. This previous node also helps us from maintaining previous pointers
  as required by the single linked lists.
  ------------------------------------------------EOF---------------------------------------------------------------
