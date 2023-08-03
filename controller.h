#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QObject>
#include "communication_thread.h"

class Controller : public QObject
{
    Q_OBJECT
    Q_PROPERTY(quint16 speed READ speed WRITE setSpeed NOTIFY speedChanged)
    Q_PROPERTY(quint16 RPM READ RPM WRITE setRPM NOTIFY RPMChanged)
    Q_PROPERTY(quint8 gear READ gear WRITE setGear NOTIFY gearChanged)
    Q_PROPERTY(quint16 battery READ battery WRITE setBattery NOTIFY batteryChanged)
    Q_PROPERTY(quint16 DRWheelSpeed READ DRWheelSpeed WRITE setDRWheelSpeed NOTIFY DRWheelSpeedChanged)
    Q_PROPERTY(quint16 DLWheelSpeed READ DLWheelSpeed WRITE setDLWheelSpeed NOTIFY DLWheelSpeedChanged)
    Q_PROPERTY(quint16 URWheelSpeed READ URWheelSpeed WRITE setURWheelSpeed NOTIFY URWheelSpeedChanged)
    Q_PROPERTY(quint16 ULWheelSpeed READ ULWheelSpeed WRITE setULWheelSpeed NOTIFY ULWheelSpeedChanged)
    Q_PROPERTY(quint8 SpeedThrottle READ SpeedThrottle WRITE setSpeedThrottle NOTIFY SpeedThrottleChanged)
    Q_PROPERTY(quint16 SteeringWheel READ SteeringWheel WRITE setSteeringWheel NOTIFY SteeringWheelChanged)
    Q_PROPERTY(quint16 XtoYDiagram READ XtoYDiagram WRITE setXtoYDiagram NOTIFY XtoYDiagramChanged)
    Q_PROPERTY(quint16 YtoXDiagram READ YtoXDiagram WRITE setYtoXDiagram NOTIFY YtoXDiagramChanged)
    Q_PROPERTY(quint8 ECT READ ECT WRITE setECT NOTIFY ECTChanged)
    Q_PROPERTY(quint8 URTravel READ URTravel WRITE setURTravel NOTIFY URTravelChanged)
    Q_PROPERTY(quint8 ULTravel READ ULTravel WRITE setULTravel NOTIFY ULTravelChanged)
    Q_PROPERTY(quint8 DRTravel READ DRTravel WRITE setDRTravel NOTIFY DRTravelChanged)
    Q_PROPERTY(quint8 DLTravel READ DLTravel WRITE setDLTravel NOTIFY DLTravelChanged)
    Q_PROPERTY(quint8 breaking READ breaking WRITE setBreaking NOTIFY breakingChanged)
    //Q_PROPERTY(qint64 Lambda READ Lambda WRITE setLambda NOTIFY LambdaChanged)
    //Q_PROPERTY(qint64 Map READ Map WRITE setMap NOTIFY MapChanged)
    Q_PROPERTY(quint8 Sliping READ Sliping WRITE setSliping NOTIFY SlipingChanged)
    Q_PROPERTY(quint8 fuel READ fuel WRITE setFuel NOTIFY fuelChanged)
public:
    explicit Controller(QObject *parent = nullptr);


    quint16 speed();
    void setSpeed(quint16 new_speed);
    quint16 RPM();
    void setRPM(quint16 new_RPM);
    quint8 gear();
    void setGear(quint8 new_gear);
    quint16 battery();
    void setBattery(quint16 new_battery);
    quint16 DRWheelSpeed();
    void setDRWheelSpeed(quint16 new_DRWheelSpeed);
    quint16 DLWheelSpeed();
    void setDLWheelSpeed(quint16 new_DLWheelSpeed);
    quint16 URWheelSpeed();
    void setURWheelSpeed(quint16 new_URWheelSpeed);
    quint16 ULWheelSpeed();
    void setULWheelSpeed(quint16 new_ULWheelSpeed);
    quint8 SpeedThrottle();
    void setSpeedThrottle(quint8 new_SpeedThrottle);
    quint16 SteeringWheel();
    void setSteeringWheel(quint16 new_SteeringWheel);
    quint16 XtoYDiagram();
    void setXtoYDiagram(quint16 new_XtoYDiagram);
    quint16 YtoXDiagram();
    void setYtoXDiagram(quint16 new_YtoXDiagram);
    quint8 ECT();
    void setECT(quint8 new_ECT);
    quint8 URTravel();
    void setURTravel(quint8 new_URTravel);
    quint8 ULTravel();
    void setULTravel(quint8 new_ULTravel);
    quint8 DRTravel();
    void setDRTravel(quint8 new_DRTravel);
    quint8 DLTravel();
    void setDLTravel(quint8 new_DLTravel);
    quint8 breaking();
    void setBreaking(quint8 new_breaking);
    quint8 Sliping();
    void setSliping(quint8 new_Sliping);
    quint8 fuel();
    void setFuel(quint8 new_fuel);



signals:
    void speedChanged(quint16);
    void RPMChanged(quint16);
    void gearChanged(quint8);
    void batteryChanged(quint16);
    void DRWheelSpeedChanged(quint16);
    void DLWheelSpeedChanged(quint16);
    void URWheelSpeedChanged(quint16);
    void ULWheelSpeedChanged(quint16);
    void SpeedThrottleChanged(quint8);
    void SteeringWheelChanged(quint16);
    void XtoYDiagramChanged(quint16);
    void YtoXDiagramChanged(quint16);
    void ECTChanged(quint8);
    void URTravelChanged(quint8);
    void ULTravelChanged(quint8);
    void DRTravelChanged(quint8);
    void DLTravelChanged(quint8);
    void breakingChanged(quint8);
    void SlipingChanged(quint8);
    void fuelChanged(quint8);

private slots:
    void processMessage(const QString &s);
    void processError(const QString &s);
    void processTimeout(const QString &s);

private:

    CommunicationThread m_thread;
    quint16 m_speed;
    quint16 m_RPM;
    quint8 m_gear;
    quint16 m_battery;
    quint16 m_DRWheelSpeed;
    quint16 m_DLWheelSpeed;
    quint16 m_URWheelSpeed;
    quint16 m_ULWheelSpeed;
    quint8 m_SpeedThrottle;
    quint16 m_SteeringWheel;
    quint16 m_XtoYDiagram;
    quint16 m_YtoXDiagram;
    quint8 m_ECT;
    quint8 m_URTravel;
    quint8 m_ULTravel;
    quint8 m_DRTravel;
    quint8 m_DLTravel;
    quint8 m_breaking;
    quint8 m_Sliping;
    quint8 m_fuel;


};

#endif // CONTROLLER_H

