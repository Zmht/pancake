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

    wxMenu *menuVideo = new wxMenu;
    menuVideo->Append(ID_VIDEO_SETTINGS, "&Video Settings\tCTRL-G", "Video Settings");
    menuVideo->Append(ID_CAMERA_SETTINGS, "&Camera", "Camera settings");

    wxMenu *menuHelp = new wxMenu;
    menuHelp->Append(wxID_ABOUT);
    menuHelp->Append(ID_HELP_DOCS, "&Docs", "Read the docs!");

    wxMenuBar *menuBar = new wxMenuBar;
    menuBar->Append( menuFile, "&File" );
    menuBar->Append( menuChat, "&Chat");
    menuBar->Append( menuVideo, "&Video");   
    menuBar->Append( menuHelp, "&Help" );
    SetMenuBar( menuBar );

    wxPanel *panel = new wxPanel(this, wxID_ANY, wxPoint(0, 0), wxSize(300, wxDisplay().GetGeometry().GetHeight()));
    wxBoxSizer *mainLayoutSizer = new wxBoxSizer( wxVERTICAL );
    mainLayoutSizer->Add(
        new wxTextCtrl(panel, wxID_ANY, "IP:PORT", wxDefaultPosition, wxSize(100, 30)),
        0,
        wxALIGN_CENTER
    );
    mainLayoutSizer->Add(
        new wxButton(panel, wxID_ANY, "ADD CONTACT", wxDefaultPosition, wxSize(60, 30)),
        0,
        wxALIGN_CENTER
    );
    SetSizer(mainLayoutSizer);







   /*      wxBoxSizer *topsizer = new wxBoxSizer( wxVERTICAL );
    // create text ctrl with minimal size 100x60
    topsizer->Add(
        new wxTextCtrl( this, -1, "My text.", wxDefaultPosition, wxSize(100,60), wxTE_MULTILINE),
        1,            // make vertically stretchable
        wxEXPAND |    // make horizontally stretchable
        wxALL,        //   and make border all around
        10 );         // set border width to 10
    wxBoxSizer *button_sizer = new wxBoxSizer( wxHORIZONTAL );
    button_sizer->Add(
        new wxButton( this, wxID_OK, "OK" ),
        0,           // make horizontally unstretchable
        wxALL,       // make border all around (implicit top alignment)
        10 );        // set border width to 10
    button_sizer->Add(
        new wxButton( this, wxID_CANCEL, "Cancel" ),
        0,           // make horizontally unstretchable
        wxALL,       // make border all around (implicit top alignment)
        10 );        // set border width to 10
    topsizer->Add(
        button_sizer,
        0,                // make vertically unstretchable
        wxALIGN_CENTER ); // no border and centre horizontally
    SetSizerAndFit(topsizer); // use the sizer for layout and size window
                              // accordingly and prevent it from being resized
                              // to smaller size */

    CreateStatusBar();
    SetStatusText( "Welcome to the future of video calls!" );

}

