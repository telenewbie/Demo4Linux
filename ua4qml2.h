#ifndef UA4QML2_H
#define UA4QML2_H

#include <QObject>
#include "curlrequest.h"
#include <deque>
#include <string>
#include <mutex>
#include <thread>
#include <semaphore.h>

struct Message{
    uint32_t type;
    std::string cmd;
};

class UA4Qml2 : public QObject
{
    Q_OBJECT
public:
    UA4Qml2(QObject *parent = 0);

    void sendMsg(const Message& msg);

signals:

public slots:
    void loadUrl();
    void msgQueueSend(const QString str);

    void createReqSession(const QString str);
    void printSessionId();
private:
    //处理消息队列
    void startProcMsg();
    static void* proc(void*);
private :
    CurlRequest* m_request;

    std::deque<Message*> m_dequeMsgs;
    std::mutex m_mutex;
    sem_t m_sem;
    pthread_t m_thread;
};

#endif // UA4QML2_H
