#include "controller.h"


Controller::Controller(QObject *parent)
    : QObject(parent), m_speed(0),m_RPM(0),m_gear(0),m_battery(0)
    ,m_DRWheelSpeed(0),m_DLWheelSpeed(0),m_URWheelSpeed(0),m_ULWheelSpeed(0)
    ,m_SpeedThrottle(0),m_SteeringWheel(180),m_XtoYDiagram(36000),m_YtoXDiagram(36000),m_ECT(0),m_breaking(0)
{
    connect(&m_thread, &CommunicationThread::message, this, &Controller::processMessage);
    connect(&m_thread, &CommunicationThread::error, this, &Controller::processError);
    connect(&m_thread, &CommunicationThread::timeout, this, &Controller::processTimeout);

    m_thread.start(QThread::HighestPriority);

}


quint16 Controller::speed()
{
    return m_speed;
}

quint16 Controller::RPM()
{
    return m_RPM;
}

quint8 Controller::gear()
{
    return m_gear;
}

quint16 Controller::battery()
{

    return m_battery;
}


quint16 Controller :: DRWheelSpeed()
{
    return m_DRWheelSpeed;
}

quint16 Controller :: URWheelSpeed()
{
    return m_URWheelSpeed;
}

quint16 Controller :: DLWheelSpeed()
{
    return m_DLWheelSpeed;
}

quint16 Controller :: ULWheelSpeed()
{
    return m_ULWheelSpeed;
}

quint8 Controller :: SpeedThrottle()
{
    return m_SpeedThrottle ;
}

quint16 Controller ::SteeringWheel()
{
    return (m_SteeringWheel);
}

quint16 Controller :: XtoYDiagram() // wenta btb3t l g adrb fy 100
{
    return m_XtoYDiagram;
}

quint16 Controller :: YtoXDiagram()
{
    return m_YtoXDiagram;
}

quint8 Controller :: ECT()
{
    return m_ECT;
}

quint8 Controller :: URTravel()
{
    return m_URTravel;
}

quint8 Controller :: ULTravel()
{
    return m_ULTravel;
}

quint8 Controller :: DRTravel()
{
    return m_DRTravel;
}

quint8 Controller :: DLTravel()
{
    return m_DLTravel;
}

quint8 Controller :: breaking()
{
    return m_breaking;
}

quint8 Controller :: Sliping()
{
    return m_Sliping;
}

quint8 Controller :: fuel()
{
    return m_fuel;
}


void Controller::setGear(quint8 new_gear)
{
    m_gear=new_gear;
    emit gearChanged(new_gear);
}

void Controller::setSpeed(quint16  new_speed)
{
    m_speed = new_speed;
    emit speedChanged(new_speed);
}

void Controller::setRPM(quint16 new_RPM)
{
    m_RPM=new_RPM;
    emit RPMChanged(new_RPM);
}

void Controller :: setBattery(quint16 new_battery)
{
    m_battery=new_battery;
    emit batteryChanged(new_battery);
}

void Controller :: setDRWheelSpeed(quint16 new_DRWheelSpeed)
{
    m_DRWheelSpeed = new_DRWheelSpeed;
    emit DRWheelSpeedChanged(new_DRWheelSpeed);
}

void Controller :: setDLWheelSpeed(quint16 new_DLWheelSpeed)
{
    m_DLWheelSpeed = new_DLWheelSpeed;
    emit DLWheelSpeedChanged(new_DLWheelSpeed);
}

void Controller :: setURWheelSpeed(quint16 new_URWheelSpeed)
{
    m_URWheelSpeed = new_URWheelSpeed;
    emit URWheelSpeedChanged(new_URWheelSpeed);
}

void Controller :: setULWheelSpeed(quint16 new_ULWheelSpeed)
{
    m_ULWheelSpeed = new_ULWheelSpeed;
    emit ULWheelSpeedChanged(new_ULWheelSpeed);
}

void Controller :: setSpeedThrottle(quint8 new_SpeedThrottle)
{
    m_SpeedThrottle = new_SpeedThrottle;
    emit SpeedThrottleChanged(new_SpeedThrottle);
}

void Controller ::setSteeringWheel(quint16 new_SteeringWheel)
{
    m_SteeringWheel = new_SteeringWheel;
    emit SteeringWheelChanged(new_SteeringWheel);
}

void Controller :: setXtoYDiagram(quint16 new_XtoYDiagram)
{
    m_XtoYDiagram = new_XtoYDiagram;
    emit XtoYDiagramChanged(new_XtoYDiagram);
}

void Controller :: setYtoXDiagram(quint16 new_YtoXDiagram)
{
    m_YtoXDiagram = new_YtoXDiagram;
    emit YtoXDiagramChanged(new_YtoXDiagram);
}

void Controller :: setECT(quint8 new_ECT)
{
    m_ECT = new_ECT;
    emit ECTChanged(new_ECT);

}

void Controller :: setURTravel(quint8 new_URTravel)
{
    m_URTravel = new_URTravel;
    emit URTravelChanged(new_URTravel);
}

void Controller :: setULTravel(quint8 new_ULTravel)
{
    m_ULTravel = new_ULTravel;
    emit ULTravelChanged(new_ULTravel);
}

void Controller :: setDRTravel(quint8 new_DRTravel)
{
    m_DRTravel = new_DRTravel;
    emit DRTravelChanged(new_DRTravel);
}

void Controller :: setDLTravel(quint8 new_DLTravel)
{
    m_DLTravel = new_DLTravel;
    emit DLTravelChanged(new_DLTravel);
}

void Controller :: setBreaking(quint8 new_breaking)
{
    m_breaking = new_breaking;
    emit breakingChanged(new_breaking);
}

void Controller :: setSliping(quint8 new_Sliping)
{
    m_Sliping = new_Sliping;
    emit SlipingChanged(new_Sliping);
}

void Controller :: setFuel(quint8 new_fuel)
{
    m_fuel = new_fuel;
    emit fuelChanged(new_fuel);
}



void Controller::processMessage(const QString &s)
{


    if((!s.isEmpty()) && (s.size()>3)) {
        quint8 header1 = s.at(0).toLatin1();
        quint8 header2 = s.at(1).toLatin1();
        quint8 header3 = s.at(2).toLatin1();
        if((header1 == '~') && (header2 == '!') && (header3 == '@')) {
        quint8 ID = s.at(3).toLatin1();
        quint64 Data = s.midRef(4).toULongLong();
        quint16 battery = 0;
        quint16 rpm = 0;
        quint16 speed = 0;
        quint16 x_diagram = 0;
        quint16 y_diagram = 0;
        quint16 wheel1 = 0;
        quint16 wheel2 = 0;
        quint16 wheel3 = 0;
        quint16 wheel4 = 0;
        quint16 steeringangle = 0;
        quint8 travel1 = 0;
        quint8 travel2 = 0;
        quint8 travel3 = 0;
        quint8 travel4 = 0;
        quint8 ECT = 0;
        quint8 speedThrottle = 0;
        quint8 gear = 0;
        quint8 breaking = 0;
        quint8 sliping = 0;
        quint8 fuel = 0;



    if((ID == 0x50) || (ID == 0x51) || (ID == 0x52) || (ID == 0x53) || (ID == 0x54) || (ID == 0x55) || (ID== 0x56) || (ID == 0x60))
    {

        switch (ID) {
        case 0x50:
            rpm = ((Data&0xFF)<<8) | ((Data&0xFF00)>>8);
            setRPM(rpm);
            battery = ((Data & 0xFF0000)>>8) | ((Data & 0xFF000000)>>24)  ;
            setBattery(battery);
            ECT = ((Data & 0xFF00000000) >> 32);
            setECT(ECT);
            speedThrottle = ((Data & 0xFF0000000000)>>40);
            setSpeedThrottle(speedThrottle);
            gear = ((Data & 0xFF000000000000) >> 48);
            setGear(gear);
            fuel = ((Data & 0xFF00000000000000)>>56);
            setFuel(fuel);
            break;

        case 0x53:
            speed = (((Data & 0xFF)<<8) | ((Data&0xFF00)>>8));
            setSpeed(speed);
            steeringangle = (((Data & 0xFF0000)>>8) |((Data&0xFF000000)>>24));
            setSteeringWheel(steeringangle);
            sliping = ((Data & 0xFF00000000000000)>>56);
            setSliping(sliping);
            break;

        case 0x52:
            x_diagram = (((Data & 0xFF)<<8) | ((Data&0xFF00)>>8));
            setXtoYDiagram(x_diagram);
            y_diagram = (((Data&0xFF0000)>>8) | ((Data&0xFF000000)>>24));
            setYtoXDiagram(y_diagram);
            break;

        case 0x54:
            wheel1 = (((Data & 0xFF)<<8) | ((Data&0xFF00)>>8));
            setDRWheelSpeed(wheel1);
            wheel2 = ((Data & 0xFF0000) >> 8) | ((Data&0xFF000000)>>24);
            setULWheelSpeed(wheel2);
            wheel3 = ((Data & 0xFF00000000)>>24) | ((Data&0xFF0000000000)>>40);
            setDLWheelSpeed(wheel3);
            wheel4 = ((Data & 0xFF000000000000)>>40) | ((Data & 0xFF00000000000000)>>56);
            setURWheelSpeed(wheel4);
            break;

        case 0x56:
            travel1 = (Data&0xFF);
            setDRTravel(travel1);
            travel2 = ((Data&0xFF00)>>8);
            setURTravel(travel2);
            travel3 = ((Data & 0xFF0000)>>16);
            setDLTravel(travel3);
            travel4 = ((Data&0xFF000000)>>24);
            setULTravel(travel4);
            break;

        case 0x57:
            breaking = (Data&0xFF);
            setBreaking(breaking);
            break;



        default:
            break;
        }
    }
  }
 }
}



void Controller::processError(const QString &s)
{
}

void Controller::processTimeout(const QString &s)
{
}
