#include "graph_store.h"

namespace graph_example {

using namespace std;

GraphStore::GraphStore() : vertex_id_(0) {}

Vertex GraphStore::CreateVertex() {
    Vertex v;
    v.id = vertex_id_;
    ++vertex_id_;
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

}
