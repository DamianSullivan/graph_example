load("@rules_cc//cc:defs.bzl", "cc_binary", "cc_library", "cc_test")

cc_library(
    name = "graph_store",
    srcs = ["graph_store.cc"],
    hdrs = ["graph_store.h"],
)

cc_test(
	name = "graph_store_test",
	srcs = ["graph_store_test.cc"],
	deps = [
		":graph_store",
		"@gtest//:gtest",
		"@gtest//:gtest_main",
    ],
)

cc_binary(
    name = "graph_store_benchmarks",
    srcs = ["graph_store_benchmarks.cc"],
    linkstatic = True,
    deps = [
        ":graph_store",
        "@gbenchmark//:benchmark",
    ],
)
