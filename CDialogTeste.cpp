// CDialogTeste.cpp : implementation file
//

#include "stdafx.h"
#include "RibbonGadgets.h"
#include "CDialogTeste.h"
#include "afxdialogex.h"


// CDialogTeste dialog

IMPLEMENT_DYNAMIC(CDialogTeste, CDialogEx)

CDialogTeste::CDialogTeste(CWnd* pParent /*=nullptr*/)
	: CDialogEx(ID_VIEW_OUTLOOKBAR, pParent)
{

}

CDialogTeste::~CDialogTeste()
{
}

void CDialogTeste::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CDialogTeste, CDialogEx)
END_MESSAGE_MAP()


// CDialogTeste message handlers
