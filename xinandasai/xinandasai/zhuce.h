#pragma once
#include "afxwin.h"


// zhuce �Ի���

class zhuce : public CDialog
{
	DECLARE_DYNAMIC(zhuce)

public:
	zhuce(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~zhuce();

// �Ի�������
	enum { IDD = IDD_ZHUCE };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	CString name;
	
	CString password;
	CString confirm;
};
