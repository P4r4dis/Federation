#ifndef __MY_FEDERATION__
#   define __MY_FEDERATION__

#include <iostream>
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


#endif  // !__MY_FEDERATION__