#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QObject>
#include "communication_thread.h"

class Controller : public QObject
{
    Q_OBJECT
    Q_PROPERTY(qint64 speed READ speed WRITE setSpeed NOTIFY speedChanged)
    Q_PROPERTY(qint64 RPM READ RPM WRITE setRPM NOTIFY RPMChanged)
    Q_PROPERTY(qint64 gear READ gear WRITE setGear NOTIFY gearChanged)
    Q_PROPERTY(qint64 battery READ battery WRITE setBattery NOTIFY batteryChanged)
    Q_PROPERTY(qint64 oil READ oil WRITE setOil NOTIFY oilChanged)
    Q_PROPERTY(qint64 DRWheelSpeed READ DRWheelSpeed WRITE setDRWheelSpeed NOTIFY DRWheelSpeedChanged)
    Q_PROPERTY(qint64 DLWheelSpeed READ DLWheelSpeed WRITE setDLWheelSpeed NOTIFY DLWheelSpeedChanged)
    Q_PROPERTY(qint64 URWheelSpeed READ URWheelSpeed WRITE setURWheelSpeed NOTIFY URWheelSpeedChanged)
    Q_PROPERTY(qint64 ULWheelSpeed READ ULWheelSpeed WRITE setULWheelSpeed NOTIFY ULWheelSpeedChanged)
    Q_PROPERTY(qint64 SpeedThrottle READ SpeedThrottle WRITE setSpeedThrottle NOTIFY SpeedThrottleChanged)
    Q_PROPERTY(qint64 SteeringWheel READ SteeringWheel WRITE setSteeringWheel NOTIFY SteeringWheelChanged)
    Q_PROPERTY(qint64 XtoYDiagram READ XtoYDiagram WRITE setXtoYDiagram NOTIFY XtoYDiagramChanged)
    Q_PROPERTY(qint64 YtoXDiagram READ YtoXDiagram WRITE setYtoXDiagram NOTIFY YtoXDiagramChanged)
    Q_PROPERTY(qint64 ECT READ ECT WRITE setECT NOTIFY ECTChanged)
    Q_PROPERTY(qint64 URTravel READ URTravel WRITE setURTravel NOTIFY URTravelChanged)
    Q_PROPERTY(qint64 ULTravel READ ULTravel WRITE setULTravel NOTIFY ULTravelChanged)
    Q_PROPERTY(qint64 DRTravel READ DRTravel WRITE setDRTravel NOTIFY DRTravelChanged)
    Q_PROPERTY(qint64 DLTravel READ DLTravel WRITE setDLTravel NOTIFY DLTravelChanged)
    Q_PROPERTY(qint64 Lambda READ Lambda WRITE setLambda NOTIFY LambdaChanged)
    Q_PROPERTY(qint64 Map READ Map WRITE setMap NOTIFY MapChanged)
public:
    explicit Controller(QObject *parent = nullptr);


    qint64 speed();
    void setSpeed(qint64 new_speed);
    qint64 RPM();
    void setRPM(qint64 new_RPM);
    qint64 gear();
    void setGear(qint64 new_gear);
    qint64 battery();
    void setBattery(qint64 new_battery);
    qint64 oil();
    void setOil(qint64 new_oil);
    qint64 DRWheelSpeed();
    void setDRWheelSpeed(qint64 new_DRWheelSpeed);
    qint64 DLWheelSpeed();
    void setDLWheelSpeed(qint64 new_DLWheelSpeed);
    qint64 URWheelSpeed();
    void setURWheelSpeed(qint64 new_URWheelSpeed);
    qint64 ULWheelSpeed();
    void setULWheelSpeed(qint64 new_ULWheelSpeed);
    qint64 SpeedThrottle();
    void setSpeedThrottle(qint64 new_SpeedThrottle);
    qint64 SteeringWheel();
    void setSteeringWheel(qint64 new_SteeringWheel);
    qint64 XtoYDiagram();
    void setXtoYDiagram(qint64 new_XtoYDiagram);
    qint64 YtoXDiagram();
    void setYtoXDiagram(qint64 new_YtoXDiagram);
    qint64 ECT();
    void setECT(qint64 new_ECT);
    qint64 URTravel();
    void setURTravel(qint64 new_URTravel);
    qint64 ULTravel();
    void setULTravel(qint64 new_ULTravel);
    qint64 DRTravel();
    void setDRTravel(qint64 new_DRTravel);
    qint64 DLTravel();
    void setDLTravel(qint64 new_DLTravel);
    qint64 Lambda();
    void setLambda(qint64 new_Lambda);
    qint64 Map();
    void setMap(qint64 new_Map);



signals:
    void speedChanged(qint64);
    void RPMChanged(qint64);
    void gearChanged(qint64);
    void batteryChanged(qint64);
    void oilChanged(qint64);
    void DRWheelSpeedChanged(qint64);
    void DLWheelSpeedChanged(qint64);
    void URWheelSpeedChanged(qint64);
    void ULWheelSpeedChanged(qint64);
    void SpeedThrottleChanged(qint64);
    void SteeringWheelChanged(qint64);
    void XtoYDiagramChanged(qint64);
    void YtoXDiagramChanged(qint64);
    void ECTChanged(qint64);
    void URTravelChanged(qint64);
    void ULTravelChanged(qint64);
    void DRTravelChanged(qint64);
    void DLTravelChanged(qint64);
    void LambdaChanged(qint64);
    void MapChanged(qint64);


private slots:
    void processMessage(const QString &s);
    void processError(const QString &s);
    void processTimeout(const QString &s);

private:

    CommunicationThread m_thread;
    qint64 m_speed;
    qint64 m_RPM;
    qint64 m_gear;
    qint64 m_battery;
    qint64 m_oil;
    qint64 m_DRWheelSpeed;
    qint64 m_DLWheelSpeed;
    qint64 m_URWheelSpeed;
    qint64 m_ULWheelSpeed;
    qint64 m_SpeedThrottle;
    qint64 m_SteeringWheel;
    qint64 m_XtoYDiagram;
    qint64 m_YtoXDiagram;
    qint64 m_ECT;
    qint64 m_URTravel;
    qint64 m_ULTravel;
    qint64 m_DRTravel;
    qint64 m_DLTravel;
    qint64 m_Map;
    qint64 m_Lambda;



};

#endif // CONTROLLER_H

