#include <iostream>
#include <vector>

using namespace std;

typedef vector<vector<double>> matrix;

matrix fillRandomMatrix(int);
void printMatrix(matrix);
void primaKraskalaAlgorithm();
void dijkstraAlgorithm();


void main()
{
	// primaKraskalaAlgorithm(); 
	dijkstraAlgorithm();
}


matrix fillRandomMatrix(int size) {
	matrix matrix(size, vector<double>(size, 0));

	for (int i = 0; i < size; i++)
	{
		vector<double> row(size, 0);
		for (int j = 0; j < size; j++)
		{
			double num = (double)(rand() % 10);
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


void dijkstraAlgorithm() {
	cout << "Enter a size of path matrix ";
	int size;
	cin >> size;

	matrix loadMatrix = fillRandomMatrix(size);

	cout << "Load matrix" << endl;
	printMatrix(loadMatrix);

	int* consideredNodesArray = new int[size];
	double* distancesArray = new double[size];
	int* nodeNumbersArray = new int[size];

	cout << "Enter a start node ";
	int startNode;
	cin >> startNode;

	for (int i = 0; i < size; i++)
	{
		consideredNodesArray[i] = 0;
		nodeNumbersArray[i] = startNode;
		distancesArray[i] = loadMatrix[startNode][i];
	}
	consideredNodesArray[startNode] = 1;
	nodeNumbersArray[startNode] = 0;

	int index = 0;
	for (int i = 0; i < size - 1; i++)
	{
		double minLength = DBL_MAX;
		for (int j = 0; j < size; j++)
		{
			if (consideredNodesArray[j] == 0 &&
				distancesArray[j] < minLength)
			{
				index = j;
				minLength = distancesArray[j];
			}
		}
		cout << "min length = " << minLength << " for node = " << index << endl;
		consideredNodesArray[index] = 1;

		for (int j = 0; j < size; j++)
		{
			if (distancesArray[j] > distancesArray[index] + loadMatrix[index][j])
			{
				distancesArray[j] = distancesArray[index] + loadMatrix[index][j];
				cout << j << " " << distancesArray[j] << endl;
				nodeNumbersArray[j] = index;
			}
		}

		int temp = 0;
		for (int j = 0; j < size; j++)
		{
			temp = nodeNumbersArray[j];
			cout << "node number = " << j << ": ";
			while (temp != 0)
			{
				cout << temp << " ";
				temp = nodeNumbersArray[temp];
			}
			cout << endl;
		}
	}

	delete[] consideredNodesArray;
	delete[] distancesArray;
	delete[] nodeNumbersArray;
}