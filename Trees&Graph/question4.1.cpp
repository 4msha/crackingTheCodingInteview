/*---------------------------------------------------------------------------------------------
                    Chapter-4    Trees And Graph 
    4.1)   Route Between Nodes: Given a directed graph,design an algorithm to find out 
                                whether there is a route between two nodes.

--------------------------------------------------------------------------------------------*/

#include <bits/stdc++.h>
using namespace std;
#include "supportFunction.h"

bool findRoute(map<int, vector<int>> graph, int node1, int node2, int v)
{
    //traversing the graph by Breadth First Search Approach
    queue<int> queue;
    queue.push(node1);

    while (!queue.empty())
    {
        int t = queue.front();
        queue.pop();

        for (auto &x : graph[t])
        {
            if (x == node2)
            {
                return true;
            }
            queue.push(x);
        }
    }
    return false;
}

int main()
{
    map<int, vector<int>> graph;
    int v;

    cout << "Enter the no on vertices\n";
    cin >> v;

    //initialising a random graph code in supportFucntion.cpp
    graph = createRandomGraph(v);

    int node1, node2;
    cout << "Enter the node bw which connection is to be found\n";
    cin >> node1 >> node2;

    if (findRoute(graph, node1, node2, v))
    {
        cout << "Yes, theres a route between node " << node1 << " and node " << node2 << endl;
    }
    else
    {
        cout << "No, theres no route between node " << node1 << " and node " << node2 << endl;
    }

    return 0;
}