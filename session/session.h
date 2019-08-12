#ifndef SESSION_H
#define SESSION_H

#include <stdint.h>
#include <iostream>

class Session{
public:
    char * name =nullptr;
//    char * other =nullptr ;
    uint32_t age =0;
    ~Session(){
        std::cout<<"~Session"<<std::endl;
    }
};

#endif // SESSION_H
