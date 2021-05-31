#pragma once

#include <string>
#include <wx/string.h>
#include <fstream>


namespace futils
{
void InitDateFile(wxString);
std::string TimeHandler();
std::string ReplaceChar(std::string str, char ch1, char ch2);
 void AppendToDateFile(wxString str);
void ClearDateFile();
void OverwriteDateFile();
wxString GetFileName( );
}
