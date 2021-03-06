/* -*- Mode: C; tab-width: 8; c-basic-offset: 2; indent-tabs-mode: nil; -*- */

#include "rrutil.h"

static void handle_sigtrap(int sig) {
  atomic_puts("EXIT-SUCCESS");
  _exit(0);
}

int main(int argc, char* argv[]) {
  signal(SIGTRAP, handle_sigtrap);

  atomic_puts("raising SIGTRAP ...");

  raise(SIGTRAP);

  return 0;
}
