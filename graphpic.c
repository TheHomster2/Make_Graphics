#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>

int main(){

int fd = open("pic.ppm", O_CREAT | O_WRONLY, 0644);
char buf[512];
write (fd,"P3\n600 600\n180\n", strlen("P3\n600 600\n180\n"));

int x = 0;
int y = 0;
for (x = 0; x < 600; x++){
	for (y = 0; y < 600; y++){
		sprintf(buf, "%d %d %d", x, y / 2, (x + y) / 3);
		write(fd, buf, strlen(buf));
	}
	write(fd, "\n", 1);
}

close(fd);
return 0;
}