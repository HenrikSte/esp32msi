//#include <tinyxml2.h>
//#include "orderparametermessage.h"
//using namespace tinyxml2;

//#include <AnalogPHMeter.h>

                                          
const char PROGMEM  PhotoMeterConfigFileName[] = "/PMConfig.json";

#define PM_BATCHID             "{{BatchId}}"
#define PM_VALUE                  "{{value}}"


const char PROGMEM  PM_MDGetValue[] ="<?xml version=\"1.0\" encoding=\"UTF-8\"?>"
                                  "<MsiInterfaceDescription xmlns:xsi=\"http://www.w3.org/2001/XMLSchema-instance\">"
                                    "<messageId>GetValue</messageId>"
                                    "<supplierId>Werum</supplierId>"
                                    "<deviceTypeId>ESP_photo_meter</deviceTypeId>"
                                    "<description>Get current pH Reading</description>"
                                    "<supplierVersion>1.0</supplierVersion>"
                                    "<systemId>"
                                    OP_MESSAGEID
                                    "</systemId>"
                                    "<creationTime>2018-05-03 13:05:00,000</creationTime>"
                                    "<parameter>"
                                        "<name>BatchID</name>"
                                        "<description>Batch ID</description>"
                                        "<dataType>String</dataType>"
                                        "<direction>BOTH</direction>"
                                        "<isMesQualifier>true</isMesQualifier>"
                                        "<isSfQualifier>true</isSfQualifier>"
                                    "</parameter>"
                                    "<parameter>"
                                        "<name>pH</name>"
                                        "<description>Current pH value</description>"
                                        "<dataType>Double</dataType>"
                                        "<direction>TO_MES</direction>"
                                        "<isMesQualifier>false</isMesQualifier>"
                                        "<isSfQualifier>false</isSfQualifier>"
                                        "<definitionRange>"
                                          "<fromValue>0</fromValue>"
                                          "<toValue>14</toValue>"
                                        "</definitionRange>"
                                        "<uom>pH</uom>"
                                    "</parameter>"
                                    "<attachment>"
                                    "</attachment>"
                                  "</MsiInterfaceDescription>";





const char PROGMEM  PM_responseGetValue[] ="<?xml version=\"1.0\"\?>"
                            "<MsiMessageContainer xmlns:xsi=\"http://www.w3.org/2001/XMLSchema-instance\" xmlns:xsd=\"http://www.w3.org/2001/XMLSchema\">"
                            "<messageInstanceId>"
                            OP_MESSAGEINSTANCEID1
                            "</messageInstanceId>"
                            "<direction>SF_TO_MES</direction>"
                            "<systemId>"
                            OP_SYSTEMID
                            "</systemId>"
                                "<messageType>MsiOrderParameterMessage</messageType>"
                                "<message>"
                                    "<MsiOrderParameterMessage>"
                                        "<messageInstanceId>"
                                        OP_MESSAGEINSTANCEID2
                                        "</messageInstanceId>"
                                        "<direction>SF_TO_MES</direction>"
                                        "<messageId>"
                                        OP_MESSAGEID
                                        "</messageId>"
                                        "<supplierId>Werum</supplierId>"
                                        "<deviceTypeId>ESP_photo_meter</deviceTypeId>"
                                        "<supplierVersion>1.0</supplierVersion>"
                                        "<creationTime>" 
                                        OP_CREATIONTIME 
                                        "</creationTime>"
                                        "<parameter>"
                                            "<name>BatchID</name>"
                                            "<dataType>String</dataType>"
                                            "<value>"
                                            PM_BATCHID
                                            "</value>"
                                            "<isQualifier>true</isQualifier>"
                                            "<acquisitionTime>{{CreationTime}}</acquisitionTime>"
                                        "</parameter>"    
                                        "<parameter>"
                                            "<name>pH</name>"
                                            "<dataType>Double</dataType>"
                                            "<value>"
                                            PM_VALUE
                                            "</value>"
                                            "<isQualifier>false</isQualifier>"
                                            "<acquisitionTime>{{CreationTime}}</acquisitionTime>"
                                        "</parameter>"                                                   
                                        "<attachment>"
                                        "</attachment>"
                                    "</MsiOrderParameterMessage>"
                                "</message>"
                            "</MsiMessageContainer>";



#define PM_MESSAGEDESCRIPTIONCOUNT 1
const char * PM_messageDescription[]      = { PM_MDGetValue};
const char * PM_messageDescriptionText[]  = { "GetValue"    };
const char * PM_messageDescriptionId[]    = { "GetValue"};




class PhotoMeter:public OrderParameterMessage
{
    public:
      PhotoMeter()
      :OrderParameterMessage()
      {
        myDeviceTypeId ="ESP_pH_meter";
        //struct PHCalibrationValue pHCalibrationValue;
        //pHSensor.initialize(pHCalibrationValue);
      }

      PhotoMeter(const OrderParameterMessage & other) 
      :OrderParameterMessage(other)
      {
        
      }
      
      ~PhotoMeter()
      {
      }

/*
    void writeConfig()
    {
          logToSerial(Serial);
          DynamicJsonBuffer jsonBuffer;
          JsonObject& json = jsonBuffer.createObject();
          // JSONify local configuration parameters
          json["upperLimit"] = upperLimit;
          json["lowerLimit"] = lowerLimit;
          json["BatchID"]  = lastBatchId;
          json["systemId"] = systemId;

          json.prettyPrintTo(Serial);
          OrderParameterMessage::writeJsonFile(pHConfigFileName, json);    
    }

    bool readConfig()
    {
      
      SPIFFS.begin(); 
      File f = SPIFFS.open(pHConfigFileName, "r");
      
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
          Serial.println(pHConfigFileName);

          return false;
        }
        json.prettyPrintTo(Serial);
        upperLimit = json["upperLimit"];
        lowerLimit = json["lowerLimit"];

        lastBatchId = (const char*)json["BatchID"];
       
        systemId = (const char*)json["systemId"];
      }
      Serial.println("phConfig file was successfully parsed");
      
      return true;
    }

      float upperLimit;
      float lowerLimit;
*/
      const char** getMessageDescriptions()
      {
        return PM_messageDescription;
      }

      const char** getMessageDescriptionIds()
      {
        return PM_messageDescriptionId;
      }

      const char** getMessageDescriptionTexts()
      {
        return PM_messageDescriptionText;
      }

      unsigned int getMessageDescriptionCount()  
      {
        return PM_MESSAGEDESCRIPTIONCOUNT;
      }

      bool initialize() 
      {
        bool success=false;
        //class PHCalibrationValue c;
        //success = c.readFromFile();
        //pHSensor.initialize(c);
        return success;
      }
    
    /*
      float getpH()
      {
        return pHSensor.singleReading().getpH();
      }

      String getpHString() 
      {
        return String(getpH(),2);
      }


      int readADC(int overSampling = 1024)
      {
        int reading = pHSensor.readADC(overSampling);
        return reading;
      }
*/

      bool parseXml(const String& content, String & errorMessage)
      {
        bool success = OrderParameterMessage::parseXml(content,errorMessage);
        if (success)
        {
          if (messageId == "GetValue")
          {
            setHasMessageToSend(true);  
            lastBatchId = (const char*)getValue("BatchID");
            //writeConfig();
          }
          /*
          else if (messageId == "CalibrateHigh")
          {
            pHSensor.calibrationHigh(atof(getValue("SetpH")));
            setHasMessageToSend(true);
            lastBatchId = (const char*)getValue("BatchID");  
            writeConfig();

            class PHCalibrationValue c= pHSensor.getCalibrationValue();
            c.saveToFile();
            pHSensor.initialize(c);
          }
          else if (messageId == "CalibrateLow")
          {
            pHSensor.calibrationLow(atof(getValue("SetpH")));
            setHasMessageToSend(true);  
            lastBatchId = (const char*)getValue("BatchID");
            writeConfig();
            
            class PHCalibrationValue c= pHSensor.getCalibrationValue();
            c.saveToFile();
            pHSensor.initialize(c);
          }
          else if (messageId == "SetExceptionLimits")
          {
            upperLimit   = getValueFloat("UpperLimit");
            lowerLimit   = getValueFloat("LowerLimit");
            Serial.print("Got Exception limits: ");
            Serial.print(lowerLimit);
            Serial.print(" - ");
            Serial.println(upperLimit);
            writeConfig();
          }
*/

        }
        return success;
      }

      bool isOk()
      {
        bool ok = OrderParameterMessage::isOk();
        if (ok)
        {
          if (messageId == "GetpH")
          {
            ok =   getValue("BatchID");
          }
          /*
          else if (messageId == "CalibrateHigh" || messageId == "CalibrateLow" )
          {
            ok =   getValue("BatchID") 
                && getValue("SetpH");
          }
          else if (messageId == "SetExceptionLimits")
          {
            ok =   getValue("LowerLimit") 
                && getValue("UpperLimit");
          }
          else
          {
            ok = false;
          }
          */
        }
        
        return ok;
      }
    

      String getNextMessageString () 
      {

        String batchId = getValue("BatchID");

        if (messageId == "GetValue" /*
        || messageId == "CalibrateHigh"
        || messageId == "CalibrateLow" */)
        {
          String Value = "Hallo welt";
          nextMessageString = PM_responseGetValue;
          nextMessageString.replace(PM_VALUE, Value);
        }

        if (nextMessageString.length())
        {
          OrderParameterMessage::getNextMessageString(nextMessageString);
          nextMessageString.replace(PM_BATCHID, batchId);
        }
        return nextMessageString;
      }

    protected:
      String nextMessageString;

         
};