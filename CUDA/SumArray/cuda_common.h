#pragma once
#include "cuda_runtime.h"
#include "device_launch_parameters.h"
#include <stdio.h>
#include <iostream>

#define gpuErrchk(ans) { gpuAssert((ans),__FILE__,__LINE__);}

inline void gpuAssert(cudaError_t code, const char* file, int line, bool abort = true) {
	if (code != cudaSuccess) {
		fprintf(stderr, "GPUassert: %s %s %d\n", cudaGetErrorString(code), file, line);
		if (abort)exit(code);
	}
}

__global__ void  sum_array_gpu(int* a, int* b, int* c, int size) {
	int gid = blockIdx.x * blockDim.x + threadIdx.x;

	if (gid < size) {
		c[gid] = a[gid] + b[gid];
	}
}

void sum_array_cpu(int* a, int* b, int* c, int size) {
	for (int i{}; i < size; ++i) {
		c[i] = a[i] + b[i];
	}
}

// compare two arrays
void compare_arrays(int* a, int* b, int size) {
	for (int i{}; i < size; ++i) {
		if (a[i] != b[i]) {
			printf("Arrays are not equal\n");
			return;
		}
	}

	printf("Arrays are equal\n");
	return;
}