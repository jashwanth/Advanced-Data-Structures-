///////////////////////////////////////////////////////////////////////
// graph.h -  graph and adajacency structure                         // 
//                                                                   // 
// ver 1.0                                                           //
// Author:      Brahmachaitahnya Sadashiva, Syracuse University(CE)  //
//              bsadashi@syr.edu                                     //  
///////////////////////////////////////////////////////////////////////
/*
* Package Operations:
* -------------------
*creates adjacancy node and list
*creates graph using adajacancy list
*/

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include<fstream>
#include<iostream>
#include<vector>
//to hold the node
struct AdjListNode
	{
	int dest;
	int weight;
	struct AdjListNode* next;
	};

// adjacancy list
struct AdjList
	{
	struct AdjListNode *head;  
	};
//graph structure
struct Graph
	{
	int V;
	struct AdjList* array;
	};

