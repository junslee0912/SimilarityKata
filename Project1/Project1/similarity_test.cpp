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

TEST_F(SimilarityTestFixture, getSimilarityLengthWithExceptionCase)
{
	assertIllegalArgument("", "12");
	assertIllegalArgument("12", "");
	assertIllegalArgument("", "");
}

TEST_F(SimilarityTestFixture, getSimilarityLength)
{
	EXPECT_EQ(similarity.getSimilarityLength("ASD", "DSA"), 60);
	EXPECT_EQ(similarity.getSimilarityLength("A", "BB"), 0);
	EXPECT_EQ(similarity.getSimilarityLength("AAABB", "BAA"), 20);
	EXPECT_EQ(similarity.getSimilarityLength("AA", "AAE"), 30);
}