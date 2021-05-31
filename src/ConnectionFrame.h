#include <wx/wxprec.h>
#include<iostream>
#include<fstream>
#ifndef WX_PRECOMP
    #include <wx/wx.h>
#endif
#pragma once

class ConnectionFrame: public wxFrame
{
public:
    ConnectionFrame(const wxString& title, const wxPoint& pos, const wxSize& size);


private:
    void OnConnect(wxCommandEvent& event);

    wxTextCtrl* NameField;
    wxTextCtrl* IPField;
    wxButton* ConnectBtn;

wxDECLARE_EVENT_TABLE();

};