#ifndef COMMUNICATIONTHREAD_H
#define COMMUNICATIONTHREAD_H

#include <QMutex>
#include <QThread>
#include <QWaitCondition>


class CommunicationThread : public QThread
{
    Q_OBJECT

public:
    explicit CommunicationThread(QObject *parent = nullptr);
    ~CommunicationThread();

    void start( int waitTimeout);

signals:
    void message(const QString &s);
    void error(const QString &s);
    void timeout(const QString &s);

private:
    void run() override;
    QString m_portName;
    int m_waitTimeout = 0;
    QMutex m_mutex;
    bool m_quit = false;
};

#endif // COMMUNICATIONTHREAD_H
