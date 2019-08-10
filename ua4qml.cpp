#include "ua4qml.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdint.h>
#include <iostream>

UA4QML& UA4QML::getInstance()
{
    static UA4QML instance;
    return instance;
}

void UA4QML::loadUrl()
{
    std::cout<<"hello"<<std::endl;
}

UA4QML::UA4QML()
{

}
