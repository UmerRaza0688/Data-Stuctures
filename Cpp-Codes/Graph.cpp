// implementing Directed graph by adjancey list
#include <iostream>
#include <list>
#include <queue>
#include <stack>
#include <vector>
using namespace std;

// No of Nodes & Edges in graph
#define VERTICES_SIZE 6
#define EDGES_SIZE  8

// structure for a single node in graph
class Node {
    public:
        char value;
        list<char> lst;

        Node() {
            value = '\0';
            lst = {};
        }
};

// class of graph
class DiGraph {
    private:
        Node* arr;      // array of nodes
        int current;    // current node

    public:
        DiGraph() {
            arr = new Node[VERTICES_SIZE];
            current = 0;
        }

        // Methode or operation on Graph
        void add_node(char node);
        // function to add edges
        void add_edge(char src, char dest);

        // Traverse through graph using BFS
        void travers_BFS(char start);
        // Traverse through graph using DFS
        void travers_DFS(char start);

        // fun to print graph
        void print_graph();
};

// Methode or operation on Graph

// function to add node
void DiGraph::add_node(char node){
    // if node is already in the Graph (here in array)
    for(int i=0; i<VERTICES_SIZE; i++){
        if(arr[i].value == node) return;
    }

    // if not
    arr[current++].value = node;
}

// function to add edges, from source to destination
void DiGraph::add_edge(char src, char dest){
    // sanity checks
    // if source node is not in the Graph
    for(int i=0; i<VERTICES_SIZE; i++){
        if(arr[i].value == src){
            arr[i].lst.push_back(dest);
                return;
        }
    }

    // only print error if loop finishes without finding src
    cout << "Source node do not exist!" << endl;
}

// Traverse through graph using BFS
void DiGraph::travers_BFS(char start){
    // to keep track of visited nodes so we don't visit them again
    vector<char> visited;

    // queue holds the nodes to visit next
    queue<char> q;

    // push starting node into queue and mark it visited
    q.push(start);
    visited.push_back(start);

    while(!q.empty()){
        // take the front node
        char current = q.front();
        q.pop();

        // print it
        cout << current << " ";

        // find this node in arr to get its neighbors
        for(int i=0; i<VERTICES_SIZE; i++){
            if(arr[i].value == current){

                // go through each neighbor
                for(char neighbor : arr[i].lst){

                    // check if neighbor was already visited
                    bool alreadyVisited = false;
                    for(char v : visited){
                        if(v == neighbor){
                            alreadyVisited = true;
                            break;  // no need to check rest of visited list
                        }
                    }

                    // only add to queue if not visited yet
                    if(!alreadyVisited){
                        visited.push_back(neighbor);  // mark visited before pushing
                        q.push(neighbor);
                    }
                }
                // found our node and processed all its neighbors, no need to keep searching arr
                break;
            }
        }
    }
    cout << endl;
}

// Traverse through graph using DFS
void DiGraph::travers_DFS(char start){
    // static so all recursive calls share the same visited list
    static vector<char> visited;

    // mark current node as visited and print it
    visited.push_back(start);
    cout << start << " ";

    // search for the current node in arr
    for(int i=0; i<VERTICES_SIZE; i++){
        if(arr[i].value == start){

            // go through each neighbor of current node
            for(char neighbor : arr[i].lst){

                // check if neighbor was already visited
                bool alreadyVisited = false;
                for(char v : visited){
                    if(v == neighbor){
                        alreadyVisited = true;
                        break;  // no need to check rest of visited list
                    }
                }

                // only go deeper if neighbor not visited yet
                if(!alreadyVisited){
                    travers_DFS(neighbor);
                }
            }

            // found our node and processed all its neighbors, no need to keep searching arr
            break;
        }
    }
}


// print Graph
void DiGraph::print_graph(){
    for(int i=0; i<current; i++){
        cout << arr[i].value << " --> ";
        for(char neighbor: arr[i].lst){
            cout << neighbor << " ";
        }
        cout << endl;
    }
}


int main() {

    DiGraph g;

    // add nodes
    int nodes[VERTICES_SIZE] = {'a', 'b', 'c', 'd', 'e', 'f'};
    for(int i=0; i<VERTICES_SIZE; i++){
        g.add_node(nodes[i]);
    }
    
    // add edges
    int edges[EDGES_SIZE][2] = {{'a', 'b'}, {'a', 'c'}, {'b', 'c'}, {'b', 'd'}, 
                            {'c', 'd'}, {'c', 'e'}, {'e', 'f'}, {'f', 'c'}};
    for(int i=0; i<EDGES_SIZE; i++){
        g.add_edge(edges[i][0], edges[i][1]);
    }

    g.print_graph();

    cout << endl;
    cout << "DFS Traverse: " ;      // if you want to call twice, handle static with visited vector
    g.travers_DFS('a');
    cout << endl;

    cout << endl;
    cout << "BFS Traverse: " ;
    g.travers_BFS('a');

    return 0;
}