#ifndef __WARPSYSTEM__
#   define __WARPSYSTEM__

#include <iostream>
namespace   WarpSystem
{
    class   QuantumReactor
    {
        private:
            bool                _stability;
        public:
            QuantumReactor();
            ~QuantumReactor();

            bool                getStability(void);
            bool                isStable(void);

            void                setStability(bool stability);
    };
    
    class   Core
    {
        private:
            QuantumReactor      *_coreReactor;
        public:
            Core(QuantumReactor *coreReactor);
            ~Core();

            QuantumReactor      *checkReactor(void);

    };
}

#endif  // !__WARPSYSTEM__