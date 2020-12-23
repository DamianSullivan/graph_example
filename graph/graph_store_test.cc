#include "graph_store.h"

#include <string>

#include "gtest/gtest.h"

namespace graph_example {

TEST(GraphStore, CreateVertex){
    GraphStore graph_store;
    Vertex v0 = graph_store.CreateVertex();
    Vertex v1 = graph_store.CreateVertex();
    Vertex v2 = graph_store.CreateVertex();
    
    EXPECT_EQ(0, v0.id);
    EXPECT_EQ(1, v1.id);
    EXPECT_EQ(2, v2.id);
}   

TEST(GraphStore, CreateEdge){
    GraphStore graph_store;

	// TODO(dsullivan): Create independent fixtures.
    Vertex v0 = graph_store.CreateVertex();
    Vertex v1 = graph_store.CreateVertex();

    graph_store.CreateEdge(&v0, &v1);

    EXPECT_EQ(1, v0.neighbors.size());
    EXPECT_EQ(1, v0.neighbors[0]->id);
}

}  // namespace graph_example
