#include "basereqsession.h"

BaseReqSession::BaseReqSession()
{}

static uint32_t m_session_id = 0;
uint32_t &BaseReqSession::get_session_id()
{
 return m_session_id;
}

