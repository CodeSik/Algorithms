#include <iostream>
#include <cstdlib>
#include <fstream>
#include <ctime>


using namespace std;

int length = 0;



void swap(int* a, int* b) { 
	int temp = *a; 
	*a = *b; 
	*b = temp;
}

int partition(int* arr, int p, int r)
{

	int x = arr[r];
	
	int i = p - 1, j;
	
	for (j = p; j < r ; j++) {
		if (arr[j] <= x) {
			i = i + 1;

			swap(&arr[i], &arr[j]);
	
		}
	}
	swap(&arr[i+1], &arr[j]);

	return i + 1;
}

int randomized(int* arr, int p, int r) {
	int a = rand() % (r-p+1) +p;
	int b = rand() % (r - p + 1) + p;
	int c = rand() % (r - p + 1) + p;
	int midindex;

	if (arr[a] >= arr[b])
		if (arr[b] >= arr[c])
			midindex = b;
		else if (arr[a] <= arr[c])
			midindex = a;
		else
			midindex = c;
	else if (arr[a] > arr[c])
		midindex = a;
	else if (arr[b] > arr[c])
		midindex = c;
	else
		midindex = b;

	swap(&arr[r], &arr[midindex]);
	
	return partition(arr, p, r);
}

void quick_sort(int* arr, int p, int r) {
	if( p < r ){
		int q = randomized(arr, p, r);
		quick_sort(arr, p, q - 1);
		quick_sort(arr, q+1, r);
	}
}

void insertion_sort(int* arr, int n) {
	int i, j, key;

	for (i = 1; i < n; i++)
	{
		key = arr[i];

		for (j = i - 1; j >= 0; j--)
		{
			if (arr[j] > key)
			{
				arr[j + 1] = arr[j];
			}
			else
			{
				break;
			}

		}
		arr[j + 1] = key;
	}
}



int main() {
	srand((unsigned)time(NULL)); // 매번 새로운 random value 를 받기위한 구문

	FILE* file = fopen("input2-1.txt", "r");
	FILE* outfile = fopen("output2-1.txt", "w");

	int* arr = new int[200000]; // 총 20만개의 array 동적할당

	if (file == NULL) {
		return 0;
	}

	while (!feof(file)) { // 배열에 값 저장
		fscanf(file, "%d ", &arr[length]);

		if (arr[length] < 0 || arr[length] > 10000) { //0 이상 10000미만의 값을 가지게 하는 조건
			return 0;
		}

		length++;
	}

	
	if (3 <= length && length <= 10) { // 원소가 3이상 10이하일때 insertion sort
		clock_t start, end;
		float delay;
		start = clock();
		insertion_sort(arr, length); // 시간을 잴 함수
		end = clock();
		delay = (float)(end - start) / CLOCKS_PER_SEC;

		for (int i = 0; i < length; i++)
		{
			fprintf(outfile, "%d ", arr[i]);
		}
		fprintf(outfile, "%s", "\n");
		fprintf(outfile, "%.3f s", delay);
		
		
	}
	else if (length < 3 || length > 200000) { //원소의 갯수 조건을 벗어날 때 프로그램 종료
		return 0;
	}
	else
	{
		clock_t start, end;
		float delay;
		start = clock();
		quick_sort(arr, 0, length - 1); // 시간을 잴 함수
		end = clock();
		delay = (float)(end - start) / CLOCKS_PER_SEC; // 나머지는 퀵소트로 돌린다.

		for (int i = 0; i < length; i++)
		{
			
			fprintf(outfile, "%d ", arr[i]);
		}

		fprintf(outfile, "%s", "\n");
		fprintf(outfile, "%.3f s", delay);
		
	}


	fclose(file);
	fclose(outfile);

	arr = NULL;
	delete[] arr;

	
}