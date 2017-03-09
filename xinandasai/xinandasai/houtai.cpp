#include "StdAfx.h"
#include "houtai.h"
#include "string.h"
#define MAC_HEADER "物理地址"

houtai::houtai(void)
{
	
	char manna[15]="huster3";
    char manpasswo[15]="123456";
	strcpy(manname,manna);
	strcpy(manpassword,manpasswo);
users=NULL;
}


houtai::~houtai(void)
{
}

int houtai::login(char name[15],char password[15])
{
    struct user *p=users;
    while(p!=NULL)
    {
		if(strcmp(name,manname)==0&&strcmp(password,manpassword)==0)
			return 1;
        if(strcmp(name,p->name)==0&&strcmp(password,p->password)==0)
        {
            if(p->power<2)
            return 1;
            else
            {
                getmac();
                if(strcmp(MAC,p->mac)==0)
                return 1;
                else
                return 2;
            }
        }
        p=p->next;
    }
    return 0;
}

int houtai::grant(char name[15],char password[15],int power)
{
    struct user *p=users;
    if(strcmp(name,manname)==0&&strcmp(password,manpassword)==0&&power!=0)
    return power;
    while(p!=NULL)
    {
        if(strcmp(name,p->name)==0&&strcmp(password,p->password)==0&&p->power<power)
        return power;
        p=p->next;
    }
    return -1;
}

int houtai::regist(char name[15],char password[15],int power)
{
    struct user *p;
    p=(struct user *)malloc(sizeof(struct user));
    strcpy(p->name,name);
    strcpy(p->password,password);
    p->power=power;
    getmac();
    strcpy(p->mac,MAC);
    p->next=users;
    users=p;
    return 1;
}

int houtai::save()
{
    FILE *out;
    struct user *p=users;
    if((out=fopen("d:\\xinandasai\\save.dat","wb"))==NULL)
    return 0;
    while(p!=NULL)
    {
        fwrite(p,sizeof(struct user),1,out);
        p=p->next;
    }
    fclose(out);
    return 1;
}

int houtai::load()
{
    FILE *in;
    struct user *p=users,*hp=NULL;
    if((in=fopen("d:\\xinandasai\\save.dat","rb"))==NULL)
    return 0;
    while(!feof(in))
    {
        p=(struct user *)malloc(sizeof(struct user));
        fread(p,sizeof(struct user),1,in);
        p->next=hp;
        hp=p;
    }
    users=hp;
    fclose(in);
    return 1;
}

int houtai::getmac()
{
     char *netname = "本地连接:";
 char buf [8200];
 FILE *fp;
 char *tmp;
 int size;
 char mac[20] = {0};

system("ipconfig /all > tmp.txt");
 fp = fopen("tmp.txt", "r");
 if(fp == NULL)
 {
  printf("can not find tmp.txt, please check \n");
  return -1;
 }
 fseek(fp, 0, SEEK_END);
 size = ftell(fp);
 if(size >= sizeof(buf))
 {
  printf("the buffer size is too small, should be more than %d\n", size);
  fclose(fp);
 }
 fseek(fp, 0, SEEK_SET);
 memset(buf, 0, sizeof(buf));
 fread(buf, 1, size, fp);
 fclose(fp);
 tmp = strstr(buf, netname);
 if(tmp == NULL)
 {
  printf("can not find network name %s, please check your network name\n", netname);
  return -2;
 }
 tmp = strstr(tmp, MAC_HEADER);
 if(tmp == NULL)
 {
  printf("no "MAC_HEADER"found in file, please check\n");
  printf("are you using chinese windows? if so, please check in file and change the MAC_HEADER define\n");
  return -3;
 }
 tmp = strstr(tmp, ":");
 if(tmp)
 {
  memset(mac, 0, sizeof(mac));
  memcpy(mac, &tmp[2], 17);
  strcpy(MAC,mac);
 }
 remove("tmp.txt");
 return 1;
}