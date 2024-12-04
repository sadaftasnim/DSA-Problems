#include <iostream>
using namespace std;
#include <queue>


void dfs_print(int** edges , int v , int starting_vrtx , bool* visited)
{
    cout << starting_vrtx << " " ;
    visited[starting_vrtx] = true;     // mark visited and don't visit again

    for(int i = 0 ; i < v ; i++)
    {
        if(starting_vrtx == i)
        {
            continue;
        }

        if(edges[starting_vrtx][i] == 1)
        {
            if(visited[i] == true)
            {
                continue;
            }

            dfs_print(edges , v , i , visited);
        }
    }


}


void bfs_print(int** edges , int v , int start_vertex , bool* visited)
{
    queue <int> pending_vertices;

    pending_vertices.push(start_vertex);
    visited[start_vertex] = true;

    while(!pending_vertices.empty())
    {
        int current_vrtx = pending_vertices.front();
        pending_vertices.pop();

        cout << current_vrtx <<" " ;

        for(int i = 0 ; i < v ; i++)
        {
            if(current_vrtx == i)
            {
                continue;
            }

            if(edges[current_vrtx][i] == 1 && !visited[i])
            {
                pending_vertices.push(i);
                visited[i] = true;
            }
        }
    }

}


void dfs(int** edges , int v)
{
    bool* visited = new bool[v];
    for(int i = 0 ; i < v ; i++)
    {
        visited[i] = false;     // not visited
    }

    for(int i = 0 ; i < v ; i++)                        //after 1st ireration 0 , 2 , 3 will be print then 1 and 4 then 5 and 6
    {
        if(!visited[i])
        {
            dfs_print(edges , v , i , visited);                            //     0            1        5     this is a disconnected graph
        }                                                                 //    /   \          |        |
    }                                                                    //    2     3         4        6



    delete [] visited;
}


void bfs(int** edges , int v)
{
    bool* visited = new bool[v];
    for(int i = 0 ; i < v ; i++)
    {
        visited[i] = false;     // not visited
    }

    for(int i = 0 ; i < v ; i++)
    {
        if(!visited[i])
        {
            bfs_print(edges , v , i , visited);
        }
    }

    delete [] visited;
}



int main()
{
    int v , e;
    cin >> v >>e;

    int** edges = new int*[v];

    for(int i = 0 ; i < v ; i++)
    {
        edges[i] = new int[v];
        for(int j = 0 ; j < v ; j++)
        {
            edges[i][j] = 0;
        }
    }


    for(int i = 0 ; i < e ; i++)
    {
        int first_vrtx , second_vrtx;
        cin >> first_vrtx >>second_vrtx;

        edges[first_vrtx][second_vrtx] = 1;  // means between first_vrtx and second_vrtx there is an edge
        edges[second_vrtx][first_vrtx] = 1; // between second_vrtx and first_vrtx there is also an edge
    }



    cout << "DFS Traversal" << ":" ;
    dfs(edges , v );
    cout << endl;

    cout << "BFS Traversal" << ":" ;
    bfs(edges , v);
    cout << endl;



     for(int i = 0 ; i < v ; i++)
     {
         delete [] edges[i];
     }

     delete [] edges;

}
