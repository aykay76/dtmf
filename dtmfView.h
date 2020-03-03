// dtmfView.h : interface of the CDtmfView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_DTMFVIEW_H__03918FA2_0372_4F17_AFFA_EF663C278341__INCLUDED_)
#define AFX_DTMFVIEW_H__03918FA2_0372_4F17_AFFA_EF663C278341__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CDtmfView : public CView
{
protected: // create from serialization only
	CDtmfView();
	DECLARE_DYNCREATE(CDtmfView)

// Attributes
public:
	CDtmfDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDtmfView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CDtmfView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CDtmfView)
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in dtmfView.cpp
inline CDtmfDoc* CDtmfView::GetDocument()
   { return (CDtmfDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DTMFVIEW_H__03918FA2_0372_4F17_AFFA_EF663C278341__INCLUDED_)
