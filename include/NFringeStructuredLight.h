#ifndef _PORTAL_CALIBRATION_N_FRINGE_STRUCTURED_LIGHT_H_
#define _PORTAL_CALIBRATION_N_FRINGE_STRUCTURED_LIGHT_H_

#define _USE_MATH_DEFINES

#include <math.h>
#include <vector>

#include <cv.h>

#include "Utils.h"

using namespace std;

class IStructuredLight
{
public:
  enum FringeDirection
  {
	Horizontal,
	Vertical
  };

  virtual float GetPhi0( int pitch ) = 0;
  virtual float GetPhi( int pitch, int x ) = 0;
  virtual vector<cv::Mat> GenerateFringe( const cv::Size fringeSize, const int pitch, FringeDirection direction ) = 0;
  virtual cv::Mat WrapPhase( vector<cv::Mat> fringeImages, cv::Ptr<cv::FilterEngine> filter = cv::Ptr<cv::FilterEngine>( ) ) = 0;
};

class NFringeStructuredLight : public IStructuredLight
{
private:
  const unsigned int m_numberOfFringes;

public:
  NFringeStructuredLight( );
  NFringeStructuredLight(unsigned int numberOfFringes);
  
  float GetPhi0( int pitch );
  float GetPhi( int pitch, int x );
  vector<cv::Mat> GenerateFringe( const cv::Size fringeSize, const int pitch, FringeDirection direction );
  cv::Mat WrapPhase( vector<cv::Mat> fringeImages, cv::Ptr<cv::FilterEngine> filter = cv::Ptr<cv::FilterEngine>( ) );
};

#endif //_PORTAL_CALIBRATION_N_FRINGE_STRUCTURED_LIGHT_H_
