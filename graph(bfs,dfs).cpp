 #include <iostream>
using namespace std;
#include <queue>
#include <vector>
#include <unordered_map>
#include <algorithm>


void dfs_print(int** edges , int v , int start_vrtx , bool* visited)
{
    cout << start_vrtx << " " ;
    visited[start_vrtx] = true;     // mark visited and don't visit again

    for(int i = 0 ; i < v ; i++)
    {
        if(start_vrtx == i)
        {
            continue;
        }

        if(edges[start_vrtx][i] == 1)
        {
            if(visited[i] == true)
            {
                continue;
            }

            dfs_print(edges , v , i , visited);
        }
    }


}


void bfs_print(int** edges , int v , int start_vertex)
{
    queue <int> pending_vertices;

    bool* visited = new bool[v];
    for(int i = 0 ; i < v ; i++)
    {
        visited[i] = false;
    }

    pending_vertices.push(start_vertex);
    visited[start_vertex] = true;

    while(!pending_vertices.empty())
    {
        int current_vrtx = pending_vertices.front();
        pending_vertices.pop();

        cout << current_vrtx <<" " ;

        for(int i = 0 ; i < v ; i++)
        {
            if(i == current_vrtx)
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
    delete [] visited;
}



bool hasPath_using_dfs(int** edges , int v, int start_vrtx , int end_vrtx , bool* visited)
{

    if(start_vrtx == end_vrtx)
        {
            return true;
        }
    visited[start_vrtx] = true;

    for(int i = 0 ; i < v ; i++)
      {
        if(start_vrtx == i)
         {
            continue;
         }

        if(edges[start_vrtx][i] == 1)
         {
            if(visited[i])
             {
                continue;
             }
             // Recursively check if there's a path from the start vertex to the end vertex
            bool got_ans = hasPath_using_dfs(edges , v , i , end_vrtx , visited);
            if(got_ans)
            {
                return true;
            }
          }
       }
        return false;

}

bool hasPath_using_Bfs(int** edges , int v, int start_vrtx , int end_vrtx , bool* visited)
{
    if(start_vrtx == end_vrtx)
    {
        return true;
    }

    queue <int> q;
    visited[start_vrtx] = true;

    q.push(start_vrtx);

    while(!q.empty())
    {
        int currentEdge = q.front();
        q.pop();

        for(int i = 0 ; i < v ; i++)
        {

            if(edges[currentEdge][i] == 1 && !visited[i])
            {

               if(i == end_vrtx)
                {
                    return true;
                }

                q.push(i);
                visited[i] = true;
            }
        }
    }

    return false;


}

/*bool is_valid(int x , int v_ )
{
    if(x >=0 && x < v_)
    {
        return true;
    }
    return false;
}*/

bool path_between_sv_to_ev_using_Dfs(int** edges , int v , int sv , int ev , bool* visited , vector<int>& path)
{
    /*if(!is_valid(sv , v) || !is_valid(ev , v))
        return false;*/

        if(!(sv >= 0 && sv < v) || !(ev >= 0 && ev < v)) //if we are giving 4 vertices(0,1,2,3) and 3 edges(0-1,0-2,1-3) then we can,t check there is an edge or not(1-4 or 2-4 so on ).we will have to give sv < 4 nd ev < 4
        {
            return false;
        }


    path.push_back(sv);
    visited[sv] = true;

    if(sv == ev)
    {
        return true;
    }



    for(int i = 0 ; i < v ; i++)
    {
        if(sv == i)
            continue;

        if(edges[sv][i] == 1)
        {
            if(visited[i])
            {
                continue;
            }

            if(path_between_sv_to_ev_using_Dfs(edges , v ,i , ev , visited , path))
            {
                return true;
            }

            else
            {
                path.pop_back();   //Backtrack if no path is found
            }

        }
    }


    return false;

}





vector<int> path_between_sv_to_ev_using_Bfs(int** edges , int v , int sv , int ev , bool* visited )
{
    vector<int> path; // it store path if exists

    if(!(sv >= 0 && sv < v) || !(ev >= 0 && ev < v)) //if we are giving 4 vertices(0,1,2,3) and 3 edges(0-1,0-2,1-3) then we can,t check there is an edge or not(1-4 or 2-4 so on ).we will have to give sv < 4 nd ev < 4
        {

            return path;
        }

    if(sv == ev)      // if sv and ev are same
    {
        path.push_back(sv);
        return path;
    }

    queue<int> q;     // queue store level wise connecting vertex

    q.push(sv);
    visited[sv] = true;

    unordered_map<int , int> parent_map;      //  We use parentMap to store the parent of each vertex. This will help us backtrack to reconstruct the path once we reach the end vertex

    bool pathFound = false;

    while(!q.empty() && !pathFound) // We continue the BFS while the queue is not empty and a path has not been found.
    {
        int current = q.front();
        q.pop();                     //We remove the front element of the queue and set it as the current vertex (current)

        for(int i = 0 ; i < v ; i++)
        {
            if(edges[current][i] == 1 && ! visited[i])
            {
                q.push(i);
                visited[i] = true;
                parent_map[i] = current;

                if(i == ev)
                {
                    pathFound = true;
                    break;
                }
            }
        }
    }



    if(pathFound)
    {
        int current = ev;

        while(current != sv)
        {
            path.push_back(current);

            current = parent_map[current];
        }

        path.push_back(sv);

       reverse(path.begin(), path.end());
    }

    return path;
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

    bool* visited = new bool[v];
    for(int i = 0 ; i < v ; i++)
    {
        visited[i] = false;     // not visited
    }

    /*cout << "DFS Traversal" << ":" ;
    dfs_print(edges , v , 0 , visited);
    cout << endl;

    cout << "BFS Traversal" << ":" ;
    bfs_print(edges , v , 0);
    cout << endl;*/

    // calling hasPath function
    int sv , ev;
    cin >> sv >> ev;
     bool ans = hasPath_using_Bfs(edges, v , sv , ev , visited);
     if(ans)
     {
        cout <<"path exists between "<< sv << " to " << ev << " ! "<<endl;
        cout << endl;

     }
     else
     {
        cout <<"path doesn't exists between "<< sv << " to " << ev << " ! "<<endl;
     }

     // calling path_between_sv_to_ev_using_Dfs

   /* vector<int> path ;
    int sv , ev;
    cin >> sv >> ev;

    if(path_between_sv_to_ev(edges , v , sv , ev , visited , path))

    {
        cout << "Path between "<< sv <<" to " << ev <<" : " ;
        for(int i = 0 ; i < path.size() ; i++)
        {
            cout << path[i] << " ";
        }
        cout << endl;
    }

    else
    {
        cout << "Path doesn't exist between "<< sv <<" to " << ev <<"!" << endl;
    }
*/


// calling path_between_sv_to_ev_using_Bfs


   /* int sv , ev;
    cin >> sv >> ev ;
    vector<int> path = path_between_sv_to_ev_using_Bfs(edges , v , sv , ev , visited);


        if(path.size() == 0)
        {
            cout << "Path doesn't exists" << endl;
            cout << "sv or ev or both is not valid" << endl;
        }

        else
        {

            cout << "path between " << sv <<" to " << ev << " : " ;

            for(int i = 0 ; i < path.size() ; i++)
            {
                cout << path[i] << " " ;
            }
            cout << endl;
        }*/




     delete [] visited;

     for(int i = 0 ; i < v ; i++)
     {
         delete [] edges[i];
     }

     delete [] edges;

     return 0;

}
