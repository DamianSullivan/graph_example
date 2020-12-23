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

TEST(GraphStore, ShortestPath){
    GraphStore graph_store;
    // TODO(dsullivan): Create independent fixtures.
    Vertex v0 = graph_store.CreateVertex();
    Vertex v1 = graph_store.CreateVertex();
    Vertex v2 = graph_store.CreateVertex();

    Label l;
    l.property = "LABEL_3";
    graph_store.AddLabel(&v0, &l);
    graph_store.AddLabel(&v1, &l);

    ASSERT_THAT(v0.labels, ElementsAre(&l)); 
    ASSERT_THAT(v1.labels, ElementsAre(&l)); 

    graph_store.CreateEdge(&v0, &v1); 
    graph_store.CreateEdge(&v0, &v2); 
    graph_store.CreateEdge(&v2, &v1); 

    std::vector<Vertex*> path = graph_store.ShortestPath(&v0, &v1, &l);
    ASSERT_THAT(path, ElementsAre(&v0, &v1));
}

}  // namespace graph_example
