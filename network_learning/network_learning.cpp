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
	//�ͻ���ַ����
	int iLen;
	//�������ݳ���
	int iSend;
	//��Ҫ���͵���Ϣ
	char buf[]="hello,how are you!";
	//���������ͻ��ĵ�ַ
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
	//������������ַ
	serv.sin_family = AF_INET;
	//��һ��˫�ֽ������ֽ�˳�������ת��Ϊ�����ֽ�˳��
	serv.sin_port = htons(port);
	//�����ֽ������ֽ�˳��ת��Ϊ�����ֽ�˳��INADDR_ANYΪϵͳָ����IP��ַ
	serv.sin_addr.s_addr = htonl(INADDR_ANY);
	
	return 0;
}
