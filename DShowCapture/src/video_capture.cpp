#include "video_capture.h"
#include <afx.h>  

CVideoCapture::CVideoCapture()
{

}

CVideoCapture::~CVideoCapture()
{

}

void CVideoCapture::ListVideoCaptureDevices(ASImgDeviceInfoArray &VidDevInfo)
{
	int count = 0;

	ImgDeviceInfo sDevice;
	// enumerate all video capture devices
	ICreateDevEnum *pCreateDevEnum = NULL;
	HRESULT hr = CoCreateInstance(CLSID_SystemDeviceEnum, NULL, CLSCTX_INPROC_SERVER,
		IID_ICreateDevEnum, (void**)&pCreateDevEnum);

	IEnumMoniker *pEm = NULL;
	hr = pCreateDevEnum->CreateClassEnumerator(CLSID_VideoInputDeviceCategory, &pEm, 0);
//	if (hr != NOERROR)
//		return ;

	ULONG cFetched;
	IMoniker *pM = NULL;
	while (hr = pEm->Next(1, &pM, &cFetched), hr == S_OK)
	{
		sDevice.nDeviceIndex = count;

		LPOLESTR strPidvid = NULL;
		hr = pM->GetDisplayName(0, 0, &strPidvid);  //��ȡID��Ϣ
		if (SUCCEEDED(hr))
		{
			//�����ȡ��һ���豸��ID
			USES_CONVERSION; //OLE2T
			CString sPidvid = strPidvid;
			string str = T2A(sPidvid);
			string result;
			static const regex re("(vid_[0-9a-f]{4}&pid_[0-9a-f]{4})", regex::icase);
			smatch match;
			if (regex_search(str, match, re) && match.size() > 1)
			{
				result = match.str(1);
			}
			else
			{
				result = string("");
			}
			CString strPid(result.c_str());
			strPid.MakeUpper(); //ȫ����д
			sDevice.strDevicePidVid = strPid;

			IPropertyBag *pBag = 0;
			hr = pM->BindToStorage(0, 0, IID_IPropertyBag, (void **)&pBag);
			if (SUCCEEDED(hr))
			{
				VARIANT var;
				var.vt = VT_BSTR;
				hr = pBag->Read(L"FriendlyName", &var, NULL); //������������,��������Ϣ�ȵ�...
				if (hr == NOERROR)
				{
					//��ȡ�豸����	
					char camera_name[1024];
					WideCharToMultiByte(CP_ACP, 0, var.bstrVal, -1, camera_name, sizeof(camera_name), "", NULL);
					TRACE("--------------------------------------camera_name: %s\n", camera_name);
					CString str(camera_name);
					sDevice.strDeviceName = str;
					VidDevInfo.Add(sDevice);
	//				m_cbxCtrl.AddString(str);

					SysFreeString(var.bstrVal);
				}
				pBag->Release();
			}
		}
		pM->Release();

		count++;
	}

//	return VidDevInfo;
}

bool CVideoCapture::InitVideoCapture()
{
	TRACE("InitVideoCapture.........\n");
	return true;
}

bool CVideoCapture::StartVideoCapture()
{
	return true;
}

bool CVideoCapture::StopVideoCapture()
{
	return true;
}