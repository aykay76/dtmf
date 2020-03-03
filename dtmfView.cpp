// dtmfView.cpp : implementation of the CDtmfView class
//

#include "stdafx.h"
#include "dtmf.h"

#include "dtmfDoc.h"
#include "dtmfView.h"

#include <mmsystem.h>
#include <mmreg.h>
#include <math.h>


#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

struct
{
  char letter;
  double f1, f2;
} button[] =
{
  {'0', 941, 1336},
  {'1', 697, 1209},
  {'2', 697, 1336},
  {'3', 697, 1477},
  {'4', 770, 1209},
  {'5', 770, 1336},
  {'6', 770, 1477},
  {'7', 852, 1209},
  {'8', 852, 1336},
  {'9', 852, 1477},
  {'A', 697, 1633},
  {'B', 770, 1633},
  {'C', 852, 1633},
  {'D', 941, 1633},
  {'*', 941, 1209},
  {'#', 941, 1477},
  {'X',  20,   20},
  {'Y', 100,  100},
  {'Z', 500,  500},
  {'E', 329.628, 329.628 }
};

/////////////////////////////////////////////////////////////////////////////
// CDtmfView

IMPLEMENT_DYNCREATE(CDtmfView, CView)

BEGIN_MESSAGE_MAP(CDtmfView, CView)
	//{{AFX_MSG_MAP(CDtmfView)
	ON_WM_LBUTTONDOWN()
	ON_WM_KEYDOWN()
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDtmfView construction/destruction

CDtmfView::CDtmfView()
{
	// TODO: add construction code here

}

CDtmfView::~CDtmfView()
{
}

BOOL CDtmfView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CDtmfView drawing

void CDtmfView::OnDraw(CDC* pDC)
{
	CDtmfDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
}

/////////////////////////////////////////////////////////////////////////////
// CDtmfView printing

BOOL CDtmfView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CDtmfView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CDtmfView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CDtmfView diagnostics

#ifdef _DEBUG
void CDtmfView::AssertValid() const
{
	CView::AssertValid();
}

void CDtmfView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CDtmfDoc* CDtmfView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDtmfDoc)));
	return (CDtmfDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CDtmfView message handlers

void CDtmfView::OnLButtonDown(UINT nFlags, CPoint point) 
{
	CView::OnLButtonDown(nFlags, point);
}

void CDtmfView::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags) 
{
	CDC *pDC = GetDC();

	pDC->MoveTo(10, 150);
	pDC->SetROP2(R2_NOT);

	int sub;
	if (nChar >= '0' && nChar <= '9') sub = nChar - '0';
	else if (nChar >= 'A' && nChar <= 'D') sub = nChar - 'A' + 10;
	else if (nChar == 0x6a) sub = 14;
	else if (nChar == 0xde) sub = 15;
	else if (nChar == 'X') sub = 16;
	else if (nChar == 'Y') sub = 17;
	else if (nChar == 'Z') sub = 18;
	else if (nChar == 'E') sub = 19;
	else return;

	// create a data block for '0'
	unsigned char sound[1103];
	int s = 0;
	int value;
	double v = 0;
	double ramp = 0.002;
	double tone = 0.1;
	int i = 0;
	for (double t = 0.0; t < tone; t += 1 / 11025.0) {
		v = cos(2 * 3.141592 * button[sub].f1 * t) + cos(2 * 3.141592 * button[sub].f2 * t);
		if (t < ramp)
			v *= t / ramp;
		if (t > tone - ramp)
			v *= (tone - t) / ramp;
		value = floor(v * 16383 + 32768.5);
		sound[s] = (value & 0xff00) >> 8;
		if (sound[s] < 0) sound[s] = 0;

		pDC->LineTo(10 + i, 256 - sound[s]);
		i++;
		s++;
	}

	WAVEFORMATEX wfx;
	HWAVEOUT hWave;

	wfx.cbSize = sizeof(wfx);
	wfx.nAvgBytesPerSec = 11025;
	wfx.nBlockAlign = 1;
	wfx.nChannels = 1;
	wfx.nSamplesPerSec = 11025;
	wfx.wBitsPerSample = 8;
	wfx.wFormatTag = WAVE_FORMAT_1M08;

	MMRESULT res;
	res = waveOutOpen(&hWave, WAVE_MAPPER, &wfx, 0, 0, 0);
	if (res == MMSYSERR_NOERROR) {
		WAVEHDR wh;

		wh.dwBufferLength = 1102;
		wh.dwBytesRecorded = 0;
		wh.dwFlags = WHDR_BEGINLOOP;
		wh.dwLoops = 1;
		wh.dwUser = 0;
		wh.lpData = (char *)sound;
		wh.lpNext = NULL;
		wh.reserved = 0;

		waveOutPrepareHeader(hWave, &wh, sizeof(wh));
		waveOutWrite(hWave, &wh, sizeof(wh));

		int i;
		while (!(wh.dwFlags & WHDR_DONE)) {
			Sleep(1);
		}

		waveOutClose(hWave);
	} else {
		char szMessage[256];
		waveOutGetErrorText(res, szMessage, 256);
		TRACE("%s\n", szMessage);
	}

//	pDC->MoveTo(10, 150);
//	i = 0;
//	for (t = 0.0; t < tone; t += 1 / 11025.0) {
//		pDC->LineTo(10 + i, sound[i]);
//		i++;
//	}
	
	ReleaseDC(pDC);

	CView::OnKeyDown(nChar, nRepCnt, nFlags);
}
