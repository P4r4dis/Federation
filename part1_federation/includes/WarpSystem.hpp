#ifndef __WARPSYSTEM__
#   define __WARPSYSTEM__

#include <iostream>
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
}

#endif  // !__WARPSYSTEM__