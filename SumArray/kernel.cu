/*Add two arrays
Confirm GPU results with CPU results*/
#include "cuda_runtime.h"
#include "device_launch_parameters.h"

#include "cuda_common.h"
#include <stdio.h>

// for random initialize
#include <stdlib.h>
#include <time.h>

// for memset
#include <cstring>

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

int main() {
	helloWorld();
	int size = 10000;
	int block_size = 128;

	int NO_BYTES = size * sizeof(int);

	// host pointers
	int* h_a, * h_b, * gpu_results, * h_c;

	// allocate memory for host pointers 
	h_a = (int*)malloc(NO_BYTES);
	h_b = (int*)malloc(NO_BYTES);
	gpu_results = (int*)malloc(NO_BYTES);
	h_c = (int*)malloc(NO_BYTES);

	// initialize host pointer
	time_t t;
	srand((unsigned)time(&t));

	for (int i{}; i < size; ++i) {
		h_a[i] = (int)(rand() & 0xFF); // limit random numbers to range of 0 to 255
	}

	for (int i{}; i < size; ++i) {
		h_b[i] = (int)(rand() & 0xFF);
	}

	sum_array_cpu(h_a, h_b, h_c, size);

	memset(gpu_results, 0, NO_BYTES);

	// device pointer
	int* d_a, * d_b, * d_c;
	gpuErrchk(cudaMalloc((int**)&d_a, NO_BYTES));
	gpuErrchk(cudaMalloc((int**)&d_b, NO_BYTES));
	gpuErrchk(cudaMalloc((int**)&d_c, NO_BYTES));

	// memory transfer from host to device 
	cudaMemcpy(d_a, h_a, NO_BYTES, cudaMemcpyHostToDevice);
	cudaMemcpy(d_b, h_b, NO_BYTES, cudaMemcpyHostToDevice);

	// launching the grid
	dim3 block(block_size);
	dim3 grid((size / block.x) + 1);

	sum_array_gpu << <grid, block >> > (d_a, d_b, d_c, size);
	cudaDeviceSynchronize();

	// memory transfer back to host 
	cudaMemcpy(gpu_results, d_c, NO_BYTES, cudaMemcpyDeviceToHost);

	// array comparison 
	compare_arrays(gpu_results, h_c, size);

	cudaFree(d_c);
	cudaFree(d_b);
	cudaFree(d_a);

	free(gpu_results);
	free(h_b);
	free(h_a);

	cudaDeviceReset();

	return 0;


}