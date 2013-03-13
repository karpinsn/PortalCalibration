#ifndef JS_SERALIZER
#define JS_SERALIZER

#include <string>
#include <cv.h>
#include <cstdio>

class JSSeralizer
{
public:
	static void WriteCalibFile(CvMat * Intrinsic, CvMat * Distortion, CvMat * Extrinsic, string * outputFileName);
};

#endif //Include Guard