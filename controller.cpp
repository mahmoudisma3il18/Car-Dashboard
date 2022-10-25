#include "controller.h"


Controller::Controller(QObject *parent)
    : QObject(parent), m_speed(0),m_RPM(0),m_gear(0),m_battery(1),m_oil(1),m_DRWheelSpeed(0),m_DLWheelSpeed(0),m_URWheelSpeed(0),m_ULWheelSpeed(0),m_SpeedThrottle(0),m_SteeringWheel(0),m_XtoYDiagram(0),m_YtoXDiagram(0)
{
    connect(&m_thread, &CommunicationThread::message, this, &Controller::processMessage);
    connect(&m_thread, &CommunicationThread::error, this, &Controller::processError);
    connect(&m_thread, &CommunicationThread::timeout, this, &Controller::processTimeout);

    m_thread.start(10);
   // m_thread.setPriority(QThread::HighestPriority );

}



qint64 Controller::speed()
{
    return m_speed;
}

qint64 Controller::RPM()
{
    return m_RPM*100;
}

qint64 Controller::gear()
{
    return m_gear;
}

qint64 Controller::battery()
{

    return m_battery;
}

qint64 Controller :: oil()
{
    return m_oil;
}

qint64 Controller :: DRWheelSpeed()
{
    return m_DRWheelSpeed;
}

qint64 Controller :: URWheelSpeed()
{
    return m_URWheelSpeed;
}

qint64 Controller :: DLWheelSpeed()
{
    return m_DLWheelSpeed;
}

qint64 Controller :: ULWheelSpeed()
{
    return m_ULWheelSpeed;
}

qint64 Controller :: SpeedThrottle()
{
    return m_SpeedThrottle ;
}

qint64 Controller ::SteeringWheel()
{
    return (m_SteeringWheel - 150);
}

qint64 Controller :: XtoYDiagram() // wenta btb3t l g adrb fy 100
{
    return m_XtoYDiagram;
}

qint64 Controller :: YtoXDiagram()
{
    return m_YtoXDiagram;
}

qint64 Controller :: ECT()
{
    return m_ECT;
}

qint64 Controller :: URTravel()
{
    return m_URTravel;
}

qint64 Controller :: ULTravel()
{
    return m_ULTravel;
}

qint64 Controller :: DRTravel()
{
    return m_DRTravel;
}

qint64 Controller :: DLTravel()
{
    return m_DLTravel;
}

qint64 Controller :: Lambda()
{
    return m_Lambda;
}

qint64 Controller :: Map()
{
    return m_Map;
}

void Controller::setGear(qint64 new_gear)
{
    m_gear=new_gear;
    emit gearChanged(new_gear);
}

void Controller::setSpeed(qint64  new_speed)
{
    m_speed = new_speed;
    emit speedChanged(new_speed);
}

void Controller::setRPM(qint64 new_RPM)
{
    m_RPM=new_RPM;
    emit RPMChanged(new_RPM);
}

void Controller :: setBattery(qint64 new_battery)
{
    m_battery=new_battery;
    emit batteryChanged(new_battery);
}

void Controller :: setOil(qint64 new_oil)
{
    m_oil = new_oil;
    emit oilChanged(new_oil);
}

void Controller :: setDRWheelSpeed(qint64 new_DRWheelSpeed)
{
    m_DRWheelSpeed = new_DRWheelSpeed;
    emit DRWheelSpeedChanged(new_DRWheelSpeed);
}

void Controller :: setDLWheelSpeed(qint64 new_DLWheelSpeed)
{
    m_DLWheelSpeed = new_DLWheelSpeed;
    emit DLWheelSpeedChanged(new_DLWheelSpeed);
}

void Controller :: setURWheelSpeed(qint64 new_URWheelSpeed)
{
    m_URWheelSpeed = new_URWheelSpeed;
    emit URWheelSpeedChanged(new_URWheelSpeed);
}

void Controller :: setULWheelSpeed(qint64 new_ULWheelSpeed)
{
    m_ULWheelSpeed = new_ULWheelSpeed;
    emit ULWheelSpeedChanged(new_ULWheelSpeed);
}

void Controller :: setSpeedThrottle(qint64 new_SpeedThrottle)
{
    m_SpeedThrottle = new_SpeedThrottle;
    emit SpeedThrottleChanged(new_SpeedThrottle);
}

void Controller ::setSteeringWheel(qint64 new_SteeringWheel)
{
    m_SteeringWheel = new_SteeringWheel;
    emit SteeringWheelChanged(new_SteeringWheel);
}

void Controller :: setXtoYDiagram(qint64 new_XtoYDiagram)
{
    m_XtoYDiagram = new_XtoYDiagram;
    emit XtoYDiagramChanged(new_XtoYDiagram);
}

void Controller :: setYtoXDiagram(qint64 new_YtoXDiagram)
{
    m_YtoXDiagram = new_YtoXDiagram;
    emit YtoXDiagramChanged(new_YtoXDiagram);
}

void Controller :: setECT(qint64 new_ECT)
{
    m_ECT = new_ECT;
    emit ECTChanged(new_ECT);

}

void Controller :: setURTravel(qint64 new_URTravel)
{
    m_URTravel = new_URTravel;
    emit URTravelChanged(new_URTravel);
}

void Controller :: setULTravel(qint64 new_ULTravel)
{
    m_ULTravel = new_ULTravel;
    emit ULTravelChanged(new_ULTravel);
}

void Controller :: setDRTravel(qint64 new_DRTravel)
{
    m_DRTravel = new_DRTravel;
    emit DRTravelChanged(new_DRTravel);
}

void Controller :: setDLTravel(qint64 new_DLTravel)
{
    m_DLTravel = new_DLTravel;
    emit DLTravelChanged(new_DLTravel);
}

void Controller :: setLambda(qint64 new_Lambda)
{
    m_Lambda = new_Lambda;
    emit URTravelChanged(new_Lambda);
}

void Controller :: setMap(qint64 new_Map)
{
    m_Map = new_Map;
    emit MapChanged(new_Map);
}


void Controller::processMessage(const QString &s)
{
    qint64 Speed = 0;
    qint64 RPM = 0;
    qint64 gear=0;
    qint64 battery=0;
   // qint64 oil = 0;
    qint64 ECT = 0;
    qint64 URTravel = 0;
    qint64 ULTravel = 0;
    qint64 DRTravel = 0;
    qint64 DLTravel = 0;
    qint64 DRWheelSpeed = 0;
    qint64 DLWheelSpeed = 0;
    qint64 URWheelSpeed = 0;
    qint64 ULWheelSpeed = 0;
    qint64 SpeedThrottle = 0;
    qint64 SteeringWheel = 0;
    qint64 XtoYDiagram = 0;
    qint64 YtoXDiagram = 0;
    qint64 Lambda = 0 ;
    qint64 Map = 0;
    qint64 ID=((s.toULongLong()) & 0x0000000000000003) ; // ID 6 BITS
    qint64 MSG=((s.toULongLong()) & 0xFFFFFFFFFFFFFFFC)>>2 ;      // MSG 58 BITS




    switch(ID)
    {
    case 1 :
        Speed=(MSG&0x7FF);
        setSpeed(Speed);
        URWheelSpeed = ((MSG&0x3FF800)>>11);
        setURWheelSpeed(URWheelSpeed);
        ULWheelSpeed = ((MSG&0x1FFC00000)>>22);
        setULWheelSpeed(ULWheelSpeed);
        DRWheelSpeed = ((MSG&0xFFE00000000)>>33);
        setDRWheelSpeed(DRWheelSpeed);
        DLWheelSpeed = ((MSG&0x7FF00000000000)>>44);
        setDLWheelSpeed(DLWheelSpeed);
        ECT = ((MSG&0x3F80000000000000)>>55);
        setECT(ECT);
        break;

    case 2 :
        RPM = (MSG&0x3FFF);
        setRPM(RPM);
        URTravel = (MSG&0xFFC000>>14);
        setURTravel(URTravel);
        ULTravel = (MSG&0x3FF000000>>24);
        setULTravel(ULTravel);
        DRTravel = (MSG&0xFFC00000000>>34);
        setDRTravel(DRTravel);
        DLTravel = (MSG&0x3FF00000000000>>44);
        setDLTravel(DLTravel);
        SteeringWheel = (MSG&0x3FC0000000000000>>54);
        setSteeringWheel(SteeringWheel);
        break;

    case 3 :

        battery = (MSG&0xFF);
        setBattery(battery);
        SpeedThrottle = ((MSG&0x3FF00)>>8);
        setSpeedThrottle(SpeedThrottle);
        Lambda = ((MSG&0x3FC0000)>>18);
        setLambda(Lambda);
        Map = ((MSG&0xFFC000000)>>26);
        setMap(Map);
        gear = ((MSG&0xF000000000)>>36);
        setGear(gear);
        XtoYDiagram = ((MSG&0x7FF0000000000)>>40);
        setXtoYDiagram(XtoYDiagram);
        YtoXDiagram = ((MSG&0x3FF8000000000000)>>51);
        setYtoXDiagram(YtoXDiagram);
        break;

   // case 4 : //268435456
       // battery = MSG;
       // setBattery(battery);
   //     break;

  //  case 5 : // 335544320
      //  oil = MSG;
      //  setOil(oil);
      //  break;

 //   case 6 : //402653184

  //      break;

    //case 7 : //469762048

  //      break;

  //  case 8 :  //536870912
      //  DLWheelSpeed = MSG;
      //  setDLWheelSpeed(DLWheelSpeed);
  //      break;

  //  case 9 : //603979776
      //  DRWheelSpeed = MSG;
      //  setDRWheelSpeed(DRWheelSpeed);
    //    break;

   // case 10 : //671088640
      //  SpeedThrottle = MSG;
      //  setSpeedThrottle(SpeedThrottle);
    //    break;

    //case 11 : //738197504
      //  SteeringWheel = MSG;
      //  setSteeringWheel(SteeringWheel);
      //  break;

  //  case 12 : //805306368
      //  XtoYDiagram = (MSG & 0x7FF) ;
      //  YtoXDiagram = ((MSG & 0x3FF800) >> 11);
      //  setXtoYDiagram(XtoYDiagram);
      //  setYtoXDiagram(YtoXDiagram);
   //     break;


    }


}

void Controller::processError(const QString &s)
{
}

void Controller::processTimeout(const QString &s)
{
}
