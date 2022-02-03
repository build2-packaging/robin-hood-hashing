

#include <robin_hood.h>

#undef NDEBUG
#include <cassert>

#include <array>
#include <string>

int main ()
{
    {
        robin_hood::unordered_set<int> my_set{5, 4, 3, 2, 1};

        const std::array<int, 5> expected{1, 2, 3, 4, 5};

        assert(std::is_permutation(my_set.begin(), my_set.end(),
                                   expected.begin()));

    }

    {
        robin_hood::unordered_map<int, std::string> my_map;
        my_map[1] = "one";
        my_map[2] = "two";
        my_map[3] = "three";

        assert(my_map.size() == 3);
        assert(my_map.at(1) == "one");
        assert(my_map.at(2) == "two");
        assert(my_map.at(3) == "three");

        try {
            my_map.at(4);
        } catch (std::out_of_range const&) {
            // pass
        }

    }
}
