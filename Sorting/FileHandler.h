/*
FileHandler.h

AUTHOR:			Tim Andrew
DATE:			March 21st, 2016
CLASS:			PROG2400-701 - Assignment #3
INSTRUCTOR:		Hal O'Connell
DESCRIPTION:	The header file for the FileHandler class.

*/
#ifndef FILEHANDLER_H
#define FILEHANDLER_H

#include "Includes.h"


class FileHandler
{
private:
	//Stores the file name argument:
	string FileName;

public:
	FileHandler();
	FileHandler(int arraySize);

	void WriteTimes(string timeSheet);

	static void WriteSolution(int*& array, int arraySize, string fileName);

};
#endif FILEHANDLER_H