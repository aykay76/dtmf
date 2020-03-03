// dtmfDoc.cpp : implementation of the CDtmfDoc class
//

#include "stdafx.h"
#include "dtmf.h"

#include "dtmfDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDtmfDoc

IMPLEMENT_DYNCREATE(CDtmfDoc, CDocument)

BEGIN_MESSAGE_MAP(CDtmfDoc, CDocument)
	//{{AFX_MSG_MAP(CDtmfDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDtmfDoc construction/destruction

CDtmfDoc::CDtmfDoc()
{
	// TODO: add one-time construction code here

}

CDtmfDoc::~CDtmfDoc()
{
}

BOOL CDtmfDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CDtmfDoc serialization

void CDtmfDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
	}
	else
	{
		// TODO: add loading code here
	}
}

/////////////////////////////////////////////////////////////////////////////
// CDtmfDoc diagnostics

#ifdef _DEBUG
void CDtmfDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CDtmfDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CDtmfDoc commands
