#ifndef graph_h
#define graph_h
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <vector>
#include <string>
#include <sstream>
#include <map>

using namespace std;

/*struct vertex
{
  char ch;
  vertex* next;
};*/

class graphedge
{
  public:
  string vertex;
  /* here key is the distance/weight */
  int key;
  string pred;
//  int color = 0;
  graphedge()
  {
    vertex = "invalid";
    key = 100000;
    pred = "invalid";
  }
};

class edge
{
  public:
  int v;
  int w;
  edge(int vertex, int weigh)
  {
    v = vertex;
    w = weigh;
  }
  void setWeight(int weigh)
  {
    w = weigh;
  }
  int vertex()
  {
    return v;
  }
  int weight()
  {
    return w;
  }
};

class graph
{
  public:
    /* To map vertices to indices */
  graphedge arr[20];
  map<std::string,int> mv;
  vector<vector<edge> > adjList = vector<vector<edge> >(20);
  /* to check whether undirected or directed graph */
  int flag;
  /* toal vertices count */
  int count;
  /* */
  void constructGraph(string name);
  void printpath(string vertex);
  void addWeights(string name);
  string vname(int index);
  void createcolorfile(string name);
  void createdotfile(string name);
  void removeedge(string str1, string str2, int weight);
//  void removeedge(int i1, int i2);
  void insertedge(string str1, string str2, int weight);
  void insertvertex(string str);
  void removevertex(string str);
  int findarrIndex(string vertex, int size);
  void printdistarr();
  void percolateDown(int index, int size);
  void swapnodes(int i, int j);
  void initarr();
  void minheapify(int i);
  void updateDistance(string vertex, int val, int size, string pred);
  void dijkstra(string vertex);
};

#endif
