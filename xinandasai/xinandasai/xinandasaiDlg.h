
// xinandasaiDlg.h : ͷ�ļ�
//

#pragma once
#include "afxwin.h"


// CxinandasaiDlg �Ի���
class CxinandasaiDlg : public CDialogEx
{
// ����
public:
	CxinandasaiDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_XINANDASAI_DIALOG };

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
	afx_msg void OnBnClickedZhuce();
	
	afx_msg void OnBnClickedOk();
	CString USERNAME;
	CString PASSWORD;
	afx_msg void OnBnClickedButton2();
};
