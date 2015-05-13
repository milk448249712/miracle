// network_learning.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <Winsock2.h>
#include <stdio.h>
#include <stdlib.h>

#define PORT 5000

#pragma comment(lib,"ws2_32.lib")

int main(int argc, char* argv[])
{
	int port = PORT;
	WSADATA wsaData;
	SOCKET sLitsen,sAccept;
	//客户地址长度
	int iLen;
	//发送数据长度
	int iSend;
	//需要发送的信息
	char buf[]="hello,how are you!";
	//服务器、客户的地址
	struct sockaddr_in serv,client;
	if(WSAStartup(MAKEWORD(2,2),&wsaData)!=0)
	{
		printf("Winsock load failed\n");
		return 1;
	}
	sLitsen = socket(AF_INET,SOCK_STREAM,0);
	if(sLitsen==INVALID_SOCKET)
	{
		printf("socket failed:%d\n",WSAGetLastError());
		return 1;
	}
	//建立服务器地址
	serv.sin_family = AF_INET;
	//把一个双字节主机字节顺序的数据转换为网络字节顺序
	serv.sin_port = htons(port);
	//把四字节主机字节顺序转换为网络字节顺序，INADDR_ANY为系统指定的IP地址
	serv.sin_addr.s_addr = htonl(INADDR_ANY);
	
	return 0;
}
