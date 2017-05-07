/*
Sort.h

AUTHOR:			Tim Andrew
DATE:			March 21st, 2016
CLASS:			PROG2400-701 - Assignment #2
INSTRUCTOR:		Hal O'Connell
DESCRIPTION:	A header file for the Sort class

*/
#ifndef SORT_H
#define SORT_H

#include "Includes.h"

class Sort
{
private:
		//a private method for MergeSort:
	static void Merge(int* array, int firstIndex, int middleIndex, int lastIndex);
		//a private method for QuickSort:
	static int Partition(int* array, int firstIndex, int lastIndex);
		//a private method for ExternalSort:
	static bool ExternalMerge(fstream& input1, fstream& input2, fstream* merge1, fstream* merge2, int runSize);
public:
		//sorting methods:
	static void BubbleSort(int*& array, int arraySize);
	static void SelectionSort(int*& array, int arraySize);
	static void InsertionSort(int*& array, int arraySize);
	static void ShellSort(int*& array, int arraySize);
	static void MergeSort(int* array, int firstIndex, int lastIndex);
	static void QuickSort(int* array, int firstIndex, int lastIndex);
	static void ExternalSort(string fileToSort);
};

#endif SORT_H