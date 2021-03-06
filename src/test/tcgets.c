/* -*- Mode: C; tab-width: 8; c-basic-offset: 2; indent-tabs-mode: nil; -*- */

#include "rrutil.h"

int main(int argc, char* argv[]) {
  struct termios tc = { 0 };
  int ret;

  ret = ioctl(STDIN_FILENO, TCGETS, &tc);
  atomic_printf("TCGETS returned %d: { iflag=0x%x, oflag=0x%x, cflag=0x%x, "
                "lflag=0x%x }\n",
                ret, tc.c_iflag, tc.c_oflag, tc.c_cflag, tc.c_lflag);

  atomic_puts("EXIT-SUCCESS");
  return 0;
}
