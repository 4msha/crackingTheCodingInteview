/*---------------------------------------------------------------------------------------------
                    Chapter-4    Trees And Graph 
    4.1)   Route Between Nodes: Given a directed graph,design an algorithm to find out 
                                whether there is a route between two nodes.

--------------------------------------------------------------------------------------------*/

#include <bits/stdc++.h>
using namespace std;

vector<int> returnRandomNeighbour(int n, int v)
{
    int x = (rand() % n) + 1;
    set<int> set;
    int count{0};
    for (int i{0}; count < x; i++)
    {
        int temp = rand() % n;
        if (temp != v)
        {
            set.insert(temp);
            count++;
        }
    }
    vector<int> vec;
    for (auto &t : set)
        vec.emplace_back(t);

    return vec;
}

map<int, vector<int>> createRandomGraph(int n)
{
    map<int, vector<int>> map;
    for (int i{0}; i < n; i++)
    {
        vector<int> vec = returnRandomNeighbour(n, i);
        map[i] = vec;
    }
    return map;
}

//bfs
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

//bfs with both end
bool findRoute2(map<int, vector<int>> &graph, int node1, int node2)
{
    set<int> visit1, visit2;

    queue<int> start, end;

    start.push(node1);
    end.push(node2);

    visit1.insert(node1);
    visit2.insert(node2);

    while (!start.empty() && !end.empty())
    {
        int t = start.front();
        start.pop();

        for (auto x : graph[t])
        {
            if (visit2.find(x) != visit2.end())
            {
                return true;
            }
            else
            {
                if (visit1.find(x) == visit1.end())
                {
                    visit1.insert(x);
                    start.push(x);
                }
            }
        }

        t = end.front();
        end.pop();
        for (auto x : graph[t])
        {
            if (visit1.find(x) != visit1.end())
            {
                return true;
            }
            else
            {
                if (visit2.find(x) == visit2.end())
                {
                    visit2.insert(x);
                    end.push(x);
                }
            }
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

    for (auto x : graph)
    {
        cout << x.first << " : ";
        for (auto y : x.second)
        {
            cout << y << " ";
        }
        cout << "\n";
    }

    return 0;
}