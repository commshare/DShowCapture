
// DShowCaptureDlg.h : ͷ�ļ�
//

#pragma once


// CDShowCaptureDlg �Ի���
class CDShowCaptureDlg : public CDialogEx
{
// ����
public:
	CDShowCaptureDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_DSHOWCAPTURE_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButtonPushstream();
	afx_msg void OnBnClickedButtonRecord();
	afx_msg void OnBnClickedButtonCapture();
	afx_msg void OnBnClickedButtonGetdevices();
	afx_msg void OnBnClickedButton2();
};
