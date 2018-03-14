#pragma once
#ifndef MAXY_TRAITS
#define MAXY_TRAITS

namespace maxy
{
    namespace traits
    {
        template<typename What, typename From>
        struct is_explicitly_constructible
        {
            template<typename T, typename F>
            static constexpr auto test (int)
                -> decltype(T{std::declval<F>()}, true)
            {
                return true;
            }

            template<typename T, typename F>
            static constexpr bool test (...)
            {
                return false;
            }

            static const bool value = test<What, From> (0);
        };
    }
}





#endif // MAXY_TRAITS