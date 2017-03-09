// grant.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "xinandasai.h"
#include "grant.h"
#include "afxdialogex.h"
#include "tianjia.h"

#include "zhuce.h"

// grant �Ի���
zhuce zhu;
IMPLEMENT_DYNAMIC(grant, CDialog)

grant::grant(CWnd* pParent /*=NULL*/)
	: CDialog(grant::IDD, pParent)
	, GRANTNAME(_T(""))
	, PASSWORD(_T(""))
	, LEVEL(0)
{

}

grant::~grant()
{

}

void grant::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, GRANTNAME);
	DDX_Text(pDX, IDC_EDIT2, PASSWORD);

	DDX_Text(pDX, IDC_EDIT3, LEVEL);
}


BEGIN_MESSAGE_MAP(grant, CDialog)
	ON_EN_CHANGE(IDC_EDIT1, &grant::OnEnChangeEdit1)
	ON_BN_CLICKED(IDOK, &grant::OnBnClickedOk)
END_MESSAGE_MAP()


// grant ��Ϣ�������


void grant::OnEnChangeEdit1()
{
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ���������
	// ���ʹ�֪ͨ��������д CDialog::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�

	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	
}


void grant::OnBnClickedOk()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	
	UpdateData();
	char user[15];
	char passw[15];
	if(GRANTNAME.IsEmpty())
	{
		MessageBox(_T("�û�������Ϊ�գ�"));
		return;
	}
	if(PASSWORD.IsEmpty())
	{
		MessageBox(_T("���벻��Ϊ�գ�"));
		return;
	}
	if(LEVEL!=1&&LEVEL!=2)
	{
		MessageBox(_T("��������ȷ��Ȩ�ޣ�"));
		return;
	}
	sprintf(user,"%s",GRANTNAME);
	sprintf(passw,"%s",PASSWORD);
	if((hou.power=hou.grant(user,passw,LEVEL))==-1)
	{
		MessageBox(_T("ʧ�ܣ�"));
		return;
	}
	else
		zhu.DoModal();
	CDialog::OnOK();
}
