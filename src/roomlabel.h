#include <tinyxml2.h>
#include "orderparametermessage.h"
using namespace tinyxml2;


const char PROGMEM lcdFileName[]  = "/lcd.json";

#define RL_BATCHID             "{{BatchId}}"
#define RL_TEMPERATURE         "{{Temperature}}"
#define RL_HUMIDITY            "{{Humidity}}"
#define RL_PRESSURE            "{{Pressure}}"
#define RL_MESSAGENUMBER       "{{MessageNumber}}"



const char PROGMEM  RL_MDShowOrderInfo[] ="<?xml version=\"1.0\" encoding=\"UTF-8\"?>"
                                "<MsiInterfaceDescription xmlns:xsi=\"http://www.w3.org/2001/XMLSchema-instance\">"
                                "<messageId>ShowOrderInfo</messageId>"
                                "<supplierId>Werum</supplierId>"
                                "<deviceTypeId>ESP_Roomlabel</deviceTypeId>"
                                "<description>Show order information and receive tmp and rh</description>"
                                "<supplierVersion>1.1</supplierVersion>"
                                "<systemId>"
                                OP_SYSTEMID
                                "</systemId>"
                                "<creationTime>2018-05-03 13:05:00,000</creationTime>"
                                "<parameter>"
                                    "<name>PU</name>"
                                    "<description>Production Unit</description>"
                                    "<dataType>String</dataType>"
                                    "<direction>TO_SF</direction>"
                                    "<isMesQualifier>false</isMesQualifier>"
                                    "<isSfQualifier>false</isSfQualifier>"
                                    "<isOptional>false</isOptional>"
                                "</parameter>"
                                "<parameter>"
                                    "<name>Mat</name>"
                                    "<description>Material number</description>"
                                    "<dataType>String</dataType>"
                                    "<direction>TO_SF</direction>"
                                    "<isMesQualifier>false</isMesQualifier>"
                                    "<isSfQualifier>false</isSfQualifier>"
                                    "<isOptional>true</isOptional>"
                                "</parameter>"
                                "<parameter>"
                                    "<name>Process</name>"
                                    "<description>Process description</description>"
                                    "<dataType>String</dataType>"
                                    "<direction>TO_SF</direction>"
                                    "<isMesQualifier>false</isMesQualifier>"
                                    "<isSfQualifier>false</isSfQualifier>"
                                    "<isOptional>true</isOptional>"
                                "</parameter>"
                                "<parameter>"
                                    "<name>BatchID</name>"
                                    "<description>Batch ID</description>"
                                    "<dataType>String</dataType>"
                                    "<direction>BOTH</direction>"
                                    "<isMesQualifier>true</isMesQualifier>"
                                    "<isSfQualifier>true</isSfQualifier>"
                                "</parameter>"
                                "<parameter>"
                                    "<name>Temperature</name>"
                                    "<description>Air temperature</description>"
                                    "<dataType>Double</dataType>"
                                    "<direction>TO_MES</direction>"
                                    "<isMesQualifier>false</isMesQualifier>"
                                    "<isSfQualifier>false</isSfQualifier>"
                                    "<definitionRange>"
                                      "<fromValue>0</fromValue>"
                                      "<toValue>100</toValue>"
                                    "</definitionRange>"
                                    "<uom>C</uom>"
                                "</parameter>"
                                "<parameter>"
                                    "<name>Humidity</name>"
                                    "<description>Relative air humidity</description>"
                                    "<dataType>Double</dataType>"
                                    "<direction>TO_MES</direction>"
                                    "<isMesQualifier>false</isMesQualifier>"
                                    "<isSfQualifier>false</isSfQualifier>"
                                    "<definitionRange>"
                                      "<fromValue>0</fromValue>"
                                      "<toValue>100</toValue>"
                                    "</definitionRange>"
                                    "<uom>RH%</uom>" 
                                "</parameter>"
                                "<attachment>"
                                "</attachment>"
                            "</MsiInterfaceDescription>";

const char PROGMEM  RL_MDShowOrderInfo2[] ="<?xml version=\"1.0\" encoding=\"UTF-8\"?>"
                                "<MsiInterfaceDescription xmlns:xsi=\"http://www.w3.org/2001/XMLSchema-instance\">"
                                "<messageId>ShowOrderInfo</messageId>"
                                "<supplierId>Werum</supplierId>"
                                "<deviceTypeId>ESP_Roomlabel</deviceTypeId>"
                                "<description>Show order information and receive tmp, rh and pressure</description>"
                                "<supplierVersion>2.1</supplierVersion>"
                                "<systemId>"
                                OP_SYSTEMID
                                "</systemId>"
                                "<creationTime>2018-05-03 13:05:00,000</creationTime>"
                                "<parameter>"
                                    "<name>PU</name>"
                                    "<description>Production Unit</description>"
                                    "<dataType>String</dataType>"
                                    "<direction>TO_SF</direction>"
                                    "<isOptional>false</isOptional>"
                               "</parameter>"
                                "<parameter>"
                                    "<name>Mat</name>"
                                    "<description>Material number</description>"
                                    "<dataType>String</dataType>"
                                    "<direction>TO_SF</direction>"
                                    "<isOptional>true</isOptional>"
                              "</parameter>"
                                "<parameter>"
                                    "<name>Process</name>"
                                    "<description>Process description</description>"
                                    "<dataType>String</dataType>"
                                    "<direction>TO_SF</direction>"
                                    "<isOptional>true</isOptional>"
                                "</parameter>"
                                "<parameter>"
                                    "<name>BatchID</name>"
                                    "<description>Batch ID</description>"
                                    "<dataType>String</dataType>"
                                    "<direction>BOTH</direction>"
                                    "<isMesQualifier>true</isMesQualifier>"
                                    "<isSfQualifier>true</isSfQualifier>"
                                "</parameter>"
                                "<parameter>"
                                    "<name>Temperature</name>"
                                    "<description>Air temperature</description>"
                                    "<dataType>Double</dataType>"
                                    "<direction>TO_MES</direction>"
                                    "<definitionRange>"
                                      "<fromValue>0</fromValue>"
                                      "<toValue>100</toValue>"
                                    "</definitionRange>"
                                    "<uom>C</uom>"
                                "</parameter>"
                                "<parameter>"
                                    "<name>Humidity</name>"
                                    "<description>Relative air humidity</description>"
                                    "<dataType>Double</dataType>"
                                    "<direction>TO_MES</direction>"
                                    "<definitionRange>"
                                      "<fromValue>0</fromValue>"
                                      "<toValue>100</toValue>"
                                    "</definitionRange>"
                                    "<uom>RH%</uom>" 
                                "</parameter>"
                                "<parameter>"
                                    "<name>Pressure</name>"
                                    "<description>Air pressure</description>"
                                    "<dataType>Double</dataType>"
                                    "<direction>TO_MES</direction>"
                                    "<uom>hPa</uom>"
                                "</parameter>"
                                "<attachment>"
                                "</attachment>"
                            "</MsiInterfaceDescription>";

const char PROGMEM  RL_MDShowInfo[] ="<?xml version=\"1.0\" encoding=\"UTF-8\"?>"
                                "<MsiInterfaceDescription xmlns:xsi=\"http://www.w3.org/2001/XMLSchema-instance\">"
                                "<messageId>ShowInfo</messageId>"
                                "<supplierId>Werum</supplierId>"
                                "<deviceTypeId>ESP_Roomlabel</deviceTypeId>"
                                "<description>Set room label with 4 lines of free text</description>"
                                "<supplierVersion>1.1</supplierVersion>"
                                "<systemId>"
                                OP_SYSTEMID
                                "</systemId>"
                                "<creationTime>2018-05-03 13:05:00,000</creationTime>"
                                "<parameter>"
                                    "<name>Line1</name>"
                                    "<description>Line 1 (max 20 characters)</description>"
                                    "<dataType>String</dataType>"
                                    "<direction>TO_SF</direction>"
                                    "<isMesQualifier>false</isMesQualifier>"
                                    "<isSfQualifier>false</isSfQualifier>"
                                "</parameter>"
                                "<parameter>"
                                    "<name>Line2</name>"
                                    "<description>Line 2 (max 20 characters)</description>"
                                    "<dataType>String</dataType>"
                                    "<direction>TO_SF</direction>"
                                    "<isMesQualifier>false</isMesQualifier>"
                                    "<isSfQualifier>false</isSfQualifier>"
                                    "<isOptional>true</isOptional>"
                                "</parameter>"
                                "<parameter>"
                                    "<name>Line3</name>"
                                    "<description>Line 3 (max 20 characters)</description>"
                                    "<dataType>String</dataType>"
                                    "<direction>TO_SF</direction>"
                                    "<isMesQualifier>false</isMesQualifier>"
                                    "<isSfQualifier>false</isSfQualifier>"
                                    "<isOptional>true</isOptional>"
                                "</parameter>"
                                "<parameter>"
                                    "<name>Line4</name>"
                                    "<description>Line 4 (max 20 characters)</description>"
                                    "<dataType>String</dataType>"
                                    "<direction>TO_SF</direction>"
                                    "<isMesQualifier>false</isMesQualifier>"
                                    "<isSfQualifier>false</isSfQualifier>"
                                    "<isOptional>true</isOptional>"
                                "</parameter>"
                                "<attachment>"
                                "</attachment>"
                            "</MsiInterfaceDescription>";

const char PROGMEM  RL_MDRequestBurst[] ="<?xml version=\"1.0\" encoding=\"UTF-8\"?>"
                                "<MsiInterfaceDescription xmlns:xsi=\"http://www.w3.org/2001/XMLSchema-instance\">"
                                "<messageId>BurstRequest</messageId>"
                                "<supplierId>Werum</supplierId>"
                                "<deviceTypeId>ESP_Roomlabel</deviceTypeId>"
                                "<description>Request a number of identical messages to be sent from the device</description>"
                                "<supplierVersion>1.1</supplierVersion>"
                                "<systemId>"
                                OP_SYSTEMID
                                "</systemId>"
                                "<creationTime>2018-05-03 13:05:00,000</creationTime>"
                                "<parameter>"
                                    "<name>NumberOfMessages</name>"
                                    "<description>Number of messages requested</description>"
                                    "<dataType>Long</dataType>"
                                    "<direction>TO_SF</direction>"
                                "</parameter>"
                                "<parameter>"
                                    "<name>BatchID</name>"
                                    "<description>Batch ID</description>"
                                    "<dataType>String</dataType>"
                                    "<direction>TO_SF</direction>"
                                "</parameter>"
                                "<attachment>"
                                "</attachment>"
                            "</MsiInterfaceDescription>";

const char PROGMEM  RL_MDBurstMessage[] ="<?xml version=\"1.0\" encoding=\"UTF-8\"?>"
                                "<MsiInterfaceDescription xmlns:xsi=\"http://www.w3.org/2001/XMLSchema-instance\">"
                                "<messageId>BurstMessage</messageId>"
                                "<supplierId>Werum</supplierId>"
                                "<deviceTypeId>ESP_Roomlabel</deviceTypeId>"
                                "<description>A dummy message</description>"
                                "<supplierVersion>1.1</supplierVersion>"
                                "<systemId>"
                                OP_SYSTEMID
                                "</systemId>"
                                "<creationTime>2018-05-03 13:05:00,000</creationTime>"
                                "<parameter>"
                                    "<name>MessageNumber</name>"
                                    "<description>Message Number</description>"
                                    "<dataType>Long</dataType>"
                                    "<direction>TO_MES</direction>"
                                "</parameter>"
                                "<parameter>"
                                    "<name>BatchID</name>"
                                    "<description>Batch ID</description>"
                                    "<dataType>String</dataType>"
                                    "<direction>TO_MES</direction>"
                                    "<isMesQualifier>true</isMesQualifier>"
                                "</parameter>"
                                "<attachment>"
                                "</attachment>"
                            "</MsiInterfaceDescription>";

const char PROGMEM  RL_MDGetEnvironmentalData[] ="<?xml version=\"1.0\" encoding=\"UTF-8\"?>"
                                "<MsiInterfaceDescription xmlns:xsi=\"http://www.w3.org/2001/XMLSchema-instance\">"
                                "<messageId>GetEnvironmentalData</messageId>"
                                "<supplierId>Werum</supplierId>"
                                "<deviceTypeId>ESP_Roomlabel</deviceTypeId>"
                                "<description>Receive tmp and rh</description>"
                                "<supplierVersion>1.1</supplierVersion>"
                                "<systemId>"
                                OP_SYSTEMID
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
                                    "<name>Temperature</name>"
                                    "<description>Air temperature</description>"
                                    "<dataType>Double</dataType>"
                                    "<direction>TO_MES</direction>"
                                    "<isMesQualifier>false</isMesQualifier>"
                                    "<isSfQualifier>false</isSfQualifier>"
                                    "<definitionRange>"
                                      "<fromValue>0</fromValue>"
                                      "<toValue>100</toValue>"
                                    "</definitionRange>"
                                    "<uom>C</uom>"
                                "</parameter>"
                                "<parameter>"
                                    "<name>Humidity</name>"
                                    "<description>Relative air humidity</description>"
                                    "<dataType>Double</dataType>"
                                    "<direction>TO_MES</direction>"
                                    "<definitionRange>"
                                      "<fromValue>0</fromValue>"
                                      "<toValue>100</toValue>"
                                    "</definitionRange>"
                                    "<uom>RH%</uom>" 
                                "</parameter>"
                                "<attachment>"
                                "</attachment>"
                            "</MsiInterfaceDescription>";

const char PROGMEM  RL_MDGetEnvironmentalData2[] ="<?xml version=\"1.0\" encoding=\"UTF-8\"?>"
                                "<MsiInterfaceDescription xmlns:xsi=\"http://www.w3.org/2001/XMLSchema-instance\">"
                                "<messageId>GetEnvironmentalData</messageId>"
                                "<supplierId>Werum</supplierId>"
                                "<deviceTypeId>ESP_Roomlabel</deviceTypeId>"
                                "<description>Receive tmp, rh and pressure</description>"
                                "<supplierVersion>2.1</supplierVersion>"
                                "<systemId>"
                                OP_SYSTEMID
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
                                    "<name>Temperature</name>"
                                    "<description>Air temperature</description>"
                                    "<dataType>Double</dataType>"
                                    "<direction>TO_MES</direction>"
                                    "<definitionRange>"
                                      "<fromValue>0</fromValue>"
                                      "<toValue>100</toValue>"
                                    "</definitionRange>"
                                    "<uom>C</uom>" 
                                "</parameter>"
                                "<parameter>"
                                    "<name>Humidity</name>"
                                    "<description>Relative air humidity</description>"
                                    "<dataType>Double</dataType>"
                                    "<direction>TO_MES</direction>"
                                    "<definitionRange>"
                                      "<fromValue>0</fromValue>"
                                      "<toValue>100</toValue>"
                                    "</definitionRange>"
                                    "<uom>RH%</uom>" 
                                "</parameter>"
                                "<parameter>"
                                    "<name>Pressure</name>"
                                    "<description>Air pressure</description>"
                                    "<dataType>Double</dataType>"
                                    "<direction>TO_MES</direction>"
                                    "<uom>hPa</uom>" 
                                "</parameter>"
                                "<attachment>"
                                "</attachment>"
                            "</MsiInterfaceDescription>";

const char PROGMEM  RL_MDRoomLabelOff[] ="<?xml version=\"1.0\" encoding=\"UTF-8\"?>"
                                "<MsiInterfaceDescription xmlns:xsi=\"http://www.w3.org/2001/XMLSchema-instance\">"
                                "<messageId>RoomLabelOff</messageId>"
                                "<supplierId>Werum</supplierId>"
                                "<deviceTypeId>ESP_Roomlabel</deviceTypeId>"
                                "<description>Switch off the room label</description>"
                                "<supplierVersion>1.1</supplierVersion>"
                                "<systemId>"
                                OP_SYSTEMID
                                "</systemId>"
                                "<creationTime>2018-05-03 13:05:00,000</creationTime>"
                                "<parameter>"
                                    "<name>BatchID</name>"
                                    "<description>Batch ID</description>"
                                    "<dataType>String</dataType>"
                                    "<direction>TO_SF</direction>"
                                    "<isMesQualifier>true</isMesQualifier>"
                                    "<isSfQualifier>true</isSfQualifier>"
                                "</parameter>"
                                "<attachment>"
                                "</attachment>"
                            "</MsiInterfaceDescription>";


const char PROGMEM  RL_MDSetExceptionLimits[] ="<?xml version=\"1.0\" encoding=\"UTF-8\"?>"
                                "<MsiInterfaceDescription xmlns:xsi=\"http://www.w3.org/2001/XMLSchema-instance\">"
                                "<messageId>SetExceptionLimits</messageId>"
                                "<supplierId>Werum</supplierId>"
                                "<deviceTypeId>ESP_Roomlabel</deviceTypeId>"
                                "<description>Set the limits for RH and temp to create exceptions</description>"
                                "<supplierVersion>1.1</supplierVersion>"
                                "<systemId>"
                                OP_SYSTEMID
                                "</systemId>"
                                "<creationTime>2018-05-03 13:05:00,000</creationTime>"
                                "<parameter>"
                                    "<name>TempUpperLimit</name>"
                                    "<description>Temperature upper limit</description>"
                                    "<dataType>Double</dataType>"
                                    "<direction>TO_SF</direction>"
                                    "<definitionRange>"
                                        "<fromValue>0</fromValue>"
                                        "<toValue>100</toValue>"
                                    "</definitionRange>"
                                    "<uom>C</uom>"
                                    "<isOptional>true</isOptional>"
                                "</parameter>"
                                "<parameter>"
                                    "<name>RHUpperLimit</name>"
                                    "<description>Humidity upper limit</description>"
                                    "<dataType>Double</dataType>"
                                    "<direction>TO_SF</direction>"
                                    "<definitionRange>"
                                        "<fromValue>0</fromValue>"
                                        "<toValue>100</toValue>"
                                    "</definitionRange>"
                                    "<uom>RH%</uom>"
                                    "<isOptional>true</isOptional>"
                                "</parameter>"
                                "<parameter>"
                                    "<name>TempLowerLimit</name>"
                                    "<description>Temperature lower limit</description>"
                                    "<dataType>Double</dataType>"
                                    "<direction>TO_SF</direction>"
                                    "<definitionRange>"
                                        "<fromValue>0</fromValue>"
                                        "<toValue>100</toValue>"
                                    "</definitionRange>"
                                    "<uom>C</uom>"
                                    "<isOptional>true</isOptional>"
                                "</parameter>"
                                "<parameter>"
                                    "<name>RHLowerLimit</name>"
                                    "<description>Humidity lower limit</description>"
                                    "<dataType>Double</dataType>"
                                    "<direction>TO_SF</direction>"
                                    "<isMesQualifier>false</isMesQualifier>"
                                    "<isSfQualifier>false</isSfQualifier>"
                                    "<definitionRange>"
                                        "<fromValue>0</fromValue>"
                                        "<toValue>100</toValue>"
                                    "</definitionRange>"
                                    "<uom>RH%</uom>"
                                    "<isOptional>true</isOptional>"
                                "</parameter>"
                                "<attachment>"
                                "</attachment>"
                            "</MsiInterfaceDescription>";

const char PROGMEM  responseShowOrderInfo[] ="<?xml version=\"1.0\"\?>"
                            "<MsiMessageContainer xmlns:xsi=\"http://www.w3.org/2001/XMLSchema-instance\" xmlns:xsd=\"http://www.w3.org/2001/XMLSchema\">"
                            "<messageInstanceId>"
                            OP_MESSAGEINSTANCEID1
                            "</messageInstanceId>"
                            "<direction>SF_TO_MES</direction>"
                            "<systemId>"
                            OP_SYSTEMID
                            "</systemId>"
                                "<messageType>MsiOrderParameterMessage</messageType>"
                               // "<messageContext>5000761792</messageContext>"
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
                                        "<deviceTypeId>ESP_Roomlabel</deviceTypeId>"
                                        "<supplierVersion>1.1</supplierVersion>"
                                       // "<orderContext>5000761792</orderContext>"
                                        "<creationTime>" 
                                        OP_CREATIONTIME 
                                        "</creationTime>"
                                        "<parameter>"
                                            "<name>BatchID</name>"
                                            "<dataType>String</dataType>"
                                            "<value>"
                                            RL_BATCHID
                                            "</value>"
                                            "<isQualifier>true</isQualifier>"
                                            "<acquisitionTime>{{CreationTime}}</acquisitionTime>"
                                        "</parameter>"    
                                        "<parameter>"
                                            "<name>Temperature</name>"
                                            "<dataType>Double</dataType>"
                                            "<value>"
                                            RL_TEMPERATURE
                                            "</value>"
                                            "<isQualifier>false</isQualifier>"
                                            "<acquisitionTime>{{CreationTime}}</acquisitionTime>"
                                        "</parameter>"
                                        "<parameter>"
                                            "<name>Humidity</name>"
                                            "<dataType>Double</dataType>"
                                            "<value>"
                                            RL_HUMIDITY
                                            "</value>"
                                            "<isQualifier>false</isQualifier>"
                                            "<acquisitionTime>{{CreationTime}}</acquisitionTime>"
                                        "</parameter>"                 
                                        "<attachment>"
                                        "</attachment>"
                                    "</MsiOrderParameterMessage>"
                                "</message>"
                            "</MsiMessageContainer>";

const char PROGMEM  responseShowOrderInfo2[] ="<?xml version=\"1.0\"\?>"
                            "<MsiMessageContainer xmlns:xsi=\"http://www.w3.org/2001/XMLSchema-instance\" xmlns:xsd=\"http://www.w3.org/2001/XMLSchema\">"
                            "<messageInstanceId>"
                            OP_MESSAGEINSTANCEID1
                            "</messageInstanceId>"
                            "<direction>SF_TO_MES</direction>"
                            "<systemId>"
                            OP_SYSTEMID
                            "</systemId>"
                                "<messageType>MsiOrderParameterMessage</messageType>"
                                //"<messageContext>5000761792</messageContext>"
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
                                        "<deviceTypeId>ESP_Roomlabel</deviceTypeId>"
                                        "<supplierVersion>2.1</supplierVersion>"
                                        //"<orderContext>5000761792</orderContext>"
                                        "<creationTime>" 
                                        OP_CREATIONTIME 
                                        "</creationTime>"
                                        "<parameter>"
                                            "<name>BatchID</name>"
                                            "<dataType>String</dataType>"
                                            "<value>"
                                            RL_BATCHID
                                            "</value>"
                                            "<isQualifier>true</isQualifier>"
                                            "<acquisitionTime>"
                                            OP_CREATIONTIME
                                            "</acquisitionTime>"
                                        "</parameter>"    
                                        "<parameter>"
                                            "<name>Temperature</name>"
                                            "<dataType>Double</dataType>"
                                            "<value>"
                                            RL_TEMPERATURE
                                            "</value>"
                                            "<isQualifier>false</isQualifier>"
                                            "<acquisitionTime>"
                                            OP_CREATIONTIME
                                            "</acquisitionTime>"
                                        "</parameter>"
                                        "<parameter>"
                                            "<name>Humidity</name>"
                                            "<dataType>Double</dataType>"
                                            "<value>"
                                            RL_HUMIDITY
                                            "</value>"
                                            "<isQualifier>false</isQualifier>"
                                            "<acquisitionTime>"
                                            OP_CREATIONTIME
                                            "</acquisitionTime>"
                                        "</parameter>"
                                        "<parameter>"
                                            "<name>Pressure</name>"
                                            "<dataType>Double</dataType>"
                                            "<value>"
                                            RL_PRESSURE
                                            "</value>"
                                            "<isQualifier>false</isQualifier>"
                                            "<acquisitionTime>"
                                            OP_CREATIONTIME
                                            "</acquisitionTime>"
                                        "</parameter>"                 
                                        "<attachment>"
                                        "</attachment>"
                                    "</MsiOrderParameterMessage>"
                                "</message>"
                            "</MsiMessageContainer>";


const char PROGMEM  responseBurstMessage[] ="<?xml version=\"1.0\"\?>"
                            "<MsiMessageContainer xmlns:xsi=\"http://www.w3.org/2001/XMLSchema-instance\" xmlns:xsd=\"http://www.w3.org/2001/XMLSchema\">"
                            "<messageInstanceId>"
                            OP_MESSAGEINSTANCEID1
                            "</messageInstanceId>"
                            "<direction>SF_TO_MES</direction>"
                            "<systemId>"
                            OP_SYSTEMID
                            "</systemId>"
                                "<messageType>MsiOrderParameterMessage</messageType>"
                                //"<messageContext>5000761792</messageContext>"
                                "<message>"
                                    "<MsiOrderParameterMessage>"
                                        "<messageInstanceId>"
                                        OP_MESSAGEINSTANCEID2
                                        "</messageInstanceId>"
                                        "<direction>SF_TO_MES</direction>"
                                        "<messageId>"
                                        "BurstMessage"
                                        "</messageId>"
                                        "<supplierId>Werum</supplierId>"
                                        "<deviceTypeId>ESP_Roomlabel</deviceTypeId>"
                                        "<supplierVersion>1.1</supplierVersion>"
                                        //"<orderContext>5000761792</orderContext>"
                                        "<creationTime>" 
                                        OP_CREATIONTIME 
                                        "</creationTime>"
                                        "<parameter>"
                                            "<name>BatchID</name>"
                                            "<dataType>String</dataType>"
                                            "<value>"
                                            RL_BATCHID
                                            "</value>"
                                            "<isQualifier>true</isQualifier>"
                                            "<acquisitionTime>"
                                            OP_CREATIONTIME
                                            "</acquisitionTime>"
                                        "</parameter>"    
                                        "<parameter>"
                                            "<name>MessageNumber</name>"
                                            "<dataType>Long</dataType>"
                                            "<value>"
                                            RL_MESSAGENUMBER
                                            "</value>"
                                            "<isQualifier>false</isQualifier>"
                                            "<acquisitionTime>"
                                            OP_CREATIONTIME
                                            "</acquisitionTime>"
                                        "</parameter>"            
                                        "<attachment>"
                                        "</attachment>"
                                    "</MsiOrderParameterMessage>"
                                "</message>"
                            "</MsiMessageContainer>";

const char PROGMEM  responseGetEnvironmantalData[] ="<?xml version=\"1.0\"\?>"
                            "<MsiMessageContainer xmlns:xsi=\"http://www.w3.org/2001/XMLSchema-instance\" xmlns:xsd=\"http://www.w3.org/2001/XMLSchema\">"
                            "<messageInstanceId>"
                            OP_MESSAGEINSTANCEID1
                            "</messageInstanceId>"
                            "<direction>SF_TO_MES</direction>"
                            "<systemId>"
                            OP_SYSTEMID
                            "</systemId>"
                                "<messageType>MsiOrderParameterMessage</messageType>"
                                //"<messageContext>5000761792</messageContext>"
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
                                        "<deviceTypeId>ESP_Roomlabel</deviceTypeId>"
                                        "<supplierVersion>1.1</supplierVersion>"
                                        //"<orderContext>5000761792</orderContext>"
                                        "<creationTime>" 
                                        OP_CREATIONTIME 
                                        "</creationTime>"
                                        "<parameter>"
                                            "<name>BatchID</name>"
                                            "<dataType>String</dataType>"
                                            "<value>"
                                            RL_BATCHID
                                            "</value>"
                                            "<isQualifier>true</isQualifier>"
                                            "<acquisitionTime>"
                                            OP_CREATIONTIME
                                            "</acquisitionTime>"
                                        "</parameter>"    
                                        "<parameter>"
                                            "<name>Temperature</name>"
                                            "<dataType>Double</dataType>"
                                            "<value>"
                                            RL_TEMPERATURE
                                            "</value>"
                                            "<isQualifier>false</isQualifier>"
                                           "<acquisitionTime>"
                                            OP_CREATIONTIME
                                            "</acquisitionTime>"
                                        "</parameter>"
                                        "<parameter>"
                                            "<name>Humidity</name>"
                                            "<dataType>Double</dataType>"
                                            "<value>"
                                            RL_HUMIDITY
                                            "</value>"
                                            "<isQualifier>false</isQualifier>"
                                            "<acquisitionTime>"
                                            OP_CREATIONTIME
                                            "</acquisitionTime>"
                                        "</parameter>"                 
                                        "<attachment>"
                                        "</attachment>"
                                    "</MsiOrderParameterMessage>"
                                "</message>"
                            "</MsiMessageContainer>";

const char PROGMEM  responseGetEnvironmantalData2[] ="<?xml version=\"1.0\"\?>"
                            "<MsiMessageContainer xmlns:xsi=\"http://www.w3.org/2001/XMLSchema-instance\" xmlns:xsd=\"http://www.w3.org/2001/XMLSchema\">"
                            "<messageInstanceId>"
                            OP_MESSAGEINSTANCEID1
                            "</messageInstanceId>"
                            "<direction>SF_TO_MES</direction>"
                            "<systemId>"
                            OP_SYSTEMID
                            "</systemId>"
                                "<messageType>MsiOrderParameterMessage</messageType>"
                                //"<messageContext>5000761792</messageContext>"
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
                                        "<deviceTypeId>ESP_Roomlabel</deviceTypeId>"
                                        "<supplierVersion>2.1</supplierVersion>"
                                        //"<orderContext>5000761792</orderContext>"
                                        "<creationTime>" 
                                        OP_CREATIONTIME 
                                        "</creationTime>"
                                        "<parameter>"
                                            "<name>BatchID</name>"
                                            "<dataType>String</dataType>"
                                            "<value>"
                                            RL_BATCHID
                                            "</value>"
                                            "<isQualifier>true</isQualifier>"
                                            "<acquisitionTime>"
                                            OP_CREATIONTIME
                                            "</acquisitionTime>"
                                        "</parameter>"    
                                        "<parameter>"
                                            "<name>Temperature</name>"
                                            "<dataType>Double</dataType>"
                                            "<value>"
                                            RL_TEMPERATURE
                                            "</value>"
                                            "<isQualifier>false</isQualifier>"
                                           "<acquisitionTime>"
                                            OP_CREATIONTIME
                                            "</acquisitionTime>"
                                        "</parameter>"
                                        "<parameter>"
                                            "<name>Humidity</name>"
                                            "<dataType>Double</dataType>"
                                            "<value>"
                                            RL_HUMIDITY
                                            "</value>"
                                            "<isQualifier>false</isQualifier>"
                                            "<acquisitionTime>"
                                            OP_CREATIONTIME
                                            "</acquisitionTime>"
                                        "</parameter>"                 
                                        "<parameter>"
                                            "<name>Pressure</name>"
                                            "<dataType>Double</dataType>"
                                            "<value>"
                                            RL_PRESSURE
                                            "</value>"
                                            "<isQualifier>false</isQualifier>"
                                            "<acquisitionTime>"
                                            OP_CREATIONTIME
                                            "</acquisitionTime>"
                                        "</parameter>"                 
                                        "<attachment>"
                                        "</attachment>"
                                    "</MsiOrderParameterMessage>"
                                "</message>"
                            "</MsiMessageContainer>";

#define MESSAGEDESCRIPTIONCOUNT 7

const char * messageDescriptionV1[]       = {RL_MDGetEnvironmentalData,    RL_MDShowOrderInfo,    RL_MDRoomLabelOff,  RL_MDShowInfo,  RL_MDSetExceptionLimits, RL_MDRequestBurst, RL_MDBurstMessage};
const char * messageDescriptionV2[]       = {RL_MDGetEnvironmentalData2,   RL_MDShowOrderInfo2,   RL_MDRoomLabelOff,  RL_MDShowInfo,  RL_MDSetExceptionLimits, RL_MDRequestBurst, RL_MDBurstMessage};
const char * messageDescriptionTextV1[] = { "GetEnvironmentalData (1.0)",  "ShowOrderInfo (1.0)", "RoomLabelOff",     "ShowInfo",     "SetExceptionLimits", "BurstRequest", "BurstMessage"};
const char * messageDescriptionTextV2[] = { "GetEnvironmentalData (2.0)",  "ShowOrderInfo (2.0)", "RoomLabelOff",     "ShowInfo",     "SetExceptionLimits", "BurstRequest", "BurstMessage"};
const char * messageDescriptionId[]     = { "GetEnvironmentalData",        "ShowOrderInfo",       "RoomLabelOff",     "ShowInfo",     "SetExceptionLimits", "BurstRequest", "BurstMessage"};

class RoomLabel:public OrderParameterMessage
{
    public:
      RoomLabel(int _lcdMaxChars)
      :OrderParameterMessage()
      {
        myDeviceTypeId ="ESP_Roomlabel";
        lcdMaxChars = _lcdMaxChars;
        version = 1;
      }

      RoomLabel(const OrderParameterMessage & other) 
      :OrderParameterMessage(other)
      {
      }
      
      ~RoomLabel()
      {
      }


      const char** getMessageDescriptions()
      {
        //Serial.print("RoomLabel.getMessageDescriptions");
        if (version==1)
        {
          return messageDescriptionV1; 
        }
        else
        {
          return messageDescriptionV2;
        }
      }

      const char** getMessageDescriptionIds()
      {
        //Serial.print("RoomLabel.getMessageDescriptionIds");
        return messageDescriptionId;
      }

      const char** getMessageDescriptionTexts()
      {
        if (version==1)
        {
          return messageDescriptionTextV1;
        }
        else
        {
          return messageDescriptionTextV2;
        }
      }

      unsigned int getMessageDescriptionCount()  
      {
        //Serial.print("RoomLabel.getMessageDescriptionCount");
        return MESSAGEDESCRIPTIONCOUNT;
      }
    

      void setVersion(int _version)
      {
        version = _version;
      }
      
      
      bool parseXml(const String& content, String & errorMessage)
      {
        bool success = OrderParameterMessage::parseXml(content,errorMessage);
        if (success)
        {
          if (messageId == "ShowOrderInfo")
          {
            setHasMessageToSend(true);  // sends environmental data back
            
            enabled = true;
            line1 = makeLCDLine(getParameter("PU"),      "PU: ");
            line2 = makeLCDLine(getParameter("Process"), "");
            line3 = makeLCDLine(getParameter("Mat"),     "Mat: ");
            line4 = makeLCDLine(getParameter("BatchID"), "Batch: ");
            lastBatchId = (const char*)getValue("BatchID");
            lastPU      = (const char*)getValue("PU");

            writeLcdFile();

          }
          else if (messageId == "ShowInfo")
          {
            setHasMessageToSend(false);
            
            enabled = true;
            line1 = makeLCDLine(getParameter("Line1"), "");
            line2 = makeLCDLine(getParameter("Line2"), "");
            line3 = makeLCDLine(getParameter("Line3"), "");
            line4 = makeLCDLine(getParameter("Line4"), "");
            writeLcdFile();

          }
          else if (messageId == "GetEnvironmentalData")
          {
            setHasMessageToSend(true);
          }
          else if (messageId == "RoomLabelOff")
          {
            setHasMessageToSend(false); 
            enabled = false;
            line1 = makeLCDLine("-off-","");
            line2 = makeLCDLine("","");
            line3 = makeLCDLine("","");
            line4 = makeLCDLine("","");
            writeLcdFile();

          }
          else if (messageId == "SetExceptionLimits")
          {
            setHasMessageToSend(false); 
            
            tempUpperLimit = getValueFloat("TempUpperLimit");
            tempLowerLimit = getValueFloat("TempLowerLimit");
            rhUpperLimit   = getValueFloat("RHUpperLimit");
            rhLowerLimit   = getValueFloat("RHLowerLimit");
            writeLcdFile();
          }
          else if (messageId == "BurstRequest")
          {
            setHasMessageToSend(true); 
            numberOfMessages = getValueInt("NumberOfMessages");
          }
          else
          {
            Serial.print("MessageId unkonown:");
            Serial.print(messageId);
            Serial.print("\n");
          }

        }

        return success;
      }

      bool isOk()
      {
        bool ok = OrderParameterMessage::isOk();
        if (ok)
        {
          if (messageId == "ShowOrderInfo")
          {
              ok =   getValue("BatchID");
                  //&& getValue("Mat")
                  //&& getValue("Process")
                  //&& getValue("PU");

          }
          else if (messageId == "ShowInfo")
          {
              ok =   getValue("Line1");
                  //&& getValue("Line2")
                  //&& getValue("Line3")
                  //&& getValue("Line4");
          }
          else if (messageId == "GetEnvironmentalData")
          {
              ok = getValue("BatchID");
          }
          else if (messageId == "RequestBurst")
          {
              ok = getValue("BatchID")
              &&   getValue("NumberOfMessages");
          }
          else if (messageId == "RoomLabelOff")
          {
              ok = getValue("BatchID");
          }
          else if (messageId == "SetExceptionLimits")
          {
              ok = getValue("TempUpperLimit") // at least one 
              ||   getValue("TempLowerLimit")
              ||   getValue("RHUpperLimit")
              ||   getValue("RHLowerLimit");
          }
          else
          {
            Serial.print("MessageId unkonown:");
            Serial.print(messageId);
            Serial.print("\n");
            ok = false;
          }

        }
        
        return ok;
      }
    

      String getBurstMessageString(int number)
      {
        String nextMessageString = responseBurstMessage; 

        OrderParameterMessage::getNextMessageString(nextMessageString);
        String batchId = getValue("BatchID");
        nextMessageString.replace(RL_BATCHID, batchId);
        nextMessageString.replace(RL_MESSAGENUMBER, String(number));

        return nextMessageString;
      }

      String getNextMessageString (float tmp, 
                                  float hum,
                                  float pres) 
      {

        String batchId = getValue("BatchID");
        if (messageId == "ShowOrderInfo")
        {
          enabled = true;
          if (version ==1) 
          {
            nextMessageString = responseShowOrderInfo;
          }
          else
          {
            nextMessageString = responseShowOrderInfo2;
          }
        }
        else if (messageId == "GetEnvironmentalData")
        {
          if (version ==1) 
          {
            nextMessageString = responseGetEnvironmantalData;
          }
          else
          {
            nextMessageString = responseGetEnvironmantalData2;
          }
        }
        else if (messageId == "RoomLabelOff")
        {
          nextMessageString = "";
          enabled = false;
        }

        if (nextMessageString.length())
        {
          OrderParameterMessage::getNextMessageString(nextMessageString);

          nextMessageString.replace(RL_BATCHID, batchId);
          nextMessageString.replace(RL_TEMPERATURE, String(tmp));
          nextMessageString.replace(RL_HUMIDITY, String(hum));
          if (version ==2)
          {
            nextMessageString.replace(RL_PRESSURE, String(pres));
          }
        }
        return nextMessageString;
      }


      String makeLCDLine(const char * v, const char* label)
      {
        String line;
        if (v) // optional parameter
        {
          line = String(String(label) + v).substring(0,lcdMaxChars);
        }
        else
        {
          line = String(label).substring(0,lcdMaxChars);
        }
        while (line.length()<lcdMaxChars)
        {
          line += " ";
        }
        return line;
      }

      String makeLCDLine(msiparameter* p, const char* label)
      {
        String line;
        if (p)
        {
          if (p->value.c_str())
          {
            line = makeLCDLine(p->value.c_str(), label);
          }
          else
          {
            line = makeLCDLine("", label);
          }
        }
        else
        {
//          line = makeLCDLine("---", label);
          line = makeLCDLine("", label);

        }
        return line;
      }

      void getLcdData(String& _line1,
                      String& _line2,
                      String& _line3,
                      String& _line4,
                      bool& _enabled)
      {
        _line1 = line1;
        _line2 = line2;
        _line3 = line3;
        _line4 = line4;
        _enabled = enabled;
      }
 
   
      bool readLcdFile() 
      {
        SPIFFS.begin(); 
        File f = SPIFFS.open(lcdFileName, "r");
        
        if (!f || !f.size()) 
        {
          Serial.println("Lcd file not found");
          line1 = makeLCDLine("Your brand new room","");
          line2 = makeLCDLine("label is now ready","");
          line3 = makeLCDLine("for use","");
          line4 = makeLCDLine("Enjoy :-)","");
          enabled = true;
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
            Serial.print("JSON parseObject() failed: ");
            Serial.println(lcdFileName);
            return false;
          }
          json.prettyPrintTo(Serial);
          line1 = (const char*)json["line1"];
          line2 = (const char*)json["line2"];
          line3 = (const char*)json["line3"];
          line4 = (const char*)json["line4"];
          enabled = (bool) json["enable"];
          tempUpperLimit = (float)json["TempUpperLimit"];
          tempLowerLimit = (float)json["TempLowerLimit"];
          rhUpperLimit   = (float)json["RHUpperLimit"];
          rhLowerLimit   = (float)json["RHLowerLimit"];

          lastBatchId = (const char*)json["BatchID"];
          lastPU      = (const char*)json["PU"];

          systemId = (const char*)json["systemId"];

          
        }
        Serial.println("\nLcd file was successfully parsed");
        
        return true;
      }

      void writeLcdFile()
      {
        DynamicJsonBuffer jsonBuffer;
        JsonObject& json = jsonBuffer.createObject();
        // JSONify local configuration parameters
        json["line1"] = line1;
        json["line2"] = line2;
        json["line3"] = line3;
        json["line4"] = line4;
        json["enable"] = enabled;
        json["BatchID"]  = lastBatchId;
        json["PU"]       = lastPU;
        json["systemId"] = systemId;
        json["TempUpperLimit"] = tempUpperLimit;
        json["TempLowerLimit"] = tempLowerLimit;
        json["RHUpperLimit"]   = rhUpperLimit;
        json["RHLowerLimit"]   = rhLowerLimit;

        writeJsonFile(lcdFileName, json);
      }  

      bool getEnabled()
      {
        return enabled;
      }


      float tempUpperLimit;
      float tempLowerLimit;
      float rhUpperLimit;
      float rhLowerLimit;

      int numberOfMessages;


    protected:
      String nextMessageString;
      int version;
      int lcdMaxChars;
      bool enabled;



      String line1;
      String line2;
      String line3;
      String line4;
         
};