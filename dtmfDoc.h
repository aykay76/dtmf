// dtmfDoc.h : interface of the CDtmfDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_DTMFDOC_H__F988272D_D280_4447_9DE9_D4A939515089__INCLUDED_)
#define AFX_DTMFDOC_H__F988272D_D280_4447_9DE9_D4A939515089__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CDtmfDoc : public CDocument
{
protected: // create from serialization only
	CDtmfDoc();
	DECLARE_DYNCREATE(CDtmfDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDtmfDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CDtmfDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CDtmfDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DTMFDOC_H__F988272D_D280_4447_9DE9_D4A939515089__INCLUDED_)
