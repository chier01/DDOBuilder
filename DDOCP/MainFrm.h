// MainFrm.h
//
#pragma once
#include <vector>

class CCustomDockablePane;
class Character;

class CMainFrame :
    public CMDIFrameWndEx
{
        DECLARE_DYNAMIC(CMainFrame)
    public:
        CMainFrame();
        virtual ~CMainFrame();
        CCustomDockablePane* CreateDockablePane(
                const char* paneTitle, 
                CDocument* doc, 
                CRuntimeClass* runtimeClass,
                UINT viewID);
        void CreateViews();
#ifdef _DEBUG
        virtual void AssertValid() const;
        virtual void Dump(CDumpContext& dc) const;
#endif

        void SetStatusBarPromptText(const CString & text);
        void SetActiveDocumentAndCharacter(CDocument * pDoc, Character * pCharacter);

        virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
        virtual BOOL LoadFrame(UINT nIDResource, DWORD dwDefaultStyle = WS_OVERLAPPEDWINDOW | FWS_ADDTOTITLE, CWnd* pParentWnd = NULL, CCreateContext* pContext = NULL);
        virtual BOOL OnCmdMsg(UINT nID, int nCode, void* pExtra, AFX_CMDHANDLERINFO* pHandlerInfo);

    protected:
        afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
        afx_msg void OnWindowManager();
        afx_msg void OnViewCustomize();
        afx_msg LRESULT OnToolbarCreateNew(WPARAM wp, LPARAM lp);
        afx_msg void OnApplicationLook(UINT id);
        afx_msg void OnUpdateApplicationLook(CCmdUI* pCmdUI);
        afx_msg void OnClose();
        afx_msg void OnItemEditor();
        DECLARE_MESSAGE_MAP()

    protected:  // control bar embedded members
        CMFCMenuBar       m_wndMenuBar;
        CMFCToolBar       m_wndToolBar;
        CMFCStatusBar     m_wndStatusBar;
        CMFCToolBarImages m_UserImages;
        std::vector<CCustomDockablePane*> m_dockablePanes;
        // never display these toolbars, just to get icons into UI
        CMFCToolBar       m_menuToolbar;

        CDocument * m_pDocument;
        Character * m_pCharacter;
};
