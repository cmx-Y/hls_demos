#include "spmv.h"

void spmv(
	int rowPtr[NUM_ROWS+1], 
	int columnIndex[NNZ],
	DTYPE values[NNZ], 
	DTYPE y[SIZE], 
	DTYPE x[SIZE]
)
{

int rowPtrBuf[NUM_ROWS+1];
int columnIndexBuf[NNZ];
DTYPE valuesBuf[NNZ];
DTYPE xBuf[SIZE];

#pragma HLS ARRAY_PARTITION variable=columnIndexBuf cyclic factor=8 dim=1
#pragma HLS ARRAY_PARTITION variable=valuesBuf cyclic factor=8 dim=1
#pragma HLS ARRAY_PARTITION variable=xBuf cyclic factor=8 dim=1


readRowPrt: for (int i = 0; i < NUM_ROWS+1; i++) {
#pragma HLS pipeline
	rowPtrBuf[i] = rowPtr[i];
}

readColumnIndex: for (int i = 0; i < NNZ; i++) {
#pragma HLS pipeline
	columnIndexBuf[i] = columnIndex[i];
}

readValues: for (int i = 0; i < NNZ; i++) {
#pragma HLS pipeline
	valuesBuf[i] = values[i];
}

readX: for (int i = 0; i < SIZE; i++) {
#pragma HLS pipeline
	xBuf[i] = x[i];
}

L1: for (int i = 0; i < NUM_ROWS; i++) {
  DTYPE y0 = 0;
  L2_1: for (int k = rowPtrBuf[i]; k < rowPtrBuf[i+1]; k+=8) {
  #pragma HLS pipeline II=8
    DTYPE yt = valuesBuf[k] * xBuf[columnIndexBuf[k]];
    L2_2: for (int j = 1; j < 8; j++) {
      	if (k + j < rowPtrBuf[i + 1]) {
        	yt += valuesBuf[k+j] * xBuf[columnIndexBuf[k+j]];
      	}
    	}
    	y0 += yt;
  	}
  	y[i] = y0;
	}
}


void mv(DTYPE A[SIZE][SIZE], DTYPE y[SIZE], DTYPE x[SIZE])
{
	for (int i = 0; i < SIZE; i++) {
		DTYPE y0 = 0;
		for (int j = 0; j < SIZE; j++) {
#pragma HLS pipeline
			y0 += A[i][j] * x[j];
		}
		y[i] = y0;
	}
}

