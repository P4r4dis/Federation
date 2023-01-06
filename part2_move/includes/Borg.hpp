#ifndef __BORG__
#   define __BORG__

#include "WarpSystem.hpp"
#include "Destination.hpp"
namespace                       Borg
{
    class                       Ship
    {
        private:
            int                 _side;
            short               _maxWarp;
            WarpSystem::Core    *_core;
            Destination         _home{UNICOMPLEX};
            Destination         _location;
        public:
            Ship();
            ~Ship();

            void                setupCore(WarpSystem::Core *core);
            WarpSystem::Core    *getCore(void);

            void                checkCore(void);
            Destination         getLocation(void);
            Destination         getHome(void);

    };
}

#endif  // !__BORG__