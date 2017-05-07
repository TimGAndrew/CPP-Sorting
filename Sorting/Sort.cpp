/*
Sort.cpp

AUTHOR:			Tim Andrew
DATE:			March 21st, 2016
CLASS:			PROG2400-701 - Assignment #2
INSTRUCTOR:		Hal O'Connell
DESCRIPTION:	The Sort class containing sorth methods

*/
#include "Sort.h"

///Sorts an array:

void Sort::BubbleSort(int*& array, int arraySize) 
{
		//Start at the 2nd last element in the array, decrement to 0:
	for (int i = arraySize - 1; i > 0; --i)
	{
			//for each iteration, start at the first element, increment to i
		for (int j = 0; j < i; ++j)
		{
				//Check if this Position's value is greater than the next position:
			if (array[j] > array[j+1])
			{
					//If so, swap them:
				int temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
					//this way the largest element will be at the max position after the first i iteration
			}
		}
	}
}

void Sort::SelectionSort(int*& array, int arraySize)
{ 
		//iterate through the array elements except for the last (increment to end)
	for (int i = 0; i < arraySize - 1; ++i)
	{	
			//set a variable to the smallest value (initialzes to array[0]):
		int min = i;
			//find the smallest element in the array:
		for (int j = i + 1; j < arraySize; ++j)
		{
			if (array[j] < array[min])
			{
				min = j;
			}
		}
			//switch positions of i with position of lowest value:
		int temp = array[i];
		array[i] = array[min];
		array[min] = temp;
	}
}

void Sort::InsertionSort(int*& array, int arraySize)
{ 
		//iterate through each element in the array (after the first element):
	for (int i = 1; i < arraySize; ++i)
	{
			//set j to the iteration count:
		int j = i;

			//while j is > 0 and the array's previous index value is greater than this one:
		while (j > 0 && array[j - 1] > array[j])
		{
				//swap it:
			int temp = array[j];
			array[j] = array[j - 1];
			array[j - 1] = temp;
				//decrement j:
			--j;
		}
	}
}

void Sort::ShellSort(int*& array, int arraySize)
{ 
		//take half the arraysize and increment by 1/2 that size while it's greater than 0:
	for (int increment = arraySize / 2; increment > 0; increment /= 2)
	{
			//for each iteration set i to increment , and while i is less than the array size increment it:
		for (int i = increment; i < arraySize; ++i)
		{
			int j;
			int temp = array[i];

				//for j >= increment, decreasing by increment
			for (j = i; j >= increment; j -= increment)
			{
					//if temp is less than array[j-increment]
				if (temp < array[j - increment])
				{
						//set this array position to that element:
					array[j] = array[j - increment];
				}
				else
				{
					break;
				}
			}
				//set this position to temp:
			array[j] = temp;
		}
	}
}

///Sorts an array by divide and conquer:

void Sort::MergeSort(int* array, int firstIndex, int lastIndex) {
		
		//if there is at least 1 element
	if ((lastIndex - firstIndex) > 1)
	{
			//find the middle:
		int middleIndex = (firstIndex + lastIndex) / 2;

			//Split search the array recursively:
		MergeSort(array, firstIndex, middleIndex);
		MergeSort(array, middleIndex+1, lastIndex);

			//merge the arrays positions:
		Merge(array, firstIndex, middleIndex, lastIndex);
	}
}
	//supporting method for MergeSort:
void Sort::Merge(int* array, int firstIndex, int middleIndex, int lastIndex)
{
	int i = 0, //count1
		j = 0, //count2
		k = firstIndex;

		//determine the size of each 1/2
	int leftSize = middleIndex - firstIndex + 1;
	int rightSize = lastIndex - middleIndex;

		//set up an array pointer:
	int* leftArray;
	int* rightArray;
			//assign it to the determined size:
	leftArray = new int[leftSize];
	rightArray = new int[rightSize];

	 //copy data to the arrays
	for (i = 0; i < leftSize; i++)
	{
		leftArray[i] = array[firstIndex + i];
	}
		
	for (j = 0; j < rightSize; j++)
	{
		rightArray[j] = array[middleIndex + 1 + j];
	}
		

	 //repurpose i & j for sub arrays
	i = 0;
	j = 0;
	
		//while i and j are less than leftSize and rightSize
	while (i < leftSize && j < rightSize)
	{
			//if element in left array is less than or equal to element in right array:
		if (leftArray[i] <= rightArray[j])
		{
				//set that element into the main array:
			array[k] = leftArray[i];
			i++;
		}
		else
		{
				//otherwise set the right element into the main array:
			array[k] = rightArray[j];
			j++;
		}
			//increment main array position:
		k++;
	}

		//copy remaining elements of leftArray in:
	while (i < leftSize)
	{
		array[k] = leftArray[i];
		i++;
		k++;
	}

		//copy remaining elements of rightArray in:
	while (j < rightSize)
	{
		array[k] = rightArray[j];
		j++;
		k++;
	}

		//delete arrays - PS: THIS ADDS A LOT OF TIME (but it has to be done or memory leaks)
	delete[] rightArray;
	delete[] leftArray;

}

void Sort::QuickSort(int* array, int firstIndex, int lastIndex)
{ 
			//if firstIndex is less than lastIndex:
		if (firstIndex < lastIndex)
		{
				//get the interger for the partition:
			int pi = Partition(array, firstIndex, lastIndex);

			// Separately sort elements before
			// partition and after partition
			QuickSort(array, firstIndex, pi - 1);
			QuickSort(array, pi + 1, lastIndex);
		}
}
	//supporting method for QuickSort:
int Sort::Partition(int* array, int firstIndex, int lastIndex)
{
		//set up a pivot point:
	int pivot = array[lastIndex];
	int i = (firstIndex - 1);  // Index of smaller element

	for (int j = firstIndex; j <= lastIndex - 1; j++)
	{
		// If current element is smaller than or equal to pivot
		if (array[j] <= pivot)
		{
			i++;    // increment index of smaller element
			int temp = array[i];
			array[i] = array[j];
			array[j] = temp;
		}
	}
		//handle the last element:
	int temp = array[i + 1];
	array[i + 1] = array[lastIndex];
	array[lastIndex] = temp;

	return (i + 1);
}


///sorts using external files:

void Sort::ExternalSort(string FileToSort)
{
		//set the run size:
	int runSize = 2;
	
		//set the initial output file flag:
	bool sendToInput1 = true;

		//integers to hold file elements:
	int element1;
	int element2;
	
		//Set up some file stream vars:
	fstream fileToSort;
	fstream input1;
	fstream input2;
	fstream merge1;
	fstream merge2;
	fstream outputFile;

		//Set some file names:
	string input1File = "input1.txt";
	string input2File = "input2.txt";
	string merge1File = "merge1.txt";
	string merge2File = "merge2.txt";
	string finalOutput = "ExternalSort.csv";

		//open incomiing file and output files for initial split:
	fileToSort.open(FileToSort, ios::in);
	input1.open(input1File, ios::out);
	input2.open(input2File, ios::out);

		//while there is one element (or not EOF) in the file, set it as e1:
	while (fileToSort >> element1)
	{
			//while there is still one element (or not EOF) in the file, set it as e2:
		if (fileToSort >> element2)
		{
				//compare 2 elements and put them in ASC order:
			if (element1 > element2)
			{
				int tmp = element1;
				element1 = element2;
				element2 = tmp;
			}

				//Alternate the file where these 2 elements will go:
			if (sendToInput1)
			{
				input1 << element1 << endl << element2 << endl;
				sendToInput1 = false;
			}
			else
			{
				input2 << element1 << endl << element2 << endl;
				sendToInput1 = true;
			}
		}
			//otherwise there is one element:
		else
		{
				//Alternate the where this element will go:
			if (sendToInput1)
			{
				input1 << element1 << endl;
				sendToInput1 = false;
			}
			else
			{
				input2 << element2 << endl;
				sendToInput1 = true;
			}
		}
	}

		//Initial split is finished, close the files:
	fileToSort.close();
	input1.close();
	input2.close();
			

		//open the input and merge files:
	input1.open(input1File, ios::in);
	input2.open(input2File, ios::in);

	merge1.open(merge1File, ios::out);
	merge2.open(merge2File, ios::out);

		//While there are still merges, merge:
	while (!ExternalMerge(input1, input2, &merge1, &merge2, runSize))
	{
			//Swap merge files with input files for next merge.
		swap(input1File, merge1File);
		swap(input2File, merge2File);

			//close files to save merges:
		input1.close();
		input2.close();
		merge1.close();
		merge2.close();

			//reopen files to work with again:
		input1.open(input1File, ios::in);
		input2.open(input2File, ios::in);

		merge1.open(merge1File, ios::out);
		merge2.open(merge2File, ios::out);

			//double the runsize:
		runSize *= 2;
	}

		//All Files are merged into input1, so close files:
	input1.close();
	input2.close();
	merge1.close();
	merge2.close();

		//open the finaloutput and input1:
	outputFile.open(finalOutput, ios::out);
	input1.open(input1File, ios::in);

		// write out each element of input1 to the new file (while not EOF):
	while (input1 >> element1)
	{
		outputFile << element1 << endl;
	}
	
		//close the files:
	outputFile.close();
	input1.close();

		//Delete input and merge files:
	remove("input1.txt");
	remove("input2.txt");
	remove("merge1.txt");
	remove("merge2.txt");


}
	//supporting method for ExternalSort - returns if any merges were done (and merges if necessary):
bool Sort::ExternalMerge(fstream& input1, fstream& input2, fstream* merge1, fstream* merge2, int runSize)
{
		//set up some variables to use:
	int input1NumCount;
	int input2NumCount;
	int element1;
	int element2;
	int numOfMerges = 0;
	

		//set a pointer variable hold the incoming merge files:
	fstream* merge1file = merge1;
	fstream* merge2file = merge2;

		//enter a loop to merge all the runs:
	while (true)
	{
			//set number counts:
		input1NumCount = 1;
		input2NumCount = 1;

			//exit if there aren't any values left from input1 file:
		if (!(input1 >> element1))
		{
			break;
		}
			//Add element1 to merge1file and exit if there aren't any values left from input2:
		else if (!(input2 >> element2))
		{
			*merge1file << element1 << endl;
			break;
		}


			//merge runs:
		while (true)
		{
			if (element1 < element2)	
			{
					//add element1
				*merge1file << element1 << endl;

				input1NumCount++;

					//check if input1 has run out of values or run size has been met:
				if (input1NumCount > runSize || !(input1 >> element1))
				{
						//if so, add element2 to file and break out of loop
					*merge1file << element2 << endl;	
					input2NumCount++;
					break;
				}
			}
			else
			{
					//add element to file:
				*merge1file << element2 << endl;

				input2NumCount++;

					//check if runsize has been met or if there's no more values for input2
				if (input2NumCount > runSize || !(input2 >> element2))
				{
						//add element1 to file and break out of loop
					*merge1file << element1 << endl;	
					input1NumCount++;
					break;
				}
			}
		}
			//put remaining values from either element into their merge files:
		while (input1NumCount <= runSize && input1 >> element1)	
		{
			*merge1file << element1 << endl;
			input1NumCount++;
		}
		while (input2NumCount <= runSize && input2 >> element2)
		{
			*merge1file << element2 << endl;
			input2NumCount++;
		}
			//swap the files to work with the next one:
		swap(merge1file, merge2file);
		numOfMerges++;
	}

		//If any  numbers are left add them to the files:
	while (input1 >> element1)
	{
		*merge1file << element1 << endl;
	}
		
	while (input2 >> element2)
	{
		*merge1file << element2 << endl;
	}
		

		//return if any merges were done or not:
	if (numOfMerges != 0)
	{
		return false;
	}
	else
	{
		return true;
	}
		
}