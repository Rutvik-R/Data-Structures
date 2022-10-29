#include <iostream>
#include <vector>
using namespace std;

class graph
{
    int nodes;
    vector<vector<int>> edges;

public:
    graph(int n)
    { 
        this->nodes = n;
        edges.resize(n + 1);
    }

    graph(int n, vector<vector<int>> edgs)
    {

        this->nodes = n;
        edges.resize(n + 1);
        this->insert_edge(edgs);
    }

    void insert_edge(int, int);
    void insert_edge(vector<int>);
    void insert_edge(vector<vector<int>>);
    void print_Breadth_First_search(int);
    void print_Depth_First_search(int);
    void depth_first_search(int, vector<bool> &);
    bool connected();
    int connected_components();
    void travel(int, vector<bool> &visited);
};

int main()
{
    graph g(8);

    int x = 5;

    while (x--)
    {
        int a, b;
        cin >> a >> b;
        g.insert_edge(a, b);
    }

    // g.print_Breadth_First_search(1);
    // cout<<((g.connected())?"YES\n":"NO\n");
    // cout<<g.connected_components();
    g.print_Depth_First_search(1);

    return 0;
}

void graph::insert_edge(int a, int b)
{
    this->edges[b].push_back(a);
    this->edges[a].push_back(b);
}

void graph::insert_edge(vector<int> edge)
{
    this->insert_edge(edge[0], edge[1]);
}

void graph::insert_edge(vector<vector<int>> edgs)
{
    for (auto edg : edgs)
        this->insert_edge(edg);
}

void graph::print_Breadth_First_search(int first_node)
{
    vector<bool> visited(this->nodes + 1, false);
    vector<int> curr_visit(0), new_visit(0);
    curr_visit.push_back(first_node);

    visited[first_node] = true;

    while (curr_visit.size())
    {
        new_visit.clear();
        for (int node : curr_visit)
        {
            cout << node << " ";
            for (auto next_node : this->edges[node])
                if (!visited[next_node])
                {
                    visited[next_node] = true;
                    new_visit.push_back(next_node);
                }
        }
        cout << "\n";
        curr_visit = new_visit;
    }
}

bool graph::connected()
{
    return ((this->connected_components() == 1) ? true : false);
}

int graph::connected_components()
{
    vector<bool> visited(this->nodes + 1, false);
    int components = 0;
    for (int i = 1; i <= this->nodes; i++)
    {
        if (visited[i] == false)
        {
            travel(i, visited);
            components++;
        }
    }

    return components;
}

void graph::travel(int first, vector<bool> &visited)
{
    for (int next_node : this->edges[first])
    {
        if (visited[next_node] == false)
        {
            visited[next_node] = true;
            travel(next_node, visited);
        }
    }
}

void graph::print_Depth_First_search(int first_node)
{
    vector<bool> visited(this->nodes + 1, false);
    depth_first_search(first_node, visited);
}

void graph::depth_first_search(int node, vector<bool> &visited)
{
    cout << node << " ";
    visited[node] = true;

    for (int next_node : this->edges[node])
    {
        if (visited[next_node] == false)
            depth_first_search(next_node, visited);
    }
}