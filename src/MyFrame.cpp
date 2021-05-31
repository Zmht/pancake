#include "MyFrame.h"
#include "cApp.h"
#include <wx/panel.h>
#include <wx/button.h>
#include <wx/textctrl.h>
#include <wx/sizer.h>
#include <wx/display.h>

MyFrame::MyFrame(const wxString& title, const wxPoint& pos, const wxSize& size)
        : wxFrame(NULL, wxID_ANY, title, pos, size)
{

    // Makes the File section on the menu. Has things like Saving a chat and Opening a chat. Also exiting
    //TODO: Add functionality or delte
    wxMenu *menuFile = new wxMenu;
    menuFile->Append(ID_FILE_OPEN, "&Open\tCtrl-O",
                     "Load your contacts!");
    menuFile->Append(ID_SAVE_AS, "&Save\tCTRL-S", "Save your contacts file");
    menuFile->AppendSeparator();
    menuFile->Append(wxID_EXIT);

    //Makes the chat menu with some goodies like clearing the chat and overwritting your chat as a janky ass way of getting security
    wxMenu *menuChat = new wxMenu;
    menuChat->Append(ID_CHAT_SETTINGS, "&Chat Settings", "Chat Settings");
    menuChat->Append(ID_CLEAR_CHAT, "&Clear", "Clear the chat list.");
    menuChat->Append(ID_OVERWRITE_CHAT, "&Overwrite Chat", "Fills the chat file with 0s"); // Ratatatata I am in the ghetto because this is so sketch.

    // Makes a help menu with nothing useful in it.
    wxMenu *menuHelp = new wxMenu;
    menuHelp->Append(wxID_ABOUT);
    menuHelp->Append(ID_HELP_DOCS, "&Docs", "Read the docs!");

    // The main meny bar.
    wxMenuBar *menuBar = new wxMenuBar;
    menuBar->Append( menuFile, "&File" );
    menuBar->Append( menuChat, "&Chat");
    //menuBar->Append( menuVideo, "&Video");   
    menuBar->Append( menuHelp, "&Help" );
    SetMenuBar( menuBar );

    // This is the sizer that everything goes in and it stacks the things vertically.
    MainSizer = new wxBoxSizer(wxVERTICAL);

    // Messages list contains all of my sent messages in a list for easy viewing.
    Messages = new wxListBox(this, wxID_ANY, wxDefaultPosition, wxSize(300, 400)); //Message to send
    MainSizer->Add (
        Messages,
        1, 
        wxEXPAND | wxALL, 
        5
    );

    // Sizer shared by the ToSend field and the send button
    MessageSizer = new wxBoxSizer(wxHORIZONTAL); 

    ToSend = new wxTextCtrl(this, ID_TO_SEND, "", wxDefaultPosition, wxSize(300, 30), wxTE_PROCESS_ENTER);
    MessageSizer->Add (
        ToSend,
        0,
        wxEXPAND | wxALL,
        5
    );

    GoButton = new wxButton(this, ID_GO_BUTTON, "GO!", wxDefaultPosition, wxSize(50, 30));
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

    // Gives our main sizer full control over our body and code.
    SetSizerAndFit(MainSizer); // use the sizer for layout and size window


    CreateStatusBar();
    SetStatusText( "Welcome to the future of chat!" );



    



}

  