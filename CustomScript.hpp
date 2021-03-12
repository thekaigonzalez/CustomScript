//
// Created by seymo on 2/24/2021.
//
#include "size_t.h"
#include <windows.h>

#ifndef CUSTOMSCRIPT_CUSTOMSCRIPT_HPP
#define CUSTOMSCRIPT_CUSTOMSCRIPT_HPP
bool ready=true;
const char* body = "Ready!";
class CustomObject {

};

class customparser {
public:
    /*
     * Links Static parser objects to script at runtime.
     */
    virtual void on();
    /*
     * Called Once every time your script is run inside of the VM.
     */
    virtual void on_ready(void*);
    /*
     * Once your module is ready, Allows This event to fire once it is available
     */
    virtual void on_module_ready();


};



#endif //CUSTOMSCRIPT_CUSTOMSCRIPT_HPP
