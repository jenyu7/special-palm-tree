#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/stat.h>

char* det_size(long size)
{
  
}

int main () {
  struct stat sb;
  stat("stat.c", &sb);
  char * units[] = {"B", "KB", "MB", "GB"};
  int ctr = 0;
  float size = (float)sb.st_size;
  while (size > 1024) {
    size /= 1024;
    ctr++;
  }
  printf("size of stat.c: %f %s\n", size, units[ctr]);
  printf("mode of stat.c: %o\n", sb.st_mode);
  printf("last accessed time of stat.c: %s\n", ctime( &sb.st_atime ) );
  return 0;
}
