# graph_example

To run the tests for this example, install google bazel, then run:  
bazel test --test_output=streamed //graph:graph_store_test

To run benchmarks run:  
bazel run -c opt //graph:graph_store_benchmarks
