#include <stdio.h>
#include <sys/mman.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>
//int fchmod(int fd, mode_t mode);
//void *mmap(void *addr, size_t length, int prot, int flags,
//		  int fd, off_t offset);
//int open(const char *pathname, int flags);
//int stat(const char *pathname, struct stat *buf);
//int fstat(int fd, struct stat *buf);

int main()
{
	void *des,*src;
	int fin=open("mmap_test.c",O_RDONLY);
	int fout=open("tmp.c",O_RDWR|O_CREAT|O_TRUNC);
	struct stat buf;
	fstat(fin,&buf);
	ftruncate(fout,buf.st_size);
	src=mmap(0,buf.st_size,PROT_READ,MAP_SHARED,fin,0);
	des=mmap(0,buf.st_size,PROT_READ|PROT_WRITE,MAP_SHARED,fout,0);
	memcpy(des,src,buf.st_size);
	munmap(src,buf.st_size);
	munmap(des,buf.st_size);
	fchmod(fout,0664);
	return 0;
}

