// chuankouselect.cpp : 实现文件
//

#include "stdafx.h"
#include "xinandasai.h"
#include "chuankouselect.h"
#include "afxdialogex.h"
#include "mscomm1.h"

// chuankouselect 对话框

IMPLEMENT_DYNAMIC(chuankouselect, CDialog)

chuankouselect::chuankouselect(CWnd* pParent /*=NULL*/)
	: CDialog(chuankouselect::IDD, pParent)
{
	
}

chuankouselect::~chuankouselect()
{
}

void chuankouselect::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);

	DDX_Control(pDX, IDC_MSCOMM1, mscom);
	DDX_Control(pDX, IDC_COMBO1, ck);
}


BEGIN_MESSAGE_MAP(chuankouselect, CDialog)
	ON_BN_CLICKED(IDOK, &chuankouselect::OnBnClickedOk)
	ON_BN_CLICKED(IDCANCEL, &chuankouselect::OnBnClickedCancel)
END_MESSAGE_MAP()


// chuankouselect 消息处理程序


void chuankouselect::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	if(mscom.get_PortOpen())
	{
		mscom.put_PortOpen(FALSE);
	}
	mscom.put_InputMode(1);//以二进制方式读写数据
	mscom.put_Settings("9600,n,8,1");//波特率9600无检验位，8个数据位，1个停止位
	mscom.put_InputLen(0);//设置当前接收区数据长度为0,表示全部读取
	mscom.put_CommPort(ck.GetCurSel()+1); //选择COM 
	mscom.put_InBufferSize(1024); //接收缓冲区
	mscom.put_OutBufferSize(1024);//发送缓冲区
	mscom.put_RThreshold(1);//接收缓冲区有1个及1个以上字符时，将引发接收数据的OnComm事件
	if(!mscom.get_PortOpen())
	{
		mscom.put_PortOpen(TRUE);
		MessageBox(_T("打开正确！"));
		CString message;
		message=_T("12");
		mscom.put_Output(COleVariant(message));
		mscom.put_PortOpen(FALSE);
	}
	else
	{
		mscom.put_OutBufferCount(0); 
		MessageBox(_T("串口1打开失败")); 
	}
	CDialog::OnOK();
}


BOOL chuankouselect::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  在此添加额外的初始化
	CString str;
	int i;
	for(i=0;i<15;i++)
	{
		str.Format(_T("com %d"),i+1);
		ck.InsertString(i,str);
	}
	ck.SetCurSel(2);
	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}


void chuankouselect::OnBnClickedCancel()
{
	// TODO: 在此添加控件通知处理程序代码
	CDialog::OnCancel();
}
