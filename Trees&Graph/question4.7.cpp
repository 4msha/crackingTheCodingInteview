/*------------------------------------------------------------------------------------------------------------------------
                    Chapter-4    Trees And Graph 

    4.7)Build Order:There are a total of n projects you have to take labelled from 0 to n - 1.
                    Some projects may have prerequisites, for example, if prerequisites[i] = [ai, bi] 
                    this means you must take the course bi before the course ai.
                    Given the total number of projects numprojects and a list of the prerequisite pairs, 
                    return the ordering of projects you should take to finish all projects.
                    If there are many valid answers, return any of them. If it is impossible to finish all projects,
                    return an empty array.
-------------------------------------------------------------------------------------------------------------------------*/

#include <bits/stdc++.h>
using namespace std;

vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites)
{

    map<int, unordered_set<int>> graph;
    for (int i{0}; i < prerequisites.size(); i++)
    {
        graph[prerequisites[i][1]].insert(prerequisites[i][0]);
    }

    vector<int> ans;
    queue<int> queue;
    for (int i{0}; i < numCourses; i++)
    {
        if (graph.find(i) == graph.end())
        {
            queue.push(i);
        }
    }

    while (!queue.empty())
    {
        int t = queue.front();
        queue.pop();
        ans.emplace_back(t);

        vector<int> temp;
        for (auto &x : graph)
        {
            if (x.second.find(t) != x.second.end())
            {
                x.second.erase(t);
                if (x.second.size() == 0)
                {
                    temp.emplace_back(x.first);
                    queue.push(x.first);
                }
            }
        }

        for (auto &x : temp)
        {
            graph.erase(x);
        }
    }

    if (graph.size() == 0)
        return ans;
    ans.clear();
    return ans;
}

int main()
{
    int n;
    cout << " Enter The no. of Courses \n";
    cin >> n;
    vector<int> ans;
    vector<vector<int>> prerequisites;
    int choice;

    while (1)
    {
        cout << "if theres a pair enter 1 else 0\n";
        cin >> choice;
        if (!choice)
            break;
        cout << "enter then pair\n";
        vector<int> temp(2, 0);
        int l, r;
        cin >> l >> r;
        temp[0] = l;
        temp[1] = r;
        prerequisites.emplace_back(temp);
    }

    ans = findOrder(n, prerequisites);

    for (auto &x : ans)
    {
        cout << x << "   ";
    }
    cout << endl;

    return 0;
}
