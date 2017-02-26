#include "graph.h"
#include <algorithm>
#include <sstream>

void testcase1()
{
  cout << endl << endl << "*****Begin of Testcase1 Execution*****" << endl << endl;
  graph g1;
  g1.constructGraph("fig1.csv");
  cout << "Constructed graph from file fig1.csv" << endl;
  cout << "list of all vertices is " << endl;
  for (std::map<string,int>::iterator it = g1.mv.begin(); it != g1.mv.end(); it++)
  {
    cout << it->first << ", " << it->second << "   ";
  }
  cout << endl << "Adjaceny list is " << endl;
  for (int i = 1 ; i <= g1.count ; i++)
  {
    cout << i << "-->";
    for (vector<edge>::size_type e = 0; e < g1.adjList[i].size(); e++)
    {
      cout << g1.adjList[i][e].vertex() << "(" << g1.adjList[i][e].weight() << ")";
      (e == g1.adjList[i].size()-1) ? cout << endl : cout << ", ";
    }
    cout << endl;
  }
  g1.createdotfile("t1.dot");
  cout << "Created dot file t1.dot " << endl;
  cout << endl << endl << "*****End of Testcase1 Execution*****" << endl << endl;
}

void testcase2()
{
  cout << endl << endl << "*****Begin of Testcase2 Execution*****" << endl << endl;
  graph g2;
  g2.constructGraph("fig2.csv");
  cout << "Constructed graph from file fig2.csv" << endl;
  cout << "list of all vertices is " << endl;
  for (std::map<string,int>::iterator it = g2.mv.begin(); it != g2.mv.end(); it++)
  {
    cout << it->first << ", " << it->second << "   ";
  }
  cout << endl << "Adjaceny list is " << endl;
  for (int i = 1 ; i <= g2.count ; i++)
  {
    cout << i << "-->";
    for (vector<edge>::size_type e = 0; e < g2.adjList[i].size(); e++)
    {
      cout << g2.adjList[i][e].vertex() << "(" << g2.adjList[i][e].weight() << ")";
      (e == g2.adjList[i].size()-1) ? cout << endl : cout << ", ";
    }
    cout << endl;
  }
  g2.createdotfile("t2.dot");
  cout << "Created dot file t2.dot " << endl;
  cout << endl << endl << "*****End of Testcase2 Execution*****" << endl << endl;
}

void testcase3()
{
  cout << endl << endl << "*****Begin of Testcase3 Execution*****" << endl << endl;
  graph g3;
  g3.constructGraph("fig3.csv");
  cout << "constructed graph from fig3.csv file" << endl;
  cout << "list of all vertices is " << endl;
  for (std::map<string,int>::iterator it = g3.mv.begin(); it != g3.mv.end(); it++)
  {
    cout << it->first << ", " << it->second << "   ";
  }
  cout << endl << "Adjaceny list is " << endl;
  for (int i = 1 ; i <= g3.count ; i++)
  {
    cout << i << "-->";
    for (vector<edge>::size_type e = 0; e < g3.adjList[i].size(); e++)
    {
      cout << g3.adjList[i][e].vertex() << "(" << g3.adjList[i][e].weight() << ")";
      (e == g3.adjList[i].size()-1) ? cout << endl : cout << ", ";
    }
    cout << endl;
  }
  g3.addWeights("fig3-w.csv");
  cout << "Adding weights to the graph from fig3-w.csv" << endl;
  cout << endl << "Adjaceny list is " << endl;
  for (int i = 1 ; i <= g3.count ; i++)
  {
    cout << i << "-->";
    for (vector<edge>::size_type e = 0; e < g3.adjList[i].size(); e++)
    {
      cout << g3.adjList[i][e].vertex() << "(" << g3.adjList[i][e].weight() << ")";
      (e == g3.adjList[i].size()-1) ? cout << endl : cout << ", ";
    }
    cout << endl;
  }
  g3.createdotfile("t3.dot");
  cout << "Created dot file t3.dot " << endl;
  cout << endl << endl << "*****End of Testcase3 Execution*****" << endl << endl;
}

void testcase4()
{
  cout << endl << endl << "*****Begin of Testcase4 Execution*****" << endl << endl;
  graph g4;
  g4.constructGraph("fig1.csv");
  cout << "list of all vertices is " << endl;
  for (std::map<string,int>::iterator it = g4.mv.begin(); it != g4.mv.end(); it++)
  {
    cout << it->first << ", " << it->second << "   ";
  }
  cout << endl << "Adjaceny list is " << endl;
  for (int i = 1 ; i <= g4.count ; i++)
  {
    cout << i << "-->";
    for (vector<edge>::size_type e = 0; e < g4.adjList[i].size(); e++)
    {
      cout << g4.adjList[i][e].vertex() << "(" << g4.adjList[i][e].weight() << ")";
      (e == g4.adjList[i].size()-1) ? cout << endl : cout << ", ";
    }
    cout << endl;
  }
//  g4.createdotfile("t1.dot");
  g4.insertvertex("z");
  cout << "Added the vertex \"z\" to the graph" << endl;
  g4.insertedge("z", "w", 1);
  g4.insertedge("w", "z", 1);
  cout << "Inserted the edge between \"z\" and \"w\" " << endl;
  g4.insertedge("z", "x", 1);
  g4.insertedge("x", "z", 1);
  cout << "Inserted the edge between \"z\" and \"x\" " << endl;
  g4.insertedge("z", "y", 1);
  g4.insertedge("y", "z", 1);
  cout << "Inserted the edge between \"z\" and \"y\" " << endl;
  g4.createdotfile("t4a.dot");
  cout << "Created dot file t4a.dot" << endl;
  g4.removevertex("s");
  cout << "Removed the vertext \"s\" from the graph " << endl;
  g4.removevertex("x");
  cout << "Removed the vertext \"x\" from the graph " << endl;
  g4.removeedge("u","t",1);
  g4.removeedge("t","u",1);
  cout << "Removed the edge between \"u\" and \"t\" from the graph" << endl;
  g4.createdotfile("t4b.dot");
  cout << "Created dot file t4b.dot" << endl;
  cout << endl << endl << "*****End of Testcase4 Execution*****" << endl << endl;

}

void testcase5()
{
  cout << endl << endl << "*****Begin of Testcase5 Execution*****" << endl << endl;
  graph g5;
  g5.count = 0;
  g5.flag = 0;
  g5.insertedge("6","7",1);
  g5.insertedge("7","6",1);
  cout << "Inserted a new edge between \"6\" and \"7\" to the graph" << endl;
  g5.insertedge("7","8",1);
  g5.insertedge("8","7",1);
  cout << "Inserted a new edge between \"7\" and \"8\" to the graph" << endl;
  g5.insertedge("8","9",1);
  g5.insertedge("9","8",1);
  cout << "Inserted a new edge between \"8\" and \"9\" to the graph" << endl;
  g5.insertedge("9","10",1);
  g5.insertedge("10","9",1);
  cout << "Inserted a new edge between \"9\" and \"10\" to the graph" << endl;
  g5.insertedge("10","6",1);
  g5.insertedge("6","10",1);
  cout << "Inserted a new edge between \"6\" and \"10\" to the graph" << endl;
  g5.insertvertex("1");
  g5.insertvertex("2");
  g5.insertvertex("3");
  g5.insertvertex("4");
  g5.insertvertex("5");
  cout << "Inserted vertices 1,2,3,4,5 to the graph" << endl;
  g5.insertedge("1","6",1);
  g5.insertedge("6","1",1);
  cout << "Inserted a new edge between \"6\" and \"1\" to the graph" << endl;
  g5.insertedge("2","7",1);
  g5.insertedge("7","2",1);
  cout << "Inserted a new edge between \"2\" and \"7\" to the graph" << endl;
  g5.insertedge("3","8",1);
  g5.insertedge("8","3",1);
  cout << "Inserted a new edge between \"3\" and \"8\" to the graph" << endl;
  g5.insertedge("4","9",1);
  g5.insertedge("9","4",1);
  cout << "Inserted a new edge between \"4\" and \"9\" to the graph" << endl;
  g5.insertedge("5","10",1);
  g5.insertedge("10","5",1);
  cout << "Inserted a new edge between \"5\" and \"10\" to the graph" << endl;
  g5.createdotfile("t5a.dot");
  cout << "Created dot file t5a.dot" << endl;
  g5.removevertex("8");
  cout << "Removed the vertex \"8\" from the graph" << endl;
  g5.removevertex("6");
  cout << "Removed the vertex \"6\" from the graph" << endl;
  g5.createdotfile("t5b.dot");
  cout << "Created dot file t5b.dot" << endl;
  cout << endl << endl << "*****End of Testcase5 Execution*****" << endl << endl;

}

void testcase6()
{
  cout << endl << endl << "*****Begin of Testcase6 Execution*****" << endl << endl;
  graph g6;
  g6.count = 0;
  /* Make the grph directed */
  g6.flag = 1;
  g6.insertvertex("2");
  g6.insertvertex("4");
  g6.insertvertex("6");
  g6.insertvertex("8");
  g6.insertvertex("10");
  cout << "Inserted vertices 2,4,6,8,10 to the graph" << endl;
  g6.insertedge("2","4",1);
  cout << "Inserted a new edge between \"2\" and \"4\" to the graph" << endl;
  g6.insertedge("2","6",1);
  cout << "Inserted a new edge between \"2\" and \"6\" to the graph" << endl;
  g6.insertedge("4","6",1);
  cout << "Inserted a new edge between \"4\" and \"6\" to the graph" << endl;
  g6.insertedge("4","8",1);
  cout << "Inserted a new edge between \"4\" and \"8\" to the graph" << endl;
  g6.insertedge("6","8",1);
  cout << "Inserted a new edge between \"6\" and \"8\" to the graph" << endl;
  g6.insertedge("6","10",1);
  cout << "Inserted a new edge between \"6\" and \"10\" to the graph" << endl;
  g6.insertedge("8","10",1);
  cout << "Inserted a new edge between \"8\" and \"10\" to the graph" << endl;
  g6.insertedge("8","2",1);
  cout << "Inserted a new edge between \"8\" and \"2\" to the graph" << endl;
  g6.insertvertex("1");
  g6.insertvertex("3");
  g6.insertvertex("5");
  g6.insertvertex("7");
  g6.insertvertex("9");
  cout << "Inserted vertices 1,3,5,7,9 to the graph" << endl;
  g6.insertedge("1","2",1);
  cout << "Inserted a new edge between \"1\" and \"2\" to the graph" << endl;
  g6.insertedge("3","4",1);
  cout << "Inserted a new edge between \"3\" and \"4\" to the graph" << endl;
  g6.insertedge("5","6",1);
  cout << "Inserted a new edge between \"5\" and \"6\" to the graph" << endl;
  g6.insertedge("7","8",1);
  cout << "Inserted a new edge between \"7\" and \"8\" to the graph" << endl;
  g6.insertedge("9","10",1);
  cout << "Inserted a new edge between \"9\" and \"10\" to the graph" << endl;
  g6.createdotfile("t6a.dot");
  cout << "Created a dot file t6a.dot " << endl;
  g6.removevertex("2");
  cout << "Removed vertex \"2\" from the graph" << endl;
  g6.removevertex("7");
  cout << "Removed vertex \"7\" from the graph" << endl;
  g6.createdotfile("t6b.dot");
  cout << "Created a dot file t6b.dot " << endl;
  cout << endl << endl << "*****End of Testcase6 Execution*****" << endl << endl;
}

void testcase7()
{
  cout << endl << endl << "*****Begin of Testcase7 Execution*****" << endl << endl;
  graph g7;
  g7.constructGraph("fig3.csv");
  cout << "constructed graph from fig3.csv file" << endl;
  cout << "list of all vertices is " << endl;
  cout << "-----------------------------------" << endl;
  for (std::map<string,int>::iterator it = g7.mv.begin(); it != g7.mv.end(); it++)
  {
    cout.width(6);cout << it->first;
   // cout.width(6);cout << it->first << "(" << it->second << ")";
  }
  cout << endl << "------------------------------------" << endl;
  g7.addWeights("fig3-w.csv");
//  g7.arr = (graphedge *)malloc(sizeof(graphedge)*(g7.count));
  g7.initarr();
  for (std::map<string,int>::iterator it = g7.mv.begin(); it != g7.mv.end(); it++)
  {
    cout << endl << it->first << " ";
    string vertexname = it->first;
    g7.dijkstra(vertexname);
    for (std::map<string,int>::iterator it2 = g7.mv.begin(); it2 != g7.mv.end(); it2++)
    {
      int findindex = g7.findarrIndex(it2->first, g7.count);
      cout.width(6); cout << g7.arr[findindex].key;
    }
//    cout << endl << it->first << " ";
/*    for (int i = 0; i < mindist.size(); i++)
    {
      cout.width(8);cout << mindist[i].dist;
    }*/
    g7.initarr();
  }
  cout << endl << "Adjaceny list is " << endl;
  for (int i = 1 ; i <= g7.count ; i++)
  {
    cout << i << "-->";
    for (vector<edge>::size_type e = 0; e < g7.adjList[i].size(); e++)
    {
      cout << g7.adjList[i][e].vertex() << "(" << g7.adjList[i][e].weight() << ")";
      (e == g7.adjList[i].size()-1) ? cout << endl : cout << ", ";
    }
    cout << endl;
  }

  cout << endl << endl << "*****End of Testcase7 Execution*****" << endl << endl;

}

void testcase8()
{
  cout << endl << endl << "*****Begin of Testcase8 Execution*****" << endl << endl;
  graph g8;
  g8.flag = 0;
  g8.insertvertex("s");
  g8.insertvertex("t");
  g8.insertvertex("x");
  g8.insertvertex("y");
  g8.insertvertex("z");
  g8.insertedge("s", "t",10);
  g8.insertedge("t", "s",10);
  g8.insertedge("s","y",5);
  g8.insertedge("y","s",5);
  g8.insertedge("s","z",7);
  g8.insertedge("z","s",7);
  g8.insertedge("t","x",1);
  g8.insertedge("x","t",1);
  g8.insertedge("t","y",2);
  g8.insertedge("y","t",2);
  g8.insertedge("y","x",9);
  g8.insertedge("x","y",9);
  g8.insertedge("y","z",2);
  g8.insertedge("z","y",2);
  g8.insertedge("z","x",4);
  g8.insertedge("x","z",4);
  g8.createdotfile("t8a.dot");
  g8.initarr();
  cout << "list of all vertices is " << endl;
  cout << "-----------------------------------" << endl;
  for (std::map<string,int>::iterator it = g8.mv.begin(); it != g8.mv.end(); it++)
  {
    cout.width(6);cout << it->first;
   // cout.width(6);cout << it->first << "(" << it->second << ")";
  }
  cout << endl << "------------------------------------" << endl;
  for (std::map<string,int>::iterator it = g8.mv.begin(); it != g8.mv.end(); it++)
  {
    cout << it->first << " ";
    string vertexname = it->first;
    g8.dijkstra(vertexname);
    for (std::map<string,int>::iterator it2 = g8.mv.begin(); it2 != g8.mv.end(); it2++)
    {
      int findindex = g8.findarrIndex(it2->first, g8.count);
      cout.width(6); cout << g8.arr[findindex].key;
    }
    cout << endl;
    g8.initarr();
  }
  cout << endl << endl << "*****End of Testcase8 Execution*****" << endl << endl;
}

void testcase9()
{
  cout << endl << endl << "*****Begin of Testcase9 Execution*****" << endl << endl;
  graph g9;
  g9.constructGraph("fig3.csv");
  g9.addWeights("fig3-w.csv");
  g9.initarr();
  g9.dijkstra("s");
  cout << endl << "------------------------------------------" << endl;
          cout << "Vertex   The path from source vertex s    " << endl;
          cout << "         to this vertex in G3             " << endl;
          cout << "------------------------------------------" << endl;
  for (std::map<string,int>::iterator it = g9.mv.begin(); it != g9.mv.end(); it++)
  {
    cout << it->first << "     ";
    stringstream ss;
    int findIndex = g9.findarrIndex(it->first, g9.count);
    ss.str("");
    while(g9.arr[findIndex].pred.compare("invalid") != 0)
    {
       ss << g9.arr[findIndex].pred << "---";
       findIndex = g9.findarrIndex(g9.arr[findIndex].pred, g9.count);
       if (findIndex == -1)
	 break;
    }
    string mystr(ss.str());
    reverse(mystr.begin(), mystr.end());
    mystr.erase(0,3);
    mystr.append("---");
    mystr.append(it->first);
    if (it->first.compare("s") == 0)
    {
      mystr = "nil";
    }
    cout << mystr << endl;
  }
  g9.initarr();
  g9.dijkstra("z");
  cout << endl << "------------------------------------------" << endl;
          cout << "Vertex   The path from source vertex z    " << endl;
          cout << "         to this vertex in G3             " << endl;
          cout << "------------------------------------------" << endl;
  for (std::map<string,int>::iterator it2 = g9.mv.begin(); it2 != g9.mv.end(); it2++)
  {
    cout << it2->first << "     ";
    stringstream ss2;
    int findIndex = g9.findarrIndex(it2->first, g9.count);
    ss2.str("");
    while(g9.arr[findIndex].pred.compare("invalid") != 0)
    {
       ss2 << g9.arr[findIndex].pred << "---";
       findIndex = g9.findarrIndex(g9.arr[findIndex].pred, g9.count);
       if (findIndex == -1)
	 break;
    }
    string mystr2(ss2.str());
    reverse(mystr2.begin(), mystr2.end());
    mystr2.erase(0,3);
    mystr2.append("---");
    mystr2.append(it2->first);
    if (it2->first.compare("z") == 0)
    {
      mystr2 = "nil";
    }
    cout << mystr2 << endl;
  }


  cout << endl << endl << "*****End of Testcase9 Execution*****" << endl << endl;
}

void testcase10()
{
  cout << endl << endl << "*****Begin of Testcase10 Execution*****" << endl << endl;
  graph g10;
  g10.flag = 0;
  g10.insertvertex("s");
  g10.insertvertex("t");
  g10.insertvertex("x");
  g10.insertvertex("y");
  g10.insertvertex("z");
  g10.insertedge("s", "t",10);
  g10.insertedge("t", "s",10);
  g10.insertedge("s","y",5);
  g10.insertedge("y","s",5);
  g10.insertedge("s","z",7);
  g10.insertedge("z","s",7);
  g10.insertedge("t","x",1);
  g10.insertedge("x","t",1);
  g10.insertedge("t","y",2);
  g10.insertedge("y","t",2);
  g10.insertedge("y","x",9);
  g10.insertedge("x","y",9);
  g10.insertedge("y","z",2);
  g10.insertedge("z","y",2);
  g10.insertedge("z","x",4);
  g10.insertedge("x","z",4);
//  g10.createdotfile("t10a.dot");
  g10.initarr();
  g10.dijkstra("s");
  cout << endl << "------------------------------------------" << endl;
          cout << "Vertex   The path from source vertex s    " << endl;
          cout << "         to this vertex in G4             " << endl;
          cout << "------------------------------------------" << endl;
  for (std::map<string,int>::iterator it = g10.mv.begin(); it != g10.mv.end(); it++)
  {
    cout << it->first << "     ";
    stringstream ss;
    int findIndex = g10.findarrIndex(it->first, g10.count);
    ss.str("");
    while(g10.arr[findIndex].pred.compare("invalid") != 0)
    {
       ss << g10.arr[findIndex].pred << "---";
       findIndex = g10.findarrIndex(g10.arr[findIndex].pred, g10.count);
       if (findIndex == -1)
	 break;
    }
    string mystr(ss.str());
    reverse(mystr.begin(), mystr.end());
    mystr.erase(0,3);
    mystr.append("---");
    mystr.append(it->first);
    if (it->first.compare("s") == 0)
    {
      mystr = "nil";
    }
    cout << mystr << endl;
  }
  g10.initarr();
  g10.dijkstra("z");
  cout << endl << "------------------------------------------" << endl;
          cout << "Vertex   The path from source vertex z    " << endl;
          cout << "         to this vertex in G4             " << endl;
          cout << "------------------------------------------" << endl;
  for (std::map<string,int>::iterator it2 = g10.mv.begin(); it2 != g10.mv.end(); it2++)
  {
    cout << it2->first << "     ";
    stringstream ss2;
    int findIndex = g10.findarrIndex(it2->first, g10.count);
    ss2.str("");
    while(g10.arr[findIndex].pred.compare("invalid") != 0)
    {
       ss2 << g10.arr[findIndex].pred << "---";
       findIndex = g10.findarrIndex(g10.arr[findIndex].pred, g10.count);
       if (findIndex == -1)
	 break;
    }
    string mystr2(ss2.str());
    reverse(mystr2.begin(), mystr2.end());
    mystr2.erase(0,3);
    mystr2.append("---");
    mystr2.append(it2->first);
    if (it2->first.compare("z") == 0)
    {
      mystr2 = "nil";
    }
    cout << mystr2 << endl;
  }
  cout << endl << endl << "*****End of Testcase10 Execution*****" << endl << endl;

}

void testcase11()
{
  cout << endl << endl << "*****Begin of Testcase11 Execution*****" << endl << endl;
  graph g11;
  g11.constructGraph("fig3.csv");
  g11.addWeights("fig3-w.csv");
  g11.initarr();
  graphedge ge;
  ge.key = 0;
  ge.vertex = "invalid";
  string source="invalid";
  for (std::map<string,int>::iterator it = g11.mv.begin(); it != g11.mv.end(); it++)
  {
  //  cout << it->first << " ";
    string vertexname = it->first;
    g11.dijkstra(vertexname);
    for (int i = 0; i < g11.count; i++)
    {
      if ((g11.arr[i].key != 100000) &&(g11.arr[i].key > ge.key))
      {
        source = it->first;
        ge.key = g11.arr[i].key;
        ge.vertex = g11.arr[i].vertex;
      }
    }
    g11.initarr();
  }
  g11.initarr();
  g11.dijkstra(source);
  cout << "Final longest cost path between two vertices is " << endl;
  int findIndex = g11.findarrIndex(ge.vertex, g11.count);
  stringstream s;
  s.str("");
  while(g11.arr[findIndex].vertex.compare("invalid") != 0)
  {
    s << g11.arr[findIndex].vertex << "---";
    findIndex = g11.findarrIndex(g11.arr[findIndex].pred, g11.count);
    if (findIndex == -1)
      break;
  }
  string mystr(s.str());
  reverse(mystr.begin(), mystr.end());
  mystr.erase(0,3);
/*  mystr.append("---");
  mystr.append(it2->first);*/
  cout << endl << mystr << endl;
  g11.createcolorfile("t11.dot");
  cout << endl << endl << "*****End of Testcase11 Execution*****" << endl << endl;
}

void testcase12()
{
  cout << endl << endl << "*****Begin of Testcase12 Execution*****" << endl << endl;
  graph g12;
  g12.flag = 0;
  g12.insertvertex("s");
  g12.insertvertex("t");
  g12.insertvertex("x");
  g12.insertvertex("y");
  g12.insertvertex("z");
  g12.insertedge("s", "t",10);
  g12.insertedge("t", "s",10);
  g12.insertedge("s","y",5);
  g12.insertedge("y","s",5);
  g12.insertedge("s","z",7);
  g12.insertedge("z","s",7);
  g12.insertedge("t","x",1);
  g12.insertedge("x","t",1);
  g12.insertedge("t","y",2);
  g12.insertedge("y","t",2);
  g12.insertedge("y","x",9);
  g12.insertedge("x","y",9);
  g12.insertedge("y","z",2);
  g12.insertedge("z","y",2);
  g12.insertedge("z","x",4);
  g12.insertedge("x","z",4);
//  g12.createdotfile("t12a.dot");
  g12.initarr();
  graphedge ge;
  ge.key = 0;
  ge.vertex = "invalid";
  string source = "invalid";
  for (std::map<string,int>::iterator it = g12.mv.begin(); it != g12.mv.end(); it++)
  {
    string vertexname = it->first;
    g12.dijkstra(vertexname);
    for (int i = 0; i < g12.count; i++)
    {
       if ((g12.arr[i].key != 100000) && (g12.arr[i].key > ge.key))
       {
         source = it->first;
         ge.key = g12.arr[i].key;
         ge.vertex = g12.arr[i].vertex;
       }
     }
     g12.initarr();
   }
  g12.initarr();
  g12.dijkstra(source);
  cout << "Final longest cost path between two vertices is " << endl;
  int findIndex = g12.findarrIndex(ge.vertex, g12.count);
  stringstream s;
  s.str("");
  while(g12.arr[findIndex].vertex.compare("invalid") != 0)
  {
    s << g12.arr[findIndex].vertex << "---";
    findIndex = g12.findarrIndex(g12.arr[findIndex].pred, g12.count);
    if (findIndex == -1)
      break;
  }
  string mystr(s.str());
  reverse(mystr.begin(), mystr.end());
  mystr.erase(0,3);
/*  mystr.append("---");
  mystr.append(it2->first);*/
  cout << endl << mystr << endl;
  g12.createcolorfile("t12.dot");

  cout << endl << endl << "*****End of Testcase12 Execution*****" << endl << endl;
}

int main()
{
  testcase1();
  testcase2();
  testcase3();
  testcase4();
  testcase5();
  testcase6();
  testcase7();
  testcase8();
  testcase9();
  testcase10();
  testcase11();
  testcase12();
}
