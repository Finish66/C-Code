#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<stdio.h>


int main(int argc, char *argv[]){
	int rtVal;
	// rtVal = mkdir(argv[1], S_IRWXU | S_IRWXG);
	rtVal = mkdir("fold/dir1",0777);	
	if(rtVal == -1)
		printf("Error While creating dir\n");
	else
		printf("Created Successfully!!\n");
	return 0;
}
