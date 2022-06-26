#include<sys/socket.h>
#include<stdio.h>
#include<string.h>
#include<netdb.h>
#include<stdlib.h>
#include<unistd.h>
#include<arpa/inet.h>

int main()
{
	char buf[100];
	int a;
	int sock_desc;
	struct sockaddr_in client;
	memset(&client,0,sizeof(client));
	sock_desc=socket(AF_INET,SOCK_STREAM,0);
	
	if(sock_desc==-1)
	{
	printf("Error in socket creation");
	exit(1);
	}
	
	client.sin_family = AF_INET;
	client.sin_addr.s_addr = inet_addr("192.168.38.4");
	client.sin_port = htons(8888);
	
	a = connect(sock_desc,(struct sockaddr*)&client,sizeof(client));
	if(a == -1)
	{
	printf("Error in connecting to server");
	exit(1);
	}
	
	while(1)
	{
		printf("Client: "); //Message for server
		fgets(buf,100,stdin);
		if(strncmp(buf,"bye",3) == 0)
		break;
		a = send(sock_desc,buf,100,0);
		if(a == -1)
		{
			printf("Error in sending");
			exit(1);
		}
		a = recv(sock_desc,buf,100,0);
		if(a == -1)
		{
			printf("Error in receiving");
			exit(1);
		}
		
		printf("\nServer: %s",buf); //Message from  server
	}
	
	close(sock_desc);
	exit(0);
	return 0;
}
