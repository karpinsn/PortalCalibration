#ifndef _H_PORTAL_CALIBRATION_JS_SERIALIZER_
#define _H_PORTAL_CALIBRATION_JS_SERIALIZER_

#include <fstream>

#include <QObject>
#include <QString>
#include <QFile>
#include <QTextStream>

#include "ISerializer.h"
#include "ScriptInterface.h"

using namespace std;

class JSSerializer : public ISerializer
{
  Q_OBJECT

private:
  const QString m_filename;

public:
  JSSerializer( QString filename );

public slots:
  bool Serialize(CalibrationData* calibrationData);

private:
  void _SerializeMatrix(QTextStream& jsFile, const cv::Mat& matrix2Serialize);
};

#endif // _H_PORTAL_CALIBRATION_JS_SERIALIZER_