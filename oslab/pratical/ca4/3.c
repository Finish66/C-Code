#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define SHM_SIZE 2097152 // 2MB

int main() {
    key_t key = ftok("shared_memory_key", 65);
    int shmid = shmget(key, SHM_SIZE, IPC_CREAT | 0666);
    char *shared_memory = (char *)shmat(shmid, NULL, 0);

    strcpy(shared_memory, "hello iam from LPU");

    shmdt(shared_memory);

    return 0;
}
