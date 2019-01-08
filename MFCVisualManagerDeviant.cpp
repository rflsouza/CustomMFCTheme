// MFCVisualManagerDeviant.cpp : implementation file
//

#include "stdafx.h"
#include "MFCVisualManagerDeviant.h"


// CMFCVisualManagerDeviant

IMPLEMENT_DYNCREATE(CMFCVisualManagerDeviant, MyCMFCVisualManagerOffice2007)

CMFCVisualManagerDeviant::CMFCVisualManagerDeviant()
	: MyCMFCVisualManagerOffice2007()
	, m_clrRibbonPanelBkBottom(SystemColors::DarkPrimary)
	, m_clrRibbonPanelBkTop(SystemColors::DarkPrimary)
	, m_clrRibbonPanelCaptionBk(SystemColors::DarkPrimary)
	, m_clrRibbonPanelTextPB(SystemColors::WHITE)
	, m_clrToolBarBtnTextHighlighted(SystemColors::WHITE)
	, m_clrRibbonPanelCaptionTextPB(SystemColors::DarkSecundary)
	, m_clrRibbonPanelCaptionTextHighlightedPB(SystemColors::DarkComplementary_2)
	, m_clrRibbonCategoryBkBottom(SystemColors::DarkPrimary)
	, m_clrRibbonCategoryBkTop(SystemColors::DarkPrimary)
	, m_clrRibbonBarBackground(SystemColors::DarkSecundary)
	, m_clrRibbonPanelOutline(SystemColors::DarkPrimary)
	, m_clrRibbonBarTextPB(SystemColors::WHITE)
	, m_clrRibbonBarTextHighlightedPB(SystemColors::WHITE)
	, m_bCustomMDIClientAreaClr(FALSE)
	, m_clrDockablePaneCaption(SystemColors::DarkSecundary)
	, m_clrDockablePaneCaptionHighlighted(SystemColors::DarkSecundary)
	, m_clrDockablePaneCaptionText(SystemColors::LightSecundary)
	, m_clrDockablePaneCaptionTextHighlighted(SystemColors::WHITE)
	// Menu Text
	, m_clrMenuText(SystemColors::WHITE)
	, m_clrMenuTextHighlighted(SystemColors::WHITE)
	, m_clrMenuTextDisabled(SystemColors::DarkComplementary_2)
	, m_clrMenuItemBackgroundHighlight(SystemColors::DarkPrimary)
	// Outlook Bar 
	, m_clrOutlookPageButtonText(SystemColors::DarkPrimary)
	, m_clrOutlookPageButtonTextHighlighted(SystemColors::BLACK)
	, m_clrOutlookPageButtonTextSelected(SystemColors::DarkPrimary)
	, m_clrOutlookPageButtonBackground(SystemColors::LightPrimary)
	, m_clrOutlookPageButtonBackgroundHighlighted(SystemColors::LightSecundary)
	, m_clrOutlookPageButtonBackgroundSelected(SystemColors::LightComplementary_1)
	, m_clrOutlookCaptionText(SystemColors::DarkSecundary)
	, m_clrOutlookCaptionBackground(SystemColors::LightComplementary_1)
	, m_clrOutlookBarSplitter(SystemColors::DarkSecundary)
	//tab (CMFCTabCtrl)
	, m_clrTabText(SystemColors::DarkPrimary)
	, m_clrTabTextHighlighted(SystemColors::BLACK)
	, m_clrTabTextSelected(SystemColors::DarkPrimary)
	, m_clrTabBackground(SystemColors::LightComplementary_1)
	, m_clrTabBackgroundHighlighted(SystemColors::LightSecundary)
	, m_clrTabBackgroundSelected(SystemColors::WHITE)
	, m_clrTabsAreaBackground(SystemColors::DarkSecundary)
{
	brActiveCaptionDockablePaneCaption.CreateSolidBrush(m_clrDockablePaneCaptionHighlighted);
	brInactiveCaptionDockablePaneCaption.CreateSolidBrush(m_clrDockablePaneCaption);
}

CMFCVisualManagerDeviant::~CMFCVisualManagerDeviant()
{
}


// CMFCVisualManagerDeviant member functions
COLORREF CMFCVisualManagerDeviant::OnDrawRibbonPanel(CDC* pDC, CMFCRibbonPanel* pPanel, CRect rectPanel, CRect rectCaption)
{
	if (!pPanel->IsCollapsed())
	{
		// Fill panel with main gradient
		rectPanel.top += 1;
		rectPanel.right -= 1;
		rectPanel.left += 1;
		CDrawingManager dm(*pDC);
		dm.FillGradient2(rectPanel, m_clrRibbonPanelBkBottom, m_clrRibbonPanelBkTop, 90);

		// Fill the panel label area
		CRect rectPanelBottom(rectPanel);
		rectPanelBottom.top = rectPanelBottom.bottom - (rectPanelBottom.Height()*.2);
		rectPanelBottom.bottom -= 1;
		dm.FillGradient2(rectPanelBottom, m_clrRibbonPanelCaptionBk, m_clrRibbonPanelCaptionBk, 90);


		// Draw surrounding rounded rectangle
		rectPanel.right += 1;
		rectPanel.left -= 1;
		rectPanel.top -= 1;
		CPen mypen(PS_SOLID, 1, m_clrRibbonPanelOutline);
		CPen* pOldPen=pDC->SelectObject(&mypen);
		CBrush* pOldBrush = (CBrush*)pDC->SelectStockObject(NULL_BRUSH);
		pDC->RoundRect(rectPanel, CPoint(5, 5));
		pDC->SelectObject(pOldPen);
		pDC->SelectObject(pOldBrush);

		// Squirrel overridden colours.
		m_clrRibbonPanelCaptionText = m_clrRibbonPanelCaptionTextPB;
		m_clrRibbonPanelCaptionTextHighlighted = m_clrRibbonPanelCaptionTextHighlightedPB;
	}

	return m_clrRibbonPanelTextPB;
}

void CMFCVisualManagerDeviant::OnDrawRibbonCategory(CDC* pDC, CMFCRibbonCategory* pCategory, CRect rectCategory)
{
	CDrawingManager dm(*pDC);
	dm.FillGradient2(rectCategory, m_clrRibbonCategoryBkBottom, m_clrRibbonCategoryBkTop, 90);
}

void CMFCVisualManagerDeviant::OnFillBarBackground(CDC* pDC, CBasePane* pBar, CRect rectClient, CRect rectClip, BOOL bNCArea /*= FALSE*/)
{	
	CBrush br(m_clrRibbonBarBackground);
	pDC->FillRect(rectClient, &br);
}


COLORREF CMFCVisualManagerDeviant::OnDrawRibbonCategoryTab(CDC* pDC, CMFCRibbonTab* pTab, BOOL bIsActive)
{
	if (!CanDrawImage())
	{
		return CMFCVisualManagerOffice2003::OnDrawRibbonCategoryTab(pDC, pTab, bIsActive);
	}

	ASSERT_VALID(pDC);
	ASSERT_VALID(pTab);

	CMFCRibbonCategory* pCategory = pTab->GetParentCategory();
	ASSERT_VALID(pCategory);
	CMFCRibbonBar* pBar = pCategory->GetParentRibbonBar();
	ASSERT_VALID(pBar);

	// Get state of this tab
	bIsActive = bIsActive && ((pBar->GetHideFlags() & AFX_RIBBONBAR_HIDE_ELEMENTS) == 0 || pTab->GetDroppedDown() != NULL);
	const BOOL bPressed = pTab->IsPressed();
	const BOOL bIsFocused = pTab->IsFocused() && (pBar->GetHideFlags() & AFX_RIBBONBAR_HIDE_ELEMENTS);
	const BOOL bIsHighlight = (pTab->IsHighlighted() || bIsFocused) && !pTab->IsDroppedDown();	// If TRUE, mouse is hovering over tab



	COLORREF clrText = GetClrRibbonBarTextPB();
	COLORREF clrTextHighlighted = m_clrRibbonBarTextHighlightedPB;

	// Get rect we need to draw
	CRect rectTab = pCategory->GetTabRect();

	TRACE(_T("\nDrawing tab '%s'. Active=%d, Pressed=%d, Focused=%d, Highlighted=%d"), pCategory->GetName(), bIsActive, bPressed, bIsFocused, bIsHighlight);

	if (pCategory->IsActive())
	{
		CDrawingManager dm(*pDC);
		//rectTab.SetRect(rectTab.left, rectTab.top, rectTab.Width() - 5, rectTab.Height() - 5);
		dm.FillGradient2(rectTab, m_clrRibbonPanelBkTop, m_clrRibbonPanelBkBottom, 90);
	}
	else
	{
		CBrush br(m_clrRibbonBarBackground);
		pDC->FillRect(rectTab, &br);
	}

	return bIsActive ? clrTextHighlighted : clrText;
}

// Draws collapsed buttons.  Code stolen from MyCMFCVisualManagerOffice2007::OnDrawRibbonDefaultPaneButton except where stated
void CMFCVisualManagerDeviant::OnDrawRibbonDefaultPaneButton(CDC* pDC, CMFCRibbonButton* pButton)
{
	if (!CanDrawImage())
	{
		CMFCVisualManagerOffice2003::OnDrawRibbonDefaultPaneButton(pDC, pButton);
		return;
	}

	ASSERT_VALID(pDC);
	ASSERT_VALID(pButton);

	// Changed by Pete
	// OnFillRibbonButton(pDC, pButton);
	CRect rect(pButton->GetRect());
	CDrawingManager dm(*pDC);
	dm.FillGradient2(rect, m_clrRibbonPanelBkBottom, m_clrRibbonPanelBkTop, 90);
	pDC->Draw3dRect(rect, RGB(192, 192, 192), RGB(192, 192, 192));
	// End of changed by Pete

	BOOL bIsQATMode = pButton->IsQATMode();

	CRect rectFrame(pButton->GetRect());

	if (!bIsQATMode)
	{
		if (m_ctrlRibbonBtnDefaultIcon.IsValid())
		{
			const CSize sizeImage = pButton->GetImageSize(CMFCRibbonButton::RibbonImageSmall);
			const int nMarginX = 11;
			const int nMarginY = 10;

			rectFrame.top += nMarginY / 2;
			rectFrame.bottom = rectFrame.top + sizeImage.cy + 2 * nMarginY;
			rectFrame.top -= 2;
			rectFrame.left = rectFrame.CenterPoint().x - sizeImage.cx / 2 - nMarginX;
			rectFrame.right = rectFrame.left + sizeImage.cx + 2 * nMarginX;

			m_ctrlRibbonBtnDefaultIcon.Draw(pDC, rectFrame);
		}
	}
	else
	{
		if (m_ctrlRibbonBtnDefaultQAT.IsValid())
		{
			int index = 0;
			if (pButton->IsDroppedDown())
			{
				index = 2;
			}
			else if (pButton->IsPressed())
			{
				if (pButton->IsHighlighted())
				{
					index = 2;
				}
			}
			else if (pButton->IsHighlighted() || pButton->IsFocused())
			{
				index = 1;
			}

			m_ctrlRibbonBtnDefaultQAT.Draw(pDC, rectFrame, index);
		}
		else if (m_ctrlRibbonBtnDefaultQATIcon.IsValid())
		{
			int nHeight = m_ctrlRibbonBtnDefaultQATIcon.GetParams().m_rectImage.Height();

			if (rectFrame.Height() < nHeight)
			{
				nHeight = rectFrame.Height() / 2;
			}

			rectFrame.DeflateRect(1, 0);
			rectFrame.top = rectFrame.bottom - nHeight;

			m_ctrlRibbonBtnDefaultQATIcon.Draw(pDC, rectFrame);
		}
	}

	OnDrawRibbonDefaultPaneButtonContext(pDC, pButton);
}

// Function splits a color into its RGB components and
// transforms the color using a scale 0..255
COLORREF CMFCVisualManagerDeviant::LightenColor(long lScale, COLORREF lColor)
{
	long R = MulDiv(255 - GetRValue(lColor), lScale, 255) + GetRValue(lColor);
	long G = MulDiv(255 - GetGValue(lColor), lScale, 255) + GetGValue(lColor);
	long B = MulDiv(255 - GetBValue(lColor), lScale, 255) + GetBValue(lColor);

	return RGB(R, G, B);
}

// Function splits a color into its RGB components and
// transforms the color using a scale 0..255
COLORREF CMFCVisualManagerDeviant::DarkenColor(long lScale, COLORREF lColor)
{
	long red = MulDiv(GetRValue(lColor), (255 - lScale), 255);
	long green = MulDiv(GetGValue(lColor), (255 - lScale), 255);
	long blue = MulDiv(GetBValue(lColor), (255 - lScale), 255);

	return RGB(red, green, blue);
}


// Draws uncollapsed buttons. Code stolen from MyCMFCVisualManagerOffice2007::OnFillRibbonButton except where stated 
COLORREF CMFCVisualManagerDeviant::OnFillRibbonButton(CDC* pDC, CMFCRibbonButton* pButton)
{
	if (!CanDrawImage())
	{
		return CMFCVisualManagerOffice2003::OnFillRibbonButton(pDC, pButton);
	}

	ASSERT_VALID(pDC);
	ASSERT_VALID(pButton);

	const BOOL bIsMenuMode = pButton->IsMenuMode();

	CRect rect(pButton->GetRect());

	CMFCControlRenderer* pRenderer = NULL;
	CMFCVisualManagerBitmapCache* pCache = NULL;
	int index = 0;

	BOOL bDisabled = pButton->IsDisabled();
	BOOL bFocused = pButton->IsFocused();
	BOOL bDroppedDown = pButton->IsDroppedDown();
	BOOL bPressed = pButton->IsPressed() && !bIsMenuMode;
	BOOL bChecked = pButton->IsChecked();
	BOOL bHighlighted = pButton->IsHighlighted() || bFocused;

	BOOL bDefaultPanelButton = pButton->IsDefaultPanelButton() && !pButton->IsQATMode();
	if (bFocused)
	{
		bDisabled = FALSE;
	}

	if (pButton->IsDroppedDown() && !bIsMenuMode)
	{
		bChecked = TRUE;
		bPressed = FALSE;
		bHighlighted = FALSE;
	}

	CMFCRibbonBaseElement::RibbonElementLocation location = pButton->GetLocationInGroup();

	if (pButton->IsKindOf(RUNTIME_CLASS(CMFCRibbonEdit)))
	{
		rect.left = pButton->GetCommandRect().left;

		COLORREF color1 = m_clrRibbonEdit;
		if (bDisabled)
		{
			color1 = m_clrRibbonEditDisabled;
		}
		else if (bChecked || bHighlighted)
		{
			color1 = m_clrRibbonEditHighlighted;
		}

		COLORREF color2 = color1;

		{
			CDrawingManager dm(*pDC);
			dm.FillGradient(rect, color1, color2, TRUE);
		}

		return(COLORREF)-1;
	}

	if (bChecked && bIsMenuMode && !pButton->IsGalleryIcon())
	{
		bChecked = FALSE;
	}

	if (location != CMFCRibbonBaseElement::RibbonElementNotInGroup && pButton->IsShowGroupBorder())
	{
		if (!pButton->GetMenuRect().IsRectEmpty())
		{
			CRect rectC = pButton->GetCommandRect();
			CRect rectM = pButton->GetMenuRect();

			CMFCControlRenderer* pRendererC = NULL;
			CMFCControlRenderer* pRendererM = NULL;

			CMFCVisualManagerBitmapCache* pCacheC = NULL;
			CMFCVisualManagerBitmapCache* pCacheM = NULL;

			if (location == CMFCRibbonBaseElement::RibbonElementSingleInGroup)
			{
				pRendererC = &m_ctrlRibbonBtnGroupMenu_F[0];
				pRendererM = &m_ctrlRibbonBtnGroupMenu_L[1];

				pCacheC = &m_cacheRibbonBtnGroupMenu_F[0];
				pCacheM = &m_cacheRibbonBtnGroupMenu_L[1];
			}
			else if (location == CMFCRibbonBaseElement::RibbonElementFirstInGroup)
			{
				pRendererC = &m_ctrlRibbonBtnGroupMenu_F[0];
				pRendererM = &m_ctrlRibbonBtnGroupMenu_F[1];

				pCacheC = &m_cacheRibbonBtnGroupMenu_F[0];
				pCacheM = &m_cacheRibbonBtnGroupMenu_F[1];
			}
			else if (location == CMFCRibbonBaseElement::RibbonElementLastInGroup)
			{
				pRendererC = &m_ctrlRibbonBtnGroupMenu_L[0];
				pRendererM = &m_ctrlRibbonBtnGroupMenu_L[1];

				pCacheC = &m_cacheRibbonBtnGroupMenu_L[0];
				pCacheM = &m_cacheRibbonBtnGroupMenu_L[1];
			}
			else
			{
				pRendererC = &m_ctrlRibbonBtnGroupMenu_M[0];
				pRendererM = &m_ctrlRibbonBtnGroupMenu_M[1];

				pCacheC = &m_cacheRibbonBtnGroupMenu_M[0];
				pCacheM = &m_cacheRibbonBtnGroupMenu_M[1];
			}

			int indexC = 0;
			int indexM = 0;

			BOOL bHighlightedC = pButton->IsCommandAreaHighlighted();
			BOOL bHighlightedM = pButton->IsMenuAreaHighlighted();

			if (IsBeta())
			{
				if (bChecked)
				{
					indexC = 3;
				}

				if (bDisabled)
				{
					indexC = 0;
				}
				else
				{
					if (pButton->IsDroppedDown() && !bIsMenuMode)
					{
						indexC = pButton->IsChecked() ? 3 : 0;
						indexM = 3;
					}
					else
					{
						if (bPressed)
						{
							if (bHighlightedC)
							{
								indexM = 1;
								indexC = 2;
							}
						}
						else if (bHighlighted)
						{
							indexC++;
							indexM = 1;
						}
					}
				}
			}
			else
			{
				if (bChecked)
				{
					indexC = 3;

					if (bHighlighted)
					{
						indexM = 5;
					}
				}

				if (bDisabled)
				{
					if (bChecked)
					{
						indexC = 5;
						indexM = 4;
					}
				}
				else
				{
					if (pButton->IsDroppedDown() && !bIsMenuMode)
					{
						indexC = pButton->IsChecked() ? 3 : 6;
						indexM = 3;
					}
					else
					{
						if (bFocused)
						{
							indexC = 6;
							indexM = 5;
						}

						if (bHighlightedC || bHighlightedM)
						{
							if (bChecked)
							{
								indexC = bHighlightedC ? 4 : 3;
							}
							else
							{
								indexC = bHighlightedC ? 1 : 6;
							}

							indexM = bHighlightedM ? 1 : 5;
						}

						if (bPressed)
						{
							if (bHighlightedC)
							{
								indexC = 2;
							}
						}
					}
				}
			}

			if (indexC != -1 && indexM != -1)
			{
				int nCacheIndex = -1;
				if (pCacheC != NULL)
				{
					CSize size(rectC.Size());
					nCacheIndex = pCacheC->FindIndex(size);
					if (nCacheIndex == -1)
					{
						nCacheIndex = pCacheC->Cache(size, *pRendererC);
					}
				}

				if (nCacheIndex != -1)
				{
					pCacheC->Get(nCacheIndex)->Draw(pDC, rectC, indexC);
				}
				else
				{
					pRendererC->Draw(pDC, rectC, indexC);
				}

				nCacheIndex = -1;
				if (pCacheM != NULL)
				{
					CSize size(rectM.Size());
					nCacheIndex = pCacheM->FindIndex(size);
					if (nCacheIndex == -1)
					{
						nCacheIndex = pCacheM->Cache(size, *pRendererM);
					}
				}

				if (nCacheIndex != -1)
				{
					pCacheM->Get(nCacheIndex)->Draw(pDC, rectM, indexM);
				}
				else
				{
					pRendererM->Draw(pDC, rectM, indexM);
				}
			}

			return(COLORREF)-1;
		}
		else
		{
			if (location == CMFCRibbonBaseElement::RibbonElementSingleInGroup)
			{
				pRenderer = &m_ctrlRibbonBtnGroup_S;
				pCache = &m_cacheRibbonBtnGroup_S;
			}
			else if (location == CMFCRibbonBaseElement::RibbonElementFirstInGroup)
			{
				pRenderer = &m_ctrlRibbonBtnGroup_F;
				pCache = &m_cacheRibbonBtnGroup_F;
			}
			else if (location == CMFCRibbonBaseElement::RibbonElementLastInGroup)
			{
				pRenderer = &m_ctrlRibbonBtnGroup_L;
				pCache = &m_cacheRibbonBtnGroup_L;
			}
			else
			{
				pRenderer = &m_ctrlRibbonBtnGroup_M;
				pCache = &m_cacheRibbonBtnGroup_M;
			}

			if (bChecked)
			{
				index = 3;
			}

			if (bDisabled && !bFocused)
			{
				index = 0;
			}
			else
			{
				if (bPressed)
				{
					if (bHighlighted)
					{
						index = 2;
					}
				}
				else if (bHighlighted)
				{
					index++;
				}
			}
		}
	}
	else if (bDefaultPanelButton)
	{
		if (bPressed)
		{
			if (bHighlighted)
			{
				index = 2;
			}
		}
		else if (bHighlighted)
		{
			index = 1;
		}
		else if (bChecked)
		{
			index = 2;
		}

		if (bFocused && !bDroppedDown && m_ctrlRibbonBtnDefault.GetImageCount() > 3)
		{
			index = 3;
		}

		if (index != -1)
		{
			pRenderer = &m_ctrlRibbonBtnDefault;
			CMFCVisualManagerBitmapCache* pCacheDefault = &m_cacheRibbonBtnDefault;

			CMFCRibbonCategory* pCategory = pButton->GetParentCategory();
			ASSERT_VALID(pCategory);

			if (pCategory->GetTabColor() != AFX_CategoryColor_None)
			{
				CMFCRibbonContextCategory& context = m_ctrlRibbonContextCategory[pCategory->GetTabColor() - 1];

				pRenderer = &context.m_ctrlBtnDefault;
				pCacheDefault = &context.m_cacheBtnDefault;
			}

			const CMFCControlRendererInfo& params = pRenderer->GetParams();

			int nCacheIndex = -1;
			if (pCacheDefault != NULL)
			{
				CSize size(params.m_rectImage.Width(), rect.Height());
				nCacheIndex = pCacheDefault->FindIndex(size);
				if (nCacheIndex == -1)
				{
					nCacheIndex = pCacheDefault->CacheY(size.cy, *pRenderer);
				}
			}

			if (nCacheIndex != -1)
			{
				pCacheDefault->Get(nCacheIndex)->DrawY(pDC, rect, CSize(params.m_rectInter.left, params.m_rectImage.right - params.m_rectInter.right), index);

				return m_clrToolBarBtnTextHighlighted;
			}
		}
	}
	else if ((!bDisabled && (bPressed || bChecked || bHighlighted)) || (bDisabled && bFocused))
	{
		if (!pButton->GetMenuRect().IsRectEmpty()/* && (pButton->IsHighlighted() || bChecked)*/)
		{
			CRect rectC = pButton->GetCommandRect();
			CRect rectM = pButton->GetMenuRect();

			CMFCControlRenderer* pRendererC = pButton->IsMenuOnBottom() ? &m_ctrlRibbonBtnMenuV[0] : &m_ctrlRibbonBtnMenuH[0];
			CMFCControlRenderer* pRendererM = pButton->IsMenuOnBottom() ? &m_ctrlRibbonBtnMenuV[1] : &m_ctrlRibbonBtnMenuH[1];

			int indexC = -1;
			int indexM = -1;

			BOOL bDropped = pButton->IsDroppedDown();
			BOOL bHighlightedC = pButton->IsCommandAreaHighlighted();
			BOOL bHighlightedM = pButton->IsMenuAreaHighlighted();

			if (IsBeta())
			{
				if (bChecked)
				{
					indexC = 2;
					indexM = 2;
				}

				if (bDisabled)
				{
					if (bChecked)
					{
					}
				}
				else
				{
					if (bDropped && !bIsMenuMode)
					{
						indexC = bChecked ? 2 : 4;
						indexM = 2;
					}
					else
					{
						if (bPressed)
						{
							if (bHighlighted)
							{
								if (bHighlightedC)
								{
									indexC = 1;
								}
								else
								{
									indexC = bChecked ? indexC : 0;
								}

								indexM = bChecked ? indexM : 0;
							}
						}
						else if (bHighlighted)
						{
							indexC++;
							indexM++;
						}
					}
				}
			}
			else
			{
				if (bDisabled)
				{
					if (bHighlightedC || bHighlightedM)
					{
						indexC = 4;
						indexM = 4;

						if (bHighlightedM)
						{
							indexM = 0;

							if (bDropped && !bIsMenuMode)
							{
								indexC = 5;
								indexM = 2;
							}
							else if (bPressed)
							{
								indexM = 1;
							}
						}
					}
				}
				else
				{
					if (bDropped && !bIsMenuMode)
					{
						indexC = 5;
						indexM = 2;
					}
					else
					{
						if (bFocused)
						{
							indexC = 5;
							indexM = 4;
						}

						if (bChecked)
						{
							indexC = 2;
							indexM = 2;
						}

						if (bHighlightedC || bHighlightedM)
						{
							indexM = 4;

							if (bPressed)
							{
								if (bHighlightedC)
								{
									indexC = 1;
								}
								else if (bHighlightedM)
								{
									indexC = bChecked ? 3 : 5;
								}
							}
							else
							{
								indexC = bChecked ? 3 : 0;

								if (bHighlightedM)
								{
									indexC = bChecked ? 3 : 5;
									indexM = 0;
								}
							}
						}
					}
				}
			}

			if (indexC != -1)
			{
				pRendererC->Draw(pDC, rectC, indexC);
			}

			if (indexM != -1)
			{
				pRendererM->Draw(pDC, rectM, indexM);
			}

			return(COLORREF)-1;
		}
		else
		{
			index = -1;

			pRenderer = &m_ctrlRibbonBtn[0];
			if (rect.Height() > pRenderer->GetParams().m_rectImage.Height() * 1.5 && m_ctrlRibbonBtn[1].IsValid())
			{
				pRenderer = &m_ctrlRibbonBtn[1];
			}

			if (bDisabled && bFocused)
			{
				if (pRenderer->GetImageCount() > 4)
				{
					index = 4;
				}
				else
				{
					index = 0;
				}
			}

			if (!bDisabled)
			{
				if (bChecked)
				{
					index = 2;
				}

				if (bPressed)
				{
					if (bHighlighted)
					{
						index = 1;
					}
				}
				else if (bHighlighted)
				{
					index++;
				}
			}
		}
	}

	COLORREF clrText = bDisabled ? m_clrToolBarBtnTextDisabled : COLORREF(-1);

	if (pRenderer != NULL)
	{
		if (index != -1)
		{
			int nCacheIndex = -1;
			if (pCache != NULL)
			{
				CSize size(rect.Size());
				nCacheIndex = pCache->FindIndex(size);
				if (nCacheIndex == -1)
				{
					nCacheIndex = pCache->Cache(size, *pRenderer);
				}
			}

			if (nCacheIndex != -1)
			{
				pCache->Get(nCacheIndex)->Draw(pDC, rect, index);
			}
			else
			{
				// Adapted by Pete
				// pRenderer->Draw(pDC, rect, index);
				CDrawingManager dm(*pDC);
				dm.FillGradient2(rect, m_clrRibbonPanelBkTop, m_clrRibbonPanelBkBottom, 90);
				pDC->Draw3dRect(rect, RGB(192, 192, 192), RGB(192, 192, 192));
				// End of Pete adaptation
			}

			if (!bDisabled)
			{
				clrText = m_clrToolBarBtnTextHighlighted;
			}
		}
	}

	return clrText;
}

// Draws (most of) orb menu at top left of application (stolen and adapted from CMFCVisualManagerOffice 2007::OnDrawMenuLabel())
COLORREF CMFCVisualManagerDeviant::OnDrawMenuLabel(CDC* pDC, CRect rect)
{
	ASSERT_VALID(pDC);

	pDC->FillRect(rect, &CBrush(m_clrRibbonBarBackground));

	CRect rectSeparator = rect;
	rectSeparator.top = rectSeparator.bottom - 2;

	DrawSeparator(pDC, rectSeparator, TRUE);

	return m_clrRibbonBarTextPB;
}

BOOL CMFCVisualManagerDeviant::OnEraseMDIClientArea(CDC* pDC, CRect rectClient)
{
	if (m_bCustomMDIClientAreaClr)
		pDC->FillSolidRect(&rectClient, m_clrMDIClientArea);
	else
		MyCMFCVisualManagerOffice2007::OnEraseMDIClientArea(pDC, rectClient);

	return TRUE;
}


//FIX Main title bar text when window maximized
BOOL CMFCVisualManagerDeviant::DrawTextOnGlass(CDC * pDC, CString strText, CRect rect, DWORD dwFlags, int nGlowSize, COLORREF clrText)
{
	return MyCMFCVisualManagerOffice2007::DrawTextOnGlass(pDC, strText, rect, dwFlags, nGlowSize, RGB(0, 0, 0));
}

COLORREF CMFCVisualManagerDeviant::OnDrawPaneCaption(CDC* pDC, CDockablePane* pBar, BOOL bActive, CRect rectCaption, CRect rectButtons)
{
	if (!CanDrawImage() || pBar == NULL || pBar->IsDialogControl())
	{
		return CMFCVisualManagerOffice2003::OnDrawPaneCaption(pDC, pBar, bActive, rectCaption, rectButtons);
	}

	ASSERT_VALID(pDC);

	CPen pen(PS_SOLID, 1, GetGlobalData()->clrBarFace);
	CPen* pOldPen = pDC->SelectObject(&pen);

	/* remove border
	rectCaption.bottom += 2;

	pDC->MoveTo(rectCaption.left, rectCaption.bottom);
	pDC->LineTo(rectCaption.left, rectCaption.top);

	pDC->MoveTo(rectCaption.left + 1, rectCaption.top);
	pDC->LineTo(rectCaption.right - 1, rectCaption.top);

	pDC->MoveTo(rectCaption.right - 1, rectCaption.top + 1);
	pDC->LineTo(rectCaption.right - 1, rectCaption.bottom);

	pDC->SelectObject(pOldPen);

	rectCaption.DeflateRect(1, 1, 1, 0);	*/	
	pDC->FillRect(rectCaption, bActive ? &(brActiveCaptionDockablePaneCaption) : &(brInactiveCaptionDockablePaneCaption));

	return bActive ? m_clrDockablePaneCaptionTextHighlighted : m_clrDockablePaneCaptionText;	
}

COLORREF CMFCVisualManagerDeviant::GetMenuItemTextColor(CMFCToolBarMenuButton * pButton, BOOL bHighlighted, BOOL bDisabled)
{
	if (!CanDrawImage())
	{
		return CMFCVisualManagerOffice2003::GetMenuItemTextColor(pButton, bHighlighted, bDisabled);
	}
	COLORREF ret = m_clrMenuText;
	if (bHighlighted) ret = m_clrMenuTextHighlighted;
	if (bDisabled) ret = m_clrMenuTextDisabled;
	return ret;
}

void CMFCVisualManagerDeviant::OnHighlightMenuItem(CDC * pDC, CMFCToolBarMenuButton * pButton, CRect rect, COLORREF & clrText)
{
	if (!CanDrawImage())
	{
		CMFCVisualManagerOffice2003::OnHighlightMenuItem(pDC, pButton, rect, clrText);
		return;
	}

	CDrawingManager dm(*pDC);
	dm.FillGradient2(rect, m_clrMenuItemBackgroundHighlight, m_clrMenuItemBackgroundHighlight);
}

COLORREF CMFCVisualManagerDeviant::GetHighlightedMenuItemTextColor(CMFCToolBarMenuButton * pButton)
{
	if (!CanDrawImage())
	{
		return CMFCVisualManagerOffice2003::GetHighlightedMenuItemTextColor(pButton);
	}

	return m_clrMenuTextHighlighted;
}

void CMFCVisualManagerDeviant::OnFillOutlookPageButton(CDC * pDC, const CRect & rect, BOOL bIsHighlighted, BOOL bIsPressed, COLORREF & clrText)
{
	if (!CanDrawImage())
	{
		CMFCVisualManagerOffice2003::OnFillOutlookPageButton(pDC, rect, bIsHighlighted, bIsPressed, clrText);
		return;
	}

	ASSERT_VALID(pDC);
	
	clrText = m_clrOutlookPageButtonText;
	COLORREF clr1 = m_clrOutlookPageButtonBackground;
	COLORREF clr2 = m_clrOutlookPageButtonBackground;

	if (bIsPressed)
	{		
		clrText = m_clrOutlookPageButtonTextSelected;
		clr1 = m_clrOutlookPageButtonBackgroundSelected;
		clr2 = m_clrOutlookPageButtonBackgroundSelected;	
	}
	
	if (bIsHighlighted)
	{
		clrText = m_clrOutlookPageButtonTextHighlighted;
		clr1 = m_clrOutlookPageButtonBackgroundHighlighted;
		clr2 = m_clrOutlookPageButtonBackgroundHighlighted;
	}

	CDrawingManager dm(*pDC);
	dm.FillGradient(rect, clr1, clr2, TRUE);
}

void CMFCVisualManagerDeviant::OnDrawOutlookPageButtonBorder(CDC * pDC, CRect & rectBtn, BOOL bIsHighlighted, BOOL bIsPressed)
{
	// not use border
	//if (!CanDrawImage())
	//{
	//	CMFCVisualManagerOffice2003::OnDrawOutlookPageButtonBorder(pDC, rectBtn, bIsHighlighted, bIsPressed);
	//	return;
	//}

	//pDC->Draw3dRect(rectBtn, GetGlobalData()->clrBtnHilite, m_clrToolBarBottomLine);
}

void CMFCVisualManagerDeviant::OnDrawOutlookBarSplitter(CDC * pDC, CRect rectSplitter)
{
	ASSERT_VALID(pDC);

	if (!CanDrawImage())
	{
		CMFCVisualManagerOffice2003::OnDrawOutlookBarSplitter(pDC, rectSplitter);
		return;
	}

	CDrawingManager dm(*pDC);
	dm.FillGradient(rectSplitter, m_clrOutlookBarSplitter, m_clrOutlookBarSplitter, TRUE);
}

void CMFCVisualManagerDeviant::OnFillOutlookBarCaption(CDC * pDC, CRect rectCaption, COLORREF & clrText)
{
	CMFCVisualManagerOffice2003::OnFillOutlookBarCaption(pDC, rectCaption, clrText);

	if (CanDrawImage())
	{
		clrText = m_clrOutlookCaptionText;		

		CDrawingManager dm(*pDC);
		dm.FillGradient(rectCaption, m_clrOutlookCaptionBackground, m_clrOutlookCaptionBackground, TRUE);
	}

}


void CMFCVisualManagerDeviant::OnDrawTab(CDC * pDC, CRect rectTab, int iTab, BOOL bIsActive, const CMFCBaseTabCtrl * pTabWnd)
{
	ASSERT_VALID(pTabWnd);
	ASSERT_VALID(pDC);

	if (!CanDrawImage())
	{
		CMFCVisualManagerOffice2003::OnDrawTab(pDC, rectTab, iTab, bIsActive, pTabWnd);
		return;
	}

	const BOOL bBottom = pTabWnd->GetLocation() == CMFCTabCtrl::LOCATION_BOTTOM;
	const BOOL bIsHighlight = iTab == pTabWnd->GetHighlightedTab();

	COLORREF clrText = m_clrTabText;
	COLORREF clr1 = m_clrTabBackground;
	COLORREF clr2 = clr1;

	if (bIsActive) {
		clrText = m_clrTabTextSelected;
		clr1 = m_clrTabBackgroundSelected;
		clr2 = clr1;		
	}	

	if (bIsHighlight) {
		clrText = m_clrTabTextHighlighted;
		clr1 = m_clrTabBackgroundHighlighted;
		clr2 = clr1;		
	}

	CDrawingManager dm(*pDC);
	dm.FillGradient2(rectTab, clr1, clr2, 0);

	OnDrawTabContent(pDC, rectTab, iTab, bIsActive, pTabWnd, clrText);
}

void CMFCVisualManagerDeviant::OnEraseTabsArea(CDC * pDC, CRect rect, const CMFCBaseTabCtrl * pTabWnd)
{
	ASSERT_VALID(pDC);
	ASSERT_VALID(pTabWnd);

	if (!CanDrawImage() || pTabWnd->IsDialogControl())
	{
		CMFCVisualManagerOffice2003::OnEraseTabsArea(pDC, rect, pTabWnd);
		return;
	}
	const BOOL bBottom = pTabWnd->GetLocation() == CMFCTabCtrl::LOCATION_BOTTOM;

	CDrawingManager dm(*pDC);
	dm.FillGradient(rect, m_clrTabsAreaBackground, m_clrTabsAreaBackground, TRUE);
}