//Class: ADS 103
//Name: Matthew Pettett
//Student ID: A00051029

//TODO: Un Matthew my code so that it looks nice/readable

// Normal includes
#include <iostream>
#include <string>
#include <fstream> //file reading/writing stuff
#include <sstream> // String Stream
#include <vector>  //for storage
#include <chrono>  // for high_resolution_clock A.K.A.(time stuff)

// Header includes
#include "Node.h"
#include "List.h"


using namespace std;


fstream question_1_InputFile;
fstream question_1_OutputFile, question_2_OutputFile;

int ascendingDescending, ifPartSorted, amountOfElements;
vector<string> result;
vector<int> elementsToSort;

// will check if the values of ascendingDescending, ifPartSorted and amountOfElements are valid 
void firstQuestion_validValueCheck(int First, int ifPartSorted, int amountOfElements)
{
	// if 1st or 2nd line do not have a 1 or 0 then the program will
	// display the error and exit
	if ((ascendingDescending != 0 && ascendingDescending != 1) || (ifPartSorted != 0 && ifPartSorted != 1))
	{
		cout << "\n\t!! Error !!" << endl;
		cout << "\n Either line 1 or line 2 of Question 1 is not valid." << endl;
		exit(1);
	}
	if (amountOfElements < 0)
	{
		cout << "\n\t!! Error !!" << endl;
		cout << "\n The 3rd line of Question 1 can not be a negative number." << endl;
		exit(1);
	}
	if (elementsToSort.size() != amountOfElements)
	{
		cout << "\n\t!! Error !!" << endl;
		cout << "\n The amount of data data elements given and the amout of elements declared do not correlate." << endl;
		exit(1);
	}
};

// Ascending and descending Bubble Sort function
void ascendingBubbleSort(vector<int>& elementsToSort, int vectorSize)
{
	bool sorted = false;
	while (!sorted)
	{
		sorted = true;
		for (int i = 0; i < (vectorSize - 1); i++)
		{
			if (elementsToSort[i] > elementsToSort[i + 1])
			{
				swap(elementsToSort[i], elementsToSort[i + 1]);
				sorted = false;
			}
		}
	}
}
void descendingBubbleSort(vector<int>& elementsToSort, int vectorSize)
{
	bool sorted = false;
	while (!sorted)
	{
		sorted = true;
		for (int i = 0; i < (vectorSize - 1); i++)
		{
			if (elementsToSort[i] < elementsToSort[i + 1])
			{
				swap(elementsToSort[i], elementsToSort[i + 1]);
				sorted = false;

			}
		}

	}
}

// Ascending and descending Quick Sort function
// Vector that needs to be sorted, size of the vector, Left pos, Right pos.
void ascendingquicksort(vector<int>& elementsToSort, int vectorSize, int L, int R) {
	int i, j, mid, piv;
	i = L;
	j = R;
	mid = L + (R - L) / 2;
	piv = elementsToSort[mid];

	while (i<R || j>L) {
		while (elementsToSort[i] < piv)
			i++;
		while (elementsToSort[j] > piv)
			j--;

		if (i <= j) {
			swap(elementsToSort[i], elementsToSort[j]);
			i++;
			j--;
		}
		else {
			if (i < R)
				ascendingquicksort(elementsToSort, vectorSize, i, R);
			if (j > L)
				ascendingquicksort(elementsToSort, vectorSize, L, j);
			return;
		}
	}

	
}
void descendingquicksort(vector<int>& elementsToSort, int vectorSize, int L, int R) {
	int i, j, mid, piv;
	i = L;
	j = R;
	mid = L + (R - L) / 2;
	piv = elementsToSort[mid];

	while (i<R || j>L) {
		while (elementsToSort[i] > piv)
			i++;
		while (elementsToSort[j] < piv)
			j--;

		if (i <= j) {
			swap(elementsToSort[i], elementsToSort[j]);
			i++;
			j--;
		}
		else {
			if (i < R)
				descendingquicksort(elementsToSort, vectorSize, i, R);
			if (j > L)
				descendingquicksort(elementsToSort, vectorSize, L, j);
			return;
		}
	}


}


int main() 
{
	// .open takes 2 parameters (file name, what mode the file will be opened as [read (ios::in), wright (ios::out)])
	// Opens the Question 1 output file
	question_1_OutputFile.open("output-a1q1.txt", ios::out);
	// Checks to see if the file was successfully
	if (question_1_OutputFile.is_open())
	{
		// Opens the Question 1 input file
		question_1_InputFile.open("input-a1q1.txt", ios::in);
		if (question_1_InputFile.is_open())
		{
			// line is used to get a line from the input text file
			string line;
			while (getline(question_1_InputFile, line))
			{
				// Reads the text file without any whitespace (spaces)
				istringstream iss(line);
				for (line; iss >> line;) {
					result.push_back(line);
				}
			}

				// This for loop takes the elements from 'result' asignes them to more appropriately
				// named vairables
				for (int i = 0; i < result.size(); i++)
				{
					stringstream stringValue(result[i]);
					// stoi --> String to integer
					// stoi takes a given string (that is a number) and converts it to an integer
					if (i == 0)
					{
						ascendingDescending = stoi(result[i]);
					}
					else if (i == 1)
					{
						ifPartSorted = stoi(result[i]);
					}
					else if (i == 2)
					{
						amountOfElements = stoi(result[i]);
					}
					else
					{
						elementsToSort.push_back(stoi(result[i]));
					}
				}
			

			// Will check if the values of ascendingDescending, ifPartSorted and amountOfElements are valid inputs
			firstQuestion_validValueCheck(ascendingDescending, ifPartSorted, amountOfElements);

			//For ascendingDescending, if it is 0 --> sort in an ascending order
			if (ascendingDescending == 0)
			{
				// 0, 0 --> ascending, Bubble Sort
				if (ifPartSorted == 0) {
					// Records the functions start time
					auto start = chrono::high_resolution_clock::now();
						// Bubble Sort Function
						ascendingBubbleSort(elementsToSort, elementsToSort.size());
					// Records the functions finishing time
					auto end = chrono::high_resolution_clock::now();

					// Calculates how long the sorting algorithm took to execute and prints it to the output file
					question_1_OutputFile << chrono::duration_cast<chrono::microseconds>(end - start).count() << " ms" << endl;
				}
				// 0, 1 --> ascending, Quick Sort
				else if (ifPartSorted == 1) {
					// Records the functions start time
					auto start = chrono::high_resolution_clock::now();
						// Quick Sort Function
						ascendingquicksort(elementsToSort, elementsToSort.size(), 0, (elementsToSort.size() - 1));
					// Records the functions finishing time
					auto end = chrono::high_resolution_clock::now();

					// Calculates how long the sorting algorithm took to execute and prints it to the output file
					question_1_OutputFile << chrono::duration_cast<chrono::microseconds>(end - start).count() << " ms" << endl;
				}
			}

			//For ascendingDescending, if it is 1 --> sort in an descending order                 
			else if (ascendingDescending == 1)
			{
				// 1, 0 --> Descending, Bubble Sort
				if (ifPartSorted == 0) {
					// Records the functions start time
					auto start = chrono::high_resolution_clock::now();
						// Bubble Sort Function
						descendingBubbleSort(elementsToSort, elementsToSort.size());
					// Records the functions finishing time
					auto end = chrono::high_resolution_clock::now();
					
					// Calculates how long the sorting algorithm took to execute and prints it to the output file
					question_1_OutputFile << chrono::duration_cast<chrono::microseconds>(end - start).count() << " ms" << endl;
				}
				// 1, 1 --> Descending, Quick Sort
				else if (ifPartSorted == 1){
					// Records the functions start time
					auto start = chrono::high_resolution_clock::now();
						// Quick Sort Function
						descendingquicksort(elementsToSort, elementsToSort.size(), 0, (elementsToSort.size() - 1));
					// Records the functions finishing time
					auto end = std::chrono::high_resolution_clock::now();

					// Calculates how long the sorting algorithm took to execute and prints it to the output file
					question_1_OutputFile << chrono::duration_cast<chrono::microseconds>(end - start).count() << " ms" << endl;
				}
			}


		}
			
			// Wrights the sorted list of numbers to the output text file
			for (int i = 0; i < elementsToSort.size(); i++)
			{
				question_1_OutputFile << elementsToSort[i] << " ";
			}

		question_1_InputFile.close();
		question_1_OutputFile.close();
		//End of output file Q-1
	}


	// Opens the Question 2 output file
	question_2_OutputFile.open("output-a1q2.txt", ios::out);
	// If file could not be opened, program will exit with an error message
	if (!question_2_OutputFile.is_open())
	{
		cout << "\t!!ERROR!!" << endl;
		cout << "\tQuestion 2 output file named 'output-a1q2.txt' was unable to be opened." << endl;
		exit(1);
	}
	// Opens the Question 2 input file
	ifstream question_2_InputFile;
	question_2_InputFile.open("input-a1q2.txt");
	// If file could not be opened, program will exit with an error message
	if (!question_2_InputFile.is_open())
	{
		cout << "\t!!ERROR!!" << endl;
		cout << "\tQuestion 2 input file named 'input-a1q2.txt' was unable to be opened." << endl;
		exit(1);
	}
	int rngElements;
	question_2_InputFile >> rngElements;

	//using the insert/delete from front
	List listFront;
	//using the insert/delete from the end of the list
	List listEnd;

	// Random number generater RNG seeder
	srand((unsigned int)time(0));
	int insertData = 0;
	// insertAtFront
	{
		// Records the functions start time
		auto start = chrono::high_resolution_clock::now();
		for (int i = 0; i < rngElements; i++)
		{
			insertData = rand();
			listFront.insertAtFront(insertData);
		}
		// Records the functions finishing time
		auto end = std::chrono::high_resolution_clock::now();
		// Calculates how long the sorting algorithm took to execute and prints it to the output file
		question_2_OutputFile << chrono::duration_cast<chrono::microseconds>(end - start).count() << " ms" << endl;
	}

	// insertAtEnd
	{
		// Records the functions start time
		auto start = chrono::high_resolution_clock::now();
		for (int i = 0; i < rngElements; i++)
		{
			insertData = rand();
			listEnd.insertAtEnd(insertData);
		}
		// Records the functions finishing time
		auto end = std::chrono::high_resolution_clock::now();
		// Calculates how long the sorting algorithm took to execute and prints it to the output file
		question_2_OutputFile << chrono::duration_cast<chrono::microseconds>(end - start).count() << " ms" << endl;
	}

	// deleteAtFront
	{
		// Records the functions start time
		auto start = chrono::high_resolution_clock::now();
		for (int i = 0; i < rngElements; i++)
		{
			listFront.deleteAtFront();
		}
		// Records the functions finishing time
		auto end = std::chrono::high_resolution_clock::now();
		// Calculates how long the sorting algorithm took to execute and prints it to the output file
		question_2_OutputFile << chrono::duration_cast<chrono::microseconds>(end - start).count() << " ms" << endl;
	}

	// deleteAtEnd
	{
		// Records the functions start time
		auto start = chrono::high_resolution_clock::now();
		for (int i = 0; i < rngElements; i++)
		{
			listEnd.deleteAtEnd();
		}
		// Records the functions finishing time
		auto end = std::chrono::high_resolution_clock::now();
		// Calculates how long the sorting algorithm took to execute and prints it to the output file
		question_2_OutputFile << chrono::duration_cast<chrono::microseconds>(end - start).count() << " ms" << endl;
	}
		question_2_InputFile.close();
		question_2_OutputFile.close();



	system("pause");
}