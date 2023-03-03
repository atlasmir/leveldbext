//
// Created by xiaofzhao4 on 3/3/2023.
//

#ifndef LEVELDBEXT_INCLUDE_SPATIAL_TRAJDB_H_
#define LEVELDBEXT_INCLUDE_SPATIAL_TRAJDB_H_

#include "leveldb/db.h"

using Status = leveldb::Status;

namespace leveldbext {

class TrajDB {
public:
  TrajDB() = default;
  ~TrajDB();

  Status Open(const leveldb::Options &options, const std::string &name){
    return leveldb::DB::Open(options, name, &db_);
  }

private:
  leveldb::DB *db_{};
};

} // namespace leveldbext

#endif // LEVELDBEXT_INCLUDE_SPATIAL_TRAJDB_H_
