#pragma once

#include <wstring.h>


class msiparameter
{
    public:
        msiparameter()
        {
            isQualifier=false;
            acquisitionTime=0;
        };

        void clear()
        {
            name="";
            dataType="";
            value="";
            isQualifier=false;
            acquisitionTimeString="";
            acquisitionTime=0;
        };


        void logToSerial(HardwareSerial & serial)
        {
            serial.print("name: ");
            serial.println(name);
            serial.print("\tdataType: ");
            serial.println(dataType);
            serial.print("\tvalue: ");
            serial.println(value);
            serial.print("\tisQualifier: ");
            serial.println(isQualifier);
            serial.print("\tacquisitionTime: ");
            serial.println(acquisitionTime);
            serial.print("\tacquisitionTimeString: ");
            serial.println(acquisitionTimeString);
        };

    public:    
        String name;
        String dataType;
        String value;
        bool isQualifier;
        String acquisitionTimeString;
        unsigned long acquisitionTime;
};