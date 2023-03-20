#include "header.h"

	
int main()
{
	mqd_t sdfd;//msg queue sender fd
	struct mq_attr att;//structure of attributes
	
	//from structure
	att.mq_flags = 0;
	att.mq_maxmsg = 10;
	att.mq_msgsize = MAX;
	att.mq_curmsgs = 0;
	
	char buff1[MAX] = {0}; // buff1 for receiver1
	char buff2[MAX] = {0};
	char buff3[MAX] = {0};
	
	int res;
	sdfd = mq_open("/mymq", O_CREAT | O_RDWR, 0666, &att);
	//error checking for sender fd
	if (sdfd == -1) {
		printf("\nsending failed\n");
		exit(1);
	}
	while (1) {
		mq_receive(sdfd, buff1, MAX, 0);
		printf("\nCLient message...:\n %s\n", buff1);
		printf("\nEnter msg..\n");
		fgets(buff2, MAX, stdin);
		//send msg queue sender fd to buff1
		if((res = mq_send(sdfd, buff2, MAX, 0)) == -1) {
			printf("\nSending failed..\n");
			exit(1);
		}
	}
	/*
    //send msg queue sender fd to buff2
    if((res = mq_send(sdfd, buff2, strlen(buff2), 2)) == -1) {
    	exit(1);
    }
	
    //send msg queue sender fd to buff3
    if((res = mq_send(sdfd, buff3, strlen(buff3), 1)) == -1) {
    	exit(1);
    }*/
/*	bzero(buff1, MAX);
	bzero(buff2, MAX);
	bzero(buff3, MAX);
	mq_receive(sdfd, buff1, MAX, 1);
	mq_receive(sdfd, buff1, MAX, 2);
	mq_receive(sdfd, buff1, MAX, 3);
	printf("%s\n%s\n%s\n", buff1, buff2, buff3);
	*/
	mq_close(sdfd);
	return 0;
}
