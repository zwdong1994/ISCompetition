#pragma once
#include "afxwin.h"
#include "mscomm1.h"


// chuankouselect 对话框

class chuankouselect : public CDialog
{
	DECLARE_DYNAMIC(chuankouselect)

public:
	chuankouselect(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~chuankouselect();

// 对话框数据
	enum { IDD = IDD_DIALOG2 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	
	afx_msg void OnBnClickedOk();
	CMscomm1 mscom;
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedCancel();
private:
	CComboBox ck;
};
