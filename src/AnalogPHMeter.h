#ifndef __ANALOG_PH_METER_H__
#define __ANALOG_PH_METER_H__

#include <fs.h>
#include <SPIFFS.h>
#include <ArduinoJson.h>
#include "orderparametermessage.h"

const char PROGMEM pHFileName[]  = "/pH.json";



class PHCalibrationValue 
{
  public:
    char point;
    float value[2];
    int adc[2];
    float slope;
    int adcOffset;
    void saveToFile()
    {
          DynamicJsonBuffer jsonBuffer;
          JsonObject& json = jsonBuffer.createObject();
          // JSONify local configuration parameters
          json["point"] = point;
          json["value0"] = value[0];
          json["value1"] = value[1];
          json["adc0"] = adc[0];
          json["adc1"] = adc[1];
          json["slope"] = slope;
          json["adcOffset"] = adcOffset;

          json.prettyPrintTo(Serial);
          OrderParameterMessage::writeJsonFile(pHFileName, json);    
    }

    bool readFromFile()
    {
      SPIFFS.begin(); 
      File f = SPIFFS.open(pHFileName, "r");
      
      if (!f) 
      {
        Serial.println("pH file not found");
        return false;
      } 
      else 
      {
        size_t size = f.size();
        // Allocate a buffer to store contents of the file.
        std::unique_ptr<char[]> buf(new char[size]);

        f.readBytes(buf.get(), size);
        f.close();
        DynamicJsonBuffer jsonBuffer;
        JsonObject& json = jsonBuffer.parseObject(buf.get());
        if (!json.success()) 
        {
          Serial.print("JSON parseObject() failed:");
          Serial.println(pHFileName);

          return false;
        }
        json.prettyPrintTo(Serial);
        point     = json["point"];
        value[0]  = json["value0"];
        value[1]  = json["value1"];
        adc[0]    = json["adc0"];
        adc[1]    = json["adc1"];
        slope     = json["slope"];
        adcOffset = json["adcOffset"];
      }
      Serial.println("\nLcd file was successfully parsed");
      return true;
    }

  
};

class AnalogPHMeter {
 private:
  class PHCalibrationValue calibrationValue;

  //unsigned int pin;
  float pH;
  float temperature;
  bool debug;

  bool stable;
  unsigned char stableCount;
  float precision;
  unsigned char index;
  float valueBefore, deltaValue, sumOfDeltaValue;
  float deltaValueBuffer[10];

  void inputValue(float value);

 public:

  int readADC(int oversampling = 64);

  //AnalogPHMeter(unsigned int pin);
  AnalogPHMeter();

  AnalogPHMeter &initialize(struct PHCalibrationValue = (struct PHCalibrationValue){});

  AnalogPHMeter &singleReading(void);
  AnalogPHMeter &temperatureCompensation(float temperature);
  AnalogPHMeter &calibration(void);
  AnalogPHMeter &calibrationClear(void);
  AnalogPHMeter &calibrationMid(float mid);
  AnalogPHMeter &calibrationLow(float low);
  AnalogPHMeter &calibrationHigh(float high);
  AnalogPHMeter &factoryReset(void);

  float getpH(void) { return this->pH; };
  float getTemperature(void) { return this->temperature; };
  float getCalibrationPoint(void) { return this->calibrationValue.point; };
  class PHCalibrationValue getCalibrationValue(void) {
    return calibrationValue;
  };

  bool ispHStable(void) { return this->stable; };
  void setpHPrecision(float precision) { this->precision = precision; };
};

#endif
