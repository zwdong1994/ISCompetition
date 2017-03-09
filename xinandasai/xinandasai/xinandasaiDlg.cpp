
// xinandasaiDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "xinandasai.h"
#include "xinandasaiDlg.h"
#include "afxdialogex.h"
#include "grant.h"
#include "houtai.h"
#include "chuankouselect.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif

houtai hou;
// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// �Ի�������
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CxinandasaiDlg �Ի���




CxinandasaiDlg::CxinandasaiDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CxinandasaiDlg::IDD, pParent)
	, USERNAME(_T(""))
	, PASSWORD(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CxinandasaiDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);

	DDX_Text(pDX, IDC_EDIT1, USERNAME);
	DDX_Text(pDX, IDC_EDIT2, PASSWORD);
}

BEGIN_MESSAGE_MAP(CxinandasaiDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CxinandasaiDlg::OnBnClickedZhuce)
	ON_BN_CLICKED(IDOK, &CxinandasaiDlg::OnBnClickedOk)
	ON_BN_CLICKED(IDC_BUTTON2, &CxinandasaiDlg::OnBnClickedButton2)
END_MESSAGE_MAP()


// CxinandasaiDlg ��Ϣ�������

BOOL CxinandasaiDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// ���ô˶Ի����ͼ�ꡣ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������
	hou.load();
	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void CxinandasaiDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CxinandasaiDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CxinandasaiDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CxinandasaiDlg::OnBnClickedZhuce()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData();
	grant gran;
	gran.DoModal();
}


void CxinandasaiDlg::OnBnClickedOk()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData();
	chuankouselect ch;
	char user[15];
	char passw[15];
	if(USERNAME.IsEmpty())
	{
		MessageBox(_T("�û�������Ϊ�գ�"));
		return;
	}
	if(PASSWORD.IsEmpty())
	{
		MessageBox(_T("���벻��Ϊ�գ�"));
		return;
	}
	sprintf(user,"%s",USERNAME);
	sprintf(passw,"%s",PASSWORD);
	if(hou.login(user,passw)==0)
	{
		MessageBox(_T("�û��������������"));
		return;
	}
	if(hou.login(user,passw)==2)
	{
		MessageBox(_T("����ע��������½��"));
		return;
	}
	ch.DoModal();
	CDialogEx::OnOK();
}


void CxinandasaiDlg::OnBnClickedButton2()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	MessageBox(_T("�����ˣ���ΰ�� �ſ��� ����\nָ����ʦ������Ȫ"));
}
