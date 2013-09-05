#include <gtest\gtest.h>
#include <tuple>

#include "Utils.h"

TEST( Utils, CalculateMinimumPitch )
{
  auto pitches = Utils::CalculateMinimumPitch( 1024, 5 );
  EXPECT_EQ( 70, std::get<0>( pitches ) );
  EXPECT_EQ( 75, std::get<1>( pitches ) );

  pitches = Utils::CalculateMinimumPitch( 768, 5 );
  EXPECT_EQ( 60, std::get<0>( pitches ) );
  EXPECT_EQ( 65, std::get<1>( pitches ) );

  pitches = Utils::CalculateMinimumPitch( 608, 9 );
  EXPECT_EQ( 72, std::get<0>( pitches ) );
  EXPECT_EQ( 81, std::get<1>( pitches ) );
}