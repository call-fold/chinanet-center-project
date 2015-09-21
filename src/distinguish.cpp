/*
-------------------------------------------------------------------------------------------------------
-- 地址辨析模块
-- @author 邓淑仪
-- @v1.1 2015/08/01
-------------------------------------------------------------------------------------------------------
*/

#include "include.h"

int ifv4=0;
int ifv6=0;
int err=0;
char address[100];

//=======================================ipv4地址判断，元组解析
void if_ipv4(char *str)
{
	int len;
	int i;
	int point_count=0;
	int num_flage=0;
	int num=0;
	len=strlen(str);
	for(i=0;i<len;i++)
	{
		if((str[i]>=48&&str[i]<=57)||str[i]==46||str[i]==58||(str[i]>=65&&str[i]<=70)||(str[i]>=97&&str[i]<=102))
		{
			if((str[i]>=48&&str[i]<=57)||str[i]==46)
			{
				if(str[i]==46&&num_flage==1)
				{
					num=0;
					point_count++;
					num_flage=0;
				}
				else if(str[i]==46&&num_flage==0)
				{
					err=1;
					return;
				}
				else if(str[i]>=48&&str[i]<=57)
				{
					num_flage=1;
					num=num*10+str[i]-48;
					if(str[i+1]==46&&num>255)
					{
						err=1;
						return;
					}
				}
			}
			else
			{
				ifv4=0;
				return;
			}
		}
		else
		{
			err=1;
			return;
		}
	}
	if(point_count==3&&num<=255)
		ifv4=1;
	else
		err=1;
	return;
}

//=======================================ipv6地址判断，元组解析
void if_ipv6(char *str)
{
	
	int len;
	int i;
	int num=0;
	int colon_count=0;
	int doublecolon_flage=0;
	int colon_flage=0;
	len=strlen(str);
	for(i=0;i<len;i++)
	{
		if((str[i]>=48&&str[i]<=57)||str[i]==46||str[i]==58||(str[i]>=65&&str[i]<=70)||(str[i]>=97&&str[i]<=102))
		{
			if((str[i]>=48&&str[i]<=57)||str[i]==58||(str[i]>=65&&str[i]<=70)||(str[i]>=97&&str[i]<=102))
			{
				if(str[i]==58)
				{
					if(colon_flage==1&&doublecolon_flage==0)
						doublecolon_flage=1;
					else if(colon_flage==1&&doublecolon_flage==1)
					{
						err=1;
						return;
					}
					if(colon_flage==0)
					{
						num=0;
						colon_flage=1;
					}
					colon_count++;
				}
				else
				{
					num++;
					colon_flage=0;
					if(num>4)
					{
						err=1;
						return;
					}
				}
			}
			else
			{
				ifv6=0;
				return;
			}
		}
		else
		{
			err=1;
			return;
		}
	}
	if(colon_count<7&&colon_count>=2&&doublecolon_flage==1||colon_count==7&&doublecolon_flage==0)
		ifv6=1;
	else
		err=1;
	return;
}

void distinguish(char *str)
{
	if_ipv4(str);
	if(ifv4==0&&err==0)
		if_ipv6(str);
	if(ifv4==0&&ifv6==0)
		err=1;
	return;
}