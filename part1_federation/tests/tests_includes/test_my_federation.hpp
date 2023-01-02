#ifndef __TEST_MY_FEDERATION__
#   define __TEST_MY_FEDERATION__

#include <criterion/criterion.h>
#include <criterion/new/assert.h>
#include <criterion/redirect.h>
#include <criterion/logging.h>
#include <criterion/parameterized.h>
#include <signal.h>


void                redirect_all_stdout(void);

namespace Federation
{
    namespace Starfleet
    {
        class Ship
        {
            private:
                int             _length;
                int             _width;
                std::string     _name;
                short           _maxWarp;

            public:
                Ship(int        length,
                    int         width,
                    std::string name,
                    short       maxWarp);
                ~Ship();
        };
    }
}

#endif  // !__TEST_MY_FEDERATION__