#pragma once


// CDialogTeste dialog

class CDialogTeste : public CDialogEx
{
	DECLARE_DYNAMIC(CDialogTeste)

public:
	CDialogTeste(CWnd* pParent = nullptr);   // standard constructor
	virtual ~CDialogTeste();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = ID_VIEW_OUTLOOKBAR };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
};
