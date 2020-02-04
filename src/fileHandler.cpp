#include "fileHandler.h"

wxString FileHandler::ReadCommandSettingsFile(wxString settingsPath, wxString defaultCommandSettings) {
    wxTextFile file;
    if(wxFile::Exists(settingsPath)) {
        file.Open(settingsPath);
        wxString firstline = file[0]; //get first line of file
        file.Close();
        return firstline;
    }
    else {
        file.Create(settingsPath);
        file.AddLine(defaultCommandSettings);
        file.Write();
        file.Close();
        return defaultCommandSettings;
    }
}

void FileHandler::SetCommandSettingsFile(wxString settingsPath, wxString newSettings) {
    wxTextFile file;
    if(wxFile::Exists(settingsPath)) {
        file.Open(settingsPath);
        file[0] = newSettings; //set first line of file
        file.Write();
        file.Close();
    }
    else {
        file.Create(settingsPath);
        file.AddLine(newSettings);
        file.Write();
        file.Close();
    }
}

FileHandler::FileHandler() { //empty constructor
}
