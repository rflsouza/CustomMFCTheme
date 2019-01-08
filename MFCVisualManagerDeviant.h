#pragma once

#include "Myafxvisualmanageroffice2007.h"
// CMFCVisualManagerDeviant command target


class CMFCVisualManagerDeviant : public MyCMFCVisualManagerOffice2007
{
	DECLARE_DYNCREATE(CMFCVisualManagerDeviant)

public:
	CMFCVisualManagerDeviant();
	virtual ~CMFCVisualManagerDeviant();

	//virtual void OnUpdateSystemColors();
	virtual COLORREF OnDrawRibbonPanel(CDC* pDC, CMFCRibbonPanel* pPanel, CRect rectPanel, CRect rectCaption);
	virtual void OnDrawRibbonCategory(CDC* pDC, CMFCRibbonCategory* pCategory, CRect rectCategory);
	virtual void OnFillBarBackground(CDC* pDC, CBasePane* pBar, CRect rectClient, CRect rectClip, BOOL bNCArea = FALSE);
	//R virtual void OnDrawRibbonButtonBorder(CDC* pDC, CMFCRibbonButton* pButton);

	virtual COLORREF OnDrawRibbonCategoryTab(CDC* pDC, CMFCRibbonTab* pTab, BOOL bIsActive);

	void OnDrawRibbonDefaultPaneButton(CDC* pDC, CMFCRibbonButton* pButton);
	COLORREF OnFillRibbonButton(CDC * pDC, CMFCRibbonButton * pButton);



	COLORREF OnDrawMenuLabel(CDC* pDC, CRect rect);
	virtual COLORREF OnDrawPaneCaption(CDC* pDC, CDockablePane* pBar, BOOL bActive, CRect rectCaption, CRect rectButtons);


	// Accessor functions for ribbon panel colours
	COLORREF GetClrRibbonPanelBkBottom() const { return m_clrRibbonPanelBkBottom; }
	void SetClrRibbonPanelBkBottom(COLORREF val) { m_clrRibbonPanelBkBottom = val; }
	COLORREF GetClrRibbonPanelBkTop() const { return m_clrRibbonPanelBkTop; }
	void SetClrRibbonPanelBkTop(COLORREF val) { m_clrRibbonPanelBkTop = val; }
	COLORREF GetClrRibbonPanelTextPB() const { return m_clrRibbonPanelTextPB; }
	void SetClrRibbonPanelTextPB(COLORREF val) { m_clrRibbonPanelTextPB = val; }
	COLORREF GetClrRibbonPanelHighlightedTextPB() const { return m_clrToolBarBtnTextHighlighted; }
	void SetClrRibbonPanelTextHighlightedPB(COLORREF val) { m_clrToolBarBtnTextHighlighted = val; }
	COLORREF GetClrRibbonPanelCaptionTextPB() const { return m_clrRibbonPanelCaptionTextPB; }
	void SetClrRibbonPanelCaptionTextPB(COLORREF val) { m_clrRibbonPanelCaptionTextPB = val; }
	COLORREF GetClrRibbonPanelCaptionTextHighlightedPB() const { return m_clrRibbonPanelCaptionTextHighlightedPB; }
	void SetClrRibbonPanelCaptionTextHighlightedPB(COLORREF val) { m_clrRibbonPanelCaptionTextHighlightedPB = val; }

	// Ribbon menu bar background
	COLORREF GetClrRibbonBarBackground() const { return m_clrRibbonBarBackground; }
	void SetClrRibbonBarBackground(COLORREF val) { m_clrRibbonBarBackground = val; }
	COLORREF GetClrRibbonBarTextPB() const { return m_clrRibbonBarTextPB; }
	void SetClrRibbonBarTextPB(COLORREF val) { m_clrRibbonBarTextPB = val; }
	COLORREF GetClrRibbonBarTextHighlightedPB() const { return m_clrRibbonBarTextHighlightedPB; }
	void SetClrRibbonBarTextHighlightedPB(COLORREF val) { m_clrRibbonBarTextHighlightedPB = val; }


	// Ribbon category colours
	COLORREF GetClrRibbonCategoryBkBottom() const { return m_clrRibbonCategoryBkBottom; }
	void SetClrRibbonCategoryBkBottom(COLORREF val) { m_clrRibbonCategoryBkBottom = val; }
	COLORREF GetClrRibbonCategoryBkTop() const { return m_clrRibbonCategoryBkTop; }
	void SetClrRibbonCategoryBkTop(COLORREF val) { m_clrRibbonCategoryBkTop = val; }
	
	// Ribbon panel outline colour
	COLORREF GetClrRibbonPanelOutline() const { return m_clrRibbonPanelOutline; }
	void SetClrRibbonPanelOutline(COLORREF val) { m_clrRibbonPanelOutline = val; }

	// Ribbon panel label background area colour
	COLORREF GetClrRibbonPanelCaptionBk() const { return m_clrRibbonPanelCaptionBk; }
	void SetClrRibbonPanelCaptionBk(COLORREF val) { m_clrRibbonPanelCaptionBk = val; }

	// MDI Client area background
	virtual BOOL OnEraseMDIClientArea(CDC* pDC, CRect rectClient);
	COLORREF GetClrMDIClientArea() const { return m_clrMDIClientArea; }
	void SetClrMDIClientArea(COLORREF val) { m_clrMDIClientArea = val; m_bCustomMDIClientAreaClr = TRUE; }
	BOOL GetCustomMDIClientAreaClr() const { return m_bCustomMDIClientAreaClr; }
	void SetCustomMDIClientAreaClr(BOOL val) { m_bCustomMDIClientAreaClr = val; }

	//FIX Main title bar text when window maximized
	BOOL DrawTextOnGlass(CDC* pDC, CString strText, CRect rect, DWORD dwFlags, int nGlowSize = 0, COLORREF clrText = (COLORREF)-1) override;

	// Dockable Pane Caption	
	COLORREF GetClrDockablePaneCaption() const { return m_clrDockablePaneCaption; }
	void SetClrDockablePaneCaption(COLORREF val) { 
		m_clrDockablePaneCaption = val; 	
		brInactiveCaptionDockablePaneCaption.DeleteObject();
		brInactiveCaptionDockablePaneCaption.CreateSolidBrush(val);
	}
	COLORREF GetClrDockablePaneCaptionHighlighted() const { return m_clrDockablePaneCaptionHighlighted; }
	void SetClrDockablePaneCaptionHighlighted(COLORREF val) { 
		m_clrDockablePaneCaptionHighlighted = val;
		brActiveCaptionDockablePaneCaption.DeleteObject();
		brActiveCaptionDockablePaneCaption.CreateSolidBrush(val);
	}	
	COLORREF GetClrDockablePaneCaptionText() const { return m_clrDockablePaneCaptionText; }
	void SetClrDockablePaneCaptionText(COLORREF val) { m_clrDockablePaneCaptionText = val; }	
	COLORREF GetClrDockablePaneCaptionTextHighlighted() const { return m_clrDockablePaneCaptionTextHighlighted; }
	void SetClrDockablePaneCaptionTextHighlighted(COLORREF val) { m_clrDockablePaneCaptionTextHighlighted = val; }

	// Menu Text
	COLORREF GetClrMenuText() const { return m_clrMenuText; }
	void SetClrMenuText(COLORREF val) { m_clrMenuText = val; }
	COLORREF GetClrMenuTextHighlighted() const { return m_clrMenuTextHighlighted; }
	void SetClrMenuTextHighlighted(COLORREF val) { m_clrMenuTextHighlighted = val; }	
	COLORREF GetClrMenuTextDisabled() const { return m_clrMenuTextDisabled; }
	void SetClrMenuTextDisabled(COLORREF val) { m_clrMenuTextDisabled = val; }		
	COLORREF GetClrMenuItemBackgroundHighlight() const { return m_clrMenuItemBackgroundHighlight; }
	void SetClrMenuItemBackgroundHighlight(COLORREF val) { m_clrMenuItemBackgroundHighlight = val; }

	virtual COLORREF GetMenuItemTextColor(CMFCToolBarMenuButton* pButton, BOOL bHighlighted, BOOL bDisabled);
	virtual COLORREF GetHighlightedMenuItemTextColor(CMFCToolBarMenuButton* pButton);
	virtual void OnHighlightMenuItem(CDC *pDC, CMFCToolBarMenuButton* pButton, CRect rect, COLORREF& clrText);

	// Outlook Bar 
	COLORREF GetClrOutlookPageButtonText() const { return m_clrOutlookPageButtonText; }
	void SetClrOutlookPageButtonText(COLORREF val) { m_clrOutlookPageButtonText = val; }	
	COLORREF GetClrOutlookPageButtonTextHighlighted() const { return m_clrOutlookPageButtonTextHighlighted; }
	void SetClrOutlookPageButtonTextHighlighted(COLORREF val) { m_clrOutlookPageButtonTextHighlighted = val; }	
	COLORREF GetClrOutlookPageButtonTextSelected() const { return m_clrOutlookPageButtonTextSelected; }
	void SetClrOutlookPageButtonTextSelected(COLORREF val) { m_clrOutlookPageButtonTextSelected = val; }
	COLORREF GetClrOutlookPageButtonBackground() const { return m_clrOutlookPageButtonBackground; }
	void SetClrOutlookPageButtonBackground(COLORREF val) { m_clrOutlookPageButtonBackground = val; }	
	COLORREF GetClrOutlookPageButtonBackgroundHighlighted() const { return m_clrOutlookPageButtonBackgroundHighlighted; }
	void SetClrOutlookPageButtonBackgroundHighlighted(COLORREF val) { m_clrOutlookPageButtonBackgroundHighlighted = val; }	
	COLORREF GetClrOutlookPageButtonBackgroundSelected() const { return m_clrOutlookPageButtonBackgroundSelected; }
	void SetClrOutlookPageButtonBackgroundSelected(COLORREF val) { m_clrOutlookPageButtonBackgroundSelected = val; }
	COLORREF GetClrOutlookCaptionText() const { return m_clrOutlookCaptionText; }
	void SetClrOutlookCaptionText(COLORREF val) { m_clrOutlookCaptionText = val; }	
	COLORREF GetClrOutlookCaptionBackground() const { return m_clrOutlookCaptionBackground; }
	void SetClrOutlookCaptionBackground(COLORREF val) { m_clrOutlookCaptionBackground = val; }	
	COLORREF GetClrOutlookBarSplitter() const { return m_clrOutlookBarSplitter; }
	void SetClrOutlookBarSplitter(COLORREF val) { m_clrOutlookBarSplitter = val; }

	virtual void OnFillOutlookPageButton(CDC* pDC, const CRect& rect, BOOL bIsHighlighted, BOOL bIsPressed, COLORREF& clrText);
	virtual void OnDrawOutlookPageButtonBorder(CDC* pDC, CRect& rectBtn, BOOL bIsHighlighted, BOOL bIsPressed);
	virtual void OnDrawOutlookBarSplitter(CDC* pDC, CRect rectSplitter);
	virtual void OnFillOutlookBarCaption(CDC* pDC, CRect rectCaption, COLORREF& clrText);

	//tab (CMFCTabCtrl)
	COLORREF GetClrTabText() const { return m_clrTabText; }
	void SetClrTabText(COLORREF val) { m_clrTabText = val; }
	COLORREF GetClrTabHighlighted() const { return m_clrTabTextHighlighted; }
	void SetClrTabHighlighted(COLORREF val) { m_clrTabTextHighlighted = val; }
	COLORREF GetClrTabTextSelected() const { return m_clrTabTextSelected; }
	void SetClrTabTextSelected(COLORREF val) { m_clrTabTextSelected = val; }
	COLORREF GetClrTabBackground() const { return m_clrTabBackground; }
	void SetClrTabBackground(COLORREF val) { m_clrTabBackground = val; }
	COLORREF GetClrTabBackgroundHighlighted() const { return m_clrTabBackgroundHighlighted; }
	void SetClrTabBackgroundHighlighted(COLORREF val) { m_clrTabBackgroundHighlighted = val; }	
	COLORREF GetClrTabBackgroundSelected() const { return m_clrTabBackgroundSelected; }
	void SetClrTabBackgroundSelected(COLORREF val) { m_clrTabBackgroundSelected = val; }	
	COLORREF GetClrTabsAreaBackground() const { return m_clrTabsAreaBackground; }
	void SetClrTabsAreaBackground(COLORREF val) { m_clrTabsAreaBackground = val; }

	virtual void OnDrawTab(CDC* pDC, CRect rectTab, int iTab, BOOL bIsActive, const CMFCBaseTabCtrl* pTabWnd);
	virtual void OnEraseTabsArea(CDC* pDC, CRect rect, const CMFCBaseTabCtrl* pTabWnd);

protected:
	// Utility fns to lighten or darken colour
	COLORREF LightenColor(long lScale, COLORREF lColor);
	COLORREF DarkenColor(long lScale, COLORREF lColor);


	// Ribbon panel colours
	COLORREF m_clrRibbonPanelBkBottom;
	COLORREF m_clrRibbonPanelBkTop;
	COLORREF m_clrRibbonPanelCaptionBk;
	COLORREF m_clrRibbonPanelTextPB;
	COLORREF m_clrToolBarBtnTextHighlighted; //Ribbon >> BtnTextHighlighted
	COLORREF m_clrRibbonPanelCaptionTextPB;
	COLORREF m_clrRibbonPanelCaptionTextHighlightedPB;
	COLORREF m_clrRibbonPanelOutline;

	// Ribbon category colours
	COLORREF m_clrRibbonCategoryBkBottom;
	COLORREF m_clrRibbonCategoryBkTop;

	// Ribbon menu bar background
	COLORREF m_clrRibbonBarBackground;
	COLORREF m_clrRibbonBarTextPB;
	COLORREF m_clrRibbonBarTextHighlightedPB;	

	// MDI background colour
	BOOL m_bCustomMDIClientAreaClr;
	COLORREF m_clrMDIClientArea;

	// Dockable Pane Caption
	CBrush		brActiveCaptionDockablePaneCaption;
	CBrush		brInactiveCaptionDockablePaneCaption;
	COLORREF	m_clrDockablePaneCaption;
	COLORREF	m_clrDockablePaneCaptionHighlighted;
	COLORREF	m_clrDockablePaneCaptionText;
	COLORREF	m_clrDockablePaneCaptionTextHighlighted;

	// Menu Text
	COLORREF m_clrMenuText;
	COLORREF m_clrMenuTextHighlighted;
	COLORREF m_clrMenuTextDisabled;
	COLORREF m_clrMenuItemBackgroundHighlight;

	// Outlook Bar 
	COLORREF m_clrOutlookPageButtonText;
	COLORREF m_clrOutlookPageButtonTextHighlighted;
	COLORREF m_clrOutlookPageButtonTextSelected;
	COLORREF m_clrOutlookPageButtonBackground;
	COLORREF m_clrOutlookPageButtonBackgroundHighlighted;
	COLORREF m_clrOutlookPageButtonBackgroundSelected;	
	COLORREF m_clrOutlookCaptionText;
	COLORREF m_clrOutlookCaptionBackground;
	COLORREF m_clrOutlookBarSplitter;

	//tab (CMFCTabCtrl)
	COLORREF m_clrTabText;
	COLORREF m_clrTabTextHighlighted;
	COLORREF m_clrTabTextSelected;
	COLORREF m_clrTabBackground;
	COLORREF m_clrTabBackgroundHighlighted;
	COLORREF m_clrTabBackgroundSelected;
	COLORREF m_clrTabsAreaBackground;

};


