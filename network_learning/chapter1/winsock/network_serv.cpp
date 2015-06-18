// network_learning.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include "network_serv.h"
int network_serv(void)
{
	int port = PORT;
	WSADATA wsaData;
	SOCKET sListen,sAccept;
	// �ͻ���ַ����
	int iLen;
	// �������ݳ���
	int iSend;
	// ��Ҫ���͵���Ϣ
	char buf[]="hello,how are you!";
	// ���������ͻ��ĵ�ַ
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
	// ������������ַ
	serv.sin_family = AF_INET;
	// ��һ��˫�ֽ������ֽ�˳�������ת��Ϊ�����ֽ�˳��
	serv.sin_port = htons(port);
	// �����ֽ������ֽ�˳��ת��Ϊ�����ֽ�˳��INADDR_ANYΪϵͳָ����IP��ַ
	serv.sin_addr.s_addr = htonl(INADDR_ANY);
	
	if(bind(sListen,(LPSOCKADDR)&serv,sizeof(serv))==SOCKET_ERROR)
	{
		printf("bind() failed:%d\n",WSAGetLastError());
		return 1;
	}
	// �������
	if(listen(sListen,5)==SOCKET_ERROR)
	{
		printf("listen() failed:%d\n",WSAGetLastError());
		return 1;
	}
	// ��ʼ���ͻ���ַ����
	iLen=sizeof(client);
	// ����ѭ�����ȴ��ͻ���������
	while(1)
	{
		sAccept = accept(sListen,(struct sockaddr*)&client,&iLen);
		if(sAccept == INVALID_SOCKET)
		{
			printf("accept() failed:%d\n",WSAGetLastError());
			break;
		}	
		// ����ͻ���IP��ַ�Ͷ˿�
		printf("accepted client IP:[%s],port:[%d]\n",inet_ntoa(client.sin_addr),ntohs(client.sin_port));

		// �����ӵĿͻ�������Ϣ
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