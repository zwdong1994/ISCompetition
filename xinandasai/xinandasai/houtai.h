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
    int power; //0为最高权限，只能有一个用户；1可以跨2等级的计算机读U盘；2，最低等级，不可跨计算机
    char mac[20];
    struct user *next;
}*users;
int power;
int login(char name[15],char password[15]);
int grant(char name[15],char password[15],int power);//在此注意，只能由高权限给低权限授权
int regist(char name[15],char password[15],int power);
int save();
int load();
int getmac();
};

