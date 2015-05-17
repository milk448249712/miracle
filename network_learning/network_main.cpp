#include "stdafx.h"
#include <Winsock2.h>
#include <stdio.h>
#include <stdlib.h>
#include "network_serv.h"
#include "network_client.h"


#pragma comment(lib,"ws2_32.lib")

int main(int argc, char* argv[])
{
	int li_option=0;
	printf("服务器按1，客户端按2,退出按3:\n");
	while(1)
	{
		scanf("%d",&li_option);
		switch(li_option)
		{
			case 1:
				{
					network_serv();
					break;
				}
			case 2:
				{
					network_client(argv[1]);
					break;			
				}
			case 3:
				{
					return 0;
				}
			default:
				{
					printf("错误的选项，重选~\n");
					break;
				}
		}
	}
	return 0;

}
