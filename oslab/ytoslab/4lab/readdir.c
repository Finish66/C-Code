#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <dirent.h>


int main()
{
	DIR *dir;
	struct dirent *entry;

	dir = opendir("/");

	if(dir){
		printf("Contents of directory\n");
		while((entry = readdir(dir)) != NULL){
			printf("%s\n", entry->d_name);
			printf("%ld\n", entry->d_ino);
		}
		closedir(dir);
	}
}

