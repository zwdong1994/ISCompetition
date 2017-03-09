#pragma once
#include "afxwin.h"


// zhuce 对话框

class zhuce : public CDialog
{
	DECLARE_DYNAMIC(zhuce)

public:
	zhuce(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~zhuce();

// 对话框数据
	enum { IDD = IDD_ZHUCE };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	CString name;
	
	CString password;
	CString confirm;
};
