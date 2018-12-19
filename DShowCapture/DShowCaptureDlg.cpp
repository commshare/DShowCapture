
// DShowCaptureDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "DShowCapture.h"
#include "DShowCaptureDlg.h"
#include "afxdialogex.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// �Ի�������
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CDShowCaptureDlg �Ի���



CDShowCaptureDlg::CDShowCaptureDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CDShowCaptureDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CDShowCaptureDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CDShowCaptureDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON_PUSHSTREAM, &CDShowCaptureDlg::OnBnClickedButtonPushstream)
	ON_BN_CLICKED(IDC_BUTTON_RECORD, &CDShowCaptureDlg::OnBnClickedButtonRecord)
	ON_BN_CLICKED(IDC_BUTTON_CAPTURE, &CDShowCaptureDlg::OnBnClickedButtonCapture)
	ON_BN_CLICKED(IDC_BUTTON_GETDEVICES, &CDShowCaptureDlg::OnBnClickedButtonGetdevices)
	ON_BN_CLICKED(IDC_BUTTON_CAMERASET, &CDShowCaptureDlg::OnBnClickedButtonCameraset)
END_MESSAGE_MAP()


// CDShowCaptureDlg ��Ϣ�������

BOOL CDShowCaptureDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// ���ô˶Ի����ͼ�ꡣ  ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO:  �ڴ���Ӷ���ĳ�ʼ������

	m_pVideoCapture =new CVideoCapture();

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void CDShowCaptureDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ  ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CDShowCaptureDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CDShowCaptureDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CDShowCaptureDlg::OnBnClickedButtonPushstream()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}


void CDShowCaptureDlg::OnBnClickedButtonRecord()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}


void CDShowCaptureDlg::OnBnClickedButtonCapture()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}


void CDShowCaptureDlg::OnBnClickedButtonGetdevices()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	ASImgDeviceInfoArray VidDevInfo;
	m_pVideoCapture->ListVideoCaptureDevices(VidDevInfo);
}




void CDShowCaptureDlg::OnBnClickedButtonCameraset()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}
