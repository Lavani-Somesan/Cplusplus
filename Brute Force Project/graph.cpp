#include "graph.hpp"


Graph::Graph()
{
	createAdjacencyMatrix();
}


void Graph::createAdjacencyMatrix()
{
	ifstream inFS;
	vector<double> dataList;
	string fileName = "distances.txt";
	bool isFileOpen = true;
	double data;
	int count = 0;
	

	inFS.open(fileName.c_str());

	if(!inFS.is_open()) 
	{
	cout << "Could not open file" << endl;
	isFileOpen = false;
	}

	if(isFileOpen == true)
	{
		while(inFS >> data)
		{
			dataList.push_back(data);
		}
	}

	for(int i = 0; i < ROW_SIZE; i++)
	{
		for(int j = 0; j < COL_SIZE; j++)
		{
			if(i == j)
			{
				adjMatrix[i][j] = 0;
			}

			else 
			{
				adjMatrix[i][j] = dataList.at(count);
				adjMatrix[j][i] = dataList.at(count);
				count++;
			}
		}
	}
}


double Graph::getEdgeCost(int row, int col)
{
	double edgeCost = adjMatrix[row][col];

	return edgeCost;
}


double Graph::calculateTourSequenceCost(vector<int> tourSequence, int numCities)
{
	int row;
	int col;
	double tourCost = 0;

	for(int i = 0; i < numCities; i++)
	{
		if(i == numCities - 1)
		{
			row = tourSequence.at(i);
			col = 0;
			tourCost += getEdgeCost(row, col);
		}
		
		else
		{
			row = tourSequence.at(i);
			col = tourSequence.at(i+1);
			tourCost += getEdgeCost(row, col);
		}
	}

	return tourCost;
}


void Graph::displayAdjacencyMatrix()
{
	for(int i = 0; i < ROW_SIZE; i++)
	{
		for(int j = 0; j < COL_SIZE; j++)
		{
			cout << adjMatrix[i][j] << "    ";
		}
		cout << endl;
	}
}
