#include "../tests_includes/test_Borg.hpp"
#include <iostream>

void    redirect_all_stdout(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}
