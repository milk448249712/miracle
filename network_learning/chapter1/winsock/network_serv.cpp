// network_learning.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include "network_serv.h"
int network_serv(void)
{
	int port = PORT;
	WSADATA wsaData;
	SOCKET sListen,sAccept;
	// 客户地址长度
	int iLen;
	// 发送数据长度
	int iSend;
	// 需要发送的信息
	char buf[]="hello,how are you!";
	// 服务器、客户的地址
	struct sockaddr_in serv,client;
	if(WSAStartup(MAKEWORD(2,2),&wsaData)!=0)
	{
		printf("Winsock load failed\n");
		return 1;
	}
	sListen = socket(AF_INET,SOCK_STREAM,0);
	if(sListen==INVALID_SOCKET)
	{
		printf("socket failed:%d\n",WSAGetLastError());
		return 1;
	}
	// 建立服务器地址
	serv.sin_family = AF_INET;
	// 把一个双字节主机字节顺序的数据转换为网络字节顺序
	serv.sin_port = htons(port);
	// 把四字节主机字节顺序转换为网络字节顺序，INADDR_ANY为系统指定的IP地址
	serv.sin_addr.s_addr = htonl(INADDR_ANY);
	
	if(bind(sListen,(LPSOCKADDR)&serv,sizeof(serv))==SOCKET_ERROR)
	{
		printf("bind() failed:%d\n",WSAGetLastError());
		return 1;
	}
	// 进入监听
	if(listen(sListen,5)==SOCKET_ERROR)
	{
		printf("listen() failed:%d\n",WSAGetLastError());
		return 1;
	}
	// 初始化客户地址长度
	iLen=sizeof(client);
	// 进入循环，等待客户连接请求
	while(1)
	{
		sAccept = accept(sListen,(struct sockaddr*)&client,&iLen);
		if(sAccept == INVALID_SOCKET)
		{
			printf("accept() failed:%d\n",WSAGetLastError());
			break;
		}	
		// 输出客户端IP地址和端口
		printf("accepted client IP:[%s],port:[%d]\n",inet_ntoa(client.sin_addr),ntohs(client.sin_port));

		// 给连接的客户发送信息
		iSend = send(sAccept,buf,sizeof(buf),0);
		if(iSend==SOCKET_ERROR)
		{
			printf("send() failed:%d\n",WSAGetLastError());
			break;
		}
		else if(iSend==0)
		{
			break;
		}
		else
		{
			printf("send()byte:%d\n",send);
		}
		closesocket(sAccept);
	}
	closesocket(sListen);
	WSACleanup();

	return 0;
}