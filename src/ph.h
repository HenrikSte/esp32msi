//#include <tinyxml2.h>
//#include "orderparametermessage.h"
//using namespace tinyxml2;

//#include <AnalogPHMeter.h>

AnalogPHMeter pHSensor;



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
                                    "</parameter>"
                                    "<parameter>"
                                        "<name>SetpH</name>"
                                        "<description>pH set point of the used calibration medium</description>"
                                        "<dataType>Double</dataType>"
                                        "<direction>TO_SF</direction>"
                                        "<isMesQualifier>false</isMesQualifier>"
                                        "<isSfQualifier>false</isSfQualifier>"
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
                                    "</parameter>"
                                    "<parameter>"
                                        "<name>SetpH</name>"
                                        "<description>pH set point of the used calibration medium</description>"
                                        "<dataType>Double</dataType>"
                                        "<direction>TO_SF</direction>"
                                        "<isMesQualifier>false</isMesQualifier>"
                                        "<isSfQualifier>false</isSfQualifier>"
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

#define PH_MESSAGEDESCRIPTIONCOUNT 3

const char * PH_messageDescription[]      = { PH_MDGetpH, PH_MDCalibrateHigh, PH_MDCalibrateLow};
const char * PH_messageDescriptionText[]  = { "GetpH",    "CalibrateHigh", "CalibrateLow"};
const char * PH_messageDescriptionId[]    = { "GetpH",    "CalibrateHigh", "CalibrateLow"};

class PHMeter:public OrderParameterMessage
{
    public:
      PHMeter()
      :OrderParameterMessage()
      {
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
          }
          else if (messageId == "CalibrateHigh")
          {
            pHSensor.calibrationHigh(atof(getValue("SetpH")));
            class PHCalibrationValue c= pHSensor.getCalibrationValue();
            c.saveToFile();

            setHasMessageToSend(true);  
          }
          else if (messageId == "Calibr ateLow")
          {
            pHSensor.calibrationLow(atof(getValue("SetpH")));
            setHasMessageToSend(true);  
            class PHCalibrationValue c= pHSensor.getCalibrationValue();
            c.saveToFile();
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
          nextMessageString.replace(PH_PH, String(getpH(),1));
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