#include<iostream>
using namespace std;

int * ArraySetItem(int);
void ArrayList(int *, int);
int * ShellSort(int *, int);
void ArraySubnet(int *, int *, int, int);

void main()
{

	int array1_length, array2_length;

	cout << "------------------------------------------- " << endl;

	cout << "Ilk arrayin uzunlugu: ";
	cin >> array1_length;
	cout << "------------------------------------------- " << endl;

	cout << "Ikinci arrayin uzunlugu: ";
	cin >> array2_length;

	cout << "------------------------------------------- " << endl;

	int *array1 = ArraySetItem(array1_length);
	cout << "------------------------------------------- " << endl;
	int *array2 = ArraySetItem(array2_length);

	cout << "------------------------------------------- " << endl;
	cout << "Arraylerin elemanlari " << endl;
	cout << "------------------------------------------- " << endl;
	cout << "Array1 " << endl;
	cout << "------------------------------------------- " << endl;
	ArrayList(array1, array1_length);
	cout << endl;
	cout << "------------------------------------------- " << endl;
	cout << "Array2 " << endl;
	cout << "------------------------------------------- " << endl;
	ArrayList(array2, array2_length);
	cout << endl;
	cout << "------------------------------------------- " << endl;
	cout << "Siralanmis Diziler " << endl;
	cout << "------------------------------------------- " << endl;
	cout << "Array1 " << endl;
	cout << "------------------------------------------- " << endl;
	int *Sort_array1 = ShellSort(array1, array1_length);
	ArrayList(Sort_array1, array1_length);
	cout << endl;
	cout << "------------------------------------------- " << endl;
	cout << "Array2 " << endl;
	cout << "------------------------------------------- " << endl;
	int *Sort_array2 = ShellSort(array2, array2_length);
	ArrayList(Sort_array2, array2_length);
	cout << endl;
	cout << "------------------------------------------- " << endl;
	ArraySubnet(Sort_array1, Sort_array2, array1_length, array2_length);
	cout << "------------------------------------------- " << endl;



	system("pause");
}

int * ArraySetItem(int array_length)
{
	int* arr = new int[array_length];

	cout << "Arrayin elemanlarini giriniz: " << endl;


	for (int i = 0; i < array_length; i++)
	{
		cout << i + 1 << ". eleman :";
		cin >> arr[i];
	}

	return arr;
}

void ArrayList(int *arr, int array_length)
{
	for (int i = 0; i < array_length; i++)
	{
		cout << arr[i] << "\t";
	}

}

int * ShellSort(int *arr, int array_length)
{

	for (int gap = array_length / 2; gap > 0; gap /= 2)
	{

		for (int i = gap; i < array_length; i += 1)
		{

			int temp = arr[i];

			int j;
			for (j = i; j >= gap && arr[j - gap] > temp; j -= gap)
				arr[j] = arr[j - gap];

			arr[j] = temp;
		}
	}
	return arr;
}

void ArraySubnet(int *arr, int *arr2, int array_length, int array_length2)
{

	int flag = 0;

	if (array_length2 >= array_length)
	{

		for (int j = 0; j < array_length2; j++)
		{
			if (array_length2 - j < array_length2 - array_length)
			{
				flag == -1;
				break;
			}
			else
			{
				if (arr[0] == arr2[j])
				{
					for (int i = 1; i < array_length; i++)
					{
						if (arr[i] == arr2[j + i])
							flag++;
						else
						{
							flag = -1;
							break;
						}
					}
				}

			}
		}

		if (flag + 1 == array_length)
			cout << "Subnettir." << endl;
		else
			cout << "Subnet degildir." << endl;

	}
	else
	{
		for (int j = 0; j < array_length; j++)
		{
			if (array_length - j < array_length - array_length2)
			{
				flag == -1;
				break;
			}
			else
			{
				if (arr2[0] == arr[j])
				{
					for (int i = 1; i < array_length2; i++)
					{
						if (arr2[i] == arr[j + i])
							flag++;
						else
						{
							flag = -1;
							break;
						}
					}
				}

			}
		}

		if (flag + 1 == array_length2)
			cout << "Subnettir." << endl;
		else
			cout << "Subnet degildir." << endl;

	}

}