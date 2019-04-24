//#include <tinyxml2.h>
//#include "orderparametermessage.h"
//using namespace tinyxml2;

//#include <AnalogPHMeter.h>

AnalogPHMeter pHSensor;
                                          
const char PROGMEM  pHConfigFileName[] = "/phConfig.json";

#define PH_BATCHID             "{{BatchId}}"
#define PH_PH                  "{{pH}}"


const char PROGMEM  PH_MDGetpH[] ="<?xml version=\"1.0\" encoding=\"UTF-8\"?>"
                                  "<MsiInterfaceDescription xmlns:xsi=\"http://www.w3.org/2001/XMLSchema-instance\">"
                                    "<messageId>GetpH</messageId>"
                                    "<supplierId>Werum</supplierId>"
                                    "<deviceTypeId>ESP_pH_meter</deviceTypeId>"
                                    "<description>Get current pH Reading</description>"
                                    "<supplierVersion>1.0</supplierVersion>"
                                    "<systemId>DemoEspMsi_2</systemId>"
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


const char PROGMEM  PH_MDCalibrateLow[] ="<?xml version=\"1.0\" encoding=\"UTF-8\"?>"
                                  "<MsiInterfaceDescription xmlns:xsi=\"http://www.w3.org/2001/XMLSchema-instance\">"
                                    "<messageId>CalibrateLow</messageId>"
                                    "<supplierId>Werum</supplierId>"
                                    "<deviceTypeId>ESP_pH_meter</deviceTypeId>"
                                    "<description>Set low calibration point</description>"
                                    "<supplierVersion>1.0</supplierVersion>"
                                    "<systemId>DemoEspMsi_2</systemId>"
                                    "<creationTime>2018-09-28 13:05:00,000</creationTime>"
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
                                    "<parameter>"
                                        "<name>SetpH</name>"
                                        "<description>pH set point of the used calibration medium</description>"
                                        "<dataType>Double</dataType>"
                                        "<direction>TO_SF</direction>"
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

const char PROGMEM  PH_MDCalibrateHigh[] ="<?xml version=\"1.0\" encoding=\"UTF-8\"?>"
                                  "<MsiInterfaceDescription xmlns:xsi=\"http://www.w3.org/2001/XMLSchema-instance\">"
                                    "<messageId>CalibrateHigh</messageId>"
                                    "<supplierId>Werum</supplierId>"
                                    "<deviceTypeId>ESP_pH_meter</deviceTypeId>"
                                    "<description>Set high calibration point</description>"
                                    "<supplierVersion>1.0</supplierVersion>"
                                    "<systemId>DemoEspMsi_2</systemId>"
                                    "<creationTime>2018-09-28 13:05:00,000</creationTime>"
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
                                    "<parameter>"
                                        "<name>SetpH</name>"
                                        "<description>pH set point of the used calibration medium</description>"
                                        "<dataType>Double</dataType>"
                                        "<direction>TO_SF</direction>"
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

const char PROGMEM  PH_MDSetExceptionLimits[] ="<?xml version=\"1.0\" encoding=\"UTF-8\"?>"
                                "<MsiInterfaceDescription xmlns:xsi=\"http://www.w3.org/2001/XMLSchema-instance\">"
                                "<messageId>SetExceptionLimits</messageId>"
                                "<supplierId>Werum</supplierId>"
                                "<deviceTypeId>ESP_pH_meter</deviceTypeId>"
                                "<description>Set the limits to create exceptions</description>"
                                "<supplierVersion>1.0</supplierVersion>"
                                "<systemId>DemoEspMsi_2</systemId>"
                                "<creationTime>2019-04-23 13:05:00,000</creationTime>"
                                "<parameter>"
                                    "<name>UpperLimit</name>"
                                    "<description>pH upper limit</description>"
                                    "<dataType>Double</dataType>"
                                    "<direction>TO_SF</direction>"
                                    "<definitionRange>"
                                        "<fromValue>0</fromValue>"
                                        "<toValue>14</toValue>"
                                    "</definitionRange>"
                                    "<uom>pH</uom>"
                                "</parameter>"
                                "<parameter>"
                                    "<name>LowerLimit</name>"
                                    "<description>pH lower limit</description>"
                                    "<dataType>Double</dataType>"
                                    "<direction>TO_SF</direction>"
                                    "<definitionRange>"
                                        "<fromValue>0</fromValue>"
                                        "<toValue>14</toValue>"
                                    "</definitionRange>"
                                    "<uom>pH</uom>"
                                "</parameter>"
                                "<attachment>"
                                "</attachment>"
                            "</MsiInterfaceDescription>";


const char PROGMEM  PH_responseGetpH[] ="<?xml version=\"1.0\"\?>"
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
                                        "<deviceTypeId>ESP_pH_meter</deviceTypeId>"
                                        "<supplierVersion>1.0</supplierVersion>"
                                        "<creationTime>" 
                                        OP_CREATIONTIME 
                                        "</creationTime>"
                                        "<parameter>"
                                            "<name>BatchID</name>"
                                            "<dataType>String</dataType>"
                                            "<value>"
                                            PH_BATCHID
                                            "</value>"
                                            "<isQualifier>true</isQualifier>"
                                            "<acquisitionTime>{{CreationTime}}</acquisitionTime>"
                                        "</parameter>"    
                                        "<parameter>"
                                            "<name>pH</name>"
                                            "<dataType>Double</dataType>"
                                            "<value>"
                                            PH_PH
                                            "</value>"
                                            "<isQualifier>false</isQualifier>"
                                            "<acquisitionTime>{{CreationTime}}</acquisitionTime>"
                                        "</parameter>"                                                   
                                        "<attachment>"
                                        "</attachment>"
                                    "</MsiOrderParameterMessage>"
                                "</message>"
                            "</MsiMessageContainer>";

#define PH_MESSAGEDESCRIPTIONCOUNT 4

const char * PH_messageDescription[]      = { PH_MDGetpH, PH_MDCalibrateHigh, PH_MDCalibrateLow,  PH_MDSetExceptionLimits};
const char * PH_messageDescriptionText[]  = { "GetpH",    "CalibrateHigh",    "CalibrateLow",     "SetExceptionLimits"};
const char * PH_messageDescriptionId[]    = { "GetpH",    "CalibrateHigh",    "CalibrateLow",     "SetExceptionLimits"};




class PHMeter:public OrderParameterMessage
{
    public:
      PHMeter()
      :OrderParameterMessage()
      {
        myDeviceTypeId ="ESP_pH_meter";
        struct PHCalibrationValue pHCalibrationValue;
        pHSensor.initialize(pHCalibrationValue);
      }

      PHMeter(const OrderParameterMessage & other) 
      :OrderParameterMessage(other)
      {
        
      }
      
      ~PHMeter()
      {
      }


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

      const char** getMessageDescriptions()
      {
        return PH_messageDescription;
      }

      const char** getMessageDescriptionIds()
      {
        return PH_messageDescriptionId;
      }

      const char** getMessageDescriptionTexts()
      {
        return PH_messageDescriptionText;
      }

      unsigned int getMessageDescriptionCount()  
      {
        return PH_MESSAGEDESCRIPTIONCOUNT;
      }

      bool initialize() 
      {
        bool success=false;
        class PHCalibrationValue c;
        success = c.readFromFile();
        pHSensor.initialize(c);
        return success;
      }
    
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


      bool parseXml(const String& content, String & errorMessage)
      {
        bool success = OrderParameterMessage::parseXml(content,errorMessage);
        if (success)
        {
          if (messageId == "GetpH")
          {
            setHasMessageToSend(true);  
            lastBatchId = (const char*)getValue("BatchID");
            writeConfig();
          }
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
        }
        
        return ok;
      }
    

      String getNextMessageString () 
      {

        String batchId = getValue("BatchID");

        if (messageId == "GetpH"
        || messageId == "CalibrateHigh"
        || messageId == "CalibrateLow")
        {
          nextMessageString = PH_responseGetpH;
          nextMessageString.replace(PH_PH, getpHString());
        }

        if (nextMessageString.length())
        {
          OrderParameterMessage::getNextMessageString(nextMessageString);
          nextMessageString.replace(PH_BATCHID, batchId);
        }
        return nextMessageString;
      }

    protected:
      String nextMessageString;

         
};