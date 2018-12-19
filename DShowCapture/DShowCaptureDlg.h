
// DShowCaptureDlg.h : 头文件
//

#pragma once

#include "video_capture.h"

// CDShowCaptureDlg 对话框
class CDShowCaptureDlg : public CDialogEx
{
// 构造
public:
	CDShowCaptureDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_DSHOWCAPTURE_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持

	CVideoCapture *m_pVideoCapture;
	CComboBox m_cbxVideoDevList;
	CComboBox m_cbxAudioDevList;
	CComboBox m_cbxVideoResList;
	ASImgDeviceInfoArray m_asVideoDeviceInfo;
	ASImgDeviceInfoArray m_asAudioDeviceInfo;

// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
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
};
