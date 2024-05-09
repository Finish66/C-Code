#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

// P1 A program to create a child process using fork system call
int main() {
  pid_t pid;
  pid = fork();
  if (pid > 0) {
    printf("Parent process PID: %d, PPID: %d\n", getpid(), getppid());
  } else if (pid == 0) {
    printf("Child process PID: %d, PPID: %d\n", getpid(), getppid());
  } else {
    printf("Fork failed\n");
  }
}

// P2 Creation of an orphan process.
int main() {
  pid_t pid = fork();
  if (pid > 0) {
    printf("Parent Process PID: %d\n", getpid());
    exit(0);
  } else if (pid == 0) {
    printf("Child Process running PID: %d, PPID: %d\n", getpid(), getppid());
    sleep(5);
    printf("Child Process completed PID: %d, PPID: %d\n", getpid(), getppid());
  } else {
    printf("Fork Failed\n");
  }
}

// P3 Creation of an Zombie process.
int main() {
  pid_t pid;
  pid = fork();
  if (pid > 0) {
    printf("Parent Sleeping.....");
    sleep(10);
    printf("Parent Process PID: %d\n", getpid());
  } else if (pid == 0) {
    printf("Child Process PID:%d, PPID:%d\n", getpid(), getppid());
    exit(0);
  } else {
    printf("Fork Failed\n");
  }
}

// Q1 performing ’n’ consecutive fork() system calls generates a total of 2n − 1
// child processes.
int main() {
  int n;
  printf("Enter the value of 'n': ");
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    fork();
  }
  int total_processes = (1 << n) - 1;
  printf("Total number of child processes generated: %d\n", total_processes);
  return 0;
}

// Q2 Generate following hierarchy: P1 → P2 → P3.Display PID &PPID
int main() {
  pid_t pid2, pid3;
  printf("Process P1 PID: %d, PPID: %d\n", getpid(), getppid());
  pid2 = fork();
  if (pid2 > 0) {
    wait(NULL);
  } else if (pid2 == 0) {
    printf("Process P2 PID: %d, PPID: %d\n", getpid(), getppid());
    pid3 = fork();
    if (pid3 > 0) {
      wait(NULL);
    } else if (pid3 == 0) {
      printf("Process P3 PID: %d, PPID: %d\n", getpid(), getppid());
    } else {
      printf("Fork pid3 Failed\n");
    }
  } else {
    printf("Fork pid2 Failed\n");
  }
}

// Q3 MAke a Heirarchy P1 → P2 → P3 → P4 → P5 → P6
int main() {
  pid_t pid_A, pid_B, pid_C, pid_D, pid_E, pid_F;
  printf("PID: %d, PPID: %d - Process P1 (Root)\n", getpid(), getppid());
  pid_A = fork();
  if (pid_A == 0) {
    printf("PID: %d, PPID: %d - Process P2\n", getpid(), getppid());
    pid_C = fork();
    if (pid_C == 0) {
      printf("PID: %d, PPID: %d - Process P4\n", getpid(), getppid());
    } else {
      pid_D = fork();
      if (pid_D == 0) {
        printf("PID: %d, PPID: %d - Process P5\n", getpid(), getppid());
      }
    }
  } else {
    pid_B = fork();
    if (pid_B == 0) {
      printf("PID: %d, PPID: %d - Process P3\n", getpid(), getppid());
      pid_F = fork();
      if (pid_F == 0) {
        printf("PID: %d, PPID: %d - Process P6\n", getpid(), getppid());
      }
    } else {
      wait(NULL);
    }
  }
  return 0;
}

// Q4 Wait system call to avoid
int main() {
  pid_t pid;
  int status;
  pid = fork();

  if (pid == 0) {
    printf("Child running\n");
    sleep(2);
    printf("Child exiting\n");
    exit(0);
  } else {
    printf("Parent wating for child...\n");
    wait(&status);
    printf("Child process exited with %d\n", status);
  }
  return 0;
}
