#include "JSSerializer.h"
<<<<<<< HEAD
#include<string>

using namespace std;

JSSerializer::JSSerializer()
{
	// IF WE NEED TO ADD DATA MEMBERS, INIT HERE
}

void JSSerializer::WriteData(CalibrationData * data, string * fileName)
{
	
=======

JSSerializer::JSSerializer(string filename) : m_filename( filename )
{ }

bool JSSerializer::Serialize( shared_ptr<CalibrationData> calibrationData )
{
  ofstream jsFile;
  jsFile.open( m_filename, ios::out | ios::app ); 

  if( !jsFile.is_open() )
	{ return false; } // Unable to open the file

  // Output intrinsic calibration
  jsFile << "this.Intrinsic = [";
  _SerializeMatrix( jsFile, calibrationData->GetIntrinsic( ) );
  jsFile << "]; \n";

  // Output distortion coefficients
  jsFile << "this.Distortion = [";
  _SerializeMatrix( jsFile, calibrationData->GetDistortion( ) );
  jsFile << "]; \n";

  // Finally output extrinsic calibration
  jsFile << "this.Extrinsic = [";
  _SerializeMatrix( jsFile, calibrationData->GetExtrinsic( ) );
  jsFile << "]; \n";

  jsFile.close( );

  return true;
}

void JSSerializer::_SerializeMatrix(ofstream& jsFile, const cv::Mat& matrix2Serialize)
{
  for(int row = 0; row < matrix2Serialize.rows; ++row)
  {
	for(int col = 0; col < matrix2Serialize.cols; ++col)
	{
	  
	  jsFile << matrix2Serialize.at<double>(row, col);
	  
	  if( (row < matrix2Serialize.rows - 1) || (col < matrix2Serialize.cols - 1) )
		{ jsFile << ","; }
	}
  }
>>>>>>> c3363c8642e58378d680d359c8a2fb07f2c8e9ed
}