#include "benchmark/benchmark.h"
#include "example/utils/IRange.hpp"

using namespace example;

static void fun(benchmark::State& state)
{
	int a = 0;
	for (auto _ : state)
	{
		for (auto i : irange(100))
			benchmark::DoNotOptimize(a = i * i);
	}
}
// Register the function as a benchmark
BENCHMARK(fun);

BENCHMARK_MAIN();
