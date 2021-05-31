#include <wx/sizer.h>
#include <wx/button.h>
#include <wx/textctrl.h>
#include <wx/frame.h>

#include "ConnectionFrame.h"
#include "cApp.h"

ConnectionFrame::ConnectionFrame(const wxString& title, const wxPoint& pos, const wxSize& size)
        : wxFrame(NULL, wxID_ANY, title, pos, size)
{

   wxBoxSizer* MainSizer = new wxBoxSizer(wxVERTICAL);

   NameField = new wxTextCtrl(this, ID_NAME, "name", wxDefaultPosition, wxSize(200, 30));
   MainSizer->Add(
       NameField,
       0,
       wxEXPAND | wxALL,
       10
   );

    wxBoxSizer* IPSizer = new wxBoxSizer(wxHORIZONTAL);

    IPField = new wxTextCtrl(this, ID_IP_FIELD, "IP:", wxDefaultPosition, wxSize(150, 30));
    IPSizer->Add(
        IPField,
        0,
        wxALL | wxEXPAND,
        5
    );

    ConnectBtn = new wxButton(this, ID_CONNECT_BTN, "Connect", wxDefaultPosition, wxSize(75, 30));
    IPSizer->Add(
        ConnectBtn,
        0,
        wxALL | wxEXPAND,
        5
    );

    MainSizer->Add(
        IPSizer,
        1,
        wxALL | wxEXPAND,
        5
    );

    
    SetSizerAndFit(MainSizer); // use the sizer for layout and size window



};

  