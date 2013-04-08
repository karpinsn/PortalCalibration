#ifndef _JSSERIALIZER_H_
#define _JSSERIALIZER_H_

#include "ISerializer.h"
#include<string>

using namespace std;

class JSSerializer : public ISerializer
{
public :
	JSSerializer();
	~JSSerializer();
	void WriteData(CalibrationData * data, string * fileName);
};

#endif