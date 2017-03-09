#pragma once
#include "afxwin.h"


// grant 对话框

class grant : public CDialog
{
	DECLARE_DYNAMIC(grant)

public:
	grant(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~grant();

// 对话框数据
	enum { IDD = IDD_DIALOG1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnEnChangeEdit1();
	CString GRANTNAME;
	CString PASSWORD;
	
	afx_msg void OnBnClickedOk();
	int LEVEL;
};
