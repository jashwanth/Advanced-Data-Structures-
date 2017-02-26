#include "graph.h"
#include <string>
using namespace std;
#define left(i)   2*i+1
#define right(i)  (2*i+2)

/* parent index of a node */
#define parent(i) ((i % 2 == 0) ? (i-1)/2 : i/2)


void graph::initarr()
{
  for (int i = 0; i < count; i++)
  {
    arr[i].vertex = vname(i+1);
    // a very large int 
    arr[i].key    = 100000;
  }
}

void graph::percolateDown(int index, int size)
{
  if (index >= size)
    return;
  int leftInd = left(index);
  int rightInd = right(index);
  int smaller = index;
  if ((leftInd < size) && (arr[index].key > arr[leftInd].key))
  { 
    smaller = leftInd;
  }
  if ((rightInd < size) && (arr[smaller].key > arr[rightInd].key))
  {
    smaller = rightInd;
  }
  swapnodes(index, smaller);
  if (index != smaller)
  {
     percolateDown(smaller, size);
  }
}

void graph::swapnodes(int index1, int index2)
{
  graphedge swap;
  swap.vertex = arr[index1].vertex;
  swap.key   = arr[index1].key;
  swap.pred  = arr[index1].pred;
  arr[index1].vertex = arr[index2].vertex;
  arr[index1].key    = arr[index2].key;
  arr[index1].pred   = arr[index2].pred;
  arr[index2].vertex = swap.vertex;
  arr[index2].key    = swap.key;
  arr[index2].pred   = swap.pred;
}

void graph::minheapify(int index)
{
  if (index < 0)
    return;
  int parentInd = parent(index);
  /* Swap the parent with greater of the two children */
  if ((parentInd >= 0) && (arr[parentInd].key > arr[index].key))
  {
    swapnodes(parentInd, index);
    minheapify(parentInd);
  }
}

int graph::findarrIndex(string vertex, int size)
{
  for (int i = 0; i< size ; i++)
  {
    if (arr[i].vertex.compare(vertex) == 0)
      return i;
  }
  return -1;
}

void graph::updateDistance(string vertex, int val, int size, string pred)
{
  int i = findarrIndex(vertex,  size);
  if ( i == -1)
  {
//    cout << vertex << " Vertex not found: " << endl;
    return;
  }
  if (arr[i].key > val)
  {
    arr[i].key = val;
    arr[i].pred = pred;
    minheapify(i);
  }
}

void graph::printpath(string vertex)
{
   int index = findarrIndex(vertex, count);
   if (arr[index].vertex.compare("invalid") == 0)
     return;
   if (arr[index].pred.compare("invalid") == 0)
   {
     cout << arr[index].vertex << "--->";
     return;
   }
   printpath(arr[index].pred);
   cout << arr[index].vertex << "--->";
}

void graph::printdistarr()
{
  for (int i = 0; i < count; i++)
  {
    printpath(arr[i].vertex);
    cout << endl << "vertex = " << arr[i].vertex << "Distance = " << arr[i].key << "pred = " << arr[i].pred << endl;
  }
}

void graph::dijkstra(string vertex)
{
  int index;
  if (mv.find(vertex) != mv.end())
    index = mv.find(vertex)->second;
  else
  { 
    return;
  }

  // cout << endl << "Dijkstra for vertex " << vertex << " " << index << endl;
  /* start vertex weight as zero */
  int size = count;
  updateDistance(vertex, 0, size, "invalid");
  while (size > 0)
  {
    int index = mv.find(arr[0].vertex)->second;
    int w1   = arr[0].key;
    swapnodes(0,size-1);
    size--;
    percolateDown(0, size);
    for (vector<edge>::iterator it1  = adjList[index].begin(); it1 !=  adjList[index].end(); it1++)
    {
      int index2 = it1->v;
      int weight = it1->w + w1;
      updateDistance(vname(index2), weight, size, vname(index));
    }
//  minheapify(arr, );
  }
//  printdistarr();
/*  if (i == index)
  {
    cout << "found the vertex index " << index << endl;
    mindist[i].dist = 0;
  } */
}

void graph::insertvertex(string str)
{
  if (mv.find(str) != mv.end())
  {
    cout << "Vertext already exists in the graph" << endl;
    return;
  }
  count++;
  mv.insert(std::pair<string,int>(str,count));
}

void graph::removeedge(string str1, string str2, int weight)
{
  int index1 = mv[str1];
  int index2 = mv[str2];
  for(vector<edge>::iterator e  = adjList[index1].begin(); e != adjList[index1].end(); e++)
  {
    if (e->v == index2)
    {
      adjList[index1].erase(e);
      return;
    }
  }
}

void graph::insertedge(string str1, string str2, int weight)
{
  if (mv.find(str1) == mv.end())
  {
    insertvertex(str1);
  }
  if (mv.find(str2) == mv.end())
  {
    insertvertex(str2);
  }
  int index1 = mv[str1];
  int index2 = mv[str2];
  adjList[index1].push_back(edge(index2, weight));
}

void graph::removevertex(string str)
{
  if (mv.find(str) == mv.end())
  {
    cout << "cannot find the vertex " << str << "in the graph" << endl;
    return;
  }
  int index = mv[str];

  for(vector<edge>::iterator it1  = adjList[index].begin(); it1 !=  adjList[index].end(); )
  {
    /* undirected graph remove both the edges */
    if (flag == 0)
    {
      int index2 = it1->v;
      for(vector<edge>::iterator it2  = adjList[index2].begin(); it2 !=  adjList[index2].end(); it2++)
      {
        if (it2->v == index)
        {
	 // edge e1(adjList[index2][f].vertex(), adjList[index2][f].weight());
          adjList[index2].erase(it2);
	  break;
        }
      }
    }
//    edge e2(adjList[index][e].vertex(), adjList[index][e].weight());
    it1 = adjList[index].erase(it1);
  }
  /* Remove incoming edges to the vertex */
  if (flag == 1)
  {
    for (std::map<string,int>::iterator item = mv.begin(); item != mv.end(); item++)
    {
      for(vector<edge>::iterator ite  = adjList[item->second].begin(); ite != adjList[item->second].end(); ite++)
      {
	if (ite->v == index)
        {
          adjList[item->second].erase(ite);
	  break;
        }
      }
    }
  }
  /* We have removed all the relevant edges 
   Now remove the vertex too */
  mv.erase(mv.find(str));
  count--;
}

/*void graph::removeedge(int index1, int index2)
{
  for(vector<edge>::iterator e  = adjList[index1].begin(); e != adjList[index1].end(); e++)
  {
    if (e->v == index2)
    {
//      edge e3(adjList[index1][e].vertex(), adjList[index1][e].weight());
      adjList[index1].erase(e);
      return;
    }
  }
}*/

/*void graph::updatecolorflag(string vertex1, string vertex2)
{
  int index = mv[str];

  for(vector<edge>::iterator it  = adjList[index].begin(); it1 !=  adjList[index].end(); )
  {
    
  }
}*/

void graph::createcolorfile(string name)
{
  stringstream ss;
  string arrow, str1, str2;
  /* undirected graph */
  if (flag == 0)
  {
    arrow = "--";
    ss << " strict graph {  \n node [shape= ellipse];\n";
  }
  else
  {
    arrow = "->";
    ss << " strict digraph {  \n node [shape= ellipse];\n";
  }
  for (std::map<string,int>::iterator it = mv.begin(); it != mv.end(); it++)
  {
    str1 = it->first;
    ss << str1 << "\t";
  }
  for (int i = 0; i < count; i++)
  {
    if ((arr[i].pred.compare("invalid") == 0) || (arr[i].vertex.compare("invalid") == 0))
    {
      continue;
    }
    ss << arr[i].pred << arrow << arr[i].vertex;
    ss << "[color=red, label=" << (arr[i].key - arr[findarrIndex(arr[i].pred, count)].key) << "];\n";
  }

  ss << endl;
  for (std::map<string,int>::iterator i = mv.begin(); i != mv.end(); i++)
  {
    for(vector<edge>::size_type e  = 0; e < adjList[i->second].size(); e++)
    {
      str1 = i->first;
      str2 = vname(adjList[i->second][e].vertex());
      //	cout << ch1 << "--" << ch2 << ";\n";
      int index2 = findarrIndex(str2, count);
      if ((index2 != -1) && (arr[index2].pred.compare(str1) == 0))
      {
	continue;
      }

      ss << str1 << arrow << str2 ;
      if ((flag == 2) || (adjList[i->second][e].weight() > 1))
      {
        ss << "[ label=" << adjList[i->second][e].weight() << "]";
      }
      ss << ";\n"; 
    }
  }
  ss << "}\n";
  fstream fs;
  remove(name.c_str());
  fs.open(name.c_str(), std::fstream::in|std::fstream::out|std::fstream::app);
  fs << ss.str();
  fs.close();
  ss.str("");


}

void graph::createdotfile(string name)
{
  stringstream ss;
  string arrow, str1, str2;
  /* undirected graph */
  if (flag == 0)
  {
    arrow = "--";
    ss << " strict graph {  \n node [shape= ellipse];\n";
  }
  else
  {
    arrow = "->";
    ss << " strict digraph {  \n node [shape= ellipse];\n";
  }
  for (std::map<string,int>::iterator it = mv.begin(); it != mv.end(); it++)
  {
    str1 = it->first;
    ss << str1 << "\t";
  }

  ss << endl;
  for (std::map<string,int>::iterator i = mv.begin(); i != mv.end(); i++)
  {
    for(vector<edge>::size_type e  = 0; e < adjList[i->second].size(); e++)
    {
      str1 = i->first;
      str2 = vname(adjList[i->second][e].vertex());
      //	cout << ch1 << "--" << ch2 << ";\n";
      ss << str1 << arrow << str2 ;
      if ((flag == 2) || (adjList[i->second][e].weight() > 1))
      {
        ss << "[ label=" << adjList[i->second][e].weight() << "]";
      }
      ss << ";\n"; 
    }
  }
  ss << "}\n";
  fstream fs;
  remove(name.c_str());
  fs.open(name.c_str(), std::fstream::in|std::fstream::out|std::fstream::app);
  fs << ss.str();
  fs.close();
  ss.str("");

}

string graph::vname(int index)
{
  for (std::map<string,int>::iterator it = mv.begin(); it != mv.end(); it++)
  {
    if (it->second == index)
      return it->first;
  }
/*    cout << it->first << ", " << it->second << "   ";
  }
  for (int i = 1; i <= count; i++)
  {
    if (mv[i] == index)
    {
      return mv[i];
    }
  }*/
  return "0";
}

void graph::addWeights(string name)
{
  fstream f;
  f.open(name.c_str());
  string line;
  getline(f, line);
  if (line[0] == 'W')
  {
    /* Weighted graph */
    flag = 2;
  }
  int row = 1, j = 1;
  while (getline (f, line))
  {
    int val;
    j = 1;
    stringstream ss(line);
    char ch;
    ss >> ch;
    while(ss >> ch)
    {
      ss >> val;
//      cout << val << " ";
      if (val != -1)
      {
	  /* find the vector<edge> corresponding to j and update weight */
//        adjList[row][j].setWeight(val);
	for(vector<edge>::size_type e  = 0; e < adjList[row].size(); e++)
	{
          if (adjList[row][e].vertex() == j)
	  {
	    adjList[row][e].setWeight(val);
	    break;
	  }
	}
      }
      j++;
    }
    row++;
    ss.clear();
//    cout << endl;
  }
}

void graph::constructGraph(string name)
{
   mv.clear();
   for (int i = 0; i < adjList.size(); i++)
   {
     adjList[i].clear();
   }
   fstream f1;
   f1.open(name.c_str());
   string line;
   getline(f1, line);
   int index = 1;
   /* Undirected graph */
   if (line[0] == 'U')
      flag = 0;
   else flag = 1;
   
   for (int i = 1; i < line.length(); i++)
   {
     if (line[i] != ',')
     {
       string mystr;
       mystr.push_back(line[i]);
       mv[mystr] = index;
       index++;
     }
   }
   count = index-1;
   int row = 1;
   while (getline (f1, line))
   {
     int j = 1;
     for (int i = 1; i < line.length(); i++)
     {
       if (line[i] == ',')
         continue;
       if (line[i] == '0')
       {
         j++;
         continue;
       }
       adjList[row].push_back(edge(j,line[i]-48));
       j++;
     }
     row++;
   }
   f1.close();
}

