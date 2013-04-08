<<<<<<< HEAD
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
=======
#ifndef _H_PORTAL_CALIBRATION_I_SERIALIZER_
#define _H_PORTAL_CALIBRATION_I_SERIALIZER_

#include <memory>

#include "CalibrationData.h"

using namespace std;

class ISerializer
{
public:
  virtual bool Serialize(shared_ptr<CalibrationData> calibrationData) = 0;
};

#endif // _H_PORTAL_CALIBRATION_I_SERIALIZER_
>>>>>>> c3363c8642e58378d680d359c8a2fb07f2c8e9ed
