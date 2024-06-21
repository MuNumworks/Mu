#include <quiz.h>
#include "execution_environment.h"

QUIZ_CASE(python_ion_import) {
  // Test "from mu import *"
  TestExecutionEnvironment env = init_environnement();
  assert_command_execution_fails(env, "destroy_ethan()");
  assert_command_execution_succeeds(env, "from mu import *");
  assert_command_execution_succeeds(env, "destroy_ethan()");
  deinit_environment();

  // "import mu"
  env = init_environnement();
  assert_command_execution_fails(env, "mu.destroy_ethan()");
  assert_command_execution_succeeds(env, "import mu");
  assert_command_execution_succeeds(env, "mu.destroy_ethan()");
  deinit_environment();
}