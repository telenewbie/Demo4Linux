#ifndef BASEREQSESSION_H
#define BASEREQSESSION_H

#include <stdint.h>
class BaseReqSession
{
public:
    BaseReqSession();
    static uint32_t& get_session_id();
};

#endif // BASEREQSESSION_H
