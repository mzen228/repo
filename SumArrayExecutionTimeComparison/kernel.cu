/*Add two arrays
Confirm GPU results with CPU results*/
#include "cuda_runtime.h"
#include "device_launch_parameters.h"

#include "../SumArray/cuda_common.h"
#include <stdio.h>

// for random initialize
#include <stdlib.h>
#include <time.h>

// for memset
#include <cstring>

int main() {
	//int size = 10000;
	//int block_size = 128;
	int size = 1 << 25;
	int block_size = 1024;

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

	// summation in CPU
	clock_t cpu_start, cpu_end, gpu_start, gpu_end, htod_start, htod_end,
		dtoh_start, dtoh_end;

	cpu_start = clock();
	sum_array_cpu(h_a, h_b, h_c, size);
	cpu_end = clock();

	memset(gpu_results, 0, NO_BYTES);

	// device pointer
	int* d_a, * d_b, * d_c;
	cudaMalloc((int**)&d_a, NO_BYTES);
	cudaMalloc((int**)&d_b, NO_BYTES);
	cudaMalloc((int**)&d_c, NO_BYTES);

	// memory transfer from host to device 
	htod_start = clock();
	cudaMemcpy(d_a, h_a, NO_BYTES, cudaMemcpyHostToDevice);
	cudaMemcpy(d_b, h_b, NO_BYTES, cudaMemcpyHostToDevice);
	htod_end = clock();

	// launching the grid
	dim3 block(block_size);
	dim3 grid((size / block.x) + 1);

	gpu_start = clock();
	sum_array_gpu << <grid, block >> > (d_a, d_b, d_c, size);
	gpu_end = clock(); 
	cudaDeviceSynchronize();

	// memory transfer back to host 
	dtoh_start = clock();
	cudaMemcpy(gpu_results, d_c, NO_BYTES, cudaMemcpyDeviceToHost);
	dtoh_end = clock();

	// array comparison 
	compare_arrays(gpu_results, h_c, size);

	printf("Sum array CPU execution time: %4.8f\n",
		(double)((double)(cpu_end - cpu_start) / CLOCKS_PER_SEC));

	printf("Sum array GPU execution time: %4.8f\n",
		(double)((double)(gpu_end - gpu_start) / CLOCKS_PER_SEC));

	printf("htod mem transfer time: %4.8f\n",
		(double)((double)(htod_end - htod_start) / CLOCKS_PER_SEC));

	printf("dtoh mem transfer time: %4.8f\n",
		(double)((double)(dtoh_end - dtoh_start) / CLOCKS_PER_SEC));

	printf("Total GPU execution time: %4.8f\n",
		(double)((double)(dtoh_end - htod_start) / CLOCKS_PER_SEC));

	cudaFree(d_c);
	cudaFree(d_b);
	cudaFree(d_a);

	free(gpu_results);
	free(h_b);
	free(h_a);

	cudaDeviceReset();

	return 0;


}