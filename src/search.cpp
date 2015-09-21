#include "include.h"

string temp_str;
std::vector<string> svec1;
std::vector<string> svec2;
std::vector<string> svec3;
char ch[5]; 	
int j=0;
int ipv4[4];
int ipv6_min[8];
int ipv6_max[8];
int ipv6_input[8];

void clear_ch(){
	for (int i = 0; i < 5; ++i)
	{
		ch[i]=0;
	}
	j=0;
}

int ipv4_change(string stemp){
	string::size_type i=0;
	int itemp=0;
	vector<string>::size_type sx=0;	
	
	for (int num = 0; num < 4; ++num){
		for(;i!=stemp.size();++i){
			if (stemp[i]=='.')
			{
				break;
			}
			ch[j++]=stemp[i];
		}
		ch[j]='\0';
		ipv4[num]=atoi(ch);
		clear_ch();
		++i;
	}

	itemp=ipv4[0]*16777216+ipv4[1]*65536+ipv4[2]*256+ipv4[3];

	return itemp;
}

void ipv6_change(string stemp,int *x){
	string::size_type i=0;
	int itemp=0;
	vector<string>::size_type sx=0;	

	for (int num=0;num<8;++num){
		for(;i!=stemp.size();++i){
			if (stemp[i]==':')
			{
				break;
			}
			ch[j++]=stemp[i];
		}
		ch[j]='\0';
		sscanf(ch,"%X",&x[num]);
		clear_ch();
		++i;
	}
}