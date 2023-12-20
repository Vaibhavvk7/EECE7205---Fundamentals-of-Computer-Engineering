#include <iostream> 
#include <vector> 
#include <queue> 
#include <climits>

using namespace std;

// Structure to hold information about an edge 

struct Edge 
{
  int destination;
  int weight; 
};

// Structure to hold information about a node in the graph 
struct Node 
{
  int parent;
  int key;
  bool inMST; 
  vector<Edge> adjList;
};

// Comparison function for priority queue based on key values
struct CompareKeys 
{
  bool operator()(const Node& n1, const Node& n2) 
  { 
    return n1.key > n2.key;
  } 
};

// Function to add an edge to the adjacency list representation of the graph 
void addEdge(vector<Node>& graph, int source, int destination, int weight) 
{
  Edge e;
  e.destination = destination; e.weight = weight;
  graph[source].adjList.push_back(e); 
}

// Function to print the edges of the MST 
void printMST(vector<Node>& graph) 
{
  cout << "Edge \tWeight" << endl; for (int i = 1; i < graph.size(); i++) 
  {
    cout << graph[i].parent << " - " << i << "\t" << graph[i].key << endl; 
  }
}

// Function to compute the MST using Prim's algorithm 
void primMST(vector<Node>& graph) 
{
  // Initialize all nodes with infinite key values and not being in the MST 
  for (int i = 1; i < graph.size(); i++) 
  {
    graph[i].key = INT_MAX;
    graph[i].inMST = false; 
  }

// Create a priority queue to store the nodes based on key values 
priority_queue<Node, vector<Node>, CompareKeys> pq;
  
// Start with the first node as the root and its key value as 0 
graph[0].key = 0;
pq.push(graph[0]);
  
while (!pq.empty()) 
{
  // Extract the node with minimum key value from the priority queue 
  Node u = pq.top();
  pq.pop();
  // Include the extracted node in the MST 
  u.inMST = true;
  // Update the key values and parent pointers of adjacent nodes if necessary 
  for (Edge& e : u.adjList) 
  {
    int v = e.destination; 
    int weight = e.weight;
    
    if (!graph[v].inMST && weight < graph[v].key) 
    { 
      graph[v].parent = u.parent;
      graph[v].key = weight;
      pq.push(graph[v]);
    } 
  }
}
  
// Print the edges of the MST
printMST(graph); 
}

int main() 
{
  int vertexCount = 5;
  vector<Node> graph(vertexCount);
  addEdge(graph, 0, 1, 2); 
  addEdge(graph, 0, 3, 6); 
  addEdge(graph, 1, 2, 3); 
  addEdge(graph, 1, 3, 8); 
  addEdge(graph, 1, 4, 5); 
  addEdge(graph, 2, 4, 7); 
  addEdge(graph, 3, 4, 9);

  primMST(graph);

  return 0; 
}
