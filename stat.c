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

long dec_to_bin(int num)
{
  if (num < 2)
    {
      return num;
    }
  else
    {
      return num%2+10*dec_to_bin(num/2);
    }
}
/*
char* [] get_permissions(int mode)
{
  int mask = 0b111000000;
  int count = 0;
  int i = 0;
  char* per[9];
  char* l[4];
  l[0] = "r";
  l[1] = "w";
  l[2] = "x";
  l[3] = "-";
  while(count++ < 3)
    {
      int new = dec_to_bin(mode&mask);
      printf("mode + mask: %d\n", new);
      int end = i + 3;
      while(i < end)
	{
	   printf("here\n");
	  //new = 
	  if (new%10 == 1)
	    {
	      per[i] = l[count%3-1];
	    }
	  else
	    per[i] = l[3];
	  new /= 10;
	  printf("%s\n", *per);
	  i ++;
	}
      mask = mask >> 3;
      printf("new mask: %d\n", dec_to_bin(mask));
    }
  return per;
}
*/

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
  //printf("mode of stat.c: %s\n",get_permissions(sb.st_mode));
  printf("last accessed time of stat.c: %s\n", ctime( &sb.st_atime ) );
  return 0;
}
