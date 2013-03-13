#include "JSSeralizer.h"

void JSSeralizer::WriteCalibFile(CvMat * Intrinsic, CvMat * Distortion, CvMat * Extrinsic, string * outputFileName)
{
	// Open the file we want to write to 
	FILE * fp = fopen(outputFileName->c_str(),"w");

	// Generic error check
	if(fp == NULL)
	{
		printf("There was an error creating our output file.  Please ensure your permissions are set correctly and that you used a valid file descriptor.");
		return;
	}

	// Here we create a pointer to our output string
	string * output = new string();

	// This section builds the Intrinsic matrix
	output->append("this.Intrinsic = [");
	
	// 1 dimentional access for simplicity
	for(int i = 0; i < 12; i++)
	{
		// Puts newlines in the output file to seperate rows of our matrix
		if(i % 4 == 0 && i > 0)
		{
			output->append("\n\t\t");
		}

		// Add an element to our matrix, the cast to long double is a VS2010 hack, c++11 is not fully supported
		output->append(to_string((long double)cvGetReal1D(Intrinsic,i)));
		
		// Add the comma delimiter, but not on the last element
		if(i != 11)
		{
			output->append(", ");
		}
	}

	output->append("];\n");
	// End build Intrinsic matrix

	// This section builds our Distortion Row Vector
	output->append("this.Distortion = [");
	for(int i = 0; i < 5; i++)
	{
		// Again, here we add an element at a time to our string
		output->append(to_string((long double)cvGetReal1D(Distortion,i)));

		// Gotta have those delimiters
		if(i != 4)
		{
			output->append(", ");
		}
	}

	output->append("];");
	// End build Distortion

	// here we build the extrinsic matrix
	output->append("this.Extrinsic = [");
	for(int i = 0; i < 16; i++)
	{
		// This adds newlines between the rows
		if(i % 4 == 0 && i > 0)
		{
			output->append("\n\t\t");
		}

		// Adding our elements
		output->append(to_string((long double)cvGetReal1D(Extrinsic,i)));
		
		// Adding comma deliters
		if(i != 15)
		{
			output->append(", ");
		}
	}
	output->append("];");
	// End Extrinsic

	// Writing our file
	fprintf(fp, output->c_str());
}
