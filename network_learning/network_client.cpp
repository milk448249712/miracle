#include "stdafx.h"

#include "network_serv.h"

#define PORT 5000
#define BUFFER 1024
#pragma comment(lib,"ws2_32.lib")
int network_client(char *seradd)
{
	WSADATA wsaData;
	SOCKET client;
	int port = PORT;
	char buf[BUFFER];
	// �������ݳ���
	int iLen;
	// ��������ַ
	struct sockaddr_in serv;
	memset(buf,0,sizeof(buf));
	if(WSAStartup(MAKEWORD(2,2),&wsaData)!=0)
	{
		printf("Winsock load failed\n");
		return 1;
	}
	// ��Ҫ���ӵķ�������ַ��Ϣ
	serv.sin_family = AF_INET;
	// ��Ҫ���ӵķ�������ַ��Ϣ
	serv.sin_port = htons(port);
	// �������е�IP��ַת��Ϊ�����Ʊ�ʾ�������ֽ�˳��IP��ַ
	serv.sin_addr.s_addr = inet_addr(seradd);
	// ���ͻ������׽���
	client = socket(AF_INET,SOCK_STREAM,0);
	if(client==INVALID_SOCKET)
	{
		printf("socket failed:%d\n",WSAGetLastError());
		return 1;
	}
	// ���������������TCP����
	if(connect(client,(struct sockaddr*)&serv,sizeof(serv))==INVALID_SOCKET)
	{
		printf("connect() failed:%d\n",WSAGetLastError());
		return 1;
	}
	else
	{
		iLen=recv(client,buf,sizeof(buf),0);
		if(iLen==0)
		{
			return 1;
		}
		else if(iLen==SOCKET_ERROR)
		{
			printf("recv() failed:%d\n",WSAGetLastError());
			return 1;
		}
		printf("recv()data from server:%s\n",buf);
	}
	closesocket(client);
	WSACleanup();
	printf("print any key to continue");
	while(1);


	return 0;
}