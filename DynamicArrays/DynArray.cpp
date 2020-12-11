#include"DynamicArray.h"
void swap(int* ptr1, int* ptr2)
{
	int temp = *ptr1;
	*ptr1 = *ptr2;
	*ptr2 = temp;
}
int* searchMin(int* A, size_t size)
{
	int* min = A;
	int* i = A + 1;
	for (i; i < A + size; i++)
	{
		if (*i < *min)
			min = i;
	}
	return min;
}
void selectionSort(int* A, size_t size)
{
	for (int* i = 0; i < A + size - 1; i++)
	{
		int* minptr = searchMin(i, size);
		swap(minptr, i);
	}
}
void selectionSort1(int* A, int n)
{
	int i, j, min_idx;

	// One by one move boundary of unsorted subarray  
	for (i = 0; i < n - 1; i++)
	{
		// Find the minimum element in unsorted array  
		min_idx = i;
		for (j = i + 1; j < n; j++)
			if (A[j] < A[min_idx])
				min_idx = j;

		// Swap the found minimum element with the first element  
		swap(&A[min_idx], &A[i]);
	}
}

int* allocateMem(int* arr, size_t size)
{
	arr = new int[size];
	return arr;
}
int* freeMem(int* arr)
{
	delete[]arr;
	arr = nullptr;
	return arr;
}
void initArray(int* arr, size_t size, int a, int b)
{
	for (size_t i = 0; i < size; i++)
	{
		arr[i] = rand() % (b - a + 1) + a;
	}
}
void printArray(int* arr, size_t size)
{
	for (size_t i = 0; i < size; i++)
	{
		std::cout << arr[i] << " ";
	}
}

int** allocateMem(int** arr, size_t rows, size_t cols)
{
	arr = new int* [rows];
	for (size_t i = 0; i < rows; i++)
	{
		arr[i] = new int[cols];
	}
	return arr;
}
int** freeMem(int** arr, size_t rows)
{
	for (size_t i = 0; i < rows; i++)
	{
		delete[] arr[i];
	}
	delete[] arr;
	arr = nullptr;
	return arr;
}

void initArray(int** arr, size_t rows, size_t cols, int a, int b)
{
	for (size_t i = 0; i < rows; i++)
	{
		for (size_t j = 0; j < cols; j++)
		{
			arr[i][j] = rand() % (b - a + 1) + a;
		}
	}
}
void printArray(int** arr, size_t rows, size_t cols)
{
	for (size_t i = 0; i < rows; i++)
	{
		for (size_t j = 0; j < cols; j++)
		{
			std::cout << arr[i][j] << " ";
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
}

int** insertRow(int** arr, size_t& rows, size_t cols, size_t index, int* insertRow)
{
	int** newArr = nullptr;
	newArr = allocateMem(newArr, rows + 1, cols);
	for (size_t i = 0; i < index; i++)
	{
		for (size_t j = 0; j < cols; j++)
		{
			newArr[i][j] = arr[i][j];
		}
	}
	for (size_t j = 0; j < cols; j++)
	{
		newArr[index][j] = insertRow[j];
	}
	for (size_t i = index; i < rows; i++)
	{
		for (size_t j = 0; j < cols; j++)
		{
			newArr[i + 1][j] = arr[i][j];
		}
	}
	rows++;
	arr = freeMem(arr, rows);
	return newArr;
}
int** insertCol(int** arr, size_t rows, size_t& cols, size_t index, int* insertCol)
{
	int** newArr = nullptr;
	newArr = allocateMem(newArr, rows, cols + 1);
	for (size_t j = 0; j < index; j++)
	{
		for (size_t i = 0; i < rows; i++)
		{
			newArr[i][j] = arr[i][j];
		}
	}
	for (size_t i = 0; i < rows; i++)
	{
		newArr[i][index] = insertCol[i];
	}
	for (size_t j = index; j < cols; j++)
	{
		for (size_t i = 0; i < rows; i++)
		{
			newArr[i][j + 1] = arr[i][j];
		}
	}
	cols++;
	arr = freeMem(arr, rows);
	return newArr;
}
int** deleteRow(int** arr, size_t& rows, size_t cols, size_t index)
{
	int** newArr = nullptr;
	newArr = allocateMem(newArr, rows - 1, cols);
	for (size_t i = 0; i < index; i++)
	{
		for (size_t j = 0; j < cols; j++)
		{
			newArr[i][j] = arr[i][j];
		}
	}
	for (size_t i = index; i < rows; i++)
	{
		for (size_t j = 0; j < cols; j++)
		{
			newArr[i][j] = arr[i + 1][j];
		}
	}
	rows--;
	arr = freeMem(arr, rows);
	return newArr;
}
int** deleteCol(int** arr, size_t rows, size_t& cols, size_t index)
{
	int** newArr = nullptr;
	newArr = allocateMem(newArr, rows, cols - 1);
	for (size_t j = 0; j < index; j++)
	{
		for (size_t i = 0; i < rows; i++)
		{
			newArr[i][j] = arr[i][j];
		}
	}
	for (size_t j = index; j < cols; j++)
	{
		for (size_t i = 0; i < rows; i++)
		{
			newArr[i][j] = arr[i][j + 1];
		}
	}
	cols--;
	arr = freeMem(arr, rows);
	return newArr;
}
void matrixProd(int** A, int** B, int** C, size_t n, size_t m, size_t l)
{
	for (size_t i = 0; i < n; i++)
	{
		for (size_t j = 0; j < m; j++)
		{
			for (size_t q = 0; q < l; q++)
			{
				C[i][q] += A[i][j] * B[j][q];
			}
		}
	}
}

size_t defineLargestArray(size_t M, size_t N)
{
	if (M > N) return M;
	else return N;
}
size_t defineSmallestArray(size_t M, size_t N)
{
	if (M < N) return M;
	else return N;
}

int* _6_addTwoPolynomials(int*A, int*B, size_t M, size_t N)
{
	int* newArr = nullptr;
	size_t sizeNew = defineLargestArray(M, N);
	newArr = allocateMem(newArr, sizeNew);
	for (size_t i = 0; i < sizeNew; i++) // load newArr with zeros
	{
		newArr[i] = 0;
	}
	for (size_t i = 0; i < M; i++)
	{
		newArr[i] = A[i];
	}
	for (size_t i = 0; i < N; i++)
	{
		newArr[i] += B[i];
	}
	return newArr;
}
int* _6_multiplyTwoPolynomials(int*A, int*B, size_t M, size_t N)
{
	int* newArr = nullptr;
	size_t sizeNew = M + N - 1;
	newArr = allocateMem(newArr, sizeNew);
	for (size_t i = 0; i < sizeNew; i++) // load newArr with zeros
	{
		newArr[i] = 0;
	}
	for (size_t i = 0; i < M; i++)
	{
		for (size_t j = 0; j < N; j++)
		{
			newArr[i + j] += A[i] * B[j];
		}
	}
	return newArr;
}

int* _7_gatherElmentsFromTwoArrays(int*A, int*B, size_t M, size_t N)
{
	int* newArr = nullptr;
	size_t sizeNew = N + M;
	newArr = allocateMem(newArr, sizeNew);
	for (size_t i = 0; i < M; i++)
	{
		newArr[i] = A[i];
	}
	for (size_t i = 0; i < N; i++)
	{
		newArr[i + M] = B[i];
	}
	return newArr;
}

size_t defineSizeForCommonElements(int* A, int* B, size_t M, size_t N)
{
	size_t commElCounter = 0;
	for (size_t i = 0; i < M; i++)
	{
		if (A[i] == A[i + 1]) continue; // eliminate duplication of equal elements
		for (size_t j = 0; j < N; j++)
		{
			if (B[j] == B[j + 1]) continue; // eliminate duplication of equal elements
			else
			{
				if (A[i] != B[j]) continue;
				else commElCounter++;
			}
		}
	}
	return commElCounter;
}
int* _8_gatherCommonElements(int*A, int*B, size_t M, size_t N)
{
	int* newArr = nullptr;
	size_t sizeNew = defineSizeForCommonElements(A, B, M, N);
	newArr = allocateMem(newArr, sizeNew);
	size_t k = 0;
	for (size_t i = 0; i < M; i++)
	{
		if (A[i] == A[i + 1]) continue;
		else
		{
			for (size_t j = 0; j < N; j++)
			{
				if (B[j] == B[j + 1]) continue;
				else
				{
					if (A[i] != B[j]) continue;
					else
					{
						newArr[k] = A[i];
						k++;
					}
				}
			}
		}
	}
	return newArr;
}

size_t defineSizeForExclusiveElements(int* A, int* B, size_t M, size_t N)
{
	int exclusiveElCounter = 0;
	for (size_t i = 0; i < M; i++)
	{
		for (size_t j = 0; j < N; j++)
		{
			if (A[i] == B[j]) break;
			else if (j == N - 1) exclusiveElCounter++;
		}
	}
	return exclusiveElCounter;
}
int* _9_exclusiveAElements(int*A, int*B, size_t M, size_t N)
{
	int* newArr = nullptr;
	size_t sizeNew = defineSizeForExclusiveElements(A, B, M, N);
	newArr = allocateMem(newArr, sizeNew);
	size_t k = 0;
	for (size_t i = 0; i < M; i++)
	{
		for (size_t j = 0; j < N; j++)
		{
			if (A[i] == B[j]) break;
			else if (j == N - 1)
			{
				newArr[k] = A[i];
				k++;
			}
		}
	}
	return newArr;
}
