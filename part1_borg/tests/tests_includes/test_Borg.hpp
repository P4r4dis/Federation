#ifndef __TEST_BORG__
#   define __TEST_BORG__

#include <criterion/criterion.h>
#include <criterion/new/assert.h>
#include <criterion/redirect.h>
#include <criterion/logging.h>
#include <criterion/parameterized.h>
#include <signal.h>

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

            public:
                Ship(int            length,
                    int             width,
                    std::string     name,
                    short           maxWarp);
                ~Ship();
                void                setupCore(WarpSystem::Core *core);
                void                checkCore(void);
                void                promote(Captain *captain);
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

            public:
                Ship(int            length,
                    int             width,
                    std::string     name);
                ~Ship();
                void                setupCore(WarpSystem::Core *core);
                void                checkCore(void);
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
        public:
            Ship();
            ~Ship();

            void                setupCore(WarpSystem::Core *core);
            WarpSystem::Core    *getCore(void);

            void                checkCore(void);

    };
}

#endif  // !__TEST_BORG__