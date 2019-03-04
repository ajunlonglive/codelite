#include "clLanguageServer.h"
#include "file_logger.h"
#include "processreaderthread.h"
#include "json_rpc/clJSONRPC.h"
#include "json_rpc/GotoDefinitionRequest.h"
#include "json_rpc/DidOpenTextDocumentRequest.h"
#include "json_rpc/DidCloseTextDocumentRequest.h"

clLanguageServer::clLanguageServer()
{
    Bind(wxEVT_ASYNC_PROCESS_TERMINATED, &clLanguageServer::OnProcessTerminated, this);
    Bind(wxEVT_ASYNC_PROCESS_OUTPUT, &clLanguageServer::OnProcessOutput, this);
}

clLanguageServer::~clLanguageServer()
{
    Unbind(wxEVT_ASYNC_PROCESS_TERMINATED, &clLanguageServer::OnProcessTerminated, this);
    Unbind(wxEVT_ASYNC_PROCESS_OUTPUT, &clLanguageServer::OnProcessOutput, this);
}

void clLanguageServer::Start(const wxString& command, const wxString& workingDirectory)
{
    if(m_process) { return; }
    m_goingDown = false;
    m_command = command;
    m_workingDirectory = workingDirectory;
    m_process = ::CreateAsyncProcess(this, command, IProcessCreateDefault, workingDirectory);
    if(!m_process) { clWARNING() << "Failed to start Language Server:" << command; }
}

void clLanguageServer::OnProcessTerminated(clProcessEvent& event)
{
    clDEBUG() << "Langauge Server Terminated";
    wxDELETE(m_process);
    DoClear();
    if(!m_goingDown) { Start(m_command, m_workingDirectory); }
}

void clLanguageServer::OnProcessOutput(clProcessEvent& event) { clDEBUG() << event.GetOutput(); }

void clLanguageServer::Send(const wxString& message)
{
    if(m_process) { m_process->Write(message); }
}

void clLanguageServer::Stop()
{
    m_goingDown = true;
    if(m_process) { m_process->Terminate(); }
}

//===--------------------------------------------------
// Protocol implementation
//===--------------------------------------------------

void clLanguageServer::FindDefinition(const wxFileName& filename, size_t line, size_t column)
{
    json_rpc::GotoDefinitionRequest req(filename, line, column);
    req.Send(this);
}

void clLanguageServer::FileOpened(const wxFileName& filename, const wxString& fileContent, const wxString& languageId)
{
    if(m_filesSent.count(filename.GetFullPath())) {
        // The file is already opened on the server side, so just notify about 'change' event
        //FileChanged(filename, fileContent, languageId);
    } else {

        json_rpc::DidOpenTextDocumentRequest req(filename, fileContent, languageId);
        req.Send(this);
        m_filesSent.insert(filename.GetFullPath());
    }
}

void clLanguageServer::FileClosed(const wxFileName& filename)
{
    if(m_filesSent.count(filename.GetFullPath()) == 0) {
        clDEBUG() << "clLanguageServer::FileClosed(): file" << filename << "is not opened";
        return;
    }

    json_rpc::DidCloseTextDocumentRequest req(filename);
    req.Send(this);
    m_filesSent.erase(filename.GetFullPath());
}

void clLanguageServer::OnFileLoaded(clCommandEvent& event) { event.Skip(); }

void clLanguageServer::OnFileClosed(clCommandEvent& event) { event.Skip(); }

void clLanguageServer::DoClear() { m_filesSent.clear(); }