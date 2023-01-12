#include<stdio.h>;
#include <fcntl.h>;
int main()
{
int sz;
int fd = open("s.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
if (fd < 0)
{
  perror("r1");
  exit(1);
}

sz = write(fd, "BG1 - rock wrens, barbets, Muscicapidae\nBG2 - fire finchs, pigeons, dodos, rollers\nBG3 - Falcons, Loons, Cranes, Cuckoos, Turkeys\nBG4 - Kiwis, Hombillss, Humming birds, Oil birds",strlen("BG1 - rock wrens, barbets, Muscicapidae\nBG2 - fire finchs, pigeons, dodos, rollers\nBG3 - Falcons, Loons, Cranes, Cuckoos, Turkeys\nBG4 - Kiwis, Hombillss, Humming birds, Oil birds"));
int fc, ss;
char *c = (char *) calloc(100, sizeof(char));
fc = open("s.txt", O_RDWR);
lseek(fc, 10, SEEK_CUR);

ss = read(fc, c, 100);
c[ss] = '\0';
char s[100] = {};
for(int i =0;i<100;i++){
  s[i] = toupper(c[i]);
}
int st;
int ff = open("d.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
if(fd < 0){
  perror("r1");
  exit(1);
}
st = write(ff,s,strlen(s));
}
