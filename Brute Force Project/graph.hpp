/***************************************************************
 * Student Name: Lavani Somesan
 * File Name: graph.hpp
 * Assignment number: Project #3
 * 
 * This class  is a completely private class that holds information
 * about a the Adjacency Matrix. The Graph class reads in a file 
 * that contain the distances between cities and puts those values
 * into an adjacency matrix. The class can calculate the cost
 * between two cities or calculate a sequence of cities. The Graph
 * class is used in both the Tour class and the Brute force class to
 * help calculate the cost of a tour sequence.
 ***************************************************************/

#ifndef GRAPH_HPP
#define GRAPH_HPP


#include <iostream>
#include <fstream>
#include <vector>
using namespace std;



class Graph {

	friend class Tour;
	friend class BruteForce;

	private:
		static const int ROW_SIZE = 20;
		static const int COL_SIZE = 20;
		double adjMatrix[ROW_SIZE][COL_SIZE];

		Graph();

		void createAdjacencyMatrix();
		double getEdgeCost(int row, int col);
		void displayAdjacencyMatrix();
		double calculateTourSequenceCost(vector<int> tourSequence, int numCities);

};

#endif
