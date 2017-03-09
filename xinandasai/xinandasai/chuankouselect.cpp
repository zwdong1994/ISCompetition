// chuankouselect.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "xinandasai.h"
#include "chuankouselect.h"
#include "afxdialogex.h"
#include "mscomm1.h"

// chuankouselect �Ի���

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


// chuankouselect ��Ϣ�������


void chuankouselect::OnBnClickedOk()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	if(mscom.get_PortOpen())
	{
		mscom.put_PortOpen(FALSE);
	}
	mscom.put_InputMode(1);//�Զ����Ʒ�ʽ��д����
	mscom.put_Settings("9600,n,8,1");//������9600�޼���λ��8������λ��1��ֹͣλ
	mscom.put_InputLen(0);//���õ�ǰ���������ݳ���Ϊ0,��ʾȫ����ȡ
	mscom.put_CommPort(ck.GetCurSel()+1); //ѡ��COM 
	mscom.put_InBufferSize(1024); //���ջ�����
	mscom.put_OutBufferSize(1024);//���ͻ�����
	mscom.put_RThreshold(1);//���ջ�������1����1�������ַ�ʱ���������������ݵ�OnComm�¼�
	if(!mscom.get_PortOpen())
	{
		mscom.put_PortOpen(TRUE);
		MessageBox(_T("����ȷ��"));
		CString message;
		message=_T("12");
		mscom.put_Output(COleVariant(message));
		mscom.put_PortOpen(FALSE);
	}
	else
	{
		mscom.put_OutBufferCount(0); 
		MessageBox(_T("����1��ʧ��")); 
	}
	CDialog::OnOK();
}


BOOL chuankouselect::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	CString str;
	int i;
	for(i=0;i<15;i++)
	{
		str.Format(_T("com %d"),i+1);
		ck.InsertString(i,str);
	}
	ck.SetCurSel(2);
	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣: OCX ����ҳӦ���� FALSE
}


void chuankouselect::OnBnClickedCancel()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CDialog::OnCancel();
}
