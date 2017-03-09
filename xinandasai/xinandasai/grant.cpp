// grant.cpp : 实现文件
//

#include "stdafx.h"
#include "xinandasai.h"
#include "grant.h"
#include "afxdialogex.h"
#include "tianjia.h"

#include "zhuce.h"

// grant 对话框
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


// grant 消息处理程序


void grant::OnEnChangeEdit1()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialog::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
	
}


void grant::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	
	UpdateData();
	char user[15];
	char passw[15];
	if(GRANTNAME.IsEmpty())
	{
		MessageBox(_T("用户名不能为空！"));
		return;
	}
	if(PASSWORD.IsEmpty())
	{
		MessageBox(_T("密码不能为空！"));
		return;
	}
	if(LEVEL!=1&&LEVEL!=2)
	{
		MessageBox(_T("请输入正确的权限！"));
		return;
	}
	sprintf(user,"%s",GRANTNAME);
	sprintf(passw,"%s",PASSWORD);
	if((hou.power=hou.grant(user,passw,LEVEL))==-1)
	{
		MessageBox(_T("失败！"));
		return;
	}
	else
		zhu.DoModal();
	CDialog::OnOK();
}
