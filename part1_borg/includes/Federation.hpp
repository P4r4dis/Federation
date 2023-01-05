#ifndef __FEDERATION__
#   define __FEDERATION__

#include <iostream>
#include "WarpSystem.hpp"
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


            public:
                Ship(int            length,
                    int             width,
                    std::string     name,
                    short           maxWarp);
                ~Ship();
                void                setupCore(WarpSystem::Core *core);
                void                checkCore(void);


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
    }
        class   Ship
        {
            private:
                int                 _length;
                int                 _width;
                std::string         _name;
                WarpSystem::Core    *_core;

            public:
                Ship(int            length,
                    int             width,
                    std::string     name);
                ~Ship();
                void                setupCore(WarpSystem::Core *core);
                void                checkCore(void);
        };
}


#endif  // !__FEDERATION__