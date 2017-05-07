/*
Assignment3.cpp

AUTHOR:			Tim Andrew
DATE:			March 21st, 2016
CLASS:			PROG2400-701 - Assignment #3
INSTRUCTOR:		Hal O'Connell
DESCRIPTION:	A driver program for Assignment 3
				This program will allow the user to build a dynamic array
				and then will time the sorts.


*/
#include "Includes.h"
#include "Sort.h"
#include "FileHandler.h"
#include <conio.h>
#include <regex>



	//Global value to determine if file will write out
static bool writeFile;

int GetInteger(string userInput)
{
	string stringToInt = "";

	for (char& c : userInput)
	{
			//write file option:
		if (c == 'w' || c == 'W')
		{
			writeFile = true;
			break;
		}
		else if (isdigit(c))
		{
			writeFile = false;
			stringToInt += c;
		}

	}
	return stoi(stringToInt);
}

int* CopyArray(int*& array, int arraySize)
{
	int* arrayCopy = new int[arraySize];

	for (int i = 0; i < arraySize; ++i)
	{
		arrayCopy[i] = array[i];
	}

	return arrayCopy;
}

void PrintOutArrays(int*& arrayOne, int*& arrayTwo, int arraySize)
{
	for (int i = 0; i < arraySize; ++i)
	{
	cout << arrayOne[i] << "\t" << arrayTwo[i] << endl;
	}
}

int main()
{
	FileHandler timesFile;

	regex validInput("^[0-9]*[1-9][0-9]*[w,W]?$");

	int arraySize;
	int* array;
	int* arrayCopy;

	time_t timeTaken;
	time_t start;
	time_t stop;

	string timeSheet = ",BubbleSort,SelectionSort,InsertionSort,ShellSort,MergeSort,QuickSort,ExternalSort\n";
	
	string indent = "\t\t";
	string divider = "------------------------------\n";
	string introduction = indent + "Tim Andrew (W02120323@nscc.ca)\n" +
						  indent + "PROG2400-701 - Assignment #3\n";
	string introPart1  =  indent + divider +
						  indent + "Sorting Part 1:\n" +
						  indent + divider;
	string introPart2  =  indent + divider + 
						  indent + "Sorting Part 2:\n" +
						  indent + divider;
	string askForInput =  indent +"Enter the # of random numbers to sort (append w [eg. 20w] to send results to a file): ";
	string inputError  =  indent + "\tOnly whole numbers greater than 0 are accepted! Please try again!\n";
	string exitProgram =  indent + divider +
						  indent + "Thanks for using my program!\n";
		                  

	/*------------------------------------------------------------------------------*/	
	cout << introduction << flush;

	while (true)
	{
		

			//Get and validate the user input:
		while (true)
		{
			string userInput;

			cout << askForInput << flush;

			getline(cin, userInput);

			if (regex_match(userInput, validInput))
			{
				arraySize = GetInteger(userInput);
				break;
			}

			cout << inputError << flush;
		}

		cout << introPart1 << flush;

			//create a new file for the timings:
		timesFile = FileHandler(arraySize);

		timeSheet += to_string(arraySize) + ",";
	

			//Create a dynamic 1D array:
		array = new int [arraySize];

			//seed randomness
		srand(time(NULL));

			//populate the array
		for (int i = 0; i < arraySize; ++i)
		{
				//Generate a number between 0 and 32767:
			int randomGeneratedNumber = rand() % 32768 + 0;
			array[i] = randomGeneratedNumber;

		}

			//create a copy of the array:
		arrayCopy = CopyArray(array, arraySize);

	//Bubble Sort it:
		cout << indent + "Performing BubbleSort..." << endl << flush;
		start = clock();
		Sort::BubbleSort(arrayCopy, arraySize);
		stop = clock();
		timeTaken = (stop - start);

		timeSheet +=  to_string(timeTaken) + ",";

		if (writeFile)
		{
			FileHandler::WriteSolution(arrayCopy, arraySize, "BubbleSort.csv");
		}

		cout << indent + indent + "BubbleSort took: " << timeTaken << "ms" << endl;
		
			//Delete and make a new copy of the array:
		delete[] arrayCopy;
		arrayCopy = CopyArray(array, arraySize);

	//Selection Sort:
		cout << indent + "Performing SelectionSort..." << endl << flush;
		start = clock();
		Sort::SelectionSort(arrayCopy, arraySize);
		stop = clock();
		timeTaken = (stop - start);

		timeSheet += to_string(timeTaken) + ",";

		if (writeFile)
		{
			FileHandler::WriteSolution(arrayCopy, arraySize, "SelectionSort.csv");
		}

		cout << indent + indent + "SelectionSort took: " << timeTaken << "ms" << endl;

			//Delete and make a new copy of the array:
		delete[] arrayCopy;
		arrayCopy = CopyArray(array, arraySize);
	
	//Insertion Sort:
		cout << indent + "Performing InsertionSort..." << endl << flush;
		start = clock();
		Sort::InsertionSort(arrayCopy, arraySize);
		stop = clock();
		timeTaken = (stop - start);
	
		timeSheet += to_string(timeTaken) + ",";


		if (writeFile)
		{
			FileHandler::WriteSolution(arrayCopy, arraySize, "InsertionSort.csv");
		}
	
		cout << indent + indent + "InsertionSort took: " << timeTaken << "ms" << endl;

			//Delete and make a new copy of the array:
		delete[] arrayCopy;
		arrayCopy = CopyArray(array, arraySize);

	//Shell Sort:
		cout << indent + "Performing ShellSort..." << endl << flush;
		start = clock();
		Sort::ShellSort(arrayCopy, arraySize);
		stop = clock();
		timeTaken = (stop - start);
	
		timeSheet += to_string(timeTaken) + ",";



		if (writeFile)
		{
			FileHandler::WriteSolution(arrayCopy, arraySize, "ShellSort.csv");
		}

		cout << indent + indent + "ShellSort took: " << timeTaken << "ms" << endl;

			//Delete and make a new copy of the array:
		delete[] arrayCopy;
		arrayCopy = CopyArray(array, arraySize);

	
	//Merge Sort:
		cout << indent + "Performing MergeSort..." << endl << flush;
		start = clock();
		Sort::MergeSort(arrayCopy, 0, arraySize -1);
		stop = clock();
		timeTaken = (stop - start);
	
		timeSheet += to_string(timeTaken) + ",";

		if (writeFile)
		{
			FileHandler::WriteSolution(arrayCopy, arraySize, "MergeSort.csv");
		}

		cout << indent + indent + "MergeSort took: " << timeTaken << "ms" << endl;

			//Delete and make a new copy of the array:
		delete[] arrayCopy;
		arrayCopy = CopyArray(array, arraySize);

	//Quick Sort:
		cout << indent + "Performing QuickSort..." << endl << flush;
		start = clock();
		Sort::QuickSort(arrayCopy, 0, arraySize-1);
		stop = clock();
		timeTaken = (stop - start);

		timeSheet += to_string(timeTaken) + ",";

		if (writeFile)
		{
			FileHandler::WriteSolution(arrayCopy, arraySize, "QuickSort.csv");
		}

		cout << indent + indent + "QuickSort took: " << timeTaken << "ms" << endl;


			//clean up:
		delete[] arrayCopy;
	
/*part 2 of the assignment:*/
		cout << introPart2 << flush;
	
		string UnsortedFile = "UnSortedElements.csv";

			//create an external file to sort:
		FileHandler::WriteSolution(array, arraySize, UnsortedFile);
	
		delete[] array; //won't use it anymore

	//External Sort:
		cout << indent + "Performing ExternalSort..." << endl << flush;
		start = clock();
		Sort::ExternalSort(UnsortedFile);
		stop = clock();
		timeTaken = (stop - start);

		timeSheet += to_string(timeTaken) + "\n";

		cout << indent + indent + "ExternalSort took: " << timeTaken << "ms" << endl;

		

		string choice;

		cout << indent + divider + "\n\t\t\tSort Another Random Array? (y/n)? ";
		getline(cin, choice);
		if (choice == "n" || choice == "N")
		{
			timesFile.WriteTimes(timeSheet);
			break;
		}

	}
	cout << exitProgram << flush;


	return 0;
}