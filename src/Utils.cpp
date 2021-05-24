#include <iostream>
#include <ctime>
#include <string>

using namespace std;

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

string TimeHandler() 
{
   // current date/time based on current system
   time_t now = time(0);
   


   // convert now to string form
   string dt = ctime(&now);
   int len = dt.length() - 10;
   dt.erase(10, len);
   dt = ReplaceChar(dt, ' ', '-');
   return dt;
}
