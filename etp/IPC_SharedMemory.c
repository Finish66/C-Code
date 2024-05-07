//Exercise 2: Demonstrate the usage of Shared Memory for IPC.

#include <stdio.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define SHM_KEY 1234
#define SHM_SIZE 100

int main() {
    int shm_id;
    char *shm_ptr;

    shm_id = shmget(SHM_KEY, SHM_SIZE, IPC_CREAT | 0666);
    shm_ptr = (char *)shmat(shm_id, NULL, 0);

    sprintf(shm_ptr, "Hello, World!");

    shmdt(shm_ptr);
    shmctl(shm_id, IPC_RMID, NULL);

    return 0;
}
