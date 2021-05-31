#include "MyFrame.h"
#include <wx/wxprec.h>
#ifndef WX_PRECOMP
    #include <wx/wx.h>
#endif
#pragma once

class MyApp: public wxApp
{
public:
    virtual bool OnInit();
};


enum
{
    ID_CHAT_SETTINGS = 1,
    ID_FILE_OPEN = 2,
    ID_SAVE_AS = 3,
    ID_HELP_DOCS = 4,
    ID_GO_BUTTON = 5,
    ID_TO_SEND = 6,
    ID_CLEAR_CHAT = 7,
    ID_OVERWRITE_CHAT = 8,
    ID_NAME = 9,
    ID_IP_FIELD = 10,
    ID_CONNECT_BTN = 11
};
