#pragma once
class houtai
{
public:
	houtai(void);
	~houtai(void);
public:
	char MAC[20];
char manname[15];
char manpassword[15];
struct user{
    char name[15];
    char password[15];
    int power; //0Ϊ���Ȩ�ޣ�ֻ����һ���û���1���Կ�2�ȼ��ļ������U�̣�2����͵ȼ������ɿ�����
    char mac[20];
    struct user *next;
}*users;
int power;
int login(char name[15],char password[15]);
int grant(char name[15],char password[15],int power);//�ڴ�ע�⣬ֻ���ɸ�Ȩ�޸���Ȩ����Ȩ
int regist(char name[15],char password[15],int power);
int save();
int load();
int getmac();
};

