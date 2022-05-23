#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define N 6

class Graph
{
private:
    int AdjMatrix[N][N];
    int N_Vertices;
    int N_Edges;

public:
    Graph()
    {
        N_Edges = 0;
        N_Vertices = 0;

        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                AdjMatrix[i][j] = 0;
            }
        }
    }

    Graph(int edges, int vertices)
    {
        N_Edges = edges;
        N_Vertices = vertices;

        for (int i = 0; i < N_Vertices; i++)
        {
            for (int j = 0; j < N_Vertices; i++)
            {
                AdjMatrix[i][j] = 0;
            }
        }
    }

    void Create_Graph()
    {
        cout << "Enter The Total Number of Edges: " << endl;
        cin >> N_Edges;
        for (int i = 0; i < N_Edges; i++)
        {
            int u, v;
            cout << "Enter the Start and Destination of the edge: " << i + 1 << endl;
            cin >> u >> v;
            AdjMatrix[u][v] = 1;
            AdjMatrix[v][u] = 1;
        }
    }

    void DFS(int start_vertex)
    {
           
    }

    void BFS(int start)
    {
        int Visited[10] = {0};
        int u, v;
        queue<int> q;

        cout << start << " ";
        Visited[start] = 1;

        q.push(start);

        while (!q.empty())
        {
            u = q.front();

            q.pop();

            for (v = 0; v < N; v++)
            {
                if (AdjMatrix[u][v] == 1 && Visited[v] == 0)
                {
                    cout << v << " ";
                    q.push(v);
                    Visited[v] = 1;
                }
            }
        }
    }

    void Display_Graph()
    {
        if (N > 0)
        {
            for (int i = 0; i < N; i++)
            {
                for (int j = 0; j < N; j++)
                {
                    cout << AdjMatrix[i][j] << " ";
                }
                cout << endl;
            }
        }
        else
        {
            cout << "Null Graph" << endl;
        }
    }
};

int main()
{
    Graph g;
    int Strt, choice;

    char flag = true;

    while (flag)
    {
        cout << "______________________________________________________________________\n";
        cout << endl;
        cout << "Welcome To Graph !!!" << endl;
        cout << "______________________________________________________________________\n";
        cout << "\n1.Create Graph\n2.BFS Traversal\n3.DFS Traversal\n4.Display Adjacency Matrix\n5.Exit\n\nWhat Do you Want To Do ?" << endl;

        cin >> choice;
        switch (choice)
        {
        case 1:
            g.Create_Graph();
            break;
        case 2:
            cout << "Enter the starting vertex for BFS: " << endl;
            cin >> Strt;
            g.BFS(Strt);
            break;
        case 3:
            cout << "Enter the starting vertex for DFS: " << endl;
            cin >> Strt;
            g.DFS(Strt);
            break;
        case 4:
            g.Display_Graph();

            break;
        case 5:
            exit(0);
            break;
        default:
            break;
        }
        char flag2;
        cout << "Do you Want to continue:(y or n) " << endl;
        cin >> flag2;
        if (flag2 == 'n')
        {
            flag = false;
        }
    }
    return 0;
}