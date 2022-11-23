#define _CRT_SECURE_NO_WARNINGS
#define _CRTDBG_MAP_ALLOC
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <crtdbg.h>
#define SIZE 16
#define MAX 100


int Size = 1;
int Copy = 0, Comparison =0;
int CollatzNum(numx);
void MergeSort(int* a, int l, int r);
void BubbleSort(int* ptr, int size);
int* CopyOriginal(int* ptr, int size);
void SelectionSort(int* arr, int n);
void qsortRecursive(int* ptr, int size);

//int BubbleSort(arr);
//int SelectedSort(arr);
//int QuickSort(arr);
//
//int* AllocateM(int* ptr);
//int* Resize(int* ptr); // , int sizear);
//void PrintAr(int* ptr); // , int sizear);
//int* CreateAr(int* ptr, int num);//,int sizear

int main()
{
	/*
	*  Declaration of variables:
	*			  ptr1 -  for original array
	*			  ptrtmp - to static array for sorting
	*			  size - for array realloc during func running
	*			  thum - for thum numbers to run loop of sequences
	*             arr - static array
	*			  num - num for func Collatz
	*			  i -  index
	*/
	int size = 1, thum = 10, i = 0, num = 5, tmp = 1, j = 0;

	/*Loop: creation of Collatz numbers sequence for every j*/
	for (j = 5; j < thum; j++)
	{
		/*Declaration: pointer array */
		int* ptr2 = (int*)malloc(sizeof(*ptr2) * Size);
		num = j;

		/*Security check: if memory was allocated*/
		if (ptr2) {

			/*Set: first num of sequence to array using pointer*/
			ptr2[0] = num;

			/*Loop: creation each number while willl get 1-> stop condition
					because Collatz sequence is enterity*/
			while (num != 1)
			{
				/* get generated Collatz number */
				tmp = CollatzNum(num);

				/*Add size and index for next number */
				i++;
				Size++;

				/*create temporary pointer and new block of memory with new size for new number in sequence*/
				int* ptrtmp = (int*)realloc(ptr2, sizeof(int) * Size);

				/*Security check: if memory was allocated*/
				if (ptrtmp) {
					num = tmp;
					ptr2 = ptrtmp;

					/*Set: new number to array */
					*(ptr2 + i) = num;
				}
			}
			printf("The elements of the array are:\n ");
			for (i = 0; i < Size; i++)
			{
				printf("%d\n ", *(ptr2 + i));
			}

		}
		printf("the elements of the array ptr2 are:\n");
		if (ptr2)
		{
			for (i = 0; i < Size; i++)
			{
				printf("%d\n", *(ptr2 + i));
			}
		}
		int* ptr1 = (int*)malloc(sizeof(*ptr2) * Size);
		int *pitmp = (int*)malloc(sizeof(*ptr2) * Size);
		ptr1 = CopyOriginal(ptr2,Size);
		pitmp = CopyOriginal(ptr2,Size);
		printf("the elements of the array ptr1 are:\n");
		if (ptr1)
		{
			for (i = 0; i < Size; i++)
			{
				printf("%d\n", *(ptr1 + i));
			}
		}
		BubbleSort(ptr2, Size);
		printf("Sorted Array --> BubbleSort:\n");
		if (ptr2)
		{
			for (i = 0; i < Size; i++)
			{
				printf("%d\n", *(ptr2 + i));
			}
		}
		printf("Copying - %d, Comparisons - %d\n", Copy, Comparison);
		Copy = 0, Comparison = 0;
		MergeSort(ptr1,0 , Size - 1);
		printf("Sorted Array --> MergeSort:\n");
		if (ptr1)
		{
			for (i = 0; i < Size; i++)
			{
				printf("%d\n", *(ptr1 + i));
			}
		}
		printf("Copying - %d, Comparisons - %d\n", Copy, Comparison);
		Copy = 0, Comparison = 0;
		ptr1 = CopyOriginal(pitmp, Size);
		printf("Return original array to ptr1:\n");
		if (ptr1)
		{
			for (i = 0; i < Size; i++)
			{
				printf("%d\n", *(ptr1 + i));
			}
		}
		SelectionSort(ptr1, Size);
		printf("Sorted Array --> SelectionSort:\n");
		if (ptr1)
		{
			for (i = 0; i < Size; i++)
			{
				printf("%d\n", *(ptr1 + i));
			}
		}
		printf("Copying - %d, Comparisons - %d\n", Copy, Comparison);
		Copy = 0, Comparison = 0;
		ptr1 = CopyOriginal(pitmp, Size);
		printf("Return original array to ptr1:\n");
		if (ptr1)
		{
			for (i = 0; i < Size; i++)
			{
				printf("%d\n", *(ptr1 + i));
			}
		}
		qsortRecursive(ptr1,Size);
		printf("Sorted Array --> qsortRecursive:\n");
		if (ptr1)
		{
			for (i = 0; i < Size; i++)
			{
				printf("%d\n", *(ptr1 + i));
			}
		}
		printf("Copying - %d, Comparisons - %d\n", Copy, Comparison);
		Copy = 0, Comparison = 0;

		//printf("Num of copying - %d,number of compairs - %d\n", Copy, Comparison);
		free(ptr2);
		free(ptr1);
		free(pitmp);
		Size = 1;
		i = 0;
	}
	return 0;
}





//int CountComp = 0;
//int CountCop = 0;
//int thum = 100;
//int Size = 20;


/*
*  Collatz() func created for generate next num of Collatz sequence
*  Description: func get a number and check if it isn't 1 then check if num is odd
*               or even and return needed number after manipulation
*  Сondition: num even --> num/2
*             num odd  --> 3*num+1
*/
int CollatzNum(numx)
{
	int tmp = 0;
	if (numx == 1) {

		return numx;
	}
	else if (numx & 1)
	{
		tmp = (3 * numx + 1);
		//printf("num is : %d\n", tmp);
		return tmp;
	}
	else if (numx % 2 == 0)
	{
		tmp = numx / 2;
		//printf("num is : %d\n", tmp);
		return tmp;
	}
	else {
		printf("Num is : %d,but smth went wrong", tmp);
		return 0;
	}
}


// Функция сортировки нисходящим слиянием
//Копирует в доп массив размер индентичен
//требует дополнительной памяти по объему равной объему сортируемого файла


void MergeSort(int* a, int l, int r)
{
	/*Condition to stop ; when left side == right side of array*/
	if (l == r) return; // границы сомкнулись
	/*Set: middle of sequence*/
	int mid = (l + r) / 2; // определяем середину последовательности
	// и рекурсивно вызываем функцию сортировки для каждой половины
	/*Call recursive sort for each part of sequence*/
	MergeSort(a, l, mid);
	MergeSort(a, mid + 1, r);
	/* Set : Start of first half of sequnce*/
	int i1 = l;  // начало первого пути
	/* Set : Start of second half of sequnce*/
	int j2 = mid + 1; // начало второго пути
	/* Create new array for merge sorted parts */
	int* tmp = (int*)malloc(r * sizeof(int)); // дополнительный массив
	/*Security: check if memory successfully allocated*/
	if(tmp)
	{
		/*Loop: for all elements of temp array*/
		for (int step = 0; step < r - l + 1; step++) // для всех элементов дополнительного массива
		{
			// записываем в формируемую последовательность меньший из элементов двух путей
			// или остаток первого пути если j2 > r

			/*Set: a least of elements from two parts or at rest of first if j>r */	   

			//if second half bigger than full size of 2nd part OR first part less or equal to size of firsr half
			//AND original array index of first part less 	than second part
			if ((j2 > r) || ((i1 <= mid) && (a[i1] < a[j2])))
			{
				tmp[step] = a[i1];
				i1++;
				Copy++;
				Comparison++;
			}
			else 
			{
				tmp[step] = a[j2];
				j2++;
				Copy++;
				Comparison++;
			}
		}
		// переписываем сформированную последовательность в исходный массив
		for (int step = 0; step < r - l + 1; step++)
			a[l + step] = tmp[step];
	}
}



// perform the bubble sort
void BubbleSort(int *ptr, int size) {

	// loop to access each array element
	for (int step = 0; step < size - 1; ++step) {

		// check if swapping occurs  
		int swapped = 0;

		// loop to compare array elements
		for (int i = 0; i < size - step - 1; ++i) 
		{

			// compare two array elements
			// change > to < to sort in descending order
			if (ptr[i] > ptr[i + 1]) {

				// swapping occurs if elements
				// are not in the intended order
				int temp = ptr[i];
				ptr[i] = ptr[i + 1];
				ptr[i + 1] = temp;

				swapped = 1;
				Comparison++;
			}
		}
		// no swapping means the array is already sorted
		// so no need for further comparison
		if (swapped == 0) {
			break;
		}

	}
}


int* CopyOriginal(int* ptr, int size)
{
	int* pi = (int*)malloc(sizeof(*ptr) * Size);
	if (pi && ptr)
	{
		for (int i = 0; i < Size; i++)
		{
			pi[i] = ptr[i];
		}
	}
	return pi;
}


void SelectionSort(int* arr, int n)
{
	int i, j, temp;
	for (i = 0; i < n; i++)	
	{
		for (j = i + 1; j < n; j++)
		{
			if (*(arr + i) > *(arr + j))
			{
				temp = *(arr + j);
				*(arr + j) = *(arr + i);
				*(arr + i) = temp;
				Comparison++;
			}
		}
	}	   
}


void qsortRecursive(int* ptr, int size)
{
	//Указатели в начало и в конец массива
	int i = 0;
	int j = size - 1;

	//Центральный элемент массива
	int mid = ptr[size / 2];

	//Делим массив
	do {
		//Пробегаем элементы, ищем те, которые нужно перекинуть в другую часть
		//В левой части массива пропускаем(оставляем на месте) элементы, которые меньше центрального
		while (ptr[i] < mid)
		{
			i++;
			Comparison++;
		}
		//В правой части пропускаем элементы, которые больше центрального
		while (ptr[j] > mid)
		{
			j--;
			Comparison++;
		}

		//Меняем элементы местами
		if (i <= j)
		{
			int tmp = ptr[i];
			ptr[i] = ptr[j];
			ptr[j] = tmp;

			i++;
			j--;
			Comparison++;
		}
	} while (i <= j);


	//Рекурсивные вызовы, если осталось, что сортировать
	if (j > 0) 
	{
		//"Левый кусок"
		qsortRecursive(ptr, j + 1);
		
	}
	if (i < size)
	{
		//"Првый кусок"
		qsortRecursive(&ptr[i], size - i);

	}
}


 
