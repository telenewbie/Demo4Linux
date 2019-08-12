#ifndef REQSESSION_H
#define REQSESSION_H
#include <stdint.h>
#include <iostream>
#include "basereqsession.h"

template <typename T>
class ReqSessionTMP :BaseReqSession
{
public:
    ReqSessionTMP(T* data){
        autoIncreateSessionId();
        m_data =data;
    }

    int getSessionId()
    {
        return get_session_id();
    }
private:
    void autoIncreateSessionId()
    {
        ++get_session_id();
        if(get_session_id() == 0)
        {
            get_session_id() = 1;
        }
    }

private:
    //携带的参数
    T * m_data =nullptr;
};

//普通类
class ReqSession:BaseReqSession
{
public:
    ReqSession(void* data){
        ++get_session_id();
        m_data =data;
    }

    void printSession(){
        std::cout<<"普通类：id:"<<get_session_id()<<",param:"<<m_data<<std::endl;
        delete m_data;// 这里做了释放的操作，注意这里没有强转
    }

private:
    //携带的参数
    void * m_data =nullptr;
};


#endif // REQSESSION_H
