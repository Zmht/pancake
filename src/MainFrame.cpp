#include "MainFrame.h"
#include "cApp.h"
#include <wx/panel.h>
#include <wx/button.h>
#include <wx/textctrl.h>
#include <wx/sizer.h>
#include <wx/display.h>

MyFrame::MyFrame(const wxString& title, const wxPoint& pos, const wxSize& size)
        : wxFrame(NULL, wxID_ANY, title, pos, size)
{


    wxMenu *menuFile = new wxMenu;
    menuFile->Append(ID_FILE_OPEN, "&Open\tCtrl-O",
                     "Load your contacts!");
    menuFile->Append(ID_SAVE_AS, "&Save\tCTRL-S", "Save your contacts file");
    menuFile->AppendSeparator();
    menuFile->Append(wxID_EXIT);

    wxMenu *menuChat = new wxMenu;
    menuChat->Append(ID_CHAT_SETTINGS, "&Chat Settings", "Chat Settings");

    wxMenu *menuHelp = new wxMenu;
    menuHelp->Append(wxID_ABOUT);
    menuHelp->Append(ID_HELP_DOCS, "&Docs", "Read the docs!");

    wxMenuBar *menuBar = new wxMenuBar;
    menuBar->Append( menuFile, "&File" );
    menuBar->Append( menuChat, "&Chat");
    //menuBar->Append( menuVideo, "&Video");   
    menuBar->Append( menuHelp, "&Help" );
    SetMenuBar( menuBar );

    wxBoxSizer *MainSizer = new wxBoxSizer(wxVERTICAL);

    /** MainSizer->Add (
        new wxTextCtrl(this, wxID_ANY, "Messages:", wxDefaultPosition, wxSize(300, 400), wxTE_MULTILINE), //Makes text Ctrl with minimum size of 100 by 60 this is for previous messages
        1,                  //Vertically Stretchable
        wxEXPAND | wxALL,   //Horizontally stretchable and border all around
        10                  //Border size of 10
    ); */


    Messages = new wxListBox(this, wxID_ANY, wxDefaultPosition, wxSize(300, 400)); //Message to send
    MainSizer->Add (
        Messages,
        1, 
        wxEXPAND | wxALL, 
        5
    );

    wxBoxSizer *MessageSizer = new wxBoxSizer(wxHORIZONTAL); 

    ToSend = new wxTextCtrl(this, ID_TO_SEND, "", wxDefaultPosition, wxSize(300, 30), wxTE_PROCESS_ENTER);
    MessageSizer->Add (
        ToSend,
        0,
        wxEXPAND | wxALL,
        5
    );

    wxButton *GoButton = new wxButton(this, ID_GO_BUTTON, "GO!", wxDefaultPosition, wxSize(50, 30));
    MessageSizer->Add (
       GoButton,
        0,
        wxEXPAND | wxALL,
        5
    );

    MainSizer->Add (
        MessageSizer,
        0,
        wxALIGN_CENTER
    );

    SetSizerAndFit(MainSizer); // use the sizer for layout and size window


    CreateStatusBar();
    SetStatusText( "Welcome to the future of chat!" );



}

  