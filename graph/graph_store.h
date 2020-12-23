#ifndef GRAPH_GRAPH_STORE_H_
#define GRAPH_GRAPH_STORE_H_

namespace graph_example {

struct Vertex {
    int id;
};

class GraphStore {
    public:
        // Default constructor
		GraphStore();

        // Creates a new vertex and assigns a unique id.
        Vertex CreateVertex();

    private:
        // Keeps track of the vertex ids created.
		int vertex_id_;
};

}  // namespace graph_example

#endif  // GRAPH_GRAPH_STORE_H_
