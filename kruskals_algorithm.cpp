/*Kruskal's Algorithm is another way to find the Minimum Spanning Tree (MST) of a connected, undirected graph.
 It works by selecting the smallest edges in the graph, ensuring they don’t form a cycle,
  until all nodes are connected with the minimum total edge weight.*/

//Adds the smallest edges from anywhere in the graph, one at a time, until all nodes are connected.


#include <iostream>
using namespace std;
#include <algorithm>
class Edge{
 public:
    int source;
    int dest;
    int weight;
};

bool compare(Edge e1 , Edge e2)
{
    return e1.weight < e2.weight;
}


int findParent(int vertex , int* parent)    // union find technique
{
    if(parent[vertex] == vertex)
    {
        return vertex;
    }

    return findParent(parent[vertex] , parent);
}

void kruskals(Edge* input , int v , int e)
{
    //sort the input array in ascending order based on weights
    sort(input , input+e , compare);
     // 0th index    last index

    Edge* output = new Edge[v-1];

    int* parent = new int[v];
    for(int i = 0 ; i < v ; i++)
    {
        parent[i] = i;
    }

    int count = 0 ;
    int i = 0;

    while(count != v-1)
    {
        Edge currentEdge =  input[i];
        int sourceParent =  findParent(currentEdge.source , parent); //cycle detection
        int destParent = findParent(currentEdge.dest , parent);

        if(sourceParent != destParent)             //if sourceParent == destParent ,means if we add this currentEdge ,a cycle is introduced
        {
            output[count] = currentEdge;
            count++;
            parent[sourceParent] = destParent;
        }
       i++;
    }

    for(int i = 0 ; i < v-1 ; i++)
    {
        if(output[i].source < output[i].dest)
        {
            cout << output[i].source <<" " << output[i].dest <<" " << output[i].weight << endl;
        }

        else
        {
            cout << output[i].dest <<" " << output[i].source << " " << output[i].weight << endl;

        }
    }





}


int main()
{
    int v , e ;
    cin >> v >> e;

    Edge* input = new Edge[e];

    for(int i = 0 ; i < e ; i++)
    {
        int s , d , w;
        cin >> s >> d >> w;

        input[i].source = s;
        input[i].dest = d;
        input[i].weight = w;
    }

    kruskals(input , v , e);

/*


        2
    0------1
    |\3  8/|
    | \  / |
  4 |  \/  |1
    |  /\  |
    | /  \ |
    |/  6 \|
    2------3
    |\10  /|
    | \  / |
   9|  \/  |7
    |  /\11|
    | /  \ |
    |/    \|
    4------5
        5


v   e
6  11

v e w

1 3 1
0 3 3
4 5 5
3 5 7
2 4 9
3 4 11
2 5 10
2 1 8
0 2 4
0 1 2
2 3 6

output
1 3 1
0 1 2
0 2 4
4 5 5
3 5 7*/


}

