

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>


int main(){

    int SIZE = 1024, fd; 
    char buffer[SIZE];

    fd = open("Test.txt",O_RDONLY,0644);

    // Print first 10 characters
    lseek(fd,0,SEEK_SET);
    read(fd,buffer,10);    
    write(1, "First 10 Char: ", sizeof("First 10 Char: "));
    write(1,buffer,10);

    //Print last 10 characters
    lseek(fd,-10,SEEK_END);
    read(fd,buffer,10);
    write(1, "Last 10 Char: ", sizeof("Last 10 Char: "));
    write(1,buffer,10);


}

