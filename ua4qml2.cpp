#include "ua4qml2.h"
#include <iostream>

#include "session/reqsession.h"

UA4Qml2::UA4Qml2(QObject *parent) : QObject(parent)
{
    m_request = new  CurlRequest;
    startProcMsg();
}

void UA4Qml2::sendMsg(const Message&  msg)
{
    //往消息队列中，增加事件
    m_mutex.lock();
    m_dequeMsgs.emplace_back(new Message(msg));
    m_mutex.unlock();
    sem_post(&m_sem);
}


void UA4Qml2::loadUrl()
{
    std::string url ="https://www.baidu.com";
    std::map<char*,char*>  header ;
    m_request->request(url,header);
}

void UA4Qml2::msgQueueSend(const QString str)
{
    Message msg;
    msg.cmd = str.toStdString();
    msg.type = 1000;
    sendMsg(msg);
}

#include "session/session.h"
void UA4Qml2::createReqSession(const QString str)
{
    //创建一个会话
    //const char* conver to char*
    std::string tmpStr = str.toStdString();
    char* c_str=new char[tmpStr.length()];
    memcpy(c_str,tmpStr.c_str(),tmpStr.length());

    Session* session =new Session();
    session->name = c_str;

#if 1
    //基本数据类型
    ReqSessionTMP<char> reqSessionTmp1(c_str) ;
    reqSessionTmp1.printSession();
#endif

#if 1
    ReqSession reqSession(session) ;
    //可以看到，没有调用析构函数
    reqSession.printSession();
#else
    ReqSessionTMP<Session> reqSessionTmp(session) ;
    //可以看到调用了析构函数
    reqSessionTmp.printSession();
#endif
}

void UA4Qml2::printSessionId()
{

}


#if 0
void UA4Qml2::startProcMsg()
{
    std::cout<<"进入消息队列"<<std::endl;
    std::thread t([this](){
        while(true){
            sem_wait(&m_sem);
            //如果有消息到来就不会开启等待
            std::cout<<"开始"<<std::endl;
            std::deque<Message*> dequeMsgs;
            m_mutex.lock();
            dequeMsgs.swap(m_dequeMsgs);
            m_mutex.unlock();
            for(auto it=dequeMsgs.begin();it!=dequeMsgs.end();it++){
                std::cout<<(*it)->type<<":::"<<(*it)->cmd<<std::endl;
                delete *it;
            }
            sleep(2);
            std::cout<<"结束"<<std::endl;
        }
    });
    t.detach();
}
#else
void UA4Qml2::startProcMsg()
{

    std::cout<<"进入消息队列"<<std::endl;
#if 1
    for(size_t i=0;i<4;++i)
    {
        pthread_create(&m_thread,NULL,proc,this);
    }
#else
    for(size_t i=0;i<4;++i)
    {
        std::thread t([this](){

            UA4Qml2::proc(this);
        });
        t.detach();
    }
#endif
}
#endif




void* UA4Qml2::proc(void* data)
{
    UA4Qml2* uA4Qml2 = (UA4Qml2*)data;
    while(true){
        sem_wait(&uA4Qml2->m_sem);
        //如果有消息到来就不会开启等待
        uA4Qml2->m_mutex.lock();
        Message* it = *(uA4Qml2->m_dequeMsgs.begin());
        uA4Qml2->m_dequeMsgs.pop_front();
        uA4Qml2->m_mutex.unlock();
        std::cout<<(*it).type<<":::"<<(*it).cmd<<std::this_thread::get_id()<<std::endl;
        std::cout<<"卡住结束"<<std::endl;
        sleep(2);
        delete it;
    }
    return nullptr;
}
