/*
-------------------------------------------------------------------------------------------------------
-- 主模块
-- @author 苏铃峰
-- @v1.1 2015/09/18
-------------------------------------------------------------------------------------------------------
*/

#include "include.h"
#include "time.h"

int main(int argc, char const *argv[])
{
	clock_t start, finish, middle;
	double durationInsert, durationSearch;

	start = clock();
	string s_ip;
	int flag=0;    // flag=1 false input,flag=2 ipv4,flag=3 ipv6
	cin>>s_ip;

	for (int i = 0; i!=s_ip.size(); ++i)
 	{
 		address[i]=s_ip[i];
 	}

 	distinguish(address);

 	if(err==1)
		flag=1;

	else
	{
		if(ifv4==1&&ifv6==0)
			flag=2;
		if(ifv4==0&&ifv6==1)
			flag=3;
	}

	if(flag==1){
		cout<<"error ip !"<<endl;
	}

	else if(flag==2){
		cout<<"ipv4"<<endl;
		fstream outfile1("../dics/ipv4.dic",ios::out|ios::in);  //输入ipv4字典库地址
		while(outfile1>>temp_str){
	 		svec1.push_back(temp_str);
	 		outfile1>>temp_str;
	 		svec2.push_back(temp_str);
	 		outfile1>>temp_str;
	 		svec3.push_back(temp_str);
 		}
 		outfile1.close();
	}

	else if(flag==3){
		cout<<"ipv6"<<endl;
		fstream outfile2("../dics/ipv6.dic",ios::out|ios::in);  //输入ipv6字典库地址
		while(outfile2>>temp_str){
	 		svec1.push_back(temp_str);
	 		outfile2>>temp_str;
	 		svec2.push_back(temp_str);
	 		outfile2>>temp_str;
	 		svec3.push_back(temp_str);
 		}
 		outfile2.close();
	}

	middle = clock();

 	int ipv4_min=0;
 	int ipv4_max=0;
 	int ipv4_input=0;
 	int flag_indic=0;  //==1 在字典中  ==0 不在字典中
 	vector<string>::size_type sx=0;	

 	for (int i = 0; i!=s_ip.size(); ++i)
 	{
 		address[i]=s_ip[i];
 	}

 	distinguish(address);

	if(flag==2){
	  	ipv4_input=ipv4_change(s_ip);
 		for(;sx!=svec1.size();++sx){
 			ipv4_min=ipv4_change(svec1[sx]);
 			ipv4_max=ipv4_change(svec2[sx]);
 			if(ipv4_input>=ipv4_min&&ipv4_input<=ipv4_max){
 				flag_indic=1;
 				break;
 			}
 		}	
 	}

 	else if(flag==3){
 		ipv6_change(s_ip,ipv6_input);
 		 for(;sx!=svec1.size();++sx){
 		 	int ipv6_flag=0;
 			ipv6_change(svec1[sx],ipv6_min);
 			ipv6_change(svec2[sx],ipv6_max);
 			for (int i = 0; i < 8; ++i)
 			{
 				if(ipv6_min[i]<=ipv6_input[i]&&ipv6_input[i]<=ipv6_max[i])
 					ipv6_flag++;
 			}
 			if(ipv6_flag==8){
 				flag_indic=1;
 				break;
 			}
 		}
 	}

 	if(flag_indic==1&&(flag==2||flag==3))
 		cout<<svec3[sx]<<endl;
 	else if(flag_indic==0&&(flag==2||flag==3))
 		cout<<"ip is not in dic !"<<endl;

 	finish = clock();
 	durationInsert = (double)(middle - start)/CLOCKS_PER_SEC;
 	durationSearch = (double)(finish - middle)/CLOCKS_PER_SEC;
 	cout<<"insert time: "<<durationInsert<<endl;    //插入时间
 	cout<<"search time: "<<durationSearch<<endl;    //搜索时间

	return 0;

}