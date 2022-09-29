#include <stdio.h>
#include <io.h>
#include "menu.h"

void main() {
  _setmode(_fileno(stdout), 0x00020000);
  execute();
}