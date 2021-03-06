#include "main.h"
//By Connor Michalec

//https://ptgmedia.pearsoncmg.com/images/0131473816/downloads/0131473816_book.pdf <- what i used
//http://zetcode.com/gui/wxwidgets/widgets/ <- also what i used



enum ids {
    MainApp_INFO,
    MainApp_ABOUT,
    MainApp_CONTINUEBUTTON,
    MainApp_USERNAMETEXT,
    MainApp_PASSWORDTEXT,
    MainApp_SETTINGS,
    SettingsDialog_TEXT,
    SettingsDialog_SAVE
};

IMPLEMENT_APP(MainApp)

BEGIN_EVENT_TABLE(MainFrame, wxFrame)
    EVT_MENU(wxID_EXIT,  MainFrame::OnQuit)
    EVT_MENU(MainApp_INFO,  MainFrame::OnInfo)
    EVT_MENU(MainApp_ABOUT,  MainFrame::OnAbout)
    EVT_MENU(MainApp_SETTINGS,  MainFrame::OnSettings)
    EVT_BUTTON(MainApp_CONTINUEBUTTON,  MainFrame::OnContinueButton)
    EVT_TEXT(MainApp_USERNAMETEXT, MainFrame::OnUsernameText)
    EVT_TEXT(MainApp_PASSWORDTEXT, MainFrame::OnPasswordText)
    EVT_TEXT_ENTER(MainApp_USERNAMETEXT, MainFrame::OnContinueButton) //these events route the enter pressed on the text box to OnContinueButton so it will automatically continue wen u push enter
    EVT_TEXT_ENTER(MainApp_PASSWORDTEXT, MainFrame::OnContinueButton) //
END_EVENT_TABLE()

bool MainApp::OnInit() {
    MainFrame *frame = new MainFrame(wxT("NCP - Map Network Drive"));
    frame->Show(true);

    return true;
}

void MainFrame::OnQuit(wxCommandEvent& event) {
    Close();
}

void MainFrame::OnInfo(wxCommandEvent& event) {
    wxMessageBox("This program will add a network drive to your filesystem in which you can upload folders and files. It should save these files and folders in the drive until the next time you log on.", wxT("Info"),wxOK | wxICON_INFORMATION, this);
}

void MainFrame::OnAbout(wxCommandEvent& event) {
    wxMessageBox("Program made by Connor Michalec", wxT("About"),wxOK | wxICON_INFORMATION, this);
}

void MainFrame::OnContinueButton(wxCommandEvent &event) {
    string parsedCommand = cmdHandler.parseCommandForPlaceholder(fileHandler.ReadCommandSettingsFile(settingsPath, defaultCommandSettings),usernameText, passwordText); //parsed command

    //easter egg possibilities:
    string eu = usernameText.ToStdString();
    string ep = passwordText.ToStdString();
    string ec = parsedCommand;
    //convert text to upper for easter egg text
    for(unsigned int i = 0; i < eu.length(); i++) {
        eu[i] = toupper(eu[i]);
    }
    for(unsigned int i = 0; i < ep.length(); i++) {
        ep[i] = toupper(ep[i]);
    }
    for(unsigned int i = 0; i < ec.length(); i++) {
        ec[i] = toupper(ec[i]);
    }

    //if easter egg is seen in an entry
    if(eu == "EASTER EGG" || eu == "RICK" || eu == "ADMIN" || eu == "HACKER" || eu == "HACK" || ep == "HACK" || ep == "HACKER" || ep == "ADMIN" || ep == "RICK" || ep == "EASTER EGG") {
        wxMessageBox("https://pastebin.com/pjGxE1nT", wxT("Easter egg"),wxOK | wxICON_INFORMATION, this); //show the easter egg dialog
    }



    cmdHandler.executeCommand(parsedCommand);
    Close();
}

void MainFrame::OnUsernameText(wxCommandEvent &event) {
    usernameText = event.GetString();

}

void MainFrame::OnPasswordText(wxCommandEvent &event) {
    passwordText = event.GetString();
}

void MainFrame::OnSettings(wxCommandEvent &event) {
    SettingsDialog *settingsDialog = new SettingsDialog(fileHandler.ReadCommandSettingsFile(settingsPath, defaultCommandSettings), settingsPath);
    settingsDialog->Show(true);
}

MainFrame::MainFrame(const wxString& title) : wxFrame(NULL, wxID_ANY, title, wxPoint(100, 100), wxDefaultSize, wxMINIMIZE_BOX | wxSYSTEM_MENU | wxCAPTION | wxCLOSE_BOX) { //all of these flags r here for window customization(don't want the resize border or maximize box) https://docs.wxwidgets.org/trunk/classwx_frame.html

    fileHandler = FileHandler();
    cmdHandler = CommandHandler();

    wxMenuBar* menubar = new wxMenuBar;
    wxMenu* help = new wxMenu;
    wxMenu* settings = new wxMenu;
    help->Append(MainApp_INFO, wxT("&Help"), wxT("Help and information"));
    help->Append(MainApp_ABOUT, wxT("&About"), wxT("About this program"));
    settings->Append(MainApp_SETTINGS, wxT("&Settings"), wxT("Change program settings"));

    menubar->Append(help, wxT("&More"));
    menubar->Append(settings, wxT("&Settings"));
    SetMenuBar(menubar);

    CreateStatusBar(1);
    SetStatusText(wxT(""));

    wxPanel* panel = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxSize(350,250));

    wxStaticText *usernameBoxLabel = new wxStaticText(panel, wxID_ANY, wxT("Username: "), wxPoint(30,55));
    wxTextCtrl *usernameBox = new wxTextCtrl(panel, MainApp_USERNAMETEXT, wxT(""), wxPoint(100,50), wxSize(150,30), wxTE_PROCESS_ENTER);

    wxStaticText *passwordBoxLabel = new wxStaticText(panel, wxID_ANY, wxT("Password: "), wxPoint(30,95));
    wxTextCtrl *passwordBox = new wxTextCtrl(panel, MainApp_PASSWORDTEXT, wxT(""), wxPoint(100,90), wxSize(150,30), wxTE_PROCESS_ENTER | wxTE_PASSWORD);
    wxButton *continueButton = new wxButton(panel, MainApp_CONTINUEBUTTON, wxT("Continue"), wxPoint(100,130), wxSize(150,50));


    panel->Fit();
    this->Fit();
    this->SetIcon(wxIcon(wxT("MainIcon")));

}


//settings dialog:
//http://zetcode.com/gui/wxwidgets/dialogs/
SettingsDialog::SettingsDialog(wxString currentCommandState, wxString pathToSettings) : wxDialog(NULL, wxID_ANY, wxT("Settings"), wxDefaultPosition, wxSize(250, 230))
{
    fileHandler = FileHandler();

    settingsPath = pathToSettings;

    settingsText = currentCommandState; //set the settingsText to what the command currently, because if its blank(if user doesnt type at all because only updates after user types into box), it will save the file as blank.

    wxPanel *panel = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxSize(600,60));
    wxStaticText *settingsBoxLabel = new wxStaticText(panel, wxID_ANY, wxT("Command: "), wxPoint(10,20));
    wxTextCtrl *settingsBox = new wxTextCtrl(panel, SettingsDialog_TEXT, currentCommandState, wxPoint(80,15), wxSize(400,30), wxTE_PROCESS_ENTER);
    wxButton *saveButton = new wxButton(panel, SettingsDialog_SAVE, wxT("Save"), wxPoint(500,15), wxSize(60,30));

    panel->Fit();
    this->Fit();

    //this one is using dynamic event handlers instead of the macro like the frame is
    Connect(SettingsDialog_SAVE, wxEVT_BUTTON, wxCommandEventHandler(SettingsDialog::OnSave));
    Connect(SettingsDialog_TEXT, wxEVT_TEXT_ENTER, wxCommandEventHandler(SettingsDialog::OnSave));
    Connect(SettingsDialog_TEXT, wxEVT_TEXT, wxCommandEventHandler(SettingsDialog::OnText));



    ShowModal();//this one waits for the user to close the window
    Destroy(); //after he closes the window destroy the dialog process
}

void SettingsDialog::OnSave(wxCommandEvent &event) {
    fileHandler.SetCommandSettingsFile(settingsPath, settingsText);
    Destroy(); //close dialog
}

void SettingsDialog::OnText(wxCommandEvent &event) {
    settingsText = event.GetString();
}

DECLARE_APP(MainApp)
