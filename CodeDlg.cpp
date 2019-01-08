// CodeDlg.cpp : implementation file
//

#include "stdafx.h"
#include "RibbonGadgets.h"
#include "CodeDlg.h"
#include "afxdialogex.h"


// CCodeDlg dialog

IMPLEMENT_DYNAMIC(CCodeDlg, CDialogEx)

CCodeDlg::CCodeDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG1, pParent)
	, m_strCode(_T(""))
{

}

CCodeDlg::~CCodeDlg()
{
}

void CCodeDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_CODE_EDIT, m_strCode);
}


BEGIN_MESSAGE_MAP(CCodeDlg, CDialogEx)
END_MESSAGE_MAP()


// CCodeDlg message handlers
