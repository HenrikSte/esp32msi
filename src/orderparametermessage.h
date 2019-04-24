#pragma once

#include <wstring.h>
#include <tinyxml2.h>
#include <ESP8266TrueRandom.h>

#include "msiparameter.h"
using namespace tinyxml2;

#define OP_CREATIONTIME        "{{CreationTime}}"
#define OP_MESSAGEINSTANCEID1  "{{MessageInstanceId1}}"
#define OP_MESSAGEINSTANCEID2  "{{MessageInstanceId2}}"
#define OP_SYSTEMID            "{{SystemId}}"
#define OP_MESSAGEID           "{{MessageId}}"



#define MAXPARAMETERS 20

class OrderParameterMessage
{
    public:
        OrderParameterMessage()
        {
          parameterCount = 0;
          hasMessage=false;
          myDeviceTypeId="";
        };

        OrderParameterMessage(const OrderParameterMessage & other)
        {
          parameterCount = 0;
          systemId        = other.systemId;
          creationTime    = other.creationTime;
          messageId       = other.messageId;
          supplierId      = other.supplierId;
          deviceTypeId    = other.deviceTypeId;
          supplierVersion = other.supplierVersion;
          creationTimeString = other.creationTimeString;
          hasMessage=false;
        };

        virtual ~OrderParameterMessage()
        {
          clear();
        };

        void getNextMessageString(String& message)
        {
          String messageInstanceId1 = getUuid();
          String messageInstanceId2 = getUuid(); 

          message.replace(OP_CREATIONTIME, creationTimeString);
          message.replace(OP_MESSAGEINSTANCEID1, messageInstanceId1);
          message.replace(OP_MESSAGEINSTANCEID2, messageInstanceId2);
          message.replace(OP_SYSTEMID, systemId);
          message.replace(OP_MESSAGEID, messageId);
        }


        bool hasMessageToSend()
        {
          return hasMessage;
        }

        void setHasMessageToSend(bool _hasMessage)
        {
          hasMessage = _hasMessage;
        }

        bool isOk()
        {
          return (creationTimeString.length())
              && (messageId.length())
              && (supplierId.length())
              && (deviceTypeId.length())
              && (supplierVersion.length())
              && (creationTimeString.length()
              && (systemId.length()));
        }

        String getUuid()
        {
          byte uuidNumber[36];
          ESP8266TrueRandom.uuid(uuidNumber);
          return ESP8266TrueRandom.uuidToString(uuidNumber);
        }

        static bool writeJsonFile(const char * fileName, const JsonObject& json) 
        {
          
          Serial.print("Saving json file ");
          Serial.print (fileName);

          File f = SPIFFS.open(fileName, "w");
          if (!f) 
          {
            Serial.println(" Failed to open json file for writing");
            return false;
          }

          json.prettyPrintTo(Serial);

          json.printTo(f);
          f.close();

          Serial.println(" json file was successfully saved");
          
          return true;
        }

    public:

        String messageId;
        String supplierId;
        String deviceTypeId;
        String supplierVersion;
        String creationTimeString;
        String systemId;
        unsigned long creationTime;

        String lastBatchId;
        String lastPU;


        String myDeviceTypeId;

        void clear()
        {
          for (int i =0; i<parameterCount; i++)
          {
              parameter[i].clear();
          } 
          parameterCount=0;
          messageId ="";
          supplierId="";
          deviceTypeId="";
          supplierVersion="";
          creationTimeString="";
          systemId="";
          creationTime=0;
         

        }

        int getParameterCount()
        {
          return parameterCount;
        }

        msiparameter* addParameter()
        {
          if (parameterCount < MAXPARAMETERS)
          {
            msiparameter* returnParameter = &parameter[parameterCount];
            parameterCount++;
            return returnParameter;
          }
          return NULL;
        }

        msiparameter* getParameter(const char* name)
        {
          for (int i =0; i<parameterCount; i++)
          {
            if (parameter[i].name.equals(name))            
            {
              return &parameter[i];
            }
          }
          return NULL;
        }

        const char * getValue(const char * parameterName)
        {
          msiparameter * p = getParameter(parameterName);
          if (p)
          {
            return p->value.c_str();
          }
          else
          {
            return 0;
          }
        }

        String getValueString(const char * parameterName)
        {
          msiparameter * p = getParameter(parameterName);
          if (p)
          {
            return p->value;
          }
          else
          {
            return String();
          }
        }

        float getValueFloat(const char * parameterName)
        {
          return getValueString(parameterName).toFloat();
        }

        void logToSerial(HardwareSerial & serial)
        {
          serial.print("messageId: ");
          serial.println(messageId);
          serial.print("deviceTypeId: ");
          serial.println(deviceTypeId);
          serial.print("supplierId: ");
          serial.println(supplierId);
          serial.print("supplierVersion: ");
          serial.println(supplierVersion);
          serial.print("creationTime: ");
          serial.println(creationTime);
          serial.print("creationTimeString: ");
          serial.println(creationTimeString);
          serial.print("systemId: ");
          serial.println(systemId);

          for (int i=0; i<parameterCount;i++)
          {
            parameter[i].logToSerial(Serial);
          }
        }



    virtual unsigned int getMessageDescriptionCount()=0;  
    virtual const char** getMessageDescriptions()=0;
    virtual const char** getMessageDescriptionIds()=0;
    virtual const char** getMessageDescriptionTexts() =0;
   

    bool hasThisMessageId (const char * messageId, const char * deviceTypeId)
    {
      bool found = false;
      if (myDeviceTypeId.equals(deviceTypeId))
      {
        for (int i=0; i<getMessageDescriptionCount(); i++)
        {
          if (getMessageDescriptionId(i).equals(messageId))
          {
            found = true;
            break;
          }
        }
      }
      return found;
    }

    String getMessageDescription(unsigned int i) 
    {
      const char ** messageDescription = getMessageDescriptions();
      
      if (messageDescription && i<getMessageDescriptionCount())
      {
          return messageDescription[i];
      }
      else
      { 
          return "";
      }
    }

    String getMessageDescriptionId(unsigned int i) 
    {
      const char ** messageDescriptionId = getMessageDescriptionIds();
      if (messageDescriptionId && i<getMessageDescriptionCount())
      {
        return messageDescriptionId[i];
      }
      else
      { 
        return "";
      }
    }

    String getMessageDescriptionText(unsigned int i) 
    {
      const char ** messageDescriptionTexts = getMessageDescriptionTexts();
      if (messageDescriptionTexts && i<getMessageDescriptionCount())
      {
        return messageDescriptionTexts[i];
      }
      else
      { 
        return "";
      }
    }

        static void getMessageIdFromXml(const String& content, String& messageId, String& deviceTypeId)
        {
          XMLDocument doc;
          if (doc.Parse(content.c_str()))
          {
              Serial.println(doc.ErrorStr());
          }
          else
          {
            /*
            <MsiMessageContainer xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance" xmlns:xsd="http://www.w3.org/2001/XMLSchema">
            <messageType>MsiOrderParameterMessage</messageType>
            <message>
              <MsiOrderParameterMessage>
                <messageId>SetRoomLabel</messageId>
            */
            const char* messageType = 0;
            const XMLElement * e=0; 
            e = doc.FirstChildElement( "MsiMessageContainer" );
            if (e)
            {
              e = e->FirstChildElement( "messageType" );
            }
            if (e)
            {
              messageType = e->GetText();
            }
            if (!strcmp(messageType,"MsiOrderParameterMessage"))
            {
              const XMLElement * message=0;
              message = doc.FirstChildElement( "MsiMessageContainer" )->FirstChildElement("message");
              if (message)
              {
                message = message->FirstChildElement( "MsiOrderParameterMessage" );
                if (message)
                {
                  e = message->FirstChildElement( "messageId" );
                  if (e)
                  {
                    messageId = e->GetText();
                  }
                  e = message->FirstChildElement( "deviceTypeId" );
                  if (e)
                  {
                    deviceTypeId = e->GetText();
                  }
                }
              }
            }
          }
        }


        bool parseXml(const String& content, String & errorMessage)
        {   
          bool success = false;
          
          clear();

          XMLDocument doc;
          if (doc.Parse(content.c_str()))
          {
              Serial.println(doc.ErrorStr());
              errorMessage = doc.ErrorStr();
              success = false;
          }
          else
          {
            const char* messageType = 0;
            const XMLElement * e    = 0; 
            const XMLElement * message = 0;
            
            e = doc.FirstChildElement( "MsiMessageContainer" );
            if (e)
            {
              e = e->FirstChildElement( "messageType" );
            }
            if (e)
            {
              messageType = e->GetText();
            }

            e = doc.FirstChildElement( "MsiMessageContainer" );
            if (e)
            {
              e = e->FirstChildElement( "systemId" );
            }
            if (e)
            {
              systemId = e->GetText();
            }

            //const XMLElement * message=0; 
            if (e)
            {
              message = doc.FirstChildElement( "MsiMessageContainer" )->FirstChildElement("message");
            }

            if (message && !strcmp(messageType,"MsiOrderParameterMessage"))
            {

              message = message->FirstChildElement( "MsiOrderParameterMessage" );

              if (message)
              {
                e = message->FirstChildElement( "messageId" );
              }
              if (e)
              {
                messageId = e->GetText();
                if (message)
                {
                  e = message->FirstChildElement( "deviceTypeId" );
                }
                if (e)
                {
                  deviceTypeId = e->GetText();
                }

                if (message)
                {
                  e = message->FirstChildElement( "supplierId" );
                }
                if (e)
                {
                  supplierId = e->GetText();
                }

                if (message)
                {
                  e = message->FirstChildElement( "supplierVersion" );
                }
                if (e)
                {
                  supplierVersion = e->GetText();
                }

                if (message)
                {
                  e = message->FirstChildElement( "creationTime" );
                }
                if (e)
                {
                  creationTimeString = e->GetText();
                }

                const XMLElement * parameter=0; 
                parameter = message->FirstChildElement( "parameter" );
                while (parameter)
                {
                  e = parameter->FirstChildElement( "name" );
                  if (e)
                  {
                    msiparameter * p = addParameter();
                    if (p)
                    {
                      p->name  = e->GetText();
                      e = parameter->FirstChildElement( "dataType" );
                      if (e)
                      {
                        p->dataType  = e->GetText();
                      }
                      e = parameter->FirstChildElement( "value" );
                      if (e)
                      {
                        p->value  = e->GetText();
                      }
                      e = parameter->FirstChildElement( "isQualifier" );
                      if (e)
                      {
                        p->isQualifier = !strcmp(e->GetText(),"true");
                      }
                      e = parameter->FirstChildElement( "acquisitionTime" );
                      if (e)
                      {
                        p->acquisitionTimeString = e->GetText();
                      }
                    }
                    else
                    {
                      // too many parameter
                    }
                  }
                  else
                  {
                    //parameter has no name !?
                  }
                  parameter = parameter->NextSiblingElement( "parameter" );
                }

                success = isOk();
                if (!success)
                {
                  errorMessage= F("Message check failed, potentially incomplete data?");
                  Serial.println("XML Content: ");
                  Serial.print(content);
                  Serial.println("*");
                  Serial.println("###########################################");
                  logToSerial(Serial);
                }
                Serial.print("success=");
                Serial.println(success);

              }
              else
              {
                errorMessage = F("element messageId not found");
              }
            }
            else
            {
              errorMessage = F("Not an MsiOrderParameterMessage");
            }
          }
          /*
          <?xml version="1.0"?>
          <MsiMessageContainer xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance" xmlns:xsd="http://www.w3.org/2001/XMLSchema">
            <messageInstanceId>3afdf762-05d6-47ed-8369-f62fb623adf1</messageInstanceId>
            <direction>MES_TO_SF</direction>
            <systemId>11111</systemId>
            <messageType>MsiOrderParameterMessage</messageType>
            <messageContext>5000203853</messageContext>
            <message>
              <MsiOrderParameterMessage>
                <messageInstanceId>0fa8a6e8-7934-489f-a5d3-d87c9a6f4de8</messageInstanceId>
                <direction>MES_TO_SF</direction>
                <messageId>SetRoomLabel</messageId>
                <supplierId>Werum</supplierId>
                <deviceTypeId>ESP_Roomlabel</deviceTypeId>
                <supplierVersion>1.0</supplierVersion>
                <orderContext>5000203853</orderContext>
                <creationTime>2018-08-15 15:02:09,205</creationTime>
                <parameter>
                    <name>Mat</name>
                    <dataType>String</dataType>
                    <value>HS125</value>
                    <isQualifier>false</isQualifier>
                    <acquisitionTime>2018-08-15 15:02:08,487</acquisitionTime>
                </parameter>
                <parameter>
                    <name>SFO</name>
                    <dataType>String</dataType>
                    <value>19735</value>
                    <isQualifier>false</isQualifier>
                    <acquisitionTime>2018-08-15 15:02:09,033</acquisitionTime>
                </parameter>
                <parameter>
                    <name>BatchID</name>
                    <dataType>String</dataType>
                    <value>VT001061</value>
                    <isQualifier>true</isQualifier>
                    <acquisitionTime>2018-08-15 15:02:09,174</acquisitionTime>
                </parameter>
                <attachment />
              </MsiOrderParameterMessage>
            </message>
          </MsiMessageContainer>
          */

          return success;
        }

    protected:
        msiparameter parameter[MAXPARAMETERS];
        int parameterCount;
        bool hasMessage;


};