#include <stdio.h>
#include <fcntl.h>
int main()
{
  int fd, sz,ss;
  char *c = (char *)calloc(100, sizeof(char));
  char *d = (char *)calloc(100, sizeof(char));
  char *e = (char *)calloc(100, sizeof(char));
  fd = open("os.txt", O_RDWR);
  if (fd < 0) {
    perror("r1");
    exit(1);
  }
  sz = read(fd, c, 30);
  c[sz] = '\0';
  printf("First 30 Bytes : \n\n");
  printf("%s\n\n", c);
  // Skipping
  lseek(fd, 15, SEEK_CUR);

  ss = read(fd, d, 30);
  d[ss] = '\0';
  printf("Skipping 15 Bytes : \n\n");
  printf("%s", d);
  lseek(fd,0,SEEK_END); if (fd < 0)
  {
    perror("r1");
    exit(1);
  }
  char ae[100] = {};
  printf("Enter a string");
  gets(ae);
  write(fd, " ", strlen(" "));
  write(fd, ae, strlen(ae));
  printf("\n\nWritten Successfully\n");
  lseek(fd,0,SEEK_SET);
  int st;
  st = read(fd, e, 10000);

  printf("Entire file : ");
  printf("\n%s\n", e);
  int count=0;
  char vowels[] = {'a', 'A', 'e', 'E', 'i', 'I', 'o', 'O', 'u', 'U'};
  for (int i = 0; i < 1000; i++) {
    for (int j = 0; j < 10; j++) {
      if (c[i] == vowels[j]) {
        count++;
      }
    }
  }
  printf("\nNo of vowels : %d", count);
}