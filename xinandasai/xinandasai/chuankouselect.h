#pragma once
#include "afxwin.h"
#include "mscomm1.h"


// chuankouselect �Ի���

class chuankouselect : public CDialog
{
	DECLARE_DYNAMIC(chuankouselect)

public:
	chuankouselect(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~chuankouselect();

// �Ի�������
	enum { IDD = IDD_DIALOG2 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	
	afx_msg void OnBnClickedOk();
	CMscomm1 mscom;
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedCancel();
private:
	CComboBox ck;
};
