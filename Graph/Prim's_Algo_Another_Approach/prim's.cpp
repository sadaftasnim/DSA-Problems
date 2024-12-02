//Prim's Algorithm is an efficient way to find the Minimum Spanning Tree (MST) of a connected, undirected graph.
//To find the Minimum Spanning Tree, which means connecting all nodes with the least possible edge weight.

//Starts from one node and keeps adding the smallest edge that connects to a new node until all nodes are connected.

#include <iostream>
#include <climits>
using namespace std;


int findMinVertex(int* weights, bool* visited , int v)
{
    int minVertex = -1;

    for(int i = 0 ; i < v ; i++)
    {
        if(!visited[i] && (minVertex == -1 || weights[i] < weights[minVertex]))
        {
            minVertex = i;
        }
    }
    return minVertex;
}

void prims(int** edges , int v )
{

    int* parent = new int[v];
    int* weights = new int[v];
    bool* visited = new bool[v];
    for(int i = 0 ; i < v ; i++)
    {
        visited[i] = false;
        weights[i] = INT_MAX;
    }


    parent[0] = -1;
    weights[0] = 0;

     for(int i = 0 ; i < v-1 ; i++)
     {

         int minVertex = findMinVertex(weights,visited ,v);
         visited[minVertex] = true;

         for(int j = 0  ; j < v ; j++)
         {
             if(edges[minVertex][j] != 0 && !visited[j])
             {
                 if(edges[minVertex][j] < weights[j])
                 {
                     weights[j] = edges[minVertex][j];
                     parent[j] = minVertex ;
                 }
             }
         }

     }


     for(int i = 1; i < v ; i++)
     {
         if(parent[i] < i)
         {
             cout << parent[i] << " " << i << " " << weights[i]  << endl;
         }

         else
         {
             cout << i << " " << parent[i] << " " << weights[i] <<  endl;
         }
     }

   delete [] parent;
   delete [] weights;
   delete [] visited;

}


int main()
{
    int v , e;
    cout << "Please enter the number of vertices and edges :" ;
    cin >> v >> e;

    int** edges = new int*[v];
    for(int i = 0  ; i < v ; i++)
    {
        edges[i] = new int[v];

        for(int j = 0 ; j < v ; j++)
        {
            edges[i][j] = 0;
        }
    }

    for(int i = 0 ; i < e ; i++)
    {
        int f , s , weight;
        cin >> f >> s >> weight;

        edges[f][s] = weight;
        edges[s][f] = weight;
    }
    cout  << endl;
    prims(edges , v );

    for(int i = 0; i < v ; i++)
    {
        delete [] edges[i];
    }
    delete [] edges;
}



/*
              6
       1------------3
    4 /|          / |
     / |       3 /  |
    0  |2       /   | 5
     \ |       /    |
    8 \|      /     |
       2------------4
             9

v e
5 7

f s w
0 1 4
0 2 8
1 3 6
1 2 2
2 3 3
2 4 9
3 4 5


output

0 1 4
1 2 2
2 3 3
3 4 5

Edges: Each edge is defined by two vertices f and s, and the weight of the edge.
The graph is represented as an adjacency matrix (edges):
edges[i][j] holds the weight of the edge between vertex i and vertex j.
If there is no edge, the value is 0.

parent: Stores the parent of each vertex in the MST.
weights: Keeps track of the minimum weight needed to connect a vertex to the MST.
visited: Marks whether a vertex has been added to the MST.

findMinVertex
Finds the unvisited vertex with the smallest weight.
This helps select the next vertex to add to the MST.

Start with vertex 0.
Set its weight to 0 (weights[0] = 0) because we are beginning there.
Mark all other vertices as unvisited and set their weights to infinity (INT_MAX).
Build the MST:


Find the unvisited vertex with the smallest weight (using findMinVertex).
Add it to the MST (visited[minVertex] = true).
Update the weights of its neighbors:

             */
