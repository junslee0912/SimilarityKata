#include <string>
#include <stdexcept>
#include <cstdlib>
class Similarity
{
public:
    int getSimilarityLength(std::string str1, std::string str2)
    {
        assertIllegalArgument(str1, str2);

        int len1 = str1.size();
        int len2 = str2.size();

        double gap = static_cast<double>(abs(len1 - len2));
        double base = (len1 >= len2) ? static_cast<double>(len2): static_cast<double>(len1);
        double score = (1.0 - gap / base) * 60.0;

        return static_cast<int>(score);
    }

    void assertIllegalArgument(const std::string& str1, const std::string& str2)
    {
        if (str1.size() == 0 || str2.size() == 0)
        {
            throw std::invalid_argument("Need more than one letters.");
        }
    }
};