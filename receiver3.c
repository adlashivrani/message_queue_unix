#include "header.h"

int main()
{
	mqd_t rdfd;
    char buff[MAX] = {0};
    FILE *fp;
    rdfd = mq_open("/mymq", O_RDONLY, 0666, NULL);
    fp = fopen("output.txt", "a+");
    int res = mq_receive(rdfd, buff, MAX, 0);
    fwrite(buff, strlen(buff), 1, fp);
	mq_send(rdfd, buff, MAX, 3);
    fclose(fp);
    mq_close(rdfd);
    return 0;
}
