//
// Created by xiaofzhao4 on 3/3/2023.
//

#include "spatial/trajdb.h"

namespace leveldbext {
  TrajDB::~TrajDB() {
    if (db_ != nullptr) {
      delete db_;
      db_ = nullptr;
    }
  }
} // namespace leveldbext
