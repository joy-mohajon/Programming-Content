#include<bits/stdc++.h>

using namespace std;

struct Edge {
    int src, dest, weight;
};

struct Graph {
    int V, E;

    // graph is represented as an array of edges.
    struct Edge* edge;
};

// Creates a graph with V vertices and E edges
struct Graph* createGraph(int V, int E)
{
    struct Graph* graph = new Graph;
    graph->V = V;
    graph->E = E;
    graph->edge = new Edge[E];
    return graph;
}

bool compare(struct Edge e1, struct Edge e2)
{
    return e1.weight < e2.weight;
}

int findParent(int v, int parent[])
{
    if(parent[v] == v){
        return v;
    }
    else {
        return findParent(parent[v], parent);
    }
}

void kruskal(struct Edge* input, int V, int E)
{
    // sorting edge based on weight as ascending order
    sort(input, input + E, compare);

    struct Edge* output = new Edge[E];
    
    int parent[V];
    for(int i=0; i<V; i++){
        parent[i] = i;
    }

    // check if source and destination parent aren't same
    int cnt = 0;
    for(int i=0; i<E; i++){
        struct Edge currentEdge = input[i];

        int srcParent = findParent(currentEdge.src, parent);
        int destParent = findParent(currentEdge.dest, parent);

        if(srcParent != destParent){
            output[cnt] = currentEdge;
            cnt++;
            parent[srcParent] = destParent;
        }
    }

    // pint sortest path with minimum cost
    for(int i=0; i<V-1; i++){
        cout << output[i].src << " " << output[i].dest << " " << output[i].weight << endl;
    }
}

int main()
{
    int m, n;
    int a, b, c;

    while(cin >> m >> n){
        if(m == 0 && n == 0){
           break;
        } 
        
        struct Graph* graph = createGraph(m, n);

        for(int e=0; e<n; e++){
            cin >> a >> b >> c;

            graph->edge[e].src = a;
            graph->edge[e].dest = b;
            graph->edge[e].weight = c;
        }
        
        kruskal(graph->edge, m, n);


    }
}