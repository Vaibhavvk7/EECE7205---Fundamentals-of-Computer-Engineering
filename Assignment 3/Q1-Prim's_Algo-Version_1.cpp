#include <iostream> 
#include <climits>

// Number of vertices in the graph 
#define V 5

// Function to find the vertex with minimum key value
int minKey(int key[], bool mstSet[]) 
{ 
  int min = INT_MAX, minIndex; 
  for (int v = 0; v < V; v++)
    if (mstSet[v] == false && key[v] < min) 
      min = key[v], minIndex = v;
  return minIndex; 
}

// Function to print the constructed MST
void printMST(int parent[], int graph[V][V]) 
{ 
  std::cout << "Edge \tWeight" << std::endl; 
  for (int i = 1; i < V; i++)
    std::cout << parent[i] << " - " << i << "\t" << graph[i][parent[i]] << std::endl; 
}

// Function to construct and print MST for a graph represented using adjacency matrix representation
void primMST(int graph[V][V]) 
{ 
  int parent[V];
  int key[V];
  bool mstSet[V];
  
  for (int i = 0; i < V; i++) 
  { 
    key[i] = INT_MAX; mstSet[i] = false;
  }
  
  key[0] = 0; 
  parent[0] = -1;
  
  for (int count = 0; count < V - 1; count++) 
  { 
    int u = minKey(key, mstSet);
    
    mstSet[u] = true;
    
    for (int v = 0; v < V; v++) 
    {
      if (graph[u][v] && mstSet[v] == false && graph[u][v] < key[v]) 
      {
        parent[v] = u;
        key[v] = graph[u][v]; 
      }
    } 
  }
  printMST(parent, graph); 
}

int main() 
{
  int graph[V][V] = 
  {
    {0, 2, 0, 6, 0}, 
    {2, 0, 3, 8, 5}, 
    {0, 3, 0, 0, 7}, 
    {6, 8, 0, 0, 0}, 
    {0, 5, 7, 0, 0}
  };
  
primMST(graph);
  
return 0; 
}
