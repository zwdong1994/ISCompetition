#pragma once
#include "afxwin.h"


// grant �Ի���

class grant : public CDialog
{
	DECLARE_DYNAMIC(grant)

public:
	grant(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~grant();

// �Ի�������
	enum { IDD = IDD_DIALOG1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnEnChangeEdit1();
	CString GRANTNAME;
	CString PASSWORD;
	
	afx_msg void OnBnClickedOk();
	int LEVEL;
};
