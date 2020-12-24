#include "graph_store.h"

#include <benchmark/benchmark.h>

using namespace graph_example;

static void BM_GraphStore(benchmark::State& state) {
    GraphStore graph_store;
    while (state.KeepRunning()) {
        Vertex v0 = graph_store.CreateVertex();
        Vertex v1 = graph_store.CreateVertex();
        Vertex v2 = graph_store.CreateVertex();

        Label l;
        l.property = "LABEL_4";
        graph_store.AddLabel(&v0, &l);
        graph_store.AddLabel(&v1, &l);

        graph_store.CreateEdge(&v0, &v1);
        graph_store.CreateEdge(&v0, &v2);
        graph_store.CreateEdge(&v2, &v1);

        std::vector<Vertex*> path = graph_store.ShortestPath(&v0, &v1, &l);
    }
}

static void BM_GraphStoreCreate(benchmark::State& state) {
    GraphStore graph_store;
    while (state.KeepRunning()) {
        graph_store.CreateVertex();
    }
}

BENCHMARK(BM_GraphStore);
BENCHMARK(BM_GraphStoreCreate);

int main(int argc, char* argv[]) {
  benchmark::Initialize(&argc, argv);
  benchmark::RunSpecifiedBenchmarks();
  return 0; 
}
