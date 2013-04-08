<<<<<<< HEAD
#ifndef _JSSERIALIZER_H_
#define _JSSERIALIZER_H_

#include "ISerializer.h"
#include<string>
=======
#ifndef _H_PORTAL_CALIBRATION_JS_SERIALIZER_
#define _H_PORTAL_CALIBRATION_JS_SERIALIZER_

#include <memory>
#include <fstream>

#include "ISerializer.h"
>>>>>>> c3363c8642e58378d680d359c8a2fb07f2c8e9ed

using namespace std;

class JSSerializer : public ISerializer
{
<<<<<<< HEAD
public :
	JSSerializer();
	~JSSerializer();
	void WriteData(CalibrationData * data, string * fileName);
};

#endif
=======
private:
  const string m_filename;

public:
  JSSerializer(string filename);
  bool Serialize(shared_ptr<CalibrationData> calibrationData);

private:
  void _SerializeMatrix(ofstream& jsFile, const cv::Mat& matrix2Serialize);
};

#endif // _H_PORTAL_CALIBRATION_JS_SERIALIZER_
>>>>>>> c3363c8642e58378d680d359c8a2fb07f2c8e9ed
