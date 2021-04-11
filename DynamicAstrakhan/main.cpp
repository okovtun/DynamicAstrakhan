#include <iostream>
using namespace std;
#define tab "\t"
//Function templates
void FillRand(int arr[], const int n);
void FillRand(int** arr, const int m, const int n);

template<typename T>//T - ��������� ��� ������
void Print(T arr[], const int n);
template<typename T>
void Print(T** arr, const int m, const int n);

template<typename T>
void push_back(T*& arr, int& n, T value);
template<typename T>
void push_front(T*& arr, int& n, T value);
template<typename T>
void insert(T*& arr, int& n, T value, int index);

template<typename T>
void pop_back(T*& arr, int& n);
template<typename T>
void pop_front(T*& arr, int& n);
template<typename T>
void erase(T*& arr, int& n, int index);

template<typename T>
void push_row_back(T**& arr, int& m, const int n);
template<typename T>
void push_row_front(T**& arr, int& m, const int n);
template<typename T>
void insert_row(T**& arr, int& m, const int n, int index);

template<typename T>
void pop_row_back(T**& arr, int& m, const int n);
template<typename T>
void pop_row_front(T**& arr, int& m, const int n);
template<typename T>
void erase_row(T**& arr, int& m, const int n, int index);

#define DYNAMIC_MEMORY_1

void main()
{
	setlocale(LC_ALL, "Russian");
#ifdef DYNAMIC_MEMORY_1
	int n;
	cout << "������� ������ �������: "; cin >> n;
	int* arr = new int[n] {};
	FillRand(arr, n);
	Print(arr, n);
	int value;	//���������� ��������
	cout << "������� ����������� ��������: "; cin >> value;
#ifdef PUSH_BACK
	//1) ������� �������� ������ ������� �������:
	int* buffer = new int[n + 1]{};
	//2) �������� ��� �������� �� ��������� ������� � ��������:
	for (int i = 0; i < n; i++)
	{
		buffer[i] = arr[i];
	}
	//3) ����� ���� ��� ������ �����������, �������� ������ ����� �������:
	delete[] arr;
	//4) ��������� ����� � ��������� �� �������� ������:
	arr = buffer;
	//5) � ������ ����� ����� ����� ����� �������� ����� �������� � ����� �������:
	arr[n] = value;
	n++;
#endif // PUSH_BACK
	push_back(arr, n, value);
	Print(arr, n);

	cout << "������� ����������� ��������: "; cin >> value;
	push_front(arr, n, value);
	Print(arr, n);

	int index;
	cout << "������� ����������� ��������: "; cin >> value;
	cout << "������� ������ ������������ ��������: "; cin >> index;
	insert(arr, n, value, index);
	Print(arr, n);

	cout << "�������� ���������� ��������:\n";
	pop_back(arr, n);
	Print(arr, n);
	cout << "������� ������ ����������� ��������: "; cin >> index;
	erase(arr, n, index);
	Print(arr, n);
	delete[] arr;
#endif // DYNAMIC_MEMORY_1
	//----------------���������� ���������� ������������� �������--------------
	int r; //���-�� �����
	int c; // ���-�� ��������� ������
	cout << "������� ���������� �����: "; cin >> r;
	cout << "������� ���������� ��������: "; cin >> c;
	//1)������� ������ ����������
	int** arr2 = new int*[r];
	//2)�������� ������ ��� ������ ���������� �������:
	for (int i = 0; i < r; i++)
	{
		arr2[i] = new int[c] {};
	}
	//----------------������������� ���������� ������������� �������--------------
	FillRand(arr2, r, c);
	Print(arr2, r, c);

	cout << "���������� ������ � ����� �������: " << endl;
	push_row_back(arr2, r, c);
	Print(arr2, r, c);

	cout << "���������� ������ � ������ �������: " << endl;
	push_row_front(arr2, r, c);
	Print(arr2, r, c);

	//int index;
	cout << "������� ������ ����������� ������ ������: "; cin >> index;
	insert_row(arr2, r, c, index);
	Print(arr2, r, c);


	cout << "�������� ��������� ������: " << endl;
	pop_row_back(arr2, r, c);
	Print(arr2, r, c);

	cout << "�������� ������� ������: " << endl;
	pop_row_front(arr2, r, c);
	Print(arr2, r, c);


	cout << "������� ������ ��������� ������: "; cin >> index;
	erase_row(arr2, r, c, index);
	Print(arr2, r, c);


	//----------------�������� ���������� ������������� �������--------------
	//1)������� �����:
	for (int i = 0; i < r; i++)
	{
		delete[] arr2[i];
	}
	//2) �������� ������� ����������:
	delete[] arr2;

}



void FillRand(int arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		arr[i] = rand() % 100;
	}
}
void FillRand(int** arr, const int m, const int n)
{
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			arr[i][j] = rand() % 100;
		}
	}
}

template<typename T>
void Print(T arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << tab;
	}
	cout << endl;
}
template<typename T>
void Print(T** arr, const int m, const int n)
{
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << arr[i][j] << tab;
		}
		cout << endl;
	}
}

template<typename T>
void push_back(T*& arr, int& n, T value)
{
	T* buffer = new T[n + 1]{};

	for (int i = 0; i < n; i++)
	{
		buffer[i] = arr[i];
	}
	delete[] arr;
	arr = buffer;
	arr[n] = value;
	n++;
}
template<typename T>
void push_front(T*& arr, int& n, T value)
{
	T* buffer = new T[n + 1]{};

	for (int i = 0; i < n; i++)
	{
		buffer[i + 1] = arr[i];
	}
	delete[] arr;
	arr = buffer;
	arr[0] = value;
	n++;
}
template<typename T>
void insert(T*& arr, int& n, T value, int index)
{
	T* buffer = new T[n + 1]{};
	for (int i = 0; i < index; i++)
	{
		buffer[i] = arr[i];
	}
	for (int i = index; i < n; i++)
	{
		buffer[i + 1] = arr[i];
	}
	delete[] arr;
	arr = buffer;
	arr[index] = value;
	n++;
}

template<typename T>
void pop_back(T*& arr, int& n)
{
	T* buffer = new T[n - 1]{};
	for (int i = 0; i < n - 1; i++)
	{
		buffer[i] = arr[i];
	}
	delete[] arr;
	arr = buffer;
	n--;
}
template<typename T>
void pop_front(T*& arr, int& n)
{
	T* buffer = new T[n - 1]{};
	for (int i = 0; i < n; i++)
	{
		buffer[i] = arr[i + 1];
	}
	delete[] arr;
	arr = buffer;
	n--;
}
template<typename T>
void erase(T*& arr, int& n, int index)
{
	T* buffer = new T[n - 1]{};
	for (int i = 0; i < n - 1; i++)
	{
		if (i < index)
		{
			buffer[i] = arr[i];
		}
		else
		{
			buffer[i] = arr[i + 1];
		}
	}
	delete[] arr;
	arr = buffer;
	n--;
}

template<typename T>
void push_row_back(T**& arr, int& m, const int n)
{
	//1)������� �������� ������
	T** buffer = new T*[m + 1]{};
	/*for (int i = 0; i < m+1; i++)
	{
		buffer[i] = new int[n] {};
	}*/
	//2)�������� ��� �������� ��������� ������� � ��������
	for (int i = 0; i < m; i++)
	{
		/*	for (int j = 0; j < n; j++)
			{
				buffer[i][j] = arr[i][j];
			}*/
		buffer[i] = arr[i]; // � �������� ������ ��������� ����� ��������������� ������
	}
	//3)������� �������� ������:
	/*for (int i = 0; i < m; i++)
	{
		delete[] arr[i];
	}*/
	//�� ����� ������� ������, ���������� ������� ������ ������ ����������
	delete[] arr;
	//4)�������������� ����� ������
	arr = buffer;
	arr[m] = new T[n] {};
	m++;
}
template<typename T>
void push_row_front(T**& arr, int& m, const int n)
{
	T** buffer = new T*[m + 1]{};

	for (int i = 0; i < m; i++)
	{
		buffer[i + 1] = arr[i];
	}
	delete[] arr;
	arr = buffer;
	arr[0] = new T[n] {};
	m++;
}
template<typename T>
void insert_row(T**& arr, int& m, const int n, int index)
{
	T** buffer = new T*[m + 1]{};
	for (int i = 0; i < index; i++)
	{
		buffer[i] = arr[i];
	}
	for (int i = index; i < m + 1; i++)
	{
		buffer[i + 1] = arr[i];
	}
	delete[] arr;
	arr = buffer;
	arr[index] = new T[n] {};
	m++;
}

template<typename T>
void pop_row_back(T**& arr, int& m, const int n)
{
	T** buffer = new T*[--m]{};

	for (int i = 0; i < m; i++)
	{
		buffer[i] = arr[i];
	}
	delete[] arr[m];
	delete[] arr;
	arr = buffer;
}
template<typename T>
void pop_row_front(T**& arr, int& m, const int n)
{
	T** buffer = new T*[--m]{};

	for (int i = 0; i < m; i++)
	{
		buffer[i] = arr[i + 1];
	}
	delete[] arr[0];
	delete[] arr;
	arr = buffer;
}
template<typename T>
void erase_row(T**& arr, int& m, const int n, int index)
{
	T** buffer = new T*[--m];

	for (int i = 0; i < index; i++)
	{
		buffer[i] = arr[i];
	}
	for (int i = index; i < m; i++)
	{
		buffer[i] = arr[i + 1];
	}
	delete arr[index];
	delete arr;
	arr = buffer;
}