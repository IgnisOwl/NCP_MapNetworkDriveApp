#ifndef COMMANDHANDLER_H
#define COMMANDHANDLER_H

#include "wx/wx.h"
#include <stdio.h>

using namespace std;

class CommandHandler {
    public:
        CommandHandler();
        string parseCommandForPlaceholder(wxString cmd, wxString username, wxString password);
        string stringReplace(string fullStr, string target, string replaceWith);
        void executeCommand(string command);
};

#endif // COMMANDHANDLER_H
