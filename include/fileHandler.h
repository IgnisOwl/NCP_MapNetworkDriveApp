#ifndef FILEHANDLER_H
#define FILEHANDLER_H
#include "wx/wx.h"
#include "wx/file.h"
#include "wx/textfile.h"
#include "stdio.h"

using namespace std;

class FileHandler
{
    public:
        FileHandler();
        wxString ReadCommandSettingsFile(wxString settingsPath, wxString defaultCommandSettings);
        void SetCommandSettingsFile(wxString settingsPath, wxString newSettings);
};

#endif // FILEHANDLER_H
