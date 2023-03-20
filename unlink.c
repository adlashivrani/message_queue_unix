#include "header.h"

int main()
{
	mqd_t sdfd;
	sdfd = mq_open("/mymq", O_RDONLY, 0660,NULL);
	mq_close(sdfd);
	mq_unlink("/mymq");
	return 0;
}
