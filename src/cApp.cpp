// wxWidgets "Hello world" Program
// For compilers that support precompilation, includes "wx/wx.h".
#include "cApp.h"
#include "MyFrame.h"
#include "ConnectionFrame.h"

bool MyApp::OnInit()
{
    MyFrame *SmallerFrame = new MyFrame("Pancake", wxPoint(50, 50), wxSize(400, 600));
    SmallerFrame->Show( true );

    ConnectionFrame *ConnectFrame = new ConnectionFrame("Connection", wxPoint(50, 50), wxSize(200, 500));
    ConnectFrame->Show( true );


    return true;
}

wxBEGIN_EVENT_TABLE(MyFrame, wxFrame)
    EVT_MENU(wxID_EXIT,  MyFrame::OnExit)
    EVT_MENU(wxID_ABOUT, MyFrame::OnAbout)
    EVT_MENU(ID_CHAT_SETTINGS, MyFrame::ChatSettings)
    EVT_MENU(ID_CHAT_SETTINGS, MyFrame::ChatSettings)
    EVT_MENU(ID_FILE_OPEN, MyFrame::OnOpen)
    EVT_MENU(ID_SAVE_AS, MyFrame::OnSave)
    EVT_MENU(ID_HELP_DOCS, MyFrame::OpenDocs)
    EVT_MENU(ID_CLEAR_CHAT, MyFrame::ClearChat)
    EVT_MENU(ID_OVERWRITE_CHAT, MyFrame::OverwriteChat)

    EVT_BUTTON(ID_GO_BUTTON, MyFrame::OnSend)
    EVT_TEXT_ENTER(ID_TO_SEND, MyFrame::OnSend)
wxEND_EVENT_TABLE()



wxBEGIN_EVENT_TABLE(ConnectionFrame, wxFrame)
    EVT_BUTTON(ID_CONNECT_BTN, ConnectionFrame::OnConnect)
wxEND_EVENT_TABLE()


wxIMPLEMENT_APP(MyApp);




