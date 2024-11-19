//Finds the shortest path from a starting node to all other nodes in a graph with non-negative weights.


#include <iostream>
#include <climits>
using namespace std;


int findMinVertex(int* distance, bool* visited , int v)
{
    int minVertex = -1;

    for(int i = 0 ; i < v ; i++)
    {
        if(!visited[i] && (minVertex == -1 || distance[i] < distance[minVertex]))
        {
            minVertex = i;
        }
    }
    return minVertex;
}

void dijkstra(int** edges , int v )
{


    int* distance = new int[v];
    bool* visited = new bool[v];
    for(int i = 0 ; i < v ; i++)
    {
        visited[i] = false;
        distance[i] = INT_MAX;
    }

    distance[0] = 0;

     for(int i = 0 ; i < v-1 ; i++)
     {

         int minVertex = findMinVertex(distance,visited ,v);
         visited[minVertex] = true;

         for(int j = 0  ; j < v ; j++)
         {
             if(edges[minVertex][j] != 0 && !visited[j])
             {
                 int dist = distance[minVertex] + edges[minVertex][j];
                 if(dist < distance[j])
                 {
                     distance[j] = dist;
                 }
             }
         }

     }


     for(int i = 0; i < v ; i++)
     {
         cout << i << " " << distance[i] <<endl;
     }


   delete [] distance;
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
    dijkstra(edges , v );

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
     / |      3  /  |
    0  |2       /   | 4
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
3 4 4


output:
0 0
1 4
2 6
3 9
4 13

*/
