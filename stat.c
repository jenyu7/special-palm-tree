#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/stat.h>

int main () {
  struct stat sb;
  stat("stat.c", &sb);
  printf("size of stat.c in bytes: %lu\n", sb.st_size);
  printf("mode of stat.c: %d\n", sb.st_mode);
  printf("last accessed time of stat.c: %s\n", ctime( &sb.st_atime ) );
  return 0;
}
