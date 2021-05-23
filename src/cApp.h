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
    ID_CHAT_SETTINGS = 1,
    ID_FILE_OPEN = 2,
    ID_SAVE_AS = 3,
    ID_HELP_DOCS = 4,
    ID_GO_BUTTON = 5
};
