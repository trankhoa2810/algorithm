#include <stdio.h>
float calculatePower(float x, int n);
bool binarySearch(int arr[], int left, int right, int s);
int getLarger(int a, int b);
int Max(int arr[], int left, int right);
int main()
{
	int arr[] = { 1, 2, 4, 5, 7 };
	int arrLenght = (int)sizeof(arr) / sizeof(arr[0]);
	printf("%d", binarySearch(arr, 0, arrLenght - 1, 7) );
	
	return 0;	
}

int Max(int arr[], int left, int right)
{

}

int getLarger(int a, int b)
{
	if (a > b) return a;
}


bool binarySearch(int arr[], int left, int right, int s)
{
	
	if (right >= left)
	{
		int mid = (left + right) / 2;
		if (s == arr[mid])
		{
			return 1;
		}
		if (arr[mid] > s)
		{
			return binarySearch(arr, left, mid - 1, s);
		}
		return binarySearch(arr, mid + 1, right, s);

	}
	else
	{
		return 0;
	}
}
float calculatePower(float x, int n)
{
	if (n == 0)
	{
		return 1;
	}
	else if (n == 1)
	{
		return x;
	}
	else
	{
		return calculatePower(x, n / 2) * calculatePower(x, n - (n / 2));
	}
}