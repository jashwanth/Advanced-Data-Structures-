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
  map<char,int> mv;
  vector<vector<edge> > adjList = vector<vector<edge> >(20);
  /* to check whether undirected or directed graph */
  int flag;
  /* toal vertices count */
  int count;
  /* */
  void constructGraph(string name);
  void addWeights(string name);
  char vname(int index);
  void createdotfile(string name);
  void removeedge(char ch1, char ch2, int weight);
//  void removeedge(int i1, int i2);
  void insertedge(char ch1, char ch2, int weight);
  void insertvertex(char ch);
  void removevertex(char ch);
};

#endif
