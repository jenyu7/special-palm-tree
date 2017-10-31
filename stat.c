#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/stat.h>

int dec_to_oct(int num)
{
  if (num < 8)
    {
      return num;
    }
  else
    {
      return num%8+ 10*dec_to_oct(num/8);
    }
}

long oct_to_bin(int num)
{
  if (num < 2)
    {
      return num;
    }
  else
    {
      return num%2+10*oct_to_bin(num/2);
    }
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
  printf("mode of stat.c: %d\n",sb.st_mode);
  printf("mode of stat.c: %d\n",dec_to_oct(sb.st_mode));
  printf("mode of stat.c: %ld\n",oct_to_bin(dec_to_oct(sb.st_mode)));
  printf("last accessed time of stat.c: %s\n", ctime( &sb.st_atime ) );
  return 0;
}
