// zhuce.cpp : 实现文件
//

#include "stdafx.h"
#include "xinandasai.h"
#include "zhuce.h"
#include "afxdialogex.h"
#include "tianjia.h"

// zhuce 对话框

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


// zhuce 消息处理程序


void zhuce::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData();
	char user[15];
	char passw[15];
	char conf[15];
	if(name.IsEmpty())
	{
		MessageBox(_T("用户名不能为空！"));
		return;
	}
	if(password.IsEmpty())
	{
		MessageBox(_T("密码不能为空！"));
		return;
	}
	if(confirm.IsEmpty())
	{
		MessageBox(_T("确认密码不能为空！"));
		return;
	}
	sprintf(user,"%s",name);
	sprintf(passw,"%s",password);
	sprintf(conf,"%s",confirm);
	if(strcmp(passw,conf)==0)
	{
		if(hou.regist(user,passw,hou.power)==1&&hou.save()==1)
			MessageBox(_T("注册成功！"));
		else
			MessageBox(_T("注册失败！"));
	}
	else
	{
		MessageBox(_T("确认密码错误！"));
		return;
	}

	CDialog::OnOK();
}
