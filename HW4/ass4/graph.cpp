#include "graph.h"
#include <string>
using namespace std;

void graph::insertvertex(char ch)
{
  if (mv.find(ch) != mv.end())
  {
    cout << "Vertext already exists in the graph" << endl;
    return;
  }
  count++;
  mv.insert(std::pair<char,int>(ch,count));
}

void graph::removeedge(char ch1, char ch2, int weight)
{
  int index1 = mv[ch1];
  int index2 = mv[ch2];
  for(vector<edge>::iterator e  = adjList[index1].begin(); e != adjList[index1].end(); e++)
  {
    if (e->v == index2)
    {
      adjList[index1].erase(e);
      return;
    }
  }
}

void graph::insertedge(char ch1, char ch2, int weight)
{
  if (mv.find(ch1) == mv.end())
  {
    insertvertex(ch1);
  }
  if (mv.find(ch2) == mv.end())
  {
    insertvertex(ch2);
  }
  int index1 = mv[ch1];
  int index2 = mv[ch2];
  adjList[index1].push_back(edge(index2, weight));
}

void graph::removevertex(char ch)
{
  if (mv.find(ch) == mv.end())
  {
    cout << "cannot find the vertex " << ch << "in the graph" << endl;
    return;
  }
  int index = mv[ch];
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
  /* We have removed all the relevant edges 
   Now remove the vertex too */
  mv.erase(mv.find(ch));
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

void graph::createdotfile(string name)
{
  stringstream ss;
  char ch1, ch2;
  string arrow;
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
  for (std::map<char,int>::iterator it = mv.begin(); it != mv.end(); it++)
  {
    ch1 = it->first;
    ss << ch1 << "\t";
  }

  ss << endl;
  for (std::map<char,int>::iterator i = mv.begin(); i != mv.end(); i++)
  {
    for(vector<edge>::size_type e  = 0; e < adjList[i->second].size(); e++)
    {
      ch1 = i->first;
      ch2 = vname(adjList[i->second][e].vertex());
      //	cout << ch1 << "--" << ch2 << ";\n";
      ss << ch1 << arrow << ch2 ;
      if (flag == 2)
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

char graph::vname(int index)
{
  for (std::map<char,int>::iterator it = mv.begin(); it != mv.end(); it++)
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
  return '0';
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
      cout << val << " ";
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
    cout << endl;
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
       mv[line[i]] = index;
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

