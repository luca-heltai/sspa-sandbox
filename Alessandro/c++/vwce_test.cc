#include <gtest/gtest.h>

#define EXCLUDE_MAIN

#include "main.cpp"

TEST(Stats, DailyReturns)
{
  std::vector<PricePoint> prices = {{.close = 100}, {.close = 110}};
  auto r = daily_returns(prices);
  EXPECT_EQ(r.size(), 1);
  EXPECT_NEAR(r[0], 0.1, 1e-12);
}

TEST(Stats, LoadWritePrices)
{
  // Load a test CSV file
  std::string test_csv = "./data_test.csv";
  auto prices = load_prices(test_csv);
  EXPECT_EQ(prices.size(), 5);

  // Write to a file and reload to verify correctness
  write_prices(prices, "./data_test_out.csv");
  auto prices_reloaded = load_prices("./data_test_out.csv");
  ASSERT_EQ(prices.size(), prices_reloaded.size());   // stop if they have not the same size
  // compare all fields
  for (size_t i = 0; i < prices.size(); ++i)
    {
      EXPECT_EQ       (prices[i].date,      prices_reloaded[i].date     );
      EXPECT_DOUBLE_EQ(prices[i].open,      prices_reloaded[i].open     );
      EXPECT_DOUBLE_EQ(prices[i].high,      prices_reloaded[i].high     );
      EXPECT_DOUBLE_EQ(prices[i].low,       prices_reloaded[i].low      );
      EXPECT_DOUBLE_EQ(prices[i].close,     prices_reloaded[i].close    );
      EXPECT_DOUBLE_EQ(prices[i].adj_close, prices_reloaded[i].adj_close);
      EXPECT_EQ       (prices[i].volume,    prices_reloaded[i].volume   );
    }
}

int main(int argc, char **argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}