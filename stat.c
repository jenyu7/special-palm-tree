#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/stat.h>

int main () {
  struct stat sb;
  stat("stat.c", &sb);
  char str[80];
  sprintf(str, "size of stat.c in bytes: %lu\n", sb.st_size);
  printf("%s", str);
  printf("mode of stat.c: %o\n", sb.st_mode);
  printf("last accessed time of stat.c: %s\n", ctime( &sb.st_atime ) );
  return 0;
}
