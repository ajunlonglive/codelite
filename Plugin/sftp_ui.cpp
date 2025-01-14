//////////////////////////////////////////////////////////////////////
// This file was auto-generated by codelite's wxCrafter Plugin
// wxCrafter project file: sftp_ui.wxcp
// Do not modify this file by hand!
//////////////////////////////////////////////////////////////////////

#include "sftp_ui.h"

#include "codelite_exports.h"

// Declare the bitmap loading function
extern void wxCE8CInitBitmapResources();

static bool bBitmapLoaded = false;

SSHAccountManagerDlgBase::SSHAccountManagerDlgBase(wxWindow* parent, wxWindowID id, const wxString& title,
                                                   const wxPoint& pos, const wxSize& size, long style)
    : wxDialog(parent, id, title, pos, size, style)
{
    if(!bBitmapLoaded) {
        // We need to initialise the default bitmap handler
        wxXmlResource::Get()->AddHandler(new wxBitmapXmlHandler);
        wxCE8CInitBitmapResources();
        bBitmapLoaded = true;
    }

    wxBoxSizer* boxSizer2 = new wxBoxSizer(wxVERTICAL);
    this->SetSizer(boxSizer2);

    wxBoxSizer* boxSizer10 = new wxBoxSizer(wxHORIZONTAL);

    boxSizer2->Add(boxSizer10, 1, wxALL | wxEXPAND, WXC_FROM_DIP(5));

    m_dvListCtrl = new clThemedListCtrl(this, wxID_ANY, wxDefaultPosition, wxDLG_UNIT(this, wxSize(200, -1)),
                                        wxDV_ROW_LINES | wxDV_SINGLE);

    boxSizer10->Add(m_dvListCtrl, 1, wxALL | wxEXPAND, WXC_FROM_DIP(5));

    m_dvListCtrl->AppendTextColumn(_("Account"), wxDATAVIEW_CELL_INERT, WXC_FROM_DIP(-2), wxALIGN_LEFT,
                                   wxDATAVIEW_COL_RESIZABLE);
    m_dvListCtrl->AppendTextColumn(_("Host"), wxDATAVIEW_CELL_INERT, WXC_FROM_DIP(-2), wxALIGN_LEFT,
                                   wxDATAVIEW_COL_RESIZABLE);
    m_dvListCtrl->AppendTextColumn(_("User"), wxDATAVIEW_CELL_INERT, WXC_FROM_DIP(-2), wxALIGN_LEFT,
                                   wxDATAVIEW_COL_RESIZABLE);
    wxBoxSizer* boxSizer15 = new wxBoxSizer(wxVERTICAL);

    boxSizer10->Add(boxSizer15, 0, wxEXPAND, WXC_FROM_DIP(5));

    m_buttonNew = new wxButton(this, wxID_ADD, _("&Add"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);
    m_buttonNew->SetToolTip(_("Add new account"));

    boxSizer15->Add(m_buttonNew, 0, wxALL | wxEXPAND, WXC_FROM_DIP(5));

    m_buttonDelete =
        new wxButton(this, wxID_DELETE, _("&Delete"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);
    m_buttonDelete->SetToolTip(_("Delete the selected accounts"));

    boxSizer15->Add(m_buttonDelete, 0, wxALL | wxEXPAND, WXC_FROM_DIP(5));

    m_buttonEdit = new wxButton(this, wxID_EDIT, _("&Edit"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);
    m_buttonEdit->SetToolTip(_("Edit the selected account"));

    boxSizer15->Add(m_buttonEdit, 0, wxALL | wxEXPAND, WXC_FROM_DIP(5));

    wxBoxSizer* boxSizer4 = new wxBoxSizer(wxHORIZONTAL);

    boxSizer2->Add(boxSizer4, 0, wxALL | wxALIGN_CENTER_HORIZONTAL, WXC_FROM_DIP(5));

    m_button6 = new wxButton(this, wxID_OK, _("&OK"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);
    m_button6->SetDefault();

    boxSizer4->Add(m_button6, 0, wxALL, WXC_FROM_DIP(5));

    m_button8 = new wxButton(this, wxID_CANCEL, _("&Cancel"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);

    boxSizer4->Add(m_button8, 0, wxALL, WXC_FROM_DIP(5));

    SetName(wxT("SSHAccountManagerDlgBase"));
    SetSize(wxDLG_UNIT(this, wxSize(-1, -1)));
    if(GetSizer()) {
        GetSizer()->Fit(this);
    }
    if(GetParent()) {
        CentreOnParent(wxBOTH);
    } else {
        CentreOnScreen(wxBOTH);
    }
#if wxVERSION_NUMBER >= 2900
    if(!wxPersistenceManager::Get().Find(this)) {
        wxPersistenceManager::Get().RegisterAndRestore(this);
    } else {
        wxPersistenceManager::Get().Restore(this);
    }
#endif
    // Connect events
    m_dvListCtrl->Connect(wxEVT_COMMAND_DATAVIEW_ITEM_ACTIVATED,
                          wxDataViewEventHandler(SSHAccountManagerDlgBase::OnItemActivated), NULL, this);
    m_buttonNew->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(SSHAccountManagerDlgBase::OnAddAccount),
                         NULL, this);
    m_buttonDelete->Connect(wxEVT_COMMAND_BUTTON_CLICKED,
                            wxCommandEventHandler(SSHAccountManagerDlgBase::OnDeleteAccount), NULL, this);
    m_buttonDelete->Connect(wxEVT_UPDATE_UI, wxUpdateUIEventHandler(SSHAccountManagerDlgBase::OnDeleteAccountUI), NULL,
                            this);
    m_buttonEdit->Connect(wxEVT_UPDATE_UI, wxUpdateUIEventHandler(SSHAccountManagerDlgBase::OnEditAccountUI), NULL,
                          this);
    m_buttonEdit->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(SSHAccountManagerDlgBase::OnEditAccount),
                          NULL, this);
    m_button6->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(SSHAccountManagerDlgBase::OnOK), NULL, this);
}

SSHAccountManagerDlgBase::~SSHAccountManagerDlgBase()
{
    m_dvListCtrl->Disconnect(wxEVT_COMMAND_DATAVIEW_ITEM_ACTIVATED,
                             wxDataViewEventHandler(SSHAccountManagerDlgBase::OnItemActivated), NULL, this);
    m_buttonNew->Disconnect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(SSHAccountManagerDlgBase::OnAddAccount),
                            NULL, this);
    m_buttonDelete->Disconnect(wxEVT_COMMAND_BUTTON_CLICKED,
                               wxCommandEventHandler(SSHAccountManagerDlgBase::OnDeleteAccount), NULL, this);
    m_buttonDelete->Disconnect(wxEVT_UPDATE_UI, wxUpdateUIEventHandler(SSHAccountManagerDlgBase::OnDeleteAccountUI),
                               NULL, this);
    m_buttonEdit->Disconnect(wxEVT_UPDATE_UI, wxUpdateUIEventHandler(SSHAccountManagerDlgBase::OnEditAccountUI), NULL,
                             this);
    m_buttonEdit->Disconnect(wxEVT_COMMAND_BUTTON_CLICKED,
                             wxCommandEventHandler(SSHAccountManagerDlgBase::OnEditAccount), NULL, this);
    m_button6->Disconnect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(SSHAccountManagerDlgBase::OnOK), NULL,
                          this);
}

AddSSHAcountDlgBase::AddSSHAcountDlgBase(wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos,
                                         const wxSize& size, long style)
    : wxDialog(parent, id, title, pos, size, style)
{
    if(!bBitmapLoaded) {
        // We need to initialise the default bitmap handler
        wxXmlResource::Get()->AddHandler(new wxBitmapXmlHandler);
        wxCE8CInitBitmapResources();
        bBitmapLoaded = true;
    }

    wxBoxSizer* boxSizer23 = new wxBoxSizer(wxVERTICAL);
    this->SetSizer(boxSizer23);

    m_infobar = new wxInfoBar(this, wxID_ANY);
    m_infobar->SetSize(wxDLG_UNIT(this, wxSize(-1, -1)));

    boxSizer23->Add(m_infobar, 0, wxEXPAND, WXC_FROM_DIP(5));

    wxFlexGridSizer* flexGridSizer31 = new wxFlexGridSizer(0, 2, 0, 0);
    flexGridSizer31->SetFlexibleDirection(wxBOTH);
    flexGridSizer31->SetNonFlexibleGrowMode(wxFLEX_GROWMODE_SPECIFIED);
    flexGridSizer31->AddGrowableCol(1);

    boxSizer23->Add(flexGridSizer31, 0, wxALL | wxEXPAND, WXC_FROM_DIP(5));

    m_staticText98 =
        new wxStaticText(this, wxID_ANY, _("Account Name:"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);
    m_staticText98->SetToolTip(_("Give this account a unique name"));

    flexGridSizer31->Add(m_staticText98, 0, wxALL | wxALIGN_RIGHT | wxALIGN_CENTER_VERTICAL, WXC_FROM_DIP(5));

    m_textCtrlName = new wxTextCtrl(this, wxID_ANY, wxT(""), wxDefaultPosition, wxDLG_UNIT(this, wxSize(250, -1)), 0);
    m_textCtrlName->SetToolTip(_("Give this account a unique name"));
    m_textCtrlName->SetFocus();
#if wxVERSION_NUMBER >= 3000
    m_textCtrlName->SetHint(wxT(""));
#endif

    flexGridSizer31->Add(m_textCtrlName, 0, wxALL | wxEXPAND, WXC_FROM_DIP(5));

    m_staticHostIp =
        new wxStaticText(this, wxID_ANY, _("Host / IP:"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);

    flexGridSizer31->Add(m_staticHostIp, 0, wxALL | wxALIGN_RIGHT | wxALIGN_CENTER_VERTICAL, WXC_FROM_DIP(5));

    m_textCtrlHost = new wxTextCtrl(this, wxID_ANY, wxT(""), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);
    m_textCtrlHost->SetToolTip(_("The remote host ip address or its known name"));
#if wxVERSION_NUMBER >= 3000
    m_textCtrlHost->SetHint(wxT(""));
#endif

    flexGridSizer31->Add(m_textCtrlHost, 0, wxALL | wxEXPAND, WXC_FROM_DIP(5));

    m_staticText45 =
        new wxStaticText(this, wxID_ANY, _("Port:"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);

    flexGridSizer31->Add(m_staticText45, 0, wxALL | wxALIGN_RIGHT | wxALIGN_CENTER_VERTICAL, WXC_FROM_DIP(5));

    m_textCtrlPort = new wxTextCtrl(this, wxID_ANY, wxT("22"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);
    m_textCtrlPort->SetToolTip(_("The SSH port. If you don't know it, leave it as 22 (SSH default port)"));
#if wxVERSION_NUMBER >= 3000
    m_textCtrlPort->SetHint(wxT(""));
#endif

    flexGridSizer31->Add(m_textCtrlPort, 0, wxALL | wxEXPAND, WXC_FROM_DIP(5));

    m_staticText37 =
        new wxStaticText(this, wxID_ANY, _("Username:"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);

    flexGridSizer31->Add(m_staticText37, 0, wxALL | wxALIGN_RIGHT | wxALIGN_CENTER_VERTICAL, WXC_FROM_DIP(5));

    m_textCtrlUsername =
        new wxTextCtrl(this, wxID_ANY, wxT(""), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);
    m_textCtrlUsername->SetToolTip(_("Login user name"));
#if wxVERSION_NUMBER >= 3000
    m_textCtrlUsername->SetHint(wxT(""));
#endif

    flexGridSizer31->Add(m_textCtrlUsername, 0, wxALL | wxEXPAND, WXC_FROM_DIP(5));

    m_staticText41 =
        new wxStaticText(this, wxID_ANY, _("Password:"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);

    flexGridSizer31->Add(m_staticText41, 0, wxALL | wxALIGN_RIGHT | wxALIGN_CENTER_VERTICAL, WXC_FROM_DIP(5));

    m_textCtrlPassword =
        new wxTextCtrl(this, wxID_ANY, wxT(""), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), wxTE_PASSWORD);
    m_textCtrlPassword->SetToolTip(_("This field is optional. By leaving this field empty, codelite will attempt to "
                                     "connect only using public key authentication"));
#if wxVERSION_NUMBER >= 3000
    m_textCtrlPassword->SetHint(wxT(""));
#endif

    flexGridSizer31->Add(m_textCtrlPassword, 0, wxALL | wxEXPAND, WXC_FROM_DIP(5));

    m_staticText110 =
        new wxStaticText(this, wxID_ANY, _("Default folder:"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);

    flexGridSizer31->Add(m_staticText110, 0, wxALL | wxALIGN_RIGHT | wxALIGN_CENTER_VERTICAL, WXC_FROM_DIP(5));

    m_textCtrlHomeFolder =
        new wxTextCtrl(this, wxID_ANY, wxT(""), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);
    m_textCtrlHomeFolder->SetToolTip(_("Set the home folder for this account"));
#if wxVERSION_NUMBER >= 3000
    m_textCtrlHomeFolder->SetHint(wxT(""));
#endif

    flexGridSizer31->Add(m_textCtrlHomeFolder, 0, wxALL | wxEXPAND, WXC_FROM_DIP(5));

    m_button51 =
        new wxButton(this, wxID_ANY, _("Test Connection"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);
#if wxVERSION_NUMBER >= 2904
    m_button51->SetBitmap(wxXmlResource::Get()->LoadBitmap(wxT("16-connected")), wxLEFT);
    m_button51->SetBitmapMargins(5, 5);
#endif

    boxSizer23->Add(m_button51, 0, wxALL | wxEXPAND, WXC_FROM_DIP(10));

    boxSizer23->Add(0, 0, 1, wxALL, WXC_FROM_DIP(5));

    wxBoxSizer* boxSizer29 = new wxBoxSizer(wxHORIZONTAL);

    boxSizer23->Add(boxSizer29, 0, wxALL | wxALIGN_CENTER_HORIZONTAL, WXC_FROM_DIP(5));

    m_button27 = new wxButton(this, wxID_OK, _("&OK"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);
    m_button27->SetDefault();

    boxSizer29->Add(m_button27, 0, wxALL, WXC_FROM_DIP(5));

    m_button25 = new wxButton(this, wxID_CANCEL, _("&Cancel"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);

    boxSizer29->Add(m_button25, 0, wxALL, WXC_FROM_DIP(5));

    SetName(wxT("AddSSHAcountDlgBase"));
    SetSize(wxDLG_UNIT(this, wxSize(-1, -1)));
    if(GetSizer()) {
        GetSizer()->Fit(this);
    }
    if(GetParent()) {
        CentreOnParent(wxBOTH);
    } else {
        CentreOnScreen(wxBOTH);
    }
#if wxVERSION_NUMBER >= 2900
    if(!wxPersistenceManager::Get().Find(this)) {
        wxPersistenceManager::Get().RegisterAndRestore(this);
    } else {
        wxPersistenceManager::Get().Restore(this);
    }
#endif
    // Connect events
    m_textCtrlHomeFolder->Connect(wxEVT_COMMAND_TEXT_UPDATED,
                                  wxCommandEventHandler(AddSSHAcountDlgBase::OnHomeFolderUpdated), NULL, this);
    m_button51->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(AddSSHAcountDlgBase::OnTestConnection),
                        NULL, this);
    m_button51->Connect(wxEVT_UPDATE_UI, wxUpdateUIEventHandler(AddSSHAcountDlgBase::OnTestConnectionUI), NULL, this);
    m_button27->Connect(wxEVT_UPDATE_UI, wxUpdateUIEventHandler(AddSSHAcountDlgBase::OnOKUI), NULL, this);
}

AddSSHAcountDlgBase::~AddSSHAcountDlgBase()
{
    m_textCtrlHomeFolder->Disconnect(wxEVT_COMMAND_TEXT_UPDATED,
                                     wxCommandEventHandler(AddSSHAcountDlgBase::OnHomeFolderUpdated), NULL, this);
    m_button51->Disconnect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(AddSSHAcountDlgBase::OnTestConnection),
                           NULL, this);
    m_button51->Disconnect(wxEVT_UPDATE_UI, wxUpdateUIEventHandler(AddSSHAcountDlgBase::OnTestConnectionUI), NULL,
                           this);
    m_button27->Disconnect(wxEVT_UPDATE_UI, wxUpdateUIEventHandler(AddSSHAcountDlgBase::OnOKUI), NULL, this);
}

SFTPBrowserBaseDlg::SFTPBrowserBaseDlg(wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos,
                                       const wxSize& size, long style)
    : wxDialog(parent, id, title, pos, size, style)
{
    if(!bBitmapLoaded) {
        // We need to initialise the default bitmap handler
        wxXmlResource::Get()->AddHandler(new wxBitmapXmlHandler);
        wxCE8CInitBitmapResources();
        bBitmapLoaded = true;
    }

    wxBoxSizer* boxSizer62 = new wxBoxSizer(wxVERTICAL);
    this->SetSizer(boxSizer62);

    m_panel149 = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), wxTAB_TRAVERSAL);

    boxSizer62->Add(m_panel149, 1, wxEXPAND, WXC_FROM_DIP(5));

    wxBoxSizer* boxSizer151 = new wxBoxSizer(wxVERTICAL);
    m_panel149->SetSizer(boxSizer151);

    m_toolbar = new clToolBar(m_panel149, wxID_ANY, wxDefaultPosition, wxDLG_UNIT(m_panel149, wxSize(-1, -1)),
                              wxTB_NODIVIDER | wxTB_FLAT);
    m_toolbar->SetToolBitmapSize(wxSize(16, 16));

    boxSizer151->Add(m_toolbar, 0, wxALL | wxEXPAND, WXC_FROM_DIP(5));

    wxFlexGridSizer* flexGridSizer147 = new wxFlexGridSizer(0, 5, 0, 0);
    flexGridSizer147->SetFlexibleDirection(wxBOTH);
    flexGridSizer147->SetNonFlexibleGrowMode(wxFLEX_GROWMODE_SPECIFIED);
    flexGridSizer147->AddGrowableCol(1);
    flexGridSizer147->AddGrowableCol(3);

    boxSizer151->Add(flexGridSizer147, 0, wxALL | wxEXPAND, WXC_FROM_DIP(5));

    m_staticText82 = new wxStaticText(m_panel149, wxID_ANY, _("Account:"), wxDefaultPosition,
                                      wxDLG_UNIT(m_panel149, wxSize(-1, -1)), 0);

    flexGridSizer147->Add(m_staticText82, 0, wxALL | wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL,
                          WXC_FROM_DIP(5));

    wxArrayString m_choiceAccountArr;
    m_choiceAccount = new wxChoice(m_panel149, wxID_ANY, wxDefaultPosition, wxDLG_UNIT(m_panel149, wxSize(-1, -1)),
                                   m_choiceAccountArr, 0);

    flexGridSizer147->Add(m_choiceAccount, 0, wxALL | wxEXPAND | wxALIGN_CENTER_VERTICAL, WXC_FROM_DIP(5));

    m_staticText66 = new wxStaticText(m_panel149, wxID_ANY, _("Path:"), wxDefaultPosition,
                                      wxDLG_UNIT(m_panel149, wxSize(-1, -1)), 0);

    flexGridSizer147->Add(m_staticText66, 0, wxALL | wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL,
                          WXC_FROM_DIP(5));

    m_textCtrlRemoteFolder = new wxTextCtrl(m_panel149, wxID_ANY, wxT("/"), wxDefaultPosition,
                                            wxDLG_UNIT(m_panel149, wxSize(-1, -1)), wxTE_PROCESS_ENTER);
    m_textCtrlRemoteFolder->SetToolTip(_("Set the remote folder to browse and click on the 'Refresh' button"));
    m_textCtrlRemoteFolder->SetFocus();
#if wxVERSION_NUMBER >= 3000
    m_textCtrlRemoteFolder->SetHint(wxT(""));
#endif

    flexGridSizer147->Add(m_textCtrlRemoteFolder, 0, wxALL | wxEXPAND | wxALIGN_CENTER_VERTICAL, WXC_FROM_DIP(5));

    m_buttonRefresh = new wxButton(m_panel149, wxID_REFRESH, _("Browse..."), wxDefaultPosition,
                                   wxDLG_UNIT(m_panel149, wxSize(-1, -1)), 0);

    flexGridSizer147->Add(m_buttonRefresh, 0, wxALL | wxALIGN_CENTER_VERTICAL, WXC_FROM_DIP(5));

    m_dataview = new clThemedListCtrl(m_panel149, wxID_ANY, wxDefaultPosition, wxDLG_UNIT(m_panel149, wxSize(500, 300)),
                                      wxDV_ROW_LINES | wxDV_SINGLE);

    boxSizer151->Add(m_dataview, 1, wxALL | wxEXPAND, WXC_FROM_DIP(5));

    m_dataview->AppendIconTextColumn(_("Name"), wxDATAVIEW_CELL_INERT, WXC_FROM_DIP(-2), wxALIGN_LEFT,
                                     wxDATAVIEW_COL_RESIZABLE);
    m_dataview->AppendTextColumn(_("Type"), wxDATAVIEW_CELL_INERT, WXC_FROM_DIP(-2), wxALIGN_LEFT,
                                 wxDATAVIEW_COL_RESIZABLE);
    m_dataview->AppendTextColumn(_("Size"), wxDATAVIEW_CELL_INERT, WXC_FROM_DIP(-2), wxALIGN_LEFT,
                                 wxDATAVIEW_COL_RESIZABLE);
    wxBoxSizer* boxSizer94 = new wxBoxSizer(wxVERTICAL);

    boxSizer151->Add(boxSizer94, 0, wxEXPAND | wxRESERVE_SPACE_EVEN_IF_HIDDEN, WXC_FROM_DIP(5));

    m_textCtrlInlineSearch = new wxTextCtrl(m_panel149, wxID_ANY, wxT(""), wxDefaultPosition,
                                            wxDLG_UNIT(m_panel149, wxSize(-1, -1)), wxTE_PROCESS_ENTER);
    m_textCtrlInlineSearch->Hide();
#if wxVERSION_NUMBER >= 3000
    m_textCtrlInlineSearch->SetHint(wxT(""));
#endif

    boxSizer94->Add(m_textCtrlInlineSearch, 0, wxALL | wxEXPAND, WXC_FROM_DIP(5));

    wxBoxSizer* boxSizer57 = new wxBoxSizer(wxHORIZONTAL);

    boxSizer151->Add(boxSizer57, 0, wxALL | wxALIGN_CENTER_HORIZONTAL, WXC_FROM_DIP(5));

    m_button59 =
        new wxButton(m_panel149, wxID_OK, _("&OK"), wxDefaultPosition, wxDLG_UNIT(m_panel149, wxSize(-1, -1)), 0);
    m_button59->SetDefault();

    boxSizer57->Add(m_button59, 0, wxALL, WXC_FROM_DIP(5));

    m_button61 = new wxButton(m_panel149, wxID_CANCEL, _("&Cancel"), wxDefaultPosition,
                              wxDLG_UNIT(m_panel149, wxSize(-1, -1)), 0);

    boxSizer57->Add(m_button61, 0, wxALL, WXC_FROM_DIP(5));

    SetName(wxT("SFTPBrowserBaseDlg"));
    SetSize(wxDLG_UNIT(this, wxSize(-1, -1)));
    if(GetSizer()) {
        GetSizer()->Fit(this);
    }
    if(GetParent()) {
        CentreOnParent(wxBOTH);
    } else {
        CentreOnScreen(wxBOTH);
    }
#if wxVERSION_NUMBER >= 2900
    if(!wxPersistenceManager::Get().Find(this)) {
        wxPersistenceManager::Get().RegisterAndRestore(this);
    } else {
        wxPersistenceManager::Get().Restore(this);
    }
#endif
    // Connect events
    m_textCtrlRemoteFolder->Connect(wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler(SFTPBrowserBaseDlg::OnTextEnter),
                                    NULL, this);
    m_buttonRefresh->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(SFTPBrowserBaseDlg::OnRefresh), NULL,
                             this);
    m_buttonRefresh->Connect(wxEVT_UPDATE_UI, wxUpdateUIEventHandler(SFTPBrowserBaseDlg::OnRefreshUI), NULL, this);
    m_dataview->Connect(wxEVT_COMMAND_DATAVIEW_SELECTION_CHANGED,
                        wxDataViewEventHandler(SFTPBrowserBaseDlg::OnItemSelected), NULL, this);
    m_dataview->Connect(wxEVT_COMMAND_DATAVIEW_ITEM_ACTIVATED,
                        wxDataViewEventHandler(SFTPBrowserBaseDlg::OnItemActivated), NULL, this);
    m_textCtrlInlineSearch->Connect(wxEVT_COMMAND_TEXT_UPDATED,
                                    wxCommandEventHandler(SFTPBrowserBaseDlg::OnTextUpdated), NULL, this);
    m_textCtrlInlineSearch->Connect(wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler(SFTPBrowserBaseDlg::OnEnter), NULL,
                                    this);
    m_textCtrlInlineSearch->Connect(wxEVT_KILL_FOCUS, wxFocusEventHandler(SFTPBrowserBaseDlg::OnFocusLost), NULL, this);
    m_button59->Connect(wxEVT_UPDATE_UI, wxUpdateUIEventHandler(SFTPBrowserBaseDlg::OnOKUI), NULL, this);
}

SFTPBrowserBaseDlg::~SFTPBrowserBaseDlg()
{
    m_textCtrlRemoteFolder->Disconnect(wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler(SFTPBrowserBaseDlg::OnTextEnter),
                                       NULL, this);
    m_buttonRefresh->Disconnect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(SFTPBrowserBaseDlg::OnRefresh),
                                NULL, this);
    m_buttonRefresh->Disconnect(wxEVT_UPDATE_UI, wxUpdateUIEventHandler(SFTPBrowserBaseDlg::OnRefreshUI), NULL, this);
    m_dataview->Disconnect(wxEVT_COMMAND_DATAVIEW_SELECTION_CHANGED,
                           wxDataViewEventHandler(SFTPBrowserBaseDlg::OnItemSelected), NULL, this);
    m_dataview->Disconnect(wxEVT_COMMAND_DATAVIEW_ITEM_ACTIVATED,
                           wxDataViewEventHandler(SFTPBrowserBaseDlg::OnItemActivated), NULL, this);
    m_textCtrlInlineSearch->Disconnect(wxEVT_COMMAND_TEXT_UPDATED,
                                       wxCommandEventHandler(SFTPBrowserBaseDlg::OnTextUpdated), NULL, this);
    m_textCtrlInlineSearch->Disconnect(wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler(SFTPBrowserBaseDlg::OnEnter),
                                       NULL, this);
    m_textCtrlInlineSearch->Disconnect(wxEVT_KILL_FOCUS, wxFocusEventHandler(SFTPBrowserBaseDlg::OnFocusLost), NULL,
                                       this);
    m_button59->Disconnect(wxEVT_UPDATE_UI, wxUpdateUIEventHandler(SFTPBrowserBaseDlg::OnOKUI), NULL, this);
}

clRemoteFindDialogBase::clRemoteFindDialogBase(wxWindow* parent, wxWindowID id, const wxString& title,
                                               const wxPoint& pos, const wxSize& size, long style)
    : wxDialog(parent, id, title, pos, size, style)
{
    if(!bBitmapLoaded) {
        // We need to initialise the default bitmap handler
        wxXmlResource::Get()->AddHandler(new wxBitmapXmlHandler);
        wxCE8CInitBitmapResources();
        bBitmapLoaded = true;
    }

    wxBoxSizer* boxSizer155 = new wxBoxSizer(wxVERTICAL);
    this->SetSizer(boxSizer155);

    wxFlexGridSizer* flexGridSizer163 = new wxFlexGridSizer(0, 2, 0, 0);
    flexGridSizer163->SetFlexibleDirection(wxBOTH);
    flexGridSizer163->SetNonFlexibleGrowMode(wxFLEX_GROWMODE_SPECIFIED);
    flexGridSizer163->AddGrowableCol(1);

    boxSizer155->Add(flexGridSizer163, 1, wxALL | wxEXPAND, WXC_FROM_DIP(5));

    m_staticText165 =
        new wxStaticText(this, wxID_ANY, _("Find:"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);

    flexGridSizer163->Add(m_staticText165, 0, wxALL | wxALIGN_RIGHT | wxALIGN_CENTER_VERTICAL, WXC_FROM_DIP(5));

    wxArrayString m_comboBoxFindWhatArr;
    m_comboBoxFindWhat = new clThemedComboBox(this, wxID_ANY, wxT(""), wxDefaultPosition,
                                              wxDLG_UNIT(this, wxSize(250, -1)), m_comboBoxFindWhatArr, 0);
    m_comboBoxFindWhat->SetFocus();
#if wxVERSION_NUMBER >= 3000
    m_comboBoxFindWhat->SetHint(wxT(""));
#endif

    flexGridSizer163->Add(m_comboBoxFindWhat, 0, wxALL | wxEXPAND, WXC_FROM_DIP(5));

    m_staticText169 =
        new wxStaticText(this, wxID_ANY, _("Where:"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);

    flexGridSizer163->Add(m_staticText169, 0, wxALL | wxALIGN_RIGHT | wxALIGN_CENTER_VERTICAL, WXC_FROM_DIP(5));

    wxArrayString m_comboBoxWhereArr;
    m_comboBoxWhere = new clThemedComboBox(this, wxID_ANY, wxT(""), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)),
                                           m_comboBoxWhereArr, 0);
#if wxVERSION_NUMBER >= 3000
    m_comboBoxWhere->SetHint(wxT(""));
#endif

    flexGridSizer163->Add(m_comboBoxWhere, 0, wxALL | wxEXPAND, WXC_FROM_DIP(5));

    m_staticText175 =
        new wxStaticText(this, wxID_ANY, _("File types:"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);

    flexGridSizer163->Add(m_staticText175, 0, wxALL | wxALIGN_RIGHT | wxALIGN_CENTER_VERTICAL, WXC_FROM_DIP(5));

    wxArrayString m_comboBoxTypesArr;
    m_comboBoxTypes = new clThemedComboBox(this, wxID_ANY, wxT(""), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)),
                                           m_comboBoxTypesArr, 0);
#if wxVERSION_NUMBER >= 3000
    m_comboBoxTypes->SetHint(wxT(""));
#endif

    flexGridSizer163->Add(m_comboBoxTypes, 0, wxALL | wxEXPAND, WXC_FROM_DIP(5));

    m_staticText177 =
        new wxStaticText(this, wxID_ANY, _("Account:"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);

    flexGridSizer163->Add(m_staticText177, 0, wxALL | wxALIGN_RIGHT | wxALIGN_CENTER_VERTICAL, WXC_FROM_DIP(5));

    wxArrayString m_choiceAccountsArr;
    m_choiceAccounts =
        new clThemedChoice(this, wxID_ANY, wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), m_choiceAccountsArr, 0);

    flexGridSizer163->Add(m_choiceAccounts, 0, wxALL | wxEXPAND, WXC_FROM_DIP(5));

    wxGridSizer* gridSizer197 = new wxGridSizer(0, 2, 0, 0);

    boxSizer155->Add(gridSizer197, 0, wxALL | wxALIGN_CENTER_HORIZONTAL, WXC_FROM_DIP(5));

    m_checkBoxCase =
        new wxCheckBox(this, wxID_ANY, _("Case sensitive"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);
    m_checkBoxCase->SetValue(false);

    gridSizer197->Add(m_checkBoxCase, 0, wxALL, WXC_FROM_DIP(5));

    m_checkBoxWholeWord =
        new wxCheckBox(this, wxID_ANY, _("Whole word"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);
    m_checkBoxWholeWord->SetValue(false);

    gridSizer197->Add(m_checkBoxWholeWord, 0, wxALL, WXC_FROM_DIP(5));

    m_stdBtnSizer157 = new wxStdDialogButtonSizer();

    boxSizer155->Add(m_stdBtnSizer157, 0, wxALL | wxALIGN_CENTER_HORIZONTAL, WXC_FROM_DIP(10));

    m_buttonOK = new wxButton(this, wxID_OK, wxT(""), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);
    m_buttonOK->SetDefault();
    m_stdBtnSizer157->AddButton(m_buttonOK);

    m_button161 = new wxButton(this, wxID_CANCEL, wxT(""), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);
    m_stdBtnSizer157->AddButton(m_button161);
    m_stdBtnSizer157->Realize();

    SetName(wxT("clRemoteFindDialogBase"));
    SetSize(wxDLG_UNIT(this, wxSize(-1, -1)));
    if(GetSizer()) {
        GetSizer()->Fit(this);
    }
    if(GetParent()) {
        CentreOnParent(wxBOTH);
    } else {
        CentreOnScreen(wxBOTH);
    }
#if wxVERSION_NUMBER >= 2900
    if(!wxPersistenceManager::Get().Find(this)) {
        wxPersistenceManager::Get().RegisterAndRestore(this);
    } else {
        wxPersistenceManager::Get().Restore(this);
    }
#endif
    // Connect events
    m_comboBoxFindWhat->Connect(wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler(clRemoteFindDialogBase::OnSearch), NULL,
                                this);
    m_comboBoxWhere->Connect(wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler(clRemoteFindDialogBase::OnSearch), NULL,
                             this);
    m_comboBoxTypes->Connect(wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler(clRemoteFindDialogBase::OnSearch), NULL,
                             this);
    m_buttonOK->Connect(wxEVT_UPDATE_UI, wxUpdateUIEventHandler(clRemoteFindDialogBase::OnOK_UI), NULL, this);
}

clRemoteFindDialogBase::~clRemoteFindDialogBase()
{
    m_comboBoxFindWhat->Disconnect(wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler(clRemoteFindDialogBase::OnSearch),
                                   NULL, this);
    m_comboBoxWhere->Disconnect(wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler(clRemoteFindDialogBase::OnSearch), NULL,
                                this);
    m_comboBoxTypes->Disconnect(wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler(clRemoteFindDialogBase::OnSearch), NULL,
                                this);
    m_buttonOK->Disconnect(wxEVT_UPDATE_UI, wxUpdateUIEventHandler(clRemoteFindDialogBase::OnOK_UI), NULL, this);
}
