#include "/Users/vishal/Development/benchmark/include/benchmark/benchmark.h"
#include <iostream>

int step = 1024;

static void BM_updateKthInt(benchmark::State& state) {
    int size = 64*1024*1024;
    int* arr= new int[size];
    step = state.range(0);
    int x;
    for (auto _ : state) 
        for(int i=0; i<size; i+= step )
            x = arr[i];
delete[] arr;
}
//BENCHMARK(BM_updateKthInt)->RangeMultiplier(2)->Range(1,2<<20);

static void BM_update16thInt(benchmark::State& state) {
        for (auto _ : state) {
                int size = state.range(0)*1024;
                state.PauseTiming();
                int steps = 64*1024*1024;
                int lengthMod = size -1; 
                int* arr= new int[size];
                state.ResumeTiming();
                for(int i=0; i<steps; i+= 16) 
                    arr[(i*16) & lengthMod]++;
                state.PauseTiming();
                delete[] arr;
                state.ResumeTiming();
        }   
}
//BENCHMARK(BM_update16thInt)->Arg(3072);
BENCHMARK(BM_update16thInt)->RangeMultiplier(2)->Range(1,2<<20);
