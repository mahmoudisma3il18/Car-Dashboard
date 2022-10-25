#include "communication_thread.h"
#include <QSerialPort>
#include <QTime>
#include <QSerialPortInfo>
#include <qdebug.h>



CommunicationThread::CommunicationThread(QObject *parent) :
    QThread(parent)
{
}

CommunicationThread::~CommunicationThread()
{
    m_mutex.lock();
    m_quit = true;
    m_mutex.unlock();
    wait();
}

void CommunicationThread::start( int waitTimeout)
{

     const auto serialPortInfos = QSerialPortInfo::availablePorts();
     for (const QSerialPortInfo &serialPortInfo : serialPortInfos) {
         m_portName = serialPortInfo.portName();
     }

    m_waitTimeout = waitTimeout;
    if (!isRunning())
        QThread::start();
}

void CommunicationThread::run()
{
    bool currentPortNameChanged = false;
    m_mutex.lock();
    QString currentPortName;
    if (currentPortName != m_portName) {
        currentPortName = m_portName;
        currentPortNameChanged = true;
    }

    int currentWaitTimeout = m_waitTimeout;
    m_mutex.unlock();
    QSerialPort serial;
    serial.setBaudRate(QSerialPort::Baud57600);

    while (!m_quit) {
        if (currentPortNameChanged) {
            serial.close();
            serial.setPortName(currentPortName);

            if (!serial.open(QIODevice::ReadWrite)) {
                emit error(tr("Can't open %1, error code %2")
                           .arg(m_portName).arg(serial.error()));
                return;
            }
        }

       if (serial.waitForReadyRead(currentWaitTimeout)) {
            QByteArray requestData = serial.readAll();
            while (serial.waitForReadyRead(1))
                requestData += serial.readAll();
            const QString request = QString::fromUtf8(requestData);
            emit this->message(request);
        } else {
            emit timeout(tr("Wait read request timeout %1")
                         .arg(QTime::currentTime().toString()));
        }


        m_mutex.lock();
        if (currentPortName != m_portName) {
            currentPortName = m_portName;
            currentPortNameChanged = true;
        } else {
            currentPortNameChanged = false;
        }
        currentWaitTimeout = m_waitTimeout;
        m_mutex.unlock();
    }
}
