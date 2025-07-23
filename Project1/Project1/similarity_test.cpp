#include "gmock/gmock.h"
#include "similarity.cpp"

class SimilarityTestFixture : public testing::Test
{
public:
	Similarity similarity;
	void assertIllegalArgument(std::string str1, std::string str2)
	{
		try
		{
			similarity.getSimilarityLength(str1, str2);
			FAIL();
		}
		catch (std::exception e)
		{
			std::cout << e.what() << std::endl;
		}
	}
};

TEST_F(SimilarityTestFixture, getSimilarityLengthWithEmptyString)
{
	assertIllegalArgument("", "AB");
	assertIllegalArgument("AB", "");
	assertIllegalArgument("", "");
}

TEST_F(SimilarityTestFixture, getSimilarityLengthWithoutAlphabet)
{
	assertIllegalArgument("123", "12");
	assertIllegalArgument("12", "123");
	assertIllegalArgument("77", "AB");
}

TEST_F(SimilarityTestFixture, getSimilarityLength)
{
	EXPECT_EQ(similarity.getSimilarityLength("ASD", "DSA"), Similarity::MAX_SCORE);
	EXPECT_EQ(similarity.getSimilarityLength("A", "BB"), Similarity::MIN_SCORE);
	EXPECT_EQ(similarity.getSimilarityLength("AAABB", "BAA"), 20);
	EXPECT_EQ(similarity.getSimilarityLength("AA", "AAE"), 30);
}