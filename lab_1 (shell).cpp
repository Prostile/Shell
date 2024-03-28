#include "Sort.h"

using namespace std;

int main()
{
	int i, n, Cpairs[6]; //массив с количеством сравнений
	bool Bpairs[6]; //массив с проверками сортировки 

	cin >> n;
	int* Array, ** Parray;
	Array = new int[n];
	Parray = new int* [n];

	//Формирования массива "по возрастанию"
	for (i = 0; i < n; Array[i] = i, i++);  
	for (i = 0; i < n; Parray[i] = &Array[i], i++);
	//Сортировка
	Cpairs[0] = IndirectSortClass<int>::Sort_Shell(Parray, n);
	Bpairs[0] = IndirectSortClass<int>::Indirect_Sort_Check(Parray, n);
	for (i = 0; i < n; Parray[i] = &Array[i], i++);
	Cpairs[1] = IndirectSortClass<int>::Sort_Pyramidal(Parray, n);
	Bpairs[1] = IndirectSortClass<int>::Indirect_Sort_Check(Parray, n);

	//Формирования массива "по убыванию"
	for (i = 0; i < n; Array[i] = n-i, i++);  
	for (i = 0; i < n; Parray[i] = &Array[i], i++);
	//Сортировка
	Cpairs[2] = IndirectSortClass<int>::Sort_Shell(Parray, n);
	Bpairs[2] = IndirectSortClass<int>::Indirect_Sort_Check(Parray, n);
	for (i = 0; i < n; Parray[i] = &Array[i], i++);
	cout << endl;
	Cpairs[3] = IndirectSortClass<int>::Sort_Pyramidal(Parray, n);
	Bpairs[3] = IndirectSortClass<int>::Indirect_Sort_Check(Parray, n);

	//Формирования массива из случайныч чисел
	for (i = 0; i < n; Array[i] = rand() % 1000, i++);  
	for (i = 0; i < n; Parray[i] = &Array[i], i++);
	//Сортировка
	Cpairs[4] = IndirectSortClass<int>::Sort_Shell(Parray, n);
	Bpairs[4] = IndirectSortClass<int>::Indirect_Sort_Check(Parray, n);
	for (i = 0; i < n; Parray[i] = &Array[i], i++);
	Cpairs[5] = IndirectSortClass<int>::Sort_Pyramidal(Parray, n);
	Bpairs[5] = IndirectSortClass<int>::Indirect_Sort_Check(Parray, n);

	//Вывод результатов
	for (int k = 1, i = 0; i <= 5; i += 2, k++){
		cout << k << ") SHELL:     " << Cpairs[i] << " SORT_CHECK: " << (Bpairs[i] == true ? "true" : "false");
		cout << "\n   PYRAMIDAL: " << Cpairs[i + 1] << " SORT_CHECK: " << (Bpairs[i + 1] == true ? "true" : "false");
		cout << endl << endl;
	}

	delete[] Array;
	delete[] Parray;
	return 0;
}

