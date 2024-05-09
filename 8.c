#include <dirent.h>
#include <fcntl.h>
#include <pthread.h>
#include <semaphore.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/shm.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

// -------------------- Practical --------------------
// P1 Communication between parent and child process using pipe
int main() {
  int pipefd[2];
  char buffer[25];
  pid_t pid;
  if (pipe(pipefd) == -1) {
    printf("Pile Failed\n");
    return 1;
  }
  pid = fork();
  if (pid > 0) {
    close(pipefd[0]);
    printf("Parent Writing into pipe\n");
    write(pipefd[1], "Hello, Child", 12);
    close(pipefd[1]);
  } else if (pid == 0) {
    close(pipefd[1]);
    printf("Child Reading...\n");
    read(pipefd[0], buffer, 25);
    printf("Data in buffer %s\n", buffer);
    close(pipefd[0]);
  } else {
    printf("Fork Failed\n");
  }
}

// P2 "How can I create a simple IPC in C using named pipes (FIFOs)?"
int main() {
  int pid, fd1, fd2;
  char buffer[20];
  mkfifo("mypipe", 0666);
  pid = fork();

  if (pid > 0) {
    fd1 = open("mypipe", O_WRONLY);
    write(fd1, "Hello Child", 20);
  } else if (pid == 0) {
    fd2 = open("mypipe", O_RDONLY);
    read(fd2, buffer, 20);
    printf("Child Read: %s\n", buffer);
  }
  return 0;
}

// P3 shared memory segment creation and data addition
#define SHM_SIZE 1024
int main() {
  char buffer[100];
  int shmid;
  void *shm;

  if ((shmid = shmget((key_t)123, SHM_SIZE, 0666 | IPC_CREAT)) == -1) {
    printf("Shared Memory Get Failed\n");
    exit(1);
  }
  printf("Key value of Shared memory is: %d\n", shmid);

  if ((shm = shmat(shmid, NULL, 0)) == (void *)-1) {
    printf("Shared Memory Attachment Failed\n");
    exit(1);
  }
  printf("Process Attached Address: %d\n", shmid);

  printf("Write data to shared memory: \n");
  fgets(buffer, sizeof(buffer), stdin);
  strcpy(shm, buffer);
  printf("Data in shared memory: %s\n", (char *)shm);

  if (shmdt(shm) == -1) {
    printf("Shared Memory De-Attachment Failed\n");
    exit(1);
  }

  return 0;
}

// -------------------- Questions --------------------
// Q1
//  Create two named pipes: one for sending data and one for receiving data.
//  Write a sender program that sends a message to the sending pipe.
//  Write a receiver program that reads from the receiving pipe and displays the
//  message.
int main() {
  int fdSend;
  char message[] = "Hello, Receiver";
  mkfifo("sendpipe", 0666);
  fdSend = open("sendpipe", O_WRONLY);
  write(fdSend, message, sizeof(message));
  close(fdSend);
  return 0;
}
int main() {
  int fdReceive;
  char buffer[100];
  mkfifo("recivepipe", 0666);
  fdReceive = open("recivepipe", O_RDONLY);
  write(fdReceive, buffer, sizeof(buffer));
  printf("Message Received: %s\n", buffer);
  close(fdReceive);
  return 0;
}

// Q2
// Create a shared memory segment and attach it to multiple processes.
// Develop a producer-consumer model, where one process writes data into the
// shared memory, and another process reads from it.
// Producer
#define SHM_SIZE 1024
int main() {
  key_t key = 1234;
  int shmid;
  void *shm;
  char msg[] = "Hello, Consumer";

  if ((shmid = shmget(key, SHM_SIZE, 0666 | IPC_CREAT)) == -1) {
    printf("Shared Memory Get Failed\n");
    exit(1);
  }
  if ((shm = shmat(shmid, NULL, 0)) == (void *)-1) {
    printf("Shared Memory Attachment Failed\n");
    exit(1);
  }
  strncpy((char *)shm, msg, SHM_SIZE);

  if (shmdt(shm) == -1) {
    printf("Shared Memory De-Attachment Failed\n");
    exit(1);
  }
}
// Consumer
int main() {
  key_t key = 1234;
  int shmid;
  void *shm;
  char buffer[SHM_SIZE];
  if ((shmid = shmget(key, SHM_SIZE, 0666)) == -1) {
    printf("Shared Memory Get Failed\n");
    exit(1);
  }

  if ((shm = shmat(shmid, NULL, 0)) == (void *)-1) {
    printf("Shared Memory Attachment Failed\n");
  }
  strcpy(buffer, (char *)shm);
  printf("Message received from the Producer: %s\n", buffer);
  if (shmdt(shm) == -1) {
    printf("Shared Memory De-Attachment Failed\n");
    exit(1);
  }
}

// Q3
// Design two processes where one process sends a signal to another process.
// Develop signal handlers in both processes to manage incoming signals and
// perform specificcat 81 actions based on the received signal.
void signal_handler(int signum) {
  if (signum == SIGUSR1) {
    printf("Received SIGUSR1 signal.\n");
  }
}
int main() {
  signal(SIGUSR1, signal_handler);
  pid_t pid = fork();
  if (pid < 0) {
    perror("fork");
    exit(EXIT_FAILURE);
  } else if (pid == 0) {
    printf("Receiver: Waiting for signal...\n");
    while (1) {
      sleep(1);
    }
  } else {
    sleep(1);
    printf("Sender: Sending signal to receiver...\n");
    kill(pid, SIGUSR1);
    wait(NULL);
    printf("Sender: Finished.\n");
  }
  return 0;
}

// Q4 Duplication of file descriptor
int main() {
  int fd1, fd2;
  fd1 = open("input.txt", O_RDWR | O_CREAT);
  fd2 = dup(fd1);

  printf("FD 1: %d\n", fd1);
  printf("FD 2: %d\n", fd2);
  // write(fd1, "Written To old fd\n", 19);
  // write(fd2, "Written To new fd\n", 19);
  // dup2(fd1, 1);
  dup2(1, fd1);
  printf("Hello World!\n");
  return 0;
  close(fd1);
  close(fd2);
}
