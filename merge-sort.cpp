#include <iostream>
#include <limits>
#include <new>
using namespace std;

int integerInput();
int getSize();
void mergeSort(int[], int, int);
void merge(int[], int, int, int);
void displayArray(int[], int);

int main()
{
	int size, * arr;

	cout << "Enter the size of the array: ";
	size = getSize();
	arr = new (nothrow) int[size];
	if (arr == nullptr)
	{
		cout << endl << "Failed to allocate memory! Please restart the application.";
		exit(0);
	}

	cout << endl << "Enter all the elements of the array: ";
	for (int i = 0; i < size; i++)
	{
		arr[i] = integerInput();
		if (size - i - 1 == 0)
			break;
		cout << "Elements remaining to be entered: " << size - i - 1 << endl;
	}

	mergeSort(arr, 0, size - 1);
	displayArray(arr, size);

	return 0;
}

int integerInput()
{
	int n;

	while (!(cin >> n))
	{
		cin.clear();
		cin.ignore(numeric_limits <streamsize>::max(), '\n');
		cout << endl << "Invalid integer input! Please try again with correct input: ";
	}

	return n;
}

int getSize()
{
	int size = integerInput();

	if (size <= 0)
	{
		cout << endl << "Invalid size! Please try again: ";
		size = getSize();
	}

	return size;
}

void mergeSort(int arr[], int start, int end)
{
	if (start < end)
	{
		int mid = (start + end) / 2;

		mergeSort(arr, start, mid);
		mergeSort(arr, mid + 1, end);

		merge(arr, start, mid, end);
	}
}

void merge(int arr[], int start, int mid, int end)
{
	int i = start, j = mid + 1, k = start;
	int* tempArr = new (nothrow) int[end + 1];
	if (tempArr == nullptr)
	{
		cout << endl << "Failed to allocate memory! Please restart the application.";
		exit(0);
	}

	while (i <= mid && j <= end)
	{
		if (arr[i] <= arr[j])
		{
			tempArr[k] = arr[i];
			i++;
		}
		else
		{
			tempArr[k] = arr[j];
			j++;
		}

		k++;
	}

	for (i; i <= mid; i++)
	{
		tempArr[k] = arr[i];
		k++;
	}

	for (j; j <= end; j++)
	{
		tempArr[k] = arr[j];
		k++;
	}

	for (int iter = start; iter <= end; iter++)
	{
		arr[iter] = tempArr[iter];
	}
}

void displayArray(int arr[], int size)
{
	cout << endl << "The sorted array is: ";

	for (int i = 0; i < size; i++)
	{
		cout << "|" << arr[i] << "|";
	}
}