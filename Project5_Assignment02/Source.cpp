#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>


using namespace std;




// defining the STUDENT_DATA struct
struct STUDENT_DATA
{
	string firstName;
	string lastName;
};



// This function reads the files passed to it and creates and stores the information as student objects 

vector<STUDENT_DATA> CreateStudentDataObjects(string fileName)
{
	ifstream fin;

	STUDENT_DATA studentData;


	string line;  // in order to read line by line


	// define the vector that stores STUDENT_DATA objects
	vector<STUDENT_DATA> studentVector;

	fin.open(fileName);

	if (fin.is_open())
	{
		while (getline(fin, line))
		{
			istringstream lineAsStream(line);   // we are converting the string line to become a stream since 'getline' accepts a stream as its first parameter
			getline(lineAsStream, studentData.lastName, ',');  // the ',' is the seperator of the first and last name so the line is going to be read until this comma

			//now the line is in ',' so we read the rest
			getline(lineAsStream, studentData.firstName, ',');


			// adding the objects to the vector
			studentVector.push_back(studentData);
		}

		fin.close();
	}

	else
		cout << "Cannot open the file " << fileName << endl;


	return studentVector;
}




int main()
{
	string studentDataFileName = "StudentData.txt";

	vector<STUDENT_DATA> studentVector; // defining a vector to store the STUDENT_DATA objects

	studentVector = CreateStudentDataObjects(studentDataFileName);

	return 1;
}


