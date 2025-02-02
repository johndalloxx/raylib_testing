#include "control_group.c"
#include "helpers.c"
#include <inttypes.h>
#include <stdint.h>

int main(int argc, char *argv[]) {
  ControlGroup controlGroup = {.sectionOne = 0,
                               .sectionTwo = 0xFFFFFFFFFFFFFFFF};
  print_binary(controlGroup.sectionOne);
  ControlGroupToggleUnit(&controlGroup, 0);
  print_binary(controlGroup.sectionOne);
  ControlGroupToggleUnit(&controlGroup, 0);
  print_binary(controlGroup.sectionOne);
  ControlGroupToggleUnit(&controlGroup, 0);
  print_binary(controlGroup.sectionOne);
  return 0;
}
