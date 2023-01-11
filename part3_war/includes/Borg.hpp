#ifndef __BORG__
#   define __BORG__

#include "WarpSystem.hpp"
#include "Destination.hpp"
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
    
} // namespace Federation

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
            int                 _shield;
            int                 _weaponFrequency;
            short               _repair;
        public:
            Ship(int weaponFrequency = 20, short repair = 3);
            ~Ship();

            void                setupCore(WarpSystem::Core *core);
            WarpSystem::Core    *getCore(void);

            void                checkCore(void);
            Destination         getLocation(void);
            Destination         getHome(void);
            bool                move(int warp, Destination d); // set _location to d
            bool                move(int warp); // set _location to _home
            bool                move(Destination d); // set _location to d
            bool                move(void); // set _location to _home
            int                 getShield(void);
            void                setShield(int shield);
            int                 getWeaponFrequency(void);
            void                setWeaponFrequency(int weaponFrequency);
            short               getRepair(void);
            void                setRepair(short repair);
            void                repair(void);
            void                fire(Federation::Starfleet::Ship *target);
            void                fire(Federation::Ship *target);
    };
}

#endif  // !__BORG__