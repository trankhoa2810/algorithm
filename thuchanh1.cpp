#include <stdio.h>
double calculatePower(double x, int n);
int binarySearch(double arr[], int left, int right, int s);  // khong tim thay return -1
int getLarger(int a, int b);
int Max(int arr[], int left, int right);
int main()
{
	double arr[] = { 1, 2, 4, 5, 7 };
	int arrLenght = (int)sizeof(arr) / sizeof(arr[0]);

	double x;
	int n;
	printf("Nhap x: "); scanf_s("%lf", &x);
	printf("Nhap n: "); scanf_s("%d", &n);
	printf("%.4f ^ %d = %.4lf", x, n, calculatePower(x, n));
	int position = binarySearch(arr, 0, arrLenght - 1, x);
	if (position != -1)
	{
		printf("\n%.4f nam o vi tri %d", x, position);
	}
	else 
	{
		printf("\nKhong tim thay");
	}

	printf("\nGia tri lon nhat %d", Max(arr, 0, arrLenght - 1));

	return 0;
}

int Max(double arr[], int start, int end)
{
	int mm = 0;
	if (end == start)
	{
		return arr[start];
	}
	if ((end - start) == 1)
	{
		return getLarger(arr[start], arr[end]);
	}
	int maxend = Max(arr, start, (end + start) / 2);
	int maxstart = Max(arr, (end + start) / 2, end);
	return mm = getLarger(maxend, maxstart);

}
int getLarger(int a, int b)
{
	return (a > b) ? a : b;
}
int binarySearch(int arr[], int left, int right, int s)
{

	if (right >= left)
	{
		int mid = (left + right) / 2;
		if (s == arr[mid])
		{
			return mid;
		}
		if (arr[mid] > s)
		{
			return binarySearch(arr, left, mid - 1, s);
		}
		return binarySearch(arr, mid + 1, right, s);

	}
	else
	{
		return -1; 
	}
}
double calculatePower(double x, int n)
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
