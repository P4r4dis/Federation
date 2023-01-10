#ifndef __TEST_WAR__
#   define __TEST_WAR__

#include <criterion/criterion.h>
#include <criterion/new/assert.h>
#include <criterion/redirect.h>
#include <criterion/logging.h>
#include <criterion/parameterized.h>
#include <signal.h>
#include "test_destination.hpp"

void                redirect_all_stdout(void);

namespace WarpSystem
{
	class QuantumReactor;
	class Core;
}

namespace   Borg
{
    class Ship;
}

namespace   Federation
{
    namespace Starfleet
    {
        class Ship;
        class Captain;
        class Ensign;
    }
    class Ship;
}


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
                Destination         _home{EARTH};
                Destination         _location;
                int                 _shield;
                int                 _torpedo;
                Federation::Starfleet::Captain             *_captain;

            public:
                Ship(int            length,
                    int             width,
                    std::string     name,
                    short           maxWarp,
                    int             torpedo);
                Ship();
                ~Ship();
                void                setupCore(WarpSystem::Core *core);
                void                checkCore(void);
                void                promote(Captain *captain);
                Destination         getLocation(void);
                Destination         getHome(void);
                bool                move(int warp, Destination d); // set _location to d
                bool                move(int warp); // set _location to _home
                bool                move(Destination d); // set _location to d
                bool                move(void); // set _location to _home
                int                 getShield(void);
                void                setShield(int shield);
                int                 getTorpedo(void);
                void                setTorpedo(int torpedo);
                void                fire(Borg::Ship *target);
                void                fire(int torpedoes, Borg::Ship *target);
        };

        class Captain
        {
            private:
                std::string         _name;
                int                 _age;
            public:
                Captain(std::string name);
                ~Captain();

                std::string         getName(void);
                int                 getAge(void);
                void                setAge(int  age);

        };

        class Ensign
        {
            private:
                std::string         _name;
            public:
                Ensign(std::string  name);
                ~Ensign();
        };
    }

            class Ship
        {
            private:
                int                 _length;
                int                 _width;
                std::string         _name;
                WarpSystem::Core    *_core;
                Destination         _home{VULCAN};
                Destination         _location;
                // Federation::Ship    *_core;
            public:
                Ship(int            length,
                    int             width,
                    std::string     name);
                ~Ship();
                void                setupCore(WarpSystem::Core *core);
                void                checkCore(void);
                Destination         getLocation(void);
                Destination         getHome(void);
                int                 getMaxWarp(void);
                bool                move(int warp, Destination d); // set _location to d
                bool                move(int warp); // set _location to _home
                bool                move(Destination d); // set _location to d
                bool                move(void); // set _location to _home
                WarpSystem::Core    *getCore(void);
        };
}

namespace WarpSystem
{
    class QuantumReactor
    {
        private:
            bool    _stability;
        public:
            QuantumReactor();
            ~QuantumReactor();

            bool    getStability(void);
            bool    isStable(void);

            void    setStability(bool stability);
    };

    class Core
    {
        private:
            QuantumReactor *_coreReactor;
        public:
            Core(QuantumReactor *coreReactor);
            ~Core();

            QuantumReactor  *checkReactor(void);
    };
}

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
    };
}

#endif  // !__TEST_WAR__