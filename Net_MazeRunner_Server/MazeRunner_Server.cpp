#pragma comment(lib, "ws2_32")
#include "stdafx.h"
#include <WinSock2.h>
#include <stdlib.h>
#include <stdio.h>

#define SERVERPORT	9000


//제공 코드 사용
void err_quit(char *msg)
{
	LPVOID lpMsgBuf;
	FormatMessage(
		FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM,
		NULL, WSAGetLastError(),
		MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT),
		(LPTSTR)&lpMsgBuf, 0, NULL);
	MessageBox(NULL, (LPCTSTR)lpMsgBuf, msg, MB_ICONERROR);
	LocalFree(lpMsgBuf);
	exit(1);
}

void err_display(char *msg)
{
	LPVOID lpMsgBuf;
	FormatMessage(
		FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM,
		NULL, WSAGetLastError(),
		MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT),
		(LPTSTR)&lpMsgBuf, 0, NULL);
	printf("[%s] %s", msg, (char *)lpMsgBuf);
	LocalFree(lpMsgBuf);
}


int main(int argc, char *argv[])
{
	//검사를 받기 위한 int값
	int Icheck_err;

	//윈속 초기화
	WSADATA wsa;
	if (WSAStartup(MAKEWORD(2, 2), &wsa) != 0)
		return 0;
	//listen socket()
	SOCKET listen_sock = socket(AF_INET, SOCK_STREAM, 0);
	if (listen_sock == INVALID_SOCKET) err_quit("socket()");


	//bind()
	SOCKADDR_IN serveraddr;
	ZeroMemory(&serveraddr, sizeof(serveraddr));
	serveraddr.sin_family = AF_INET;
	serveraddr.sin_addr.s_addr = htonl(INADDR_ANY);
	serveraddr.sin_port = htons(SERVERPORT);
	Icheck_err = bind(listen_sock, (SOCKADDR *)&serveraddr, sizeof(serveraddr));
	if (Icheck_err == SOCKET_ERROR) err_quit("bind()");

	//listen()
	Icheck_err = listen(listen_sock, SOMAXCONN);
	if (Icheck_err == SOCKET_ERROR) err_quit("listen()");

	//데이터 통신에 사용할 변수
	SOCKET Sclient_sock;//SOCKET 클라 소켓
	SOCKADDR_IN Sclient_addr;//SOCKET_IN 클라ADDR
	int I_addr_len;//INT ADDRLEN
	//우리의 경우엔 플레이어array+맵array+유령좌표array+조명각도 한 정보... 하나의 구조체로 표현 >> 아직 미제작
	char buf[BUFSIZ];
	ZeroMemory(buf, BUFSIZ);


	while (0/*1*/)
	{
		//accept()
		I_addr_len = sizeof(Sclient_addr);
		Sclient_sock = accept(listen_sock, (SOCKADDR *)&Sclient_addr, &I_addr_len);
		if (Sclient_sock == INVALID_SOCKET) {
			err_display("accept()");
			break;
		}
		//접속 클라 정보 출력
		printf("\n[TCP 서버] 클라이언트 접속: IP 주소=%s, 포트 번호=%d\n",
			inet_ntoa(Sclient_addr.sin_addr), ntohs(Sclient_addr.sin_port));

		while (0/*1*/)	// while조건문 내부에 bool문으로 처리해도 될 것 같은데, game start나 end같은
		{
			//예제코드에선 데이터 받기였는데. >> 보내기로 해야 하지 않을까? : 맵 정보와 귀신 정보 등은 서버가 가지고 있기 때문에
		
			//충돌처리 및 시간경과 처리

			//데이터 받기? 

			//일단 예제 파일처럼 평범하게 만들어놓기만 함.
		}

		//클라소켓 close
		closesocket(Sclient_sock);
	}

	//listen소켓 close
	closesocket(listen_sock);

	//윈속 종료
	WSACleanup();

    return 0;
}

