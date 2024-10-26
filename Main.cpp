#include "Header.h"
#include <chrono>
#include <fstream>
using namespace std::chrono;

void out_data(int A[], int len)
{
	for (int i = 0; i < len; i++)
	{
		cout << A[i] << " ";
	}
	cout << endl;
}

//��������� ����������
void set_rnd_data(int A[], int len)
{
	random_device random_device;
	mt19937 generator(random_device());
	uniform_int_distribution<> distribution(-1000, 10000);

	for (int i = 0; i < len; i++)
	{
		A[i] = distribution(generator);
	}
}

//����������� ���������� ����������
void set_srd_data(int data[], int len)
{
	for (int i = 1; i <= len; i++) data[i - 1] = i;
}

//��������� � ������� �������� 
void set_rvs_data(int data[], int len) 
{
	for (int i = 0; i < len; i++) data[i] = len - i;
}

//���������� 90/10
void set_alm_srd_data(int data[], int len) 
{
	set_srd_data(data, len);
	random_device random_device;
	mt19937 generator(random_device());
	uniform_int_distribution<> distribution(0, len - 1);

	for (int i = 0; i < len / 20 ; i++) {
		int u = distribution(generator);
		int v = distribution(generator);
		swap(data[u], data[v]);
	}
}


double mst(int data[], int len) {
	auto start = high_resolution_clock::now();
	//sel_sort(data, len);
	//ins_sort(data, len); 
	//bub_sort(data, len);
	//mrg_sort(data, len);
	//shl_sort(data, len);
	//qck_sort(data, len);
	hep_sort(data, len);
	auto end = high_resolution_clock::now();
	duration<double, milli> elapsed = end - start;
	return elapsed.count();
}

int main()
{
	setlocale(LC_ALL, "ru");

	//�������� ����������

	//int len = 100;
	//int *data = new int [len];
	//set_rnd_data(data, len);
	//set_srd_data(data, len);
	//set_rvs_data(data, len);
	//set_alm_srd_data(data, len);
	//out_data(data, len);
	//cout << endl;

	//sel_sort(data, len);
	//ins_sort(data, len);
	//bub_sort(data, len);
	//mrg_sort(data, len);
	//qck_sort(data, len);
	//shl_sort(data, len);
	//hep_sort(data, len);
	
	//out_data(data, len);
	//delete[] data;

	//�������� ����� � �������� ����������

	//*
	int lengths[] = { 5000, 10000, 15000, 20000, 25000, 30000, 35000, 40000, 45000, 50000 };
	int num_lengths = sizeof(lengths) / sizeof(lengths[0]);

	ofstream resultFile("sort_times.txt");
	if (!resultFile.is_open()) {
		cout << "������ �������� ����� ��� ������ �����������" << endl;
		return 1;
	}

	for (int i = 0; i < num_lengths; i++) {
		int len = lengths[i];
		int* data = new int[len];
		//set_rnd_data(data, len);
		//set_srd_data(data, len);
		//set_rvs_data(data, len);
		set_alm_srd_data(data, len);

		double sort_time = mst(data, len);
		resultFile << len << " " << sort_time << endl;
		cout << "������: " << len;
		cout << ", �����: " << sort_time;
		cout << " ms" << endl;

		delete[] data;
	}

	resultFile.close();
	cout << "\n���������� ��������� � sort_times.txt" << endl;
	//*/




	/*
	// ���������� ������� �������� ��� �������
	int sizes[] = { 5000, 10000, 15000, 20000, 25000, 30000, 35000, 40000, 45000, 50000 };
	int num_sizes = sizeof(sizes) / sizeof(sizes[0]);

	// ��������� ������ ��� ������ ����� �������� � ��������
	for (int i = 0; i < num_sizes; i++) {
		int len = sizes[i];
		int* data = new int[len];
		double time_sorted, time_random, time_reverse, time_almost_sorted;

		// ��������� ������� ��� ���������������� �������
		set_srd_data(data, len);
		time_sorted = mst(data, len);
		cout << "Sorted array (" << len << "): " << time_sorted << " ms" << endl;

		// ��������� ������� ��� ���������� �������
		set_rnd_data(data, len);
		time_random = mst(data, len);
		cout << "Random array (" << len << "): " << time_random << " ms" << endl;

		// ��������� ������� ��� �������, ���������������� � �������� �������
		set_rvs_data(data, len);
		time_reverse = mst(data, len);
		cout << "Reverse sorted array (" << len << "): " << time_reverse << " ms" << endl;

		// ��������� ������� ��� ����� ���������������� ������� (90/10)
		set_alm_srd_data(data, len);
		time_almost_sorted = mst(data, len);
		cout << "Almost sorted array (90/10) (" << len << "): " << time_almost_sorted << " ms" << endl;

		// ������������ ������
		delete[] data;
	}
	*/
}