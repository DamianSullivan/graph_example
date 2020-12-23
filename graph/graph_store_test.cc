#include "graph_store.h"

#include <string>

#include "gmock/gmock.h"
#include "gtest/gtest.h"

namespace graph_example {

using testing::ElementsAre;

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

TEST(GraphStore, AddLabel){
    GraphStore graph_store;

    // TODO(dsullivan): Create independent fixtures.
    Vertex v0 = graph_store.CreateVertex();
    Label l;
    l.property = "LABEL_1";

    graph_store.AddLabel(&v0, &l);

    ASSERT_THAT(v0.labels, ElementsAre(&l));
}


TEST(GraphStore, RemoveLabel){
    GraphStore graph_store;

    // TODO(dsullivan): Create independent fixtures.
    Vertex v0 = graph_store.CreateVertex();
    Label l;
    l.property = "LABEL_2";

    graph_store.AddLabel(&v0, &l);
    graph_store.RemoveLabel(&v0, &l);

    ASSERT_THAT(v0.labels, ElementsAre());
}

}  // namespace graph_example
