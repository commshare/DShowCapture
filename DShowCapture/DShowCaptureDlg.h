
// DShowCaptureDlg.h : ͷ�ļ�
//

#pragma once

#include "video_capture.h"
#include "Mp4Record.h"
#include "RtspServerInstance.h"
//#include "framequeue.h"
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

	CVideoCapture *m_pVideoCapture;
	Mp4Record *m_pMp4Record;
	RTSPServerInstance *m_pRtspServer;
	CComboBox m_cbxVideoDevList;
	CComboBox m_cbxAudioDevList;
	CComboBox m_cbxVideoResList;
	ASImgDeviceInfoArray m_asVideoDeviceInfo;
	ASImgDeviceInfoArray m_asAudioDeviceInfo;
	ASCamResolutionInfoArray m_arrCamResolutionArr;

	BOOL m_bInit;
	BOOL m_bIsVideoOpen;
	BOOL m_bIsRecord;
	BOOL m_bIsPush;
	
	int m_nWidth;
	int m_nHeight;

	int m_nSampleRate;
	FrameQueue m_stVideoQueue;
	FrameQueue m_stAudioQueue;	
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
	afx_msg void OnBnClickedButtonPushstream();
	afx_msg void OnBnClickedButtonRecord();
	afx_msg void OnBnClickedButtonCapture();
	afx_msg void OnBnClickedButtonGetdevices();
	afx_msg void OnBnClickedButtonCameraset();
	afx_msg void OnBnClickedButtonInit();
};
