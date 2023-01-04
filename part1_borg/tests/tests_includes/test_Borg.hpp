#ifndef __TEST_BORG__
#   define __TEST_BORG__

#include <criterion/criterion.h>
#include <criterion/new/assert.h>
#include <criterion/redirect.h>
#include <criterion/logging.h>
#include <criterion/parameterized.h>
#include <signal.h>

#include "../../../part0_federation/includes/WarpSystem.hpp"

void                redirect_all_stdout(void);

namespace                       Borg
{
    class                       Ship
    {
        private:
            int                 _side;
            short               _maxWarp;
            WarpSystem::Core    *_core;
        public:
            Ship();
            ~Ship();

            void                setupCore(WarpSystem::Core *core);
            WarpSystem::Core    *getCore(void);

    };
}

#endif  // !__TEST_BORG__