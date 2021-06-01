#include <wx/filedlg.h>
#include <wx/utils.h>
#include <wx/wfstream.h>
#include <wx/datetime.h>
#include <fstream>
#include <iostream>

#include "futils.h"
#include "ConnectionFrame.h"
#include "MyFrame.h"
#include "cApp.h"


bool contentSaved = true;


void MyFrame::OnExit(wxCommandEvent& event)
{
    // Closes the application
    Close( true );
}
void MyFrame::OnAbout(wxCommandEvent& event)
{
    // NGL I hope it is!
    wxMessageBox( "This is the start of something BIG!",
                  "About CppCall", wxOK | wxICON_INFORMATION );
}
void MyFrame::OnHello(wxCommandEvent& event)
{
    // 
    wxLogMessage("Hello world from wxWidgets!");
}

void MyFrame::ChatSettings(wxCommandEvent& event)
{
    // LMAO there are no settings boi!
    wxLogMessage("Hello this is the chat settings lmao you just got pranked noob. There are no settings because I dont care! HAHA");
}

void MyFrame::OnOpen(wxCommandEvent& event)
{
    if (contentSaved != true)
    {
        if (wxMessageBox(_("Current setup is not saved! Are you sure that you want to proceed?"), _("Please Confirm"),
            wxICON_QUESTION | wxYES_NO, this) == wxNO )
            {
                return;
            }
    }
    wxFileDialog openFileDialog(this, ("Open a configuration file!"), "", "", "Zach Files (*.zach)|.zach", wxFD_OPEN|wxFD_FILE_MUST_EXIST);


    if (openFileDialog.ShowModal() == wxID_CANCEL)
        return;     // the user changed idea...
    
    // proceed loading the file chosen by the user;
    // this can be done with e.g. wxWidgets input streams:
    wxFileInputStream input_stream(openFileDialog.GetPath());
    if (!input_stream.IsOk())
    {
        wxLogError("Cannot open file '%s'.", openFileDialog.GetPath());
        return;
    }
}

void MyFrame::OnSave(wxCommandEvent& WXUNUSED(event))
{
    wxFileDialog 
    saveFileDialog(this, _("Save as a zach file"), "", "",
                       "ZACH files (*.zach)|*.zach", wxFD_SAVE|wxFD_OVERWRITE_PROMPT);
    if (saveFileDialog.ShowModal() == wxID_CANCEL)
    {
        contentSaved = false;
        return;
    }
    
    // save the current contents in the file;
    // this can be done with e.g. wxWidgets output streams:
    wxFileOutputStream output_stream(saveFileDialog.GetPath());
    contentSaved = true;
    if (!output_stream.IsOk())
    {
        wxLogError("Cannot save current contents in file '%s'.", saveFileDialog.GetPath());
        contentSaved = false;
        return;
    }
}

void MyFrame::OpenDocs(wxCommandEvent& event)
{
    // Opens up my website for now, one day it will open the doxygen docs.
    wxLaunchDefaultBrowser("https:/zmht25.ddns.net");
}


void MyFrame::OnSend(wxCommandEvent& event)
{
    futils::AppendToDateFile(ToSend->GetValue() + std::string("\n"));
    // Adds the message from the text field to the file
    MyFrame::Messages->AppendString(ToSend->GetValue( ));
    // Clears the text field
    ToSend->ChangeValue( "" );


}

void MyFrame::ClearChat(wxCommandEvent& event)
{

    futils::ClearDateFile();
    Messages->Clear();
}

void MyFrame::OverwriteChat(wxCommandEvent& event)
{
    futils::OverwriteDateFile();
}

void ConnectionFrame::OnConnect(wxCommandEvent& event)
{
    futils::InitDateFile(NameField->GetValue());
    ConnectionFrame::Close();   
    // TODO: Rename smaller frame to something that makes sense.
}


