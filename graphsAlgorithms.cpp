#include <iostream>
#include <vector>

using namespace std;

typedef vector<vector<double>> matrix;

matrix fillRandomMatrix(int);
void printMatrix(matrix);
void primaKraskalaAlgorithm();


void main()
{
	primaKraskalaAlgorithm();
}


matrix fillRandomMatrix(int size) {
	matrix matrix(size, vector<double>(size, 0));

	for (int i = 0; i < size; i++)
	{
		vector<double> row(size, 0);
		for (int j = 0; j < size; j++)
		{
			double num = (double)(rand() % 101);
			if (i < j)
			{
				row[j] = num;
			}
		}
		matrix[i] = row;;
	}

	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (i > j)
			{
				matrix[i][j] = matrix[j][i];
			}
		}
	}

	return matrix;
}

void printMatrix(matrix matrix) {
	for (int i = 0; i < matrix.size(); i++)
	{
		for (int j = 0; j < matrix[i].size(); j++)
		{
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}
}

void primaKraskalaAlgorithm() {

	cout << "Enter a size of path matrix ";
	int size;
	cin >> size;

	matrix loadMatrix = fillRandomMatrix(size);

	cout << "Load matrix" << endl;
	printMatrix(loadMatrix);

	int* colorsArray = new int[size];
	int* resultArray1 = new int[size];
	int* resultArray2 = new int[size];

	for (int i = 0; i < size; i++)
	{
		colorsArray[i] = i;
	}

	int k = 0, rowIndex, columnIndex;
	double lengthTree = 0;

	while (k < size - 1)
	{
		double minLength = DBL_MAX;
		for (int i = 0; i < size - 1; i++)
		{
			for (int j = 0; j < size - 1; j++)
			{
				if (loadMatrix[i][j] < minLength &&
					colorsArray[i] != colorsArray[j])
				{
					minLength = loadMatrix[i][j];
					rowIndex = i; columnIndex = j;
				}
			}
		}

		lengthTree += minLength;
		resultArray1[k] = rowIndex;
		resultArray2[k] = columnIndex;
		k++;

		for (int i = 1; i <= size; i++)
		{
			if (colorsArray[i] == colorsArray[columnIndex])
			{
				colorsArray[i] = colorsArray[rowIndex];
			}
		}
	}

	for (int i = 0; i < size - 1; i++)
	{
		cout << resultArray1[i] << " " << resultArray2[i] << endl;
	}
	cout << "Min length of tree " << lengthTree << endl;

	delete[] colorsArray;
	delete[] resultArray1;
	delete[] resultArray2;
}