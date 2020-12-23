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

}
