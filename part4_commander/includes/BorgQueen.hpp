#ifndef         __BORGQUEEN__
# define        __BORGQUEEN__

#include "Borg.hpp"

namespace   Borg
{
    class   Ship;
}

namespace   Borg
{
    class   BorgQueen
    {
        private:
        public:
            BorgQueen(void);
            ~BorgQueen(void);

            bool                (Borg::Ship::*movePtr) (Destination destination);
            bool                move(Borg::Ship *ship, Destination dest);

            void                (Borg::Ship::*firePtr) (Federation::Starfleet::Ship *ship);
            void                fire(Borg::Ship *ship,  Federation::Starfleet::Ship *target);
    };
}
#endif //       !__BORGQUEEN__