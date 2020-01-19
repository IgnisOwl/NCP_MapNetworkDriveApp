#include "wx/wx.h"
#include "commandHandler.h"
#include "fileHandler.h"
#include <stdio.h>
#include "iostream"
class MainApp : public wxApp {
public:
    bool OnInit();
};

class MainFrame : public wxFrame {
public:
    CommandHandler cmdHandler;
    FileHandler fileHandler;
    wxString usernameText;
    wxString passwordText;
    wxString commandSettings;
    wxString settingsPath = wxT("NCP_MNDSettings.txt");
    wxString defaultCommandSettings = wxT("net use q: \\\\nscollege-srv01.instr.cps.k12.il.us\\student\\<USERNAME> /user:instr.cps.k12.il.us\\<USERNAME> <PASSWORD> & explorer q: & timeout 3");

    MainFrame(const wxString& title);

    void OnQuit(wxCommandEvent& event);
    void OnAbout(wxCommandEvent& event);
    void OnInfo(wxCommandEvent& event);
    void OnContinueButton(wxCommandEvent& event);
    void OnUsernameText(wxCommandEvent& event);
    void OnPasswordText(wxCommandEvent& event);
    void OnSettings(wxCommandEvent& event);
private:
    DECLARE_EVENT_TABLE()
};

class SettingsDialog : public wxDialog {
public:
    FileHandler fileHandler;
    wxString settingsText;
    SettingsDialog(wxString currentCommandState, wxString settingsPath);
    void OnText(wxCommandEvent& event);
    void OnSave(wxCommandEvent& event);
    wxString commandSettings;
    wxString settingsPath;
};
