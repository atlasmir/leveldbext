//
// Created by xiaofzhao4 on 3/3/2023.
//

#include <filesystem>

#include "spatial/trajdb.h"
#include "gtest/gtest.h"

namespace leveldbext {

TEST(TrajDB, Empty) {
  TrajDB *trajdb = new TrajDB;
  delete trajdb;
}

} // namespace leveldbext