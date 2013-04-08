#ifndef _I_SERIALIZER_H_
#define _I_SERIALIZER_H_

#include "CalibrationData.h"
#include <string>

using namespace std;
// A Generic interface for writing out calibration data to a file
class ISerializer
{
public:
	virtual void WriteData(CalibrationData * data, string * fileName) = 0;
};

#endif //_ISERIALIZER_H_