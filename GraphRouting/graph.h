#ifndef GRAPH_H
#define GRAPH_H

typedef struct {       // node declaration
    int id;
    char name[64];
    double lat, lon;
} Node;

typedef struct {      // edge declaration
    int from, to;
    int distance_m;
    int avg_time_s;
    int bidirectional;
} Edge;

typedef struct {
    Node* nodes;
    int node_count;
    Edge* edges;
    int edge_count;
} Graph;

typedef struct {
    int path_node_ids[64];
    int path_length;
    int total_distance_m;
    int total_time_s;
} Route;

// we will tell other C files that these are the functions our modules holds
// These lines are declarations,not implementations.The actual logic will go in graph.c.
Graph* load_graph(const char* nodes_path, const char* edges_path);

Route* dijkstra(Graph* g, int from_id, int to_id);

void free_graph(Graph* g);

void free_route(Route* r);

/*
Declaration	Purpose
load_graph(...)	Reads the JSON files and loads the campus map into memory.
dijkstra(...)	Finds a shortest-distance route between two location IDs.
free_graph(...)	Releases memory allocated for the graph.
free_route(...)	Releases memory allocated for a route.
*/

#endif