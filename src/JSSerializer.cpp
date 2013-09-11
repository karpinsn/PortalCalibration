#include "JSSerializer.h"

JSSerializer::JSSerializer( QString filename ) : m_filename( filename )
{ }

bool JSSerializer::Serialize( CalibrationData* calibrationData )
{
  if(nullptr == calibrationData)
	{ return false; }

  QFile file( m_filename );

  if( !file.open( QIODevice::WriteOnly | QIODevice::Truncate ) )
	{ return false; } // Unable to open the file

  QTextStream jsFileStream( &file );


  // Output intrinsic calibration
  jsFileStream << "this.Intrinsic = [";
  _SerializeMatrix( jsFileStream, calibrationData->GetIntrinsic( ) );
  jsFileStream << "]; \n";

  // Output distortion coefficients
  jsFileStream << "this.Distortion = [";
  _SerializeMatrix( jsFileStream, calibrationData->GetDistortion( ) );
  jsFileStream << "]; \n";

  // Finally output extrinsic calibration
  jsFileStream << "this.Extrinsic = [";
  _SerializeMatrix( jsFileStream, calibrationData->GetExtrinsic( ) );
  jsFileStream << "]; \n";

  file.close( );
  return true;
}

void JSSerializer::_SerializeMatrix(QTextStream& jsFile, const cv::Mat& matrix2Serialize)
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
}