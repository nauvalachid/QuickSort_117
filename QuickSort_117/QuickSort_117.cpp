#include <iostream>
using namespace std;


int arr[20];				//array of integres to hold values
int cmp_count = 0;			//number of comparison
int mov_count = 0;			//number of data movements
int n; 

void input() {
	while (true)
	{
		cout << "Masukkan panjang element array: ";
		cin >> n;

		if (n <= 20)
			break;
		else
			cout << "\nMaksimum panjang array adalah 20" << endl;
	}

	cout << "\n-------------------" << endl;
	cout << "\nEnter Array Element" << endl;
	cout << "\n-------------------" << endl;

	for (int i = 0; i < n; i++)
	{
		cout << "<" << (i + 1) << ">";
		cin >> arr[i];
	}
}

//swaps the element st index x with the element at index y
void swap(int x, int y)
{
	int temp;

	temp = arr[x];
	arr[x] = arr[y];
	arr[y] = temp;
}

void q_short(int low, int high)
{
	int pivot, i, j;
	if (low > high)						//langkah algoritma No. 1
		return;

	//Partition the list into two parts;
	//one containing element less that or equal to pivot 
	//OUther conntainning elements greather than pivot 

	pivot = arr[low];					//Langkah ALgoritma No. 2

	i = low + 1;						//Langkah Algoritma No.3
	j = high;							//Langkah Algoritma NO.4


	while (i <= j)						//Langkah Algoritma No.5
	{
		//search for an element less than or equal to pivot 
		while ((arr[i] <= pivot) && (i <= high))	//Langkah Algoritma No. 6
		{
			i++;
			cmp_count++;
		}
		cmp_count++;

		//search for an element less than or equal to pivot
		while ((arr[j] > pivot) && (j >= low))			//Langkah Algoritma No. 7
		{
			j--;										//Langkah Algoritma No. 8
			cmp_count++;
		}
		cmp_count++;

		// if the greater element is on the left of the element
		if (i < j)
		{
			//swap the element at index i whit the element at index j
			swap(i, j);
			mov_count++;
		}
	}
	//j now containt the index of the last element in the sorted list
	if (low < j)									//Langkah ALgoritma No.9
	{
		//move the pivot to its correct position in the list 
		swap(low, j);
		mov_count++;
	}
	//sort the list on the left of pivot using quick sort
	q_short(low, j - 1);							//Langkah ALgoritma No.10

	//sort the list on the right of pivot using quick sort 
	q_short(j + 1, high);							//Langkah Algoritma N0.11

}

void display() {
	cout << "\n---------------------" << endl;
	cout << "Sorted Array" << endl;
	cout << "---------------------" << endl;

	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << " ";
	}

	cout << "\n\nNumber of comparisions: " << cmp_count << endl;
	cout << "Number of data movements: " << mov_count << endl;
}

int main()
{
	input();
	q_short(0, n - 1);		//Sort the array using quick sort
	display();
	system("pause");

	return 0;
}