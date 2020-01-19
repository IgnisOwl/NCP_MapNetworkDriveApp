/***************************************************************
 * Name:      MapNetworkDrive_NCPApp.cpp
 * Purpose:   Code for Application Class
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

#include "MapNetworkDrive_NCPApp.h"
#include "MapNetworkDrive_NCPMain.h"

IMPLEMENT_APP(MapNetworkDrive_NCPApp);

bool MapNetworkDrive_NCPApp::OnInit()
{
    MapNetworkDrive_NCPFrame* frame = new MapNetworkDrive_NCPFrame(0L, _("wxWidgets Application Template"));
    frame->SetIcon(wxICON(aaaa)); // To Set App Icon
    frame->Show();
    
    return true;
}
