#ifndef __MY_FEDERATION__
#   define __MY_FEDERATION__

#include <iostream>
#include "WarpSystem.hpp"
namespace Federation
{
    namespace Starfleet
    {
        class Ship
        {
            private:
                int                 _length;
                int                 _width;
                std::string         _name;
                short               _maxWarp;
                WarpSystem::Core    *_core;


            public:
                Ship(int            length,
                    int             width,
                    std::string     name,
                    short           maxWarp);
                ~Ship();
                void                setupCore(WarpSystem::Core *core);
                void                checkCore(void);


        };
    }
}


#endif  // !__MY_FEDERATION__