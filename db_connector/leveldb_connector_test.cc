//
// Created by xiaofzhao4 on 3/3/2023.
//

#include <filesystem>

#include "db_connector/connector.h"
#include "gtest/gtest.h"

namespace leveldbext {

TEST(Connector, Empty) {
  Connector *connector = new LevelDBConnector;
  delete connector;
}

TEST(LevelDBConnector, PutGet) {
  leveldb::Options options;
  options.create_if_missing = true;
  leveldb::WriteOptions write_options;
  leveldb::ReadOptions read_options;
  Connector *connector = new LevelDBConnector;
  auto status = connector->Open(options, "test_db");
  EXPECT_TRUE(status.ok());
  status = connector->Put(write_options, "key", "value");
  EXPECT_TRUE(status.ok());
  std::string value;
  status = connector->Get(read_options, "key", &value);
  EXPECT_TRUE(status.ok());
  EXPECT_EQ(value, "value");

  // cleanup
  delete connector;
  std::filesystem::remove_all("test_db");
}

} // namespace leveldbext