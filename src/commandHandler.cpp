#include "commandHandler.h"

using namespace std;

CommandHandler::CommandHandler() {

}

string CommandHandler::parseCommandForPlaceholder(wxString cmd, wxString username, wxString password) {
    string usernamePlaceholder = string("<USERNAME>");
    string passwordPlaceholder = string("<PASSWORD>");

    string stdUsername = string(username.mb_str());
    string stdCmd = string(cmd.mb_str());
    string stdPassword = string(password.mb_str());


    stdCmd = stringReplace(stdCmd, usernamePlaceholder, stdUsername);
    stdCmd = stringReplace(stdCmd, passwordPlaceholder, stdPassword);
    return stdCmd;
}


//https://stackoverflow.com/questions/3418231/replace-part-of-a-string-with-another-string
string CommandHandler::stringReplace(string fullStr, string target, string replaceWith) {
    size_t start_pos = 0;
    while((start_pos = fullStr.find(target, start_pos)) != string::npos) {
        fullStr.replace(start_pos, target.length(), replaceWith);
        start_pos+= replaceWith.length();
    }
    return fullStr;
}

void CommandHandler::executeCommand(string command) {
     char charCommand[command.length()+1]; //these 2 convert the string to char
     strcpy(charCommand, command.c_str()); //
     system(charCommand); //not the most secure way to execute commands, and is not cross platform, but it works
}
