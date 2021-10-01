// Copyright srcmake 2018.
// C++ Example Breadth First Search (BFS) Code. And Adjacency Lists.
/* BFS concept: In a graph, starting from a certain node, visit all other nodes.
The order of visiting is "all of my friends first, then my friends friends".
*/

/* BFS coding:
// Create a "visited" array (true or false) to keep track of if we visited a vertex.
// Create a queue for the nodes we visit.
// Add the starting vertex to the queue and mark it as visited.
// While the queue is not empty..
    // Loop through all of it's friends.
        // If the friend hasn't been visited yet, add it to the queue and mark it as visited.
*/

// The example graph: https://www.srcmake.com/uploads/5/3/9/0/5390645/graph_orig.jpg

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// Adjacency List - Adding O(1), Lookup O(N), Space O(N^2) but usually better.
// Each vector position represents a node - the vector inside that position represents that node's friends.
vector< vector<int> > FormAdjList()
    {
    // Our adjacency list.
    vector< vector<int> > adjList;
    
    // We have 10 vertices, so initialize 10 rows.
    const int n = 9;
    
    for(int i = 0; i < n; i++)
        {
        // Create a vector to represent a row, and add it to the adjList.
        vector<int> row;
        adjList.push_back(row);
        }
    
    // Now "adjList[0]" has a vector<int> in it that represents the friends of vertex 1. 
    // (Remember, we use 0-based indexing. 0 is the first number in our vector, not 1.
    
    // Now let's add our actual edges into the adjacency list.
    // See the picture here: https://www.srcmake.com/uploads/5/3/9/0/5390645/adjl_4_orig.png
    
    adjList[0].push_back(2);
    adjList[0].push_back(4);
    adjList[0].push_back(6);
    
    adjList[1].push_back(4);
    adjList[1].push_back(7);
    
    adjList[2].push_back(0);
    adjList[2].push_back(5);
    
    adjList[3].push_back(4);
    adjList[3].push_back(5);
    
    adjList[4].push_back(1);
    adjList[4].push_back(3);
    adjList[4].push_back(0);
    
    adjList[5].push_back(2);
    adjList[5].push_back(3);
    adjList[5].push_back(8);
    
    adjList[6].push_back(0);
    
    adjList[7].push_back(1);
    
    adjList[8].push_back(5);
    
    // Our graph is now represented as an adjacency list. 
    return adjList;
    }
    
// Adjacency Matrix - Adding O(N), Lookup O(1), Space O(N^2)
vector< vector<int> > FormAdjMatrix()
    {
    // We could use an array for the adjMatrix if we knew the size, but it's safer to use a vector.
    vector< vector<int> > adjMatrix;
    
    // Initialize the adjMatrix so that all vertices can visit themselves.
    // (Basically, make an identity matrix.)
    const int n = 9;
    
    for(int i = 0; i < n; i++)
        {
        // Initialize the row.
        vector<int> row;
        adjMatrix.push_back(row);
        
        // Set the row to have all 0's. (Except the vertex ing itself.)
        for(int j = 0; j < n; j++)
            {
            int value = 0;
            
            if(i == j) 
                { value = 1; }
            
            adjMatrix[i].push_back(value);
            }
        }
    
    // Our matrix is set up, we just need to set up the edges (vertex connections).
    // See this image: https://www.srcmake.com/uploads/5/3/9/0/5390645/adjm_2_orig.png
    
    adjMatrix[0][2] = 1;
    adjMatrix[2][0] = 1;
    
    adjMatrix[0][4] = 1;
    adjMatrix[4][0] = 1;
    
    adjMatrix[0][6] = 1;
    adjMatrix[6][0] = 1;
    
    adjMatrix[1][4] = 1;
    adjMatrix[4][1] = 1;
    
    adjMatrix[1][7] = 1;
    adjMatrix[7][1] = 1;
    
    adjMatrix[2][5] = 1;
    adjMatrix[5][2] = 1;
    
    adjMatrix[3][4] = 1;
    adjMatrix[4][3] = 1;
    
    adjMatrix[3][5] = 1;
    adjMatrix[5][3] = 1;
    
    adjMatrix[5][8] = 1;
    adjMatrix[8][5] = 1;
    
    // Our adjacency matrix is complete.
    return adjMatrix;
    }
    
// Given an Adjacency List, do a BFS on vertex "start"
void AdjListBFS(vector< vector<int> > adjList, int start)
    {
    cout << "\nDoing a BFS on an adjacency list.\n";
    
    int n = adjList.size();
    // Create a "visited" array (true or false) to keep track of if we visited a vertex.
    bool visited[n];
    
    for(int i = 0; i<n; i++){
        visited[i]=false;
    }
    // Create a queue for the nodes we visit.
    queue<int> q;
    
    // Add the starting vertex to the queue and mark it as visited.
    q.push(start);
    visited[start] = true;
    
    // While the queue is not empty..
    while(q.empty() == false)
        {
        int vertex = q.front();
        q.pop();
        
        // Doing +1 in the cout because our graph is 1-based indexing, but our code is 0-based.
        cout << vertex+1 << " ";
        
        // Loop through all of it's friends.
        for(int i = 0; i < adjList[vertex].size(); i++)
            {
            // If the friend hasn't been visited yet, add it to the queue and mark it as visited
            int neighbor = adjList[vertex][i];
            
            if(visited[neighbor] == false)
                {
                q.push(neighbor);
                visited[neighbor] = true;
                }
            }
        }
    cout << endl << endl;
    return;
    }
    
    
// Given an Adjacency Matrix, do a BFS on vertex "start"
void AdjMatrixBFS(vector< vector<int> > adjMatrix, int start)
    {
    cout << "\nDoing a BFS on an adjacency matrix.\n";
    
    int n = adjMatrix.size();
    // Create a "visited" array (true or false) to keep track of if we visited a vertex.
    bool visited[n];
    
    for(int i = 0; i<n; i++){
        visited[i]=false;
    }
    // Create a queue for the nodes we visit.
    queue<int> q;
    
    // Add the starting vertex to the queue and mark it as visited.
    q.push(start);
    visited[start] = true;
    
    // While the queue is not empty..
    while(q.empty() == false)
        {
        int vertex = q.front();
        q.pop();
        
        // Doing +1 in the cout because our graph is 1-based indexing, but our code is 0-based.
        cout << vertex+1 << " ";
        
        // Loop through all of it's friends.
        for(int i = 0; i < adjMatrix[vertex].size(); i++)
            {
            
            // The neighbor is the column number, and the edge is the value in the matrix.
            int neighbor = i;
            int edge = adjMatrix[vertex][i];
            
            // If the edge is "0" it means this guy isn't a neighbor. Move on.
            if(edge == 0) { continue; }
            
            // If the friend hasn't been visited yet, add it to the queue and mark it as visited
            if(visited[neighbor] == false)
                {
                q.push(neighbor);
                visited[neighbor] = true;
                }
            }
        }
    cout << endl << endl;
    return;
    }

bool shortestPathBFS(vector< vector<int> > adj, int start, int end, int predecessor[], int dist[]){
    int n = adj.size();
    bool visited[n];

    for(int i = 0; i<n; i++){
        visited[i] = false;
        predecessor[i] = -1;
        dist[i] = INT_MAX;
    }

    queue<int> q;

    visited[start] = true;
    dist[start] = 0;
    
    q.push(start);

    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(int i = 0; i<adj[u].size();i++){
            int neighbor = adj[u][i]; //Adjacent node
            if(visited[neighbor] == false)
                {
                q.push(neighbor); //Add on to queue
                visited[neighbor] = true; //Set the neighbor as visited
                dist[neighbor] = dist[u] + 1; //Each adjacent neighbor gets parent plus 1
                predecessor[neighbor] = u; //Each i stores immediate predecessor
                }
            if(neighbor == end){
                return true;
            }
        }
    }
    return false;
}

void printShortestDistance(vector<vector<int> > adj, int s, int dest)
{
    // predecessor[i] array stores predecessor of
    // i and distance array stores distance of i
    // from s
    int v = adj.size();
    int pred[v], dist[v];
 
    if (shortestPathBFS(adj, s, dest, pred, dist) == false) {
        cout << "Given source and destination"
             << " are not connected";
        return;
    }
 
    // vector path stores the shortest path
    vector<int> path;
    int crawl = dest;
    path.push_back(crawl);
    while (pred[crawl] != -1) {
        path.push_back(pred[crawl]); //Each pred has a value corresponding to predecessor
        crawl = pred[crawl]; //Move to predeecessor
    }
 
    // distance from source is in distance array
    cout << "Shortest path length is : "
         << dist[dest];
 
    // printing path from source to destination
    cout << "\nPath is::\n";
    for (int i = path.size() - 1; i >= 0; i--)
        cout << path[i] << " ";
}

int main() 
    {
    cout << "Program started.\n";
    
    // Get the adjacency list/matrix.
    vector< vector<int> > adjList = FormAdjList();
    vector< vector<int> > adjMatrix = FormAdjMatrix();
    
    // Call BFS on Vertex 5. (Labeled as 4 in our 0-based-indexing.)
    AdjListBFS(adjList, 4);
    AdjMatrixBFS(adjMatrix, 4);
    printShortestDistance(adjList, 4, 8);
    cout << "Program ended.\n";

    return 0;
    }