/***************************************************************
 * Name:      MapNetworkDrive_NCPMain.h
 * Purpose:   Defines Application Frame
 * Author:    Connor Michalec (connormichalec@yahoo.com)
 * Created:   2019-09-22
 * Copyright: Connor Michalec ()
 * License:
 **************************************************************/

#ifndef MAPNETWORKDRIVE_NCPMAIN_H
#define MAPNETWORKDRIVE_NCPMAIN_H

#ifndef WX_PRECOMP
    #include <wx/wx.h>
#endif

#include "MapNetworkDrive_NCPApp.h"

class MapNetworkDrive_NCPFrame: public wxFrame
{
    public:
        MapNetworkDrive_NCPFrame(wxFrame *frame, const wxString& title);
        ~MapNetworkDrive_NCPFrame();
    private:
        enum
        {
            idMenuQuit = 1000,
            idMenuAbout
        };
        void OnClose(wxCloseEvent& event);
        void OnQuit(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
        DECLARE_EVENT_TABLE()
};


#endif // MAPNETWORKDRIVE_NCPMAIN_H
