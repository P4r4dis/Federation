#ifndef __TEST_BORG__
#   define __TEST_BORG__

#include <criterion/criterion.h>
#include <criterion/new/assert.h>
#include <criterion/redirect.h>
#include <criterion/logging.h>
#include <criterion/parameterized.h>
#include <signal.h>


void                redirect_all_stdout(void);

#endif  // !__TEST_BORG__