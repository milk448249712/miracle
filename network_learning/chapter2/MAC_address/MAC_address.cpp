// MAC_address.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "getLocalMac.h"
#include "stdio.h"
#include "CheckIP.h"

int main(int argc, char* argv[])
{
	char *p;
	p="sadf";
	printf("%s\n",p);
	unsigned char address[1024];
    if(getLocalMac(address)>0)
    {
        printf("mac-%s\n",address);
    }else
    {
        printf("invoke getMAC error!\n");
    }
	CheckIP();
	return 0;
}
