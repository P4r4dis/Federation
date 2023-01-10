#ifndef __FEDERATION__
#   define __FEDERATION__

#include <iostream>
#include "WarpSystem.hpp"
#include "Destination.hpp"
#include "Borg.hpp"
namespace       Federation {
	namespace   Starfleet {
		class   Ship;
		class   Captain;
		class   Ensign;
	}
	class       Ship;
}

namespace       Federation
{
    namespace   Starfleet
    {
        class   Ship
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
                Captain             *_captain;
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
                void                promote(Federation::Starfleet::Captain *captain);
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
            void                fire(int torpedeos, Borg::Ship *target);
        };
        
        class   Captain
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
                explicit Ensign(std::string  name);
                ~Ensign();
        };
    }
    class   Ship
    {
        private:
            int                 _length;
            int                 _width;
            std::string         _name;
            WarpSystem::Core    *_core;
            Destination         _home{VULCAN};
            Destination         _location;
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
    };
}


#endif  // !__FEDERATION__