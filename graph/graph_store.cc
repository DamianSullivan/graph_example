#include "graph_store.h"

#include <queue>
#include <vector>
#include <unordered_map>

namespace graph_example {

using namespace std;

GraphStore::GraphStore() : vertex_id_(0) {}

Vertex GraphStore::CreateVertex() {
    Vertex v;
    v.id = vertex_id_;

    // TODO(dsullivan): Separate out id assignment, preferably from an injected
    // class or at least a separate call wrapped in a mutex.
    ++vertex_id_;
    ++graph_size_;

    return v;
}

void GraphStore::CreateEdge(Vertex* a, Vertex* b) {
    a->neighbors.push_back(b);
} 

void GraphStore::AddLabel(Vertex* a, Label* l) {
    a->labels.insert(l);
}
    
void GraphStore::RemoveLabel(Vertex* a, Label* l) {
    a->labels.erase(l);
} 

vector<Vertex*> GraphStore::ShortestPath(Vertex* source, Vertex* destination, Label* label) {
    vector<Vertex*> path;
	if (source->id == destination->id) {
        return path;
	}

    queue<Vertex*> queue;
    vector<bool> visited(graph_size_, false);
    vector<int> distance(graph_size_, INT_MAX);
    vector<int> predecessor(graph_size_, -1);

    // TODO(dsullivan): Using a map to convert id to vertex is ugly,
    // clean this up.
    unordered_map<int, Vertex*> id_to_vertex;

    visited[source->id] = true;
    distance[source->id] = 0;
    bool reached_destination = false;

    queue.push(source);
    while (!queue.empty()) {
        Vertex* vertex = queue.front();
        queue.pop();
        for (Vertex* neighbor : vertex->neighbors) {
            if (neighbor->labels.count(label) == 0) {
                continue;
            }
            if (visited[neighbor->id]) {
                continue;
            }

            id_to_vertex[vertex->id] = vertex;

            visited[neighbor->id] = true;
            distance[neighbor->id] = distance[vertex->id] + 1;
            predecessor[neighbor->id] = vertex->id;
            queue.push(neighbor);

            if (neighbor->id == destination->id) {
                reached_destination = true;
                break;
            }
        }
    }

    if (!reached_destination) {
        // Return an empty path if destination could not be reached.
        return path;
    }

    path.push_back(destination);
    int vertex_id = destination->id;
    while (predecessor[vertex_id] != -1) {
        path.push_back(id_to_vertex[predecessor[vertex_id]]);
        vertex_id = predecessor[vertex_id];
    }

    // TODO(dsullivan): To find a path we need to start with the destination
    // node and walk back through the predecessors so this leaves things in
    // reverse order. Find a way to build the path, maybe using list instead
    // of vector. This way we can build the path in reverse order.
    reverse(path.begin(), path.end());
    return path;
}

}  // namespace graph_example
