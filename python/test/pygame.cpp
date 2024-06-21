#include <quiz.h>
#include "execution_environment.h"

QUIZ_CASE(python_pygame_import) {
  // Test "from pygame import *"
  TestExecutionEnvironment env = init_environment();
  assert_command_execution_fails(env, "init()");
  assert_command_execution_succeeds(env, "from pygame import *");
  assert_command_execution_succeeds(env, "init()");
  deinit_environment(env);

  // "import pygame"
  env = init_environment();
  assert_command_execution_fails(env, "pygame.init()");
  assert_command_execution_succeeds(env, "import pygame");
  assert_command_execution_succeeds(env, "pygame.init()");
  deinit_environment(env);
}
