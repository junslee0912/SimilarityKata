#include <string>
#include <stdexcept>
#include <cstdlib>
class Similarity
{
public:
    static constexpr int MAX_SCORE = 60;
    static constexpr int MIN_SCORE = 0;
    int getSimilarityLength(const std::string& str1, const std::string& str2)
    {
        assertIllegalArgument(str1, str2);

        int len1 = str1.size();
        int len2 = str2.size();

        double gap = static_cast<double>(abs(len1 - len2));
        double base = (len1 >= len2) ? static_cast<double>(len2): static_cast<double>(len1);
        double score = (1.0 - gap / base) * 60.0;

        return static_cast<int>(score);
    }

private:
    void assertIllegalArgument(const std::string& str1, const std::string& str2)
    {
        if (str1.size() == 0 || str2.size() == 0)
        {
            throw std::invalid_argument("Need more than one letters.");
        }

        for (char ch : str1)
        {
            if (!(IsAlphatbet(ch)))
            {
                throw std::invalid_argument("Need Only Alphabets");
            }
        }

        for (char ch : str2)
        {
            if (!(IsAlphatbet(ch)))
            {
                throw std::invalid_argument("Need Only Alphabets");
            }
        }
    }

    bool IsAlphatbet(char ch)
    {
        return ((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z'));
    }
};