#include <iostream>
#include <ctime>
#include <fstream>
#include <string>
#include <wx/string.h>

#include "MyFrame.h"

namespace futils
{
   using namespace std;

   string g_name;

   // Searches for and replaces a character in a given string
   string ReplaceChar(string str, char ch1, char ch2)
   {
      for (int i = 0; i < str.length(); ++i)
      {
         if (str[i] == ch1)
         {
            str[i] = ch2;
         }
      }
      return str;
   }


   // Returns time with spaces in it using day, month, and day of month
   string TimeHandler() 
   {
      // current date/time based on current system
      time_t now = time(0);
      


      // convert now to string form
      string dt = ctime(&now);
      int len = dt.length() - 10;
      dt.erase(10, len);
      return dt;
   }

   // Adds given string to a file that is named after the day
   void AppendToDateFile(wxString str)
   {
      ofstream DateFile;
      // Opens up the file that is todays date
      DateFile.open("MessageLogs/" + ReplaceChar(TimeHandler(), ' ', '-') + "-" + ReplaceChar(g_name, ' ', '-') + string(".txt"), ios::out | ios::app);
      // Adds the message from the text field to the file and adds a newline
      DateFile << str;
      // Closes the file for epicness
      DateFile.close();
   }

   //Overwritest the file of the current day with nothing so that it is a blank page
   void ClearDateFile()
   {
      // TODO: Make sure that the overwriteDateFile and ClearDateFile methods do not remove the name of the person from the first line of the file.
      ofstream DateFile;
      DateFile.open("MessageLogs/" + ReplaceChar(TimeHandler(), ' ', '-') + "-" + ReplaceChar(g_name, ' ', '-') + string(".txt"), ios::out);
      DateFile << "";
      DateFile.close();
   }

// Overwrites the days file with zeros.
   void OverwriteDateFile()
   {
      ofstream DateFile;
      DateFile.open("MessageLogs/" + ReplaceChar(TimeHandler(), ' ', '-') + "-" + ReplaceChar(g_name, ' ', '-') + string(".txt"), ios::out);
      
      for(int i = 0; i < 1000000; ++i)
      {
         DateFile << "0";
         if (i % 100 == 0)
         {
            DateFile << "\n";
         }
         
      }
      DateFile.close();
   }

// Is essential to the rest of the program working. Sets up the file that the chats will be stored in and defines the g_name variable
   void InitDateFile( wxString name )
   {
      // Converts the name to std::string
      std::string strName = std::string(name);
      // Defines the g_name global variable so that the other methods can use it.
      g_name = strName;
      // Createst the date file file stream
      ofstream DateFile;
      // Opens the right file with some stuff
      //TODO: put this stuff in  a method so that it does not need to be re written every time
      DateFile.open("MessageLogs/" + ReplaceChar(TimeHandler(), ' ', '-') + "-" + ReplaceChar(strName, ' ', '-') + string(".txt"), ios::out | ios::app);
      // Adds the recipients name to the beggining of the date file.
      DateFile << "name: " + name + "\n\n";
   }
}