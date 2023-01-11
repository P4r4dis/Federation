#ifndef         __ADMIRAL__
# define        __ADMIRAL__

#include <string>
#include "Federation.hpp"

namespace       Federation
{
    namespace   Starfleet
    {
        class   Ship;
        class   Captain;
        class   Ensign;
    };
    class       Ship;
}
namespace       Federation
{
    namespace   Starfleet
    {
        class   Admiral
        {
            private:
                std::string             _name;
            public:
                Admiral(std::string     name);
                ~Admiral(void);

                std::string             getName(void);
                bool            (Federation::Starfleet::Ship::*movePtr) (Destination destination);
                bool            move(Federation::Starfleet::Ship *ship, Destination dest);

                // void            (Borg::Ship::*firePtr) (Borg::Ship *ship);
                // void            fire(Federation::Starfleet::Ship *ship, Borg::Ship *target);
        };
    }
}
#endif //       !__ADMIRAL__