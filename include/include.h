#ifndef INCLUDE_H
#define INCLUDE_H

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <string.h>
using namespace std;

extern int ifv4;
extern int ifv6;
extern int err;
extern char address[100];
extern void if_ipv4(char *str);
extern void if_ipv6(char *str);
extern void distinguish(char *str);

extern string temp_str;
extern std::vector<string> svec1;
extern std::vector<string> svec2;
extern std::vector<string> svec3;
extern char ch[5]; 	
extern int j;
extern int ipv4[4];
extern int ipv6_min[8];
extern int ipv6_max[8];
extern int ipv6_input[8];
extern void clear_ch();
extern int ipv4_change(string stemp);
extern void ipv6_change(string stemp,int *x);

#endif