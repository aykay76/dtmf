// dtmf.h : main header file for the DTMF application
//

#if !defined(AFX_DTMF_H__34EDD220_9E9D_411F_8BF3_60C511DA1087__INCLUDED_)
#define AFX_DTMF_H__34EDD220_9E9D_411F_8BF3_60C511DA1087__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CDtmfApp:
// See dtmf.cpp for the implementation of this class
//

class CDtmfApp : public CWinApp
{
public:
	CDtmfApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDtmfApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CDtmfApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DTMF_H__34EDD220_9E9D_411F_8BF3_60C511DA1087__INCLUDED_)
