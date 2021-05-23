// wxWidgets "Hello world" Program
// For compilers that support precompilation, includes "wx/wx.h".
#include "cApp.h"
#include "MainFrame.h"

bool MyApp::OnInit()
{
    //MyFrame *frame = new MyFrame( "Hello World", wxPoint(50, 50), wxGetDisplaySize());
    MyFrame *SmallerFrame = new MyFrame("")
    frame->Show( true );

    return true;
}

wxBEGIN_EVENT_TABLE(MyFrame, wxFrame)
    EVT_MENU(ID_Hello,   MyFrame::OnHello)
    EVT_MENU(wxID_EXIT,  MyFrame::OnExit)
    EVT_MENU(wxID_ABOUT, MyFrame::OnAbout)
    EVT_MENU(ID_CHAT_SETTINGS, MyFrame::ChatSettings)
    EVT_MENU(ID_CHAT_SETTINGS, MyFrame::ChatSettings)
    EVT_MENU(ID_FILE_OPEN, MyFrame::OnOpen)
    EVT_MENU(ID_SAVE_AS, MyFrame::OnSave)
    EVT_MENU(ID_HELP_DOCS, MyFrame::OpenDocs)
wxEND_EVENT_TABLE()


wxIMPLEMENT_APP(MyApp);




