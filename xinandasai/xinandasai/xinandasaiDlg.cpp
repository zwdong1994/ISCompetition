
// xinandasaiDlg.cpp : 实现文件
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
// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
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


// CxinandasaiDlg 对话框




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


// CxinandasaiDlg 消息处理程序

BOOL CxinandasaiDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
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

	// 设置此对话框的图标。当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码
	hou.load();
	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
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

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CxinandasaiDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CxinandasaiDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CxinandasaiDlg::OnBnClickedZhuce()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData();
	grant gran;
	gran.DoModal();
}


void CxinandasaiDlg::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData();
	chuankouselect ch;
	char user[15];
	char passw[15];
	if(USERNAME.IsEmpty())
	{
		MessageBox(_T("用户名不能为空！"));
		return;
	}
	if(PASSWORD.IsEmpty())
	{
		MessageBox(_T("密码不能为空！"));
		return;
	}
	sprintf(user,"%s",USERNAME);
	sprintf(passw,"%s",PASSWORD);
	if(hou.login(user,passw)==0)
	{
		MessageBox(_T("用户名或者密码错误！"));
		return;
	}
	if(hou.login(user,passw)==2)
	{
		MessageBox(_T("请在注册计算机登陆！"));
		return;
	}
	ch.DoModal();
	CDialogEx::OnOK();
}


void CxinandasaiDlg::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码
	MessageBox(_T("制作人：朱伟东 张骏川 黎星\n指导老师：崔永泉"));
}
