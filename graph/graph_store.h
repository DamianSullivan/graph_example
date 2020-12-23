#ifndef GRAPH_GRAPH_STORE_H_
#define GRAPH_GRAPH_STORE_H_

#include <string>
#include <unordered_set>
#include <vector>

namespace graph_example {

struct Label {
    std::string property;
};

struct Vertex {
    int id;
    std::vector<Vertex*> neighbors;
    std::unordered_set<Label*> labels;
};

class GraphStore {
    public:
        // Default constructor.
        GraphStore();

        // Creates a new vertex and assigns a unique id.
        Vertex CreateVertex();

        // Creates a directed edge between vertex a and vertex b.
        // TODO(dsullivan): Clean up pointer interface and determine const'ness.
        void CreateEdge(Vertex* a, Vertex* b);

        // Adds a label `l` to vertex `a`.
        void AddLabel(Vertex* a, Label* l);

        // Removes a label `l` from vertex `a`.
        void RemoveLabel(Vertex* a, Label* l);

    private:
        // Keeps track of the vertex ids created.
        int vertex_id_;
};

}  // namespace graph_example

#endif  // GRAPH_GRAPH_STORE_H_
