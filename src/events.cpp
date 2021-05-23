#include "MainFrame.h"
#include "cApp.h"
#include <wx/filedlg.h>
#include <wx/utils.h>
#include <wx/wfstream.h>
#include <wx/datetime.h>
#include <fstream>
#include <iostream>

bool contentSaved = true;

void MyFrame::OnExit(wxCommandEvent& event)
{
    Close( true );
}
void MyFrame::OnAbout(wxCommandEvent& event)
{
    wxMessageBox( "This is the start of something BIG!",
                  "About CppCall", wxOK | wxICON_INFORMATION );
}
void MyFrame::OnHello(wxCommandEvent& event)
{
    wxLogMessage("Hello world from wxWidgets!");
}

void MyFrame::ChatSettings(wxCommandEvent& event)
{
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
    wxLaunchDefaultBrowser("https:/zmht25.ddns.net");
}


void MyFrame::OnButtonClicked(wxCommandEvent& event)
{
    MyFrame::MessagesFile.open("MessageLogs/Log.txt", std::ios::out | std::ios::app);
    MyFrame::Messages->AppendString(ToSend->GetValue());
    MyFrame::MessagesFile << ToSend->GetValue() + "\n";
    MyFrame::MessagesFile.close();
    ToSend->ChangeValue( "" );
}


