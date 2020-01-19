/***************************************************************
 * Name:      MapNetworkDrive_NCPMain.cpp
 * Purpose:   Code for Application Frame
 * Author:    Connor Michalec (connormichalec@yahoo.com)
 * Created:   2019-09-22
 * Copyright: Connor Michalec ()
 * License:
 **************************************************************/

#ifdef WX_PRECOMP
#include "wx_pch.h"
#endif

#ifdef __BORLANDC__
#pragma hdrstop
#endif //__BORLANDC__

#include "MapNetworkDrive_NCPMain.h"

//helper functions
enum wxbuildinfoformat {
    short_f, long_f };

wxString wxbuildinfo(wxbuildinfoformat format)
{
    wxString wxbuild(wxVERSION_STRING);

    if (format == long_f )
    {
#if defined(__WXMSW__)
        wxbuild << _T("-Windows");
#elif defined(__WXMAC__)
        wxbuild << _T("-Mac");
#elif defined(__UNIX__)
        wxbuild << _T("-Linux");
#endif

#if wxUSE_UNICODE
        wxbuild << _T("-Unicode build");
#else
        wxbuild << _T("-ANSI build");
#endif // wxUSE_UNICODE
    }

    return wxbuild;
}

BEGIN_EVENT_TABLE(MapNetworkDrive_NCPFrame, wxFrame)
    EVT_CLOSE(MapNetworkDrive_NCPFrame::OnClose)
    EVT_MENU(idMenuQuit, MapNetworkDrive_NCPFrame::OnQuit)
    EVT_MENU(idMenuAbout, MapNetworkDrive_NCPFrame::OnAbout)
END_EVENT_TABLE()

MapNetworkDrive_NCPFrame::MapNetworkDrive_NCPFrame(wxFrame *frame, const wxString& title)
    : wxFrame(frame, -1, title)
{
#if wxUSE_MENUS
    // create a menu bar
    wxMenuBar* mbar = new wxMenuBar();
    wxMenu* fileMenu = new wxMenu(_T(""));
    fileMenu->Append(idMenuQuit, _("&Quit\tAlt-F4"), _("Quit the application"));
    mbar->Append(fileMenu, _("&File"));

    wxMenu* helpMenu = new wxMenu(_T(""));
    helpMenu->Append(idMenuAbout, _("&About\tF1"), _("Show info about this application"));
    mbar->Append(helpMenu, _("&Help"));

    SetMenuBar(mbar);
#endif // wxUSE_MENUS

#if wxUSE_STATUSBAR
    // create a status bar with some information about the used wxWidgets version
    CreateStatusBar(2);
    SetStatusText(_("Hello Code::Blocks user!"),0);
    SetStatusText(wxbuildinfo(short_f), 1);
#endif // wxUSE_STATUSBAR

}


MapNetworkDrive_NCPFrame::~MapNetworkDrive_NCPFrame()
{
}

void MapNetworkDrive_NCPFrame::OnClose(wxCloseEvent &event)
{
    Destroy();
}

void MapNetworkDrive_NCPFrame::OnQuit(wxCommandEvent &event)
{
    Destroy();
}

void MapNetworkDrive_NCPFrame::OnAbout(wxCommandEvent &event)
{
    wxString msg = wxbuildinfo(long_f);
    wxMessageBox(msg, _("Welcome to..."));
}
