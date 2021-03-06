#include <wx/wxprec.h>
#include<iostream>
#include<fstream>
#ifndef WX_PRECOMP
    #include <wx/wx.h>
#endif
#pragma once




class MyFrame: public wxFrame
{
public:
    MyFrame(const wxString& title, const wxPoint& pos, const wxSize& size);
    wxListBox* Messages;
    wxTextCtrl *ToSend;
    wxBoxSizer *MessageSizer;
    wxBoxSizer *MainSizer;
    wxButton *GoButton;
    
private:
    void OnHello(wxCommandEvent& event);
    void OnExit(wxCommandEvent& event);
    void OnAbout(wxCommandEvent& event);
    void ChatSettings(wxCommandEvent& event);
    void OnOpen(wxCommandEvent& event);
    void OnSave(wxCommandEvent& WXUNUSED(event));
    void OpenDocs(wxCommandEvent& event);
    void OnSend(wxCommandEvent& event);
    void ClearChat(wxCommandEvent& event);
    void OverwriteChat(wxCommandEvent& event);

    void SetToSendFocus();

    
    


    wxDECLARE_EVENT_TABLE();
};