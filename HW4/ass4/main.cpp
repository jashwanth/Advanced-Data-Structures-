#include "graph.h"

void testcase1()
{
  cout << endl << endl << "*****Begin of Testcase1 Execution*****" << endl << endl;
  graph g1;
  g1.constructGraph("fig1.csv");
  cout << "Constructed graph from file fig1.csv" << endl;
  cout << "list of all vertices is " << endl;
  for (std::map<char,int>::iterator it = g1.mv.begin(); it != g1.mv.end(); it++)
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
  for (std::map<char,int>::iterator it = g2.mv.begin(); it != g2.mv.end(); it++)
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
  for (std::map<char,int>::iterator it = g3.mv.begin(); it != g3.mv.end(); it++)
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
  for (std::map<char,int>::iterator it = g4.mv.begin(); it != g4.mv.end(); it++)
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
  g4.insertvertex('z');
  cout << "Added the vertex \"z\" to the graph" << endl;
  g4.insertedge('z', 'w', 1);
  g4.insertedge('w', 'z', 1);
  cout << "Inserted the edge between \"z\" and \"w\" " << endl;
  g4.insertedge('z', 'x', 1);
  g4.insertedge('x', 'z', 1);
  cout << "Inserted the edge between \"z\" and \"x\" " << endl;
  g4.insertedge('z', 'y', 1);
  g4.insertedge('y', 'z', 1);
  cout << "Inserted the edge between \"z\" and \"y\" " << endl;
  g4.createdotfile("t4a.dot");
  cout << "Created dot file t4a.dot" << endl;
  g4.removevertex('s');
  cout << "Removed the vertext \"s\" from the graph " << endl;
  g4.removevertex('x');
  cout << "Removed the vertext \"x\" from the graph " << endl;
  g4.removeedge('u','t',1);
  g4.removeedge('t','u',1);
  cout << "Removed the edge between \"u\" and \"v\" from the graph" << endl;
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
  g5.insertedge('6','7',1);
  g5.insertedge('7','6',1);
  cout << "Inserted a new edge between \"6\" and \"7\" to the graph" << endl;
  g5.insertedge('7','8',1);
  g5.insertedge('8','7',1);
  cout << "Inserted a new edge between \"7\" and \"8\" to the graph" << endl;
  g5.insertedge('8','9',1);
  g5.insertedge('9','8',1);
  cout << "Inserted a new edge between \"8\" and \"9\" to the graph" << endl;
//  g5.insertedge('9','10',1);
//  g5.insertedge('9','8',1);
//  cout << "Inserted a new edge between \"8\" and \"9\" to the graph" << endl;
  g5.insertvertex('1');
  g5.insertvertex('2');
  g5.insertvertex('3');
  g5.insertvertex('4');
  g5.insertvertex('5');
  cout << "Inserted vertices 1,2,3,4,5 to the graph" << endl;
  g5.createdotfile("t5a.dot");
  cout << endl << endl << "*****End of Testcase5 Execution*****" << endl << endl;

}

int main()
{
  testcase1();
  testcase2();
  testcase3();
  testcase4();
  testcase5();
}
