///////////////////////////////////////////////////////////////////////
// graph.cpp -  iplementation of graph calss and dijikstaras         // 
//                                                                   // 
// ver 1.0                                                           //
// Author:      Brahmachaitahnya Sadashiva, Syracuse University(CE)  //
//              bsadashi@syr.edu                                     //  
///////////////////////////////////////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include<fstream>
#include<iostream>
#include<vector>
#include"graph.h"
using namespace std;
int vertex_count = 0;
int edges_count = 0;
int vertex[50];



//new node for list
struct AdjListNode* newAdjListNode(int dest, int weight)
{
  struct AdjListNode* newNode = new AdjListNode;
  newNode->dest = dest;
  newNode->weight = weight;
  newNode->next = NULL;
  return newNode;
}

// creating graph
struct Graph* createGraph(int V)
{
  vertex_count = 0;
  edges_count = 0;
  struct Graph* graph = new Graph;
  graph->V = V;
  vertex[50] =  0 ;
  graph->array = new AdjList[V];
  return graph;
}
//to add vertex
void addVertex(int a ,Graph * graph)
{
  vertex[vertex_count] = a;
  vertex_count++;
  graph->array[a].head = NULL;


}
// to add an edge
void addEdge(struct Graph* graph, int src, int dest, int weight,int directed)
{
  edges_count++;
  struct AdjListNode* newNode = newAdjListNode(dest, weight);
  newNode->next = graph->array[src].head;
  graph->array[src].head = newNode;
  if (directed == 0)
  {
    //for undirected graph
    newNode = newAdjListNode(src, weight);
    newNode->next = graph->array[dest].head;
    graph->array[dest].head = newNode;
  }
}
//to delete an edge
void deleteEdge(struct Graph* graph, int src, int dest)
{
  struct AdjListNode* phead = graph->array[src].head;
  if (phead == NULL) return;
  if (phead->dest == dest)
  {
    graph->array[src].head = phead->next;
    delete phead;
  }

  else
  {
    struct AdjListNode* p, *q;
    p = phead;
    q = phead;
    phead = phead->next;
    while (phead)
    {
      if (phead->dest == dest&&phead->next != NULL)
      {
	p->next = phead->next;
	delete phead;
	break;
      }
      else if (phead->dest == dest&&phead->next == NULL)
      {
	p->next = NULL;
	delete phead;
	break;
      }
      p = p->next;
      phead = phead->next;
    }
  }
}

// for min heap node
struct MinHeapNode
{
  int  v;
  int dist;
};
//min heap
struct MinHeap
{
  int size;      // nodes 
  int capacity;  // max nodes
  int *pos;     // 
  struct MinHeapNode **array;
};

// creating min heap node
struct MinHeapNode* newMinHeapNode(int v, int dist)
{
  struct MinHeapNode* minHeapNode =
    (struct MinHeapNode*) malloc(sizeof(struct MinHeapNode));
  minHeapNode->v = v;
  minHeapNode->dist = dist;
  return minHeapNode;
}

// creating min heap
struct MinHeap* createMinHeap(int capacity)
{
  struct MinHeap* minHeap =
    (struct MinHeap*) malloc(sizeof(struct MinHeap));
  minHeap->pos = (int *)malloc(capacity * sizeof(int));
  minHeap->size = 0;
  minHeap->capacity = capacity;
  minHeap->array =
    (struct MinHeapNode**) malloc(capacity * sizeof(struct MinHeapNode*));
  return minHeap;
}


void swapMinHeapNode(struct MinHeapNode** a, struct MinHeapNode** b)
{
  struct MinHeapNode* t = *a;
  *a = *b;
  *b = t;
}
void minHeapify(struct MinHeap* minHeap, int idx)
{
  int smallest, left, right;
  smallest = idx;
  left = 2 * idx + 1;
  right = 2 * idx + 2;

  if (left < minHeap->size &&
      minHeap->array[left]->dist < minHeap->array[smallest]->dist)
    smallest = left;

  if (right < minHeap->size &&
      minHeap->array[right]->dist < minHeap->array[smallest]->dist)
    smallest = right;

  if (smallest != idx)
  {
    // The nodes to be swapped in min heap
    MinHeapNode *smallestNode = minHeap->array[smallest];
    MinHeapNode *idxNode = minHeap->array[idx];

    // Swap positions
    minHeap->pos[smallestNode->v] = idx;
    minHeap->pos[idxNode->v] = smallest;

    // Swap nodes
    swapMinHeapNode(&minHeap->array[smallest], &minHeap->array[idx]);

    minHeapify(minHeap, smallest);
  }
}

// to check empy
int isEmpty(struct MinHeap* minHeap)
{
  return minHeap->size == 0;
}

// to extract minimum node from heap
struct MinHeapNode* extractMin(struct MinHeap* minHeap)
{
  if (isEmpty(minHeap))
    return NULL;

  // root node
  struct MinHeapNode* root = minHeap->array[0];


  struct MinHeapNode* lastNode = minHeap->array[minHeap->size - 1];
  minHeap->array[0] = lastNode;


  minHeap->pos[root->v] = minHeap->size - 1;
  minHeap->pos[lastNode->v] = 0;


  --minHeap->size;
  minHeapify(minHeap, 0);

  return root;
}

//decrease key
void decreaseKey(struct MinHeap* minHeap, int v, int dist)
{

  int i = minHeap->pos[v];
  minHeap->array[i]->dist = dist;

  while (i && minHeap->array[i]->dist < minHeap->array[(i - 1) / 2]->dist)
  {

    minHeap->pos[minHeap->array[i]->v] = (i - 1) / 2;
    minHeap->pos[minHeap->array[(i - 1) / 2]->v] = i;
    swapMinHeapNode(&minHeap->array[i], &minHeap->array[(i - 1) / 2]);
    i = (i - 1) / 2;
  }
}
bool isInMinHeap(struct MinHeap *minHeap, int v)
{
  if (minHeap->pos[v] < minHeap->size)
    return true;
  return false;
}
//dijikstra for bot directed and undirected 


void dijkstra(struct Graph* graph, int src,int path_display)
{
  vector<int> path[20];
  int V = 20;
  int dist[20];
  struct MinHeap* minHeap = createMinHeap(V); //creating heap
  for (int v = 0; v < V; ++v)
  {
    dist[v] = INT_MAX;
    minHeap->array[v] = newMinHeapNode(v, dist[v]);
    minHeap->pos[v] = v;
  }
  minHeap->array[src] = newMinHeapNode(src, dist[src]);
  minHeap->pos[src] = src;
  dist[src] = 0;
  decreaseKey(minHeap, src, dist[src]);
  minHeap->size = V;
  //finding paths  
  while (!isEmpty(minHeap))
  {
    struct MinHeapNode* minHeapNode = extractMin(minHeap);
    int u = minHeapNode->v; 
    struct AdjListNode* pCrawl = graph->array[u].head;
    while (pCrawl != NULL)
    {

      int v = pCrawl->dest;
      if (isInMinHeap(minHeap, v) && dist[u] != INT_MAX &&
	  pCrawl->weight + dist[u] < dist[v])
      {
	dist[v] = (dist[u] + pCrawl->weight);
	path[v].push_back(u);
	decreaseKey(minHeap, v, dist[v]);
      }
      pCrawl = pCrawl->next;
    }
  }
  //to show distance
  if (path_display == 0)
  {
    cout << "Vertex   Distance from Source\n";
    for (int i = 0; i < V; ++i)
    {
      if (!(i == src))
      {
	cout << i + 1 << "\t\t" << dist[i] << "\n";
      }
    }
  }
  //to show the path
  if (path_display == 1)
  {
    for (int i = 0; i < V; i++)
    {
      if (i != src)
      {
	cout << "\nVertex" << i + 1 << ":\t\t\t";
	for (std::vector<int>::iterator it = path[i].begin(); it != path[i].end(); ++it)
	{
	  cout << *it + 1 << "<---";
	}

	cout << "\n";
      }
    }
  }

}
//to generate dot file
void showgraph(struct Graph* graph, ofstream* stream,int directed)
{
  //for undirected
  if (directed == 0)
  {
    *stream << " strict graph {  \n node [shape= ellipse];\n";
    int v;
    for (v = 0; v < vertex_count; ++v)
    {

      *stream << vertex[v] << "\t";
    }
    *stream << ";\n";

    if (edges_count > 0)
    {
      for (v = 1; v <= vertex_count; ++v)
      {

	struct AdjListNode* pCrawl = graph->array[v].head;
	while (pCrawl)
	{

	  *stream << v << "--" << pCrawl->dest << ";\n";
	  pCrawl = pCrawl->next;
	}
	printf("\n");
      }
    }



    *stream << "}\n";
  }
  //for directed graph
  else
  {
    *stream << " strict digraph {  \n node [shape= ellipse];\n";
    int v;
    for (v = 0; v < vertex_count; ++v)
    {

      *stream << vertex[v] << "\t";
    }
    *stream << ";\n";

    if (edges_count > 0)
    {
      for (v = 1; v <= vertex_count; ++v)
      {

	struct AdjListNode* pCrawl = graph->array[v].head;
	while (pCrawl)
	{

	  *stream << v << "->" << pCrawl->dest << ";\n";
	  pCrawl = pCrawl->next;
	}
	printf("\n");
      }
    }



    *stream << "}\n";
  }

}
using namespace std;
#include<fstream>
#include<sstream>
int main()
{
  cout << "--------------------------------Test case 1--------------------------------------------------\n";
  int undirected = 0;
  int vertex_count = 0;
  int edges_count = 0;
  int V = 20;
  struct Graph* graph = createGraph(V);
  addVertex(1,graph);
  addVertex(2, graph);
  addVertex(18, graph);
  addVertex(13, graph);
  addVertex(3, graph);
  addVertex(4, graph);
  addVertex(20, graph);
  addVertex(5, graph);
  addVertex(17, graph);
  addVertex(6, graph);
  std::ofstream *f = new ofstream;
  cout << "generated dot file after 10 random vetex inserion 1a.dot and png 1a.png\n";
  f->open("1a.dot");
  showgraph(graph, f, undirected);
  f->close();
  addVertex(7, graph);
  addVertex(8, graph);
  addVertex(9, graph);
  addVertex(10, graph);
  addVertex(11, graph);
  addVertex(12, graph);
  addVertex(14, graph);
  addVertex(15, graph);
  addVertex(16, graph);
  addVertex(19, graph);
  cout << "generated dot file after 20 random vetex inserion 1b.dot and png 1b.png\n";
  std::ofstream *f2 = new ofstream;
  f2->open("1b.dot");
  showgraph(graph, f2, undirected);
  f2->close();
  for (int i = 1; i <= 20; i++)
  {
    if (i == 20)
    {
      addEdge(graph, 20, 1, 0, undirected);
    }
    else
    {
      addEdge(graph, i, (i + 1), 0, undirected);
    }
  }
  std::ofstream *f3 = new ofstream;
  f3->open("1c.dot");
  showgraph(graph, f3, undirected);
  cout << "generated dot file after 20 edges (1,2), .., (i,i+1), ... , (19,20), (20, 1)"
    <<"edges  1c.dot and png 1c.png\n";
  f3->close();
  for (int i = 1; i <= 18; i++)
  {
    addEdge(graph, i, i+2, 0, undirected);
  }
  addEdge(graph, 19, 1, 0, undirected);
  addEdge(graph, 20, 2, 0, undirected);
  std::ofstream *f4 = new ofstream;
  f4->open("1d.dot");
  showgraph(graph, f4, undirected);
  cout << "generated dot file after 20 edges (1,3), .., (i,i+2), ... , (18,20), (19, 1), (20, 2)"
    << "edges  1d.dot and png 1d.png\n";
  f4->close();
  deleteEdge(graph, 1, 2);
  deleteEdge(graph, 2, 3);
  deleteEdge(graph, 18, 19);
  deleteEdge(graph, 19, 20);
  deleteEdge(graph, 7, 8);
  deleteEdge(graph, 5, 6);
  deleteEdge(graph, 4, 5);
  deleteEdge(graph, 1, 3);
  deleteEdge(graph, 2, 4);
  deleteEdge(graph, 20, 3);
  cout << "Deleted edges and generating 1edot and 1e.png \n";
  std::ofstream *f5 = new ofstream;
  f5->open("1e.dot");
  showgraph(graph, f5, undirected);
  f5->close();




  cout << "--------------------------------Test case 2--------------------------------------------------\n";
  int directed = 1;
  int V1 = 20;
  struct Graph* graph2 = createGraph(V1);
  addVertex(1, graph2);
  addVertex(2, graph2);
  addVertex(18, graph2);
  addVertex(13, graph2);
  addVertex(3, graph2);
  addVertex(4, graph2);
  addVertex(20, graph2);
  addVertex(5, graph2);
  addVertex(17, graph2);
  addVertex(6, graph2);
  std::ofstream *f6 = new ofstream;
  cout << "generated dot file after 10 random vetex inserion 2a.dot and png 2a.png\n";
  f6->open("2a.dot");
  showgraph(graph2, f6,directed);
  f6->close();
  addVertex(7, graph2);
  addVertex(8, graph2);
  addVertex(9, graph2);
  addVertex(10, graph2);
  addVertex(11, graph2);
  addVertex(12, graph2);
  addVertex(14, graph2);
  addVertex(15, graph2);
  addVertex(16, graph2);
  addVertex(19, graph2);
  cout << "generated dot file after 20 random vetex inserion 2b.dot and png 2b.png\n";
  std::ofstream *f7 = new ofstream;
  f7->open("2b.dot");
  showgraph(graph2, f7, directed);
  f7->close();
  for (int i = 1; i <= 20; i++)
  {
    if (i == 20)
    {
      addEdge(graph2, 20, 1, 0,directed);
    }
    else
    {
      addEdge(graph2, i, (i + 1), 0, directed);
    }
  }
  std::ofstream *f8 = new ofstream;
  f8->open("2c.dot");
  showgraph(graph2, f8, directed);
  cout << "generated dot file after 20 edges (1,2), .., (i,i+1), ... , (19,20), (20, 1)"
    << "edges  2c.dot and png 2c.png\n";
  f8->close();
  for (int i = 1; i <= 18; i++)
  {
    addEdge(graph2, i, i + 2, 0, directed);
  }
  addEdge(graph2, 19, 1, 0, directed);
  addEdge(graph2, 20, 2, 0, directed);
  std::ofstream *f9 = new ofstream;
  f9->open("2d.dot");
  showgraph(graph2, f9, directed);
  cout << "generated dot file after 20 edges (1,3), .., (i,i+2), ... , (18,20), (19, 1), (20, 2)"
    << "edges  2d.dot and png 2d.png\n";
  f9->close();
  deleteEdge(graph2, 1, 2);
  deleteEdge(graph2, 2, 3);
  deleteEdge(graph2, 18, 19);
  deleteEdge(graph2, 19, 20);
  deleteEdge(graph2, 7, 8);
  deleteEdge(graph2, 5, 6);
  deleteEdge(graph2, 4, 5);
  deleteEdge(graph2, 1, 3);
  deleteEdge(graph2, 2, 4);
  deleteEdge(graph2, 20, 3);
  cout << "Deleted edges and generating 2e.dot and 2e.png \n";
  std::ofstream *f10 = new ofstream;
  f10->open("2e.dot");
  showgraph(graph2, f10, directed);
  f10->close();


  cout << "------------------------Test case 3-----------------------------\n";
  int data[25][25] = {0,0};
  std::ifstream file("../undirected_graph.csv");

  for (int row = 0; row < 25; ++row)
  {
    std::string line;
    std::getline(file, line);
    /*if (!file.good())
      break;*/

    std::stringstream iss(line);

    for (int col = 0; col < 25; ++col)
    {
      std::string val;
      std::getline(iss, val, ',');
      /*if (!iss.good())
	break;*/

      std::stringstream convertor(val);
      convertor >> data[row][col];
    }
  }


  int V3 = 25;
  struct Graph* graph3 = createGraph(V3);
  for (int i = 1; i <= 25; i++)
  {
    addVertex(i, graph3);
  }
  for (int i = 0; i < 25; i++)
  {
    for (int j = 0; j < 25; j++)
    {
      if (data[i][j] == 1)
      {
	addEdge(graph3, i + 1, j + 1, 0, 0);
      }
    }

  }

  std::ofstream *f17 = new ofstream;
  cout << "generated dot file after reading csv  : 3a.dot and png 3a.png\n";
  f17->open("3a.dot");
  showgraph(graph3, f17, directed);
  f17->close();
  for (int i = 1; i <= 25; i++)
  {
    int s, d;
    s = rand() % 25;
    d = (rand() % 25 + 2) % 25;
    if (s == 0) s = 1;
    if (d == 0) d = 2;
    addEdge(graph3,  s,d, 0, 0);

  }
  std::ofstream *f18 = new ofstream;
  cout << "generated dot file after adding random n edges   : 3b.dot and png 3b.png\n";
  f18->open("3b.dot");
  showgraph(graph3, f18, directed);
  f18->close();



  cout << "------------------------Test case 4-----------------------------\n";
  int data2[25][25] = {0,0};
  std::ifstream file4("../directed_graph.csv");

  for (int row = 0; row < 25; ++row)
  {
    std::string line;
    std::getline(file4, line);
    /*if (!file.good())
      break;*/

    std::stringstream iss(line);

    for (int col = 0; col < 25; ++col)
    {
      std::string val;
      std::getline(iss, val, ',');
      /*if (!iss.good())
	break;*/

      std::stringstream convertor(val);
      convertor >> data2[row][col];
    }
  }


  int V4 = 25;
  struct Graph* graph4 = createGraph(V4);
  for (int i = 1; i <= 25; i++)
  {
    addVertex(i, graph4);
  }
  for (int i = 0; i < 25; i++)
  {
    for (int j = 0; j < 25; j++)
    {
      if (data2[i][j] == 1)
      {
	addEdge(graph4, i + 1, j + 1, 0, 1);
      }
    }

  }

  std::ofstream *f19 = new ofstream;
  cout << "generated dot file after reading directed csv  : 4a.dot and png 4a.png\n";
  f19->open("4a.dot");
  showgraph(graph4, f19, directed);
  f19->close();
  for (int i = 1; i <= 25; i++)
  {
    int s, d;
    s = rand() % 25;
    d = (rand() % 25 + 2) % 25;
    if (s == 0) s = 1;
    if (d == 0) d = 2;
    addEdge(graph4,  s,d, 0, directed);

  }
  std::ofstream *f20 = new ofstream;
  cout << "generated dot file after adding random n edges   : 4b.dot and png 4b.png\n";
  f20->open("4b.dot");
  showgraph(graph4, f20, directed);
  f20->close();
  for (int i = 1; i <= 25; i++)
  {
    int s, d;
    s = rand() % 25;
    d = (rand() % 25 + 2) % 25;
    if (s == 0) s = 1;
    if (d == 0) d = 2;
    deleteEdge(graph4, s, d);

  }
  std::ofstream *f11 = new ofstream;
  cout << "generated dot file after deleting random n edges   : 4c.dot and png 4c.png\n";
  f11->open("4c.dot");
  showgraph(graph4, f11, directed);
  f11->close();

  cout << "---------------------------Test case 5 undirected graph --------------------------------------------------\n";

  int V6 = 20;
  struct Graph* graph5 = createGraph(V6);
  for (int i = 0; i < 20; ++i)
    graph5->array[i].head = NULL;
  int data3[20][20] = { 0,0 };
  std::ifstream file6("../weighted_undirected_graph.csv");

  for (int row = 0; row < 20; ++row)
  {
    std::string line;
    std::getline(file6, line);
    /*if (!file.good())
      break;*/

    std::stringstream iss(line);

    for (int col = 0; col < 20; ++col)
    {
      std::string val;
      std::getline(iss, val, ',');
      /*if (!iss.good())
	break;*/

      std::stringstream convertor(val);
      convertor >> data3[row][col];
    }
  }

  for (int i = 0; i < 20; i++)
  {
    for (int j = 0; j < 20; j++)
    {
      if (data3[i][j]>0)
      {
	addEdge(graph5, i, j, (data3[i][j]), 0);
      }
    }
  }
  cout << "For undirected weighted graph \n";
  cout << "selected Vertex 6 as source and the shortest distance are as below\n";

  dijkstra(graph5,5,0);

  cout << "removing all edges to 5";
  for (int i = 0; i < 20; i++)
  {
    deleteEdge(graph5, 4, i);
  }
  for (int i = 0; i < 20; i++)
  {
    deleteEdge(graph5, i, 4);
  }
  dijkstra(graph5, 5,0);

  cout << "---------------------------Test case 6 directed graph --------------------------------------------------\n";

  int V16 = 20;
  struct Graph* graph6 = createGraph(V16);
  for (int i = 0; i < 20; ++i)
    graph6->array[i].head = NULL;
  int data4[20][20] = { 0,0 };
  std::ifstream file8("../weighted_directed_graph.csv");

  for (int row = 0; row < 20; ++row)
  {
    std::string line;
    std::getline(file8, line);
    /*if (!file.good())
      break;*/

    std::stringstream iss(line);

    for (int col = 0; col < 20; ++col)
    {
      std::string val;
      std::getline(iss, val, ',');
      /*if (!iss.good())
	break;*/

      std::stringstream convertor(val);
      convertor >> data4[row][col];
    }
  }

  for (int i = 0; i < 20; i++)
  {
    for (int j = 0; j < 20; j++)
    {
      if (data4[i][j]>0)
      {
	addEdge(graph6, i, j, (data4[i][j]), 1);
      }
    }
  }
  cout << "For directed weighted graph \n";
  cout << "selected Vertex 6 as source and the shortest distance are as below\n";

  dijkstra(graph6, 5,0);

  cout << "removing all edges to 5 and showing infinite value to 5 since no edges to it\n";
  for (int i = 0; i < 20; i++)
  {
    deleteEdge(graph6, 4, i);
  }
  for (int i = 0; i < 20; i++)
  {
    deleteEdge(graph6, i, 4);
  }
  dijkstra(graph6, 5,0);

  cout << "---------------------------Test case 7 undirected graph --------------------------------------------------\n";

  int V7 = 20;
  struct Graph* graph7 = createGraph(V7);
  for (int i = 0; i < 20; ++i)
    graph7->array[i].head = NULL;
  int data5[20][20] = { 0,0 };
  std::ifstream file2("../weighted_undirected_graph.csv");

  for (int row = 0; row < 20; ++row)
  {
    std::string line;
    std::getline(file2, line);

    std::stringstream iss(line);

    for (int col = 0; col < 20; ++col)
    {
      std::string val;
      std::getline(iss, val, ',');

      std::stringstream convertor(val);
      convertor >> data5[row][col];
    }
  }

  for (int i = 0; i < 20; i++)
  {
    for (int j = 0; j < 20; j++)
    {
      if (data5[i][j]>0)
      {
	addEdge(graph7, i, j, (data5[i][j]), 0);
      }
    }
  }
  cout << "For undirected weighted graph \n";
  cout << "selected Vertex 8 as source and  shortest path to other vertices are as below\n";

  dijkstra(graph7, 7, 1);

  cout << "removing 1/4[E] and resulting paths are as below\n";
  for (int i = 0, j = 0; i < 5; i++,j++)
  {
    deleteEdge(graph7, j, i);
  }

  dijkstra(graph7, 7, 1);

  cout << "---------------------------Test case 8 directed graph --------------------------------------------------\n";

  int V8 = 20;
  struct Graph* graph8 = createGraph(V8);
  for (int i = 0; i < 20; ++i)
    graph8->array[i].head = NULL;
  int data6[20][20] = { 0,0 };
  std::ifstream file3("../weighted_directed_graph.csv");

  for (int row = 0; row < 20; ++row)
  {
    std::string line;
    std::getline(file3, line);

    std::stringstream iss(line);

    for (int col = 0; col < 20; ++col)
    {
      std::string val;
      std::getline(iss, val, ',');

      std::stringstream convertor(val);
      convertor >> data6[row][col];
    }
  }

  for (int i = 0; i < 20; i++)
  {
    for (int j = 0; j < 20; j++)
    {
      if (data6[i][j]>0)
      {
	addEdge(graph8, i, j, (data6[i][j]), 1);
      }
    }
  }
  cout << "For directed weighted graph \n";
  cout << "selected Vertex 15 as source and  shortest path to other vertices are as below\n";

  dijkstra(graph8, 14, 1);

  cout << "removing 1/4[E] and resulting paths are as below\n";
  for (int i = 0, j = 0; i < 5; i++, j++)
  {
    deleteEdge(graph8, j, i);
  }

  dijkstra(graph8, 14, 1);


  cout << "---------------------------Test case 9 undirected graph --------------------------------------------------\n";
  cout << "generated dot file 9.dot and png 9.png\n";
  cout << "---------------------------Test case 10 directed graph --------------------------------------------------\n";
  cout << "generated dot file 10.dot and png 10.png\n";


  return 0;
}
