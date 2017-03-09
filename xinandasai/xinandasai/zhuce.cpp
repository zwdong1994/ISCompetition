// zhuce.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "xinandasai.h"
#include "zhuce.h"
#include "afxdialogex.h"
#include "tianjia.h"

// zhuce �Ի���

IMPLEMENT_DYNAMIC(zhuce, CDialog)

zhuce::zhuce(CWnd* pParent /*=NULL*/)
	: CDialog(zhuce::IDD, pParent)
	, name(_T(""))
	, password(_T(""))
	, confirm(_T(""))
{

}

zhuce::~zhuce()
{
}

void zhuce::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, name);

	DDX_Text(pDX, IDC_EDIT2, password);
	DDX_Text(pDX, IDC_EDIT3, confirm);
}


BEGIN_MESSAGE_MAP(zhuce, CDialog)
	ON_BN_CLICKED(IDOK, &zhuce::OnBnClickedOk)
END_MESSAGE_MAP()


// zhuce ��Ϣ�������


void zhuce::OnBnClickedOk()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData();
	char user[15];
	char passw[15];
	char conf[15];
	if(name.IsEmpty())
	{
		MessageBox(_T("�û�������Ϊ�գ�"));
		return;
	}
	if(password.IsEmpty())
	{
		MessageBox(_T("���벻��Ϊ�գ�"));
		return;
	}
	if(confirm.IsEmpty())
	{
		MessageBox(_T("ȷ�����벻��Ϊ�գ�"));
		return;
	}
	sprintf(user,"%s",name);
	sprintf(passw,"%s",password);
	sprintf(conf,"%s",confirm);
	if(strcmp(passw,conf)==0)
	{
		if(hou.regist(user,passw,hou.power)==1&&hou.save()==1)
			MessageBox(_T("ע��ɹ���"));
		else
			MessageBox(_T("ע��ʧ�ܣ�"));
	}
	else
	{
		MessageBox(_T("ȷ���������"));
		return;
	}

	CDialog::OnOK();
}
