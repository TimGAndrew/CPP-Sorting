/*
FileHandler.cpp

AUTHOR:			Tim Andrew
DATE:			March 21st, 2016
CLASS:			PROG2400-701 - Assignment #3
INSTRUCTOR:		Hal O'Connell
DESCRIPTION:	The FileHandler class to handle writing files:

*/
#include "FileHandler.h"

FileHandler::FileHandler() {}


//Default FileHandler constructor:
FileHandler::FileHandler(int arraySize)
{
	FileName = "SortTimes.csv";
}

void FileHandler::WriteTimes(string timeSheet)
{
	ofstream file(FileName);

	file << timeSheet << endl;

	file.close();
}


//a method to write out the solution to a file:
void FileHandler::WriteSolution(int*& array, int arraySize, string fileName)
{

	ofstream file(fileName);
	
		//for each element
	for (int i = 0; i < arraySize; i++)
	{
		file << array[i] << endl;
	}

	file.close();
}
