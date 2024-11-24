class Solution {
public:

 //1st Approach
   bool dfs(int source , int clr, vector<vector<int>>& graph , vector<int>& visited , vector<int>& color)
   {
     visited[source] = true;
     color[source] = clr;

     //for(auto& neigh : graph[source])
     for(int i = 0 ; i < graph[source].size() ; i++)
     {
        int neigh = graph[source][i];
        if(!visited[neigh])
        {
            if(!dfs( neigh , !clr , graph , visited , color))
                {
                    return false;
                }
        }

      else if(color[neigh] == color[source])
        {
          return false;
        }
        
     }
     return true;

   }


    bool isBipartite(vector<vector<int>>& graph) {

        
    int v = graph.size(); 
    vector <int> color(v , -1);
    vector<int> visited (v , 0);

       
       for(int i = 0 ; i < v ; i++) //if source does not have neighbour then we have to go for next source and find its neighbour,
        {
            if(!visited[i])
            {
                if(!dfs( i , 0 , graph , visited , color))
                {
                    return false;
                }
            }
       }

         return true;
       
        
        
    }



    // 2nd Approach
   /* bool dfs(int source ,  vector<vector<int>>& graph , vector<int>& color)
     {
     
     for(int neigh_index = 0 ; neigh_index < graph[source].size() ; neigh_index++)
     {
        int neighbour = graph[source][neigh_index];
        
        if(color[neighbour] == -1)
        {
            color[neighbour] = 1 ^ color[source];
        
            if(!dfs( neighbour , graph  , color))
                {
                    return false;
                }
        
        }
       if(color[neighbour] == color[source])
        {
          return false;
        }
        
     }
     return true;

   }


    bool isBipartite(vector<vector<int>>& graph) {

    int v = graph.size(); 

    vector <int> color(v , -1);

       color[0] = 0;
       for(int source = 0 ; source < v ; source++) //if source does not h ave neighbour then we have to go for next source and find its neighbour,
        {
               if(!dfs( source , graph  , color))
                {
                    return false;
                }
            
       }

         return true;
       
        
        
    }*/
};