#ifndef __BORG__
#   define __BORG__

#include "../../part0_federation/includes/WarpSystem.hpp"
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

            void                checkCore(void);

    };
}

#endif  // !__BORG__