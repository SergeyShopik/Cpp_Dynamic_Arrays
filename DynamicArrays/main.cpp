#include"DynamicArray.h"
int main()
{
	srand(time(0));
	int* array = nullptr;
	int* Arr = nullptr;
	int* Brr = nullptr;

	size_t size, sizeM, sizeN;
	std::cout << "Enter M and N:\n";
	std::cin >> sizeM >> sizeN;
	size_t sizeC = sizeM + sizeN;

	Arr = allocateMem(Arr, sizeM);
	initArray(Arr, sizeM, 1, 10);
	printArray(Arr, sizeM);
	std::cout << std::endl;

	Brr = allocateMem(Brr, sizeN);
	initArray(Brr, sizeN, 1, 10);
	printArray(Brr, sizeN);
	std::cout << "\n\n";

	int** arr = nullptr; //dynamic double dimension array
	int** A = nullptr, ** B = nullptr, ** C = nullptr; // 5th task

	size_t n = 2, m = 3, l = 2;
	size_t rows = 4, cols = 5;
	size_t index;
	arr = allocateMem(arr, rows, cols);

	A = allocateMem(A, n, m);
	B = allocateMem(B, m, l);
	C = allocateMem(C, n, l);

	initArray(arr, rows, cols, 10, 20);
	printArray(arr, rows, cols);
	std::cout << "\n";

	// 1. Insert row in double dimension dynamic array in given position
	/*std::cout << "Enter index:\n";
	std::cin >> index;
	arr = insertRow(arr, rows, cols, index, array);
	printArray(arr, rows, cols);*/

	// 2. Insert column in double dimension dynamic array in given position
	/*arr = insertCol(arr, rows, cols, 1, array);
	printArray(arr, rows, cols);*/

	// 3. Delete given row from double dimension dynamic array
	/*std::cout << "Enter index:\n";
	std::cin >> index;
	arr = deleteRow(arr, rows, cols, index);
	printArray(arr, rows, cols);*/

	// 4. Delete given column from double dimension dynamic array
	/*std::cout << "Enter index:\n";
	std::cin >> index;
	arr = deleteCol(arr, rows, cols, index);
	printArray(arr, rows, cols);*/

	// 5. Initialize and load two double dimension dynamic arrays randomly in -10 and 15 range. Print.
	// User defines number of rows and columns. Get product of arrays.
	// Matrixes can be multiplied if 〖(A〗_(n*m)*B_(m*l)=C_(n*l).
	/*std::cout << "Enter n, m, l:\n";
	std::cin >> n >> m >> l;

	initArray(A, n, m, -10, 15);
	printArray(A, n, m);
	std::cout << std::endl;

	initArray(B, m, l, -10, 15);
	printArray(B, m, l);
	std::cout << std::endl;

	initArray(C, n, l, 0, 0);
	matrixProd(A, B, C, n, m, l);
	printArray(C, n, l);*/

	// 6. Get sum and product of two polynomials whose coefficients defined by dynamic arrays
	/*size = defineLargestArray(sizeM, sizeN);
	array = allocateMem(array, size);
	array = _6_addTwoPolynomials(Arr, Brr, sizeM, sizeN);
	printArray(array, size);
	std::cout << std::endl;
	array = _6_multiplyTwoPolynomials(Arr, Brr, sizeM, sizeN);
	printArray(array, size);
	std::cout << std::endl;*/

	// 7. Given A[M] and B[N]. Create third array with minimal size which gathers elements of both arrays.
	/*array = _7_gatherElmentsFromTwoArrays(Arr, Brr, sizeM, sizeN);
	printArray(array, sizeC);*/

	// 8. Given A[M] and B[N]. Create third array with minimal size which gathers same elements of both arrays.
	/*selectionSort1(Arr, sizeM);
	printArray(Arr, sizeM);
	std::cout << std::endl;
	selectionSort1(Brr, sizeN);
	printArray(Brr, sizeN);
	std::cout << std::endl;
	array = _8_gatherCommonElements(Arr, Brr, sizeM, sizeN);
	printArray(array, defineSizeForCommonElements(Arr, Brr, sizeM, sizeN));*/


	// 9. Given A[M] and B[N]. Create third array with minimal size which includes A elements which aren't in B.
	array = _9_exclusiveAElements(Arr, Brr, sizeM, sizeN);
	printArray(array, defineSizeForExclusiveElements(Arr, Brr, sizeM, sizeN));

	array = freeMem(array);
	arr = freeMem(arr, rows);
	system("pause");
	return 0;
}
