#include "MainFrame.h"
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
    ID_Hello = 1,
    ID_CHAT_SETTINGS = 2,
    ID_NEW_CHAT = 3,
    ID_IP_BOX = 4,
    ID_TEXT_ENTER = 5,
    ID_FILE_OPEN = 6,
    ID_SAVE_AS = 7,
    ID_VIDEO_SETTINGS = 8,
    ID_CAMERA_SETTINGS = 9,
    ID_HELP_DOCS = 10,
    ID_CTRL_PANEL = 11
};
