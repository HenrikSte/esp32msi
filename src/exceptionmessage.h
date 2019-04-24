#pragma once

#include <wstring.h>
//#include <tinyxml2.h>
#include <ESP8266TrueRandom.h>

//#include "msiparameter.h"
//using namespace tinyxml2;

#define EX_CREATIONTIME        "{{CreationTime}}"
#define EX_MESSAGEINSTANCEID1  "{{MessageInstanceId1}}"
#define EX_MESSAGEINSTANCEID2  "{{MessageInstanceId2}}"
#define EX_SYSTEMID            "{{SystemId}}"
//#define EX_MESSAGEID           "{{MessageId}}"
#define EX_CAUSEDAT            "{{CausedAt}}"
#define EX_SYSTEMDESCRIPTION   "{{SystemDescription}}"
#define EX_USERDESCRIPTION     "{{UserDescription}}"
#define EX_BATCHNUMBER         "{{BatchNumber}}"
#define EX_PU                  "{{PU}}"




const char PROGMEM exceptionMessage[] ="<?xml version=\"1.0\"\?>"
                            "<MsiMessageContainer xmlns:xsi=\"http://www.w3.org/2001/XMLSchema-instance\" xmlns:xsd=\"http://www.w3.org/2001/XMLSchema\">"
                            "<messageInstanceId>"
                            EX_MESSAGEINSTANCEID1
                            "</messageInstanceId>"
                            "<direction>SF_TO_MES</direction>"
                            "<systemId>"
                            EX_SYSTEMID
                            "</systemId>"
                            "<messageType>MsiExceptionMessage</messageType>"
                            // "<messageContext>5000761792</messageContext>"
                            "<message>"
  "<MsiExceptionMessage>"
    "<messageInstanceId>"
    EX_MESSAGEINSTANCEID2
    "</messageInstanceId>"
    "<creationTime>"
    EX_CREATIONTIME
    "</creationTime>"
    "<exception>"
        "<causedAt>"
        EX_CAUSEDAT
        "</causedAt>"
        //"<exceptionType>exceptionType1</exceptionType>"
        //"<user>user3</user>"
        "<systemDescription>"
        EX_SYSTEMDESCRIPTION
        "</systemDescription>"
        //"<deviationNumber>deviationNumber1</deviationNumber>"
        "<userDescription>"
        EX_USERDESCRIPTION
        "</userDescription>"
        //"<manufacturingOrderID>manufacturingOrderID1</manufacturingOrderID>"
        //"<sfoID>sfoID1</sfoID>"
        "<batchNumber>"
        EX_BATCHNUMBER
        "</batchNumber>"
        "<productionUnit>" 
        EX_PU 
        "</productionUnit>"
        //"<equipmentID>equipmentID1</equipmentID>"
        //"<operationID>operationID1</operationID>"
        //"<stepID>stepID1</stepID>"
        /*
        "<exceptionComment>"
            "<changeDate>1000-00-00 00:00:00,000</changeDate>"
            "<commentText>commentText2</commentText>"
            "<user>user4</user>"
        "</exceptionComment>"
        "<exceptionComment>"
            "<changeDate>1000-00-00 00:00:00,000</changeDate>"
            "<commentText>commentText3</commentText>"
            "<user>user5</user>"
        "</exceptionComment>"
        */
    "</exception>"
    "<attachment>"
    "</attachment>"
"</MsiExceptionMessage>"
"</message>"
"</MsiMessageContainer>";


class ExceptionMessage
{
  private:
  static String getUuid()
  {
    byte uuidNumber[36];
    ESP8266TrueRandom.uuid(uuidNumber);
    return ESP8266TrueRandom.uuidToString(uuidNumber);
  }

  public:

  static String getExceptionMessageText(const char* systemId, 
                                                const char* batchNumber,
                                                const char* PU,
                                                const char* sytemDescription, 
                                                const char* userDescription,
                                                const char* causedAt)
  {
    String messageString= exceptionMessage;

    String uuid1 = getUuid();
    String uuid2 = getUuid();


    messageString.replace(EX_CREATIONTIME, causedAt);
    messageString.replace(EX_MESSAGEINSTANCEID1, uuid1);
    messageString.replace(EX_MESSAGEINSTANCEID2, uuid2);
    messageString.replace(EX_SYSTEMID, systemId);
    messageString.replace(EX_CAUSEDAT, causedAt);
    messageString.replace(EX_SYSTEMDESCRIPTION, sytemDescription);
    messageString.replace(EX_USERDESCRIPTION, userDescription);
    messageString.replace(EX_BATCHNUMBER, batchNumber);
     messageString.replace(EX_PU, PU);


    return messageString;
  }

};