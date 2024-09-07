#include "get_next_line.h"
#include "../Printf/ft_printf.h"

int main(void) 
{
  int fd;
  char *str;

  fd = open("test.txt", O_RDONLY);
  str = "";
  while (1) {
    str = get_next_line(fd);
    ft_printf("%s", str);
    if (str == NULL)
      break;
    free(str);
  }
  close(fd);
  return 0;
}
