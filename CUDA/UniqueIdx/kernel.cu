#include "cuda_runtime.h"
#include "device_launch_parameters.h"

#include <stdio.h>
#include <stdlib.h>

__global__ void unique_idx_cal_threadIdx(int * input) {
	int tid = threadIdx.x;
	int gid = tid + blockIdx.x * blockDim.x; 
	printf("gid: %d, value: %d\n", gid, input[gid]);
}

int main() {
	int array_size = 16;
	int array_byte_size = array_size * sizeof(int);
	int h_data[] = { 23,9,4,54,65,12,1,33,52, 106, 48, 26, 18, 91, 85, 75 }; 

	printf("Array: ");
	for (int i{}; i < array_size; ++i)
		printf("%d, ", h_data[i]);
	printf("\n\n");

	int* d_data;
	cudaMalloc((void**)&d_data, array_byte_size);
	cudaMemcpy(d_data, h_data, array_byte_size, cudaMemcpyHostToDevice);

	dim3 block(4);
	dim3 grid(4); 

	unique_idx_cal_threadIdx << <grid, block >> > (d_data);
	cudaDeviceSynchronize();
	cudaDeviceReset();
}