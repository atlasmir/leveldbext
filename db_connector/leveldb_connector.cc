//
// Created by xiaofzhao4 on 3/3/2023.
//

#include <iostream>

#include "db_connector/connector.h"

using std::cout, std::endl;

namespace leveldbext {
LevelDBConnector::~LevelDBConnector() { Close(); }

Status LevelDBConnector::Open(const leveldb::Options &options,
                              const std::string &name) {
  return leveldb::DB::Open(options, name, &db_);
}

Status LevelDBConnector::Close() {
  if (db_ != nullptr) {
    delete db_;
    db_ = nullptr;
  }

  if (iterator_ != nullptr) {
    delete iterator_;
    iterator_ = nullptr;
  }

  cout << "DB connection closed." << endl;

  return Status::OK();
}

Status LevelDBConnector::Put(const leveldb::WriteOptions &options,
                             const std::string &key, const std::string &value) {
  return db_->Put(options, key, value);
}

Status LevelDBConnector::Get(const leveldb::ReadOptions &options,
                             const std::string &key, std::string *value) {
  return db_->Get(options, key, value);
}

Status LevelDBConnector::Delete(const leveldb::WriteOptions &options,
                                const std::string &key) {
  return db_->Delete(options, key);
}

Status LevelDBConnector::Write(const leveldb::WriteOptions &options,
                               leveldb::WriteBatch *updates) {
  return db_->Write(options, updates);
}

Status LevelDBConnector::NewIterator(const leveldb::ReadOptions &options,
                                     leveldb::Iterator **iterator) {
  *iterator = db_->NewIterator(read_options_);
  return Status::OK();
}

} // namespace leveldbext