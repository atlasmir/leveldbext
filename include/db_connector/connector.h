//
// Created by xiaofzhao4 on 3/3/2023.
//

#ifndef LEVELDBEXT_INCLUDE_DB_CONNECTOR_CONNECTOR_H_
#define LEVELDBEXT_INCLUDE_DB_CONNECTOR_CONNECTOR_H_

#include "leveldb/db.h"
#include "leveldb/options.h"

namespace leveldbext {

using Status = leveldb::Status;

class Connector {
public:
  Connector() = default;
  virtual ~Connector() = default;

  virtual Status Open(const leveldb::Options &options,
                      const std::string &name) = 0;
  virtual Status Close() = 0;

  virtual Status Put(const leveldb::WriteOptions &options,
                     const std::string &key, const std::string &value) = 0;
  virtual Status Get(const leveldb::ReadOptions &options,
                     const std::string &key, std::string *value) = 0;
  virtual Status Delete(const leveldb::WriteOptions &options,
                        const std::string &key) = 0;

  virtual Status Write(const leveldb::WriteOptions &options,
                       leveldb::WriteBatch *updates) = 0;

  virtual Status NewIterator(const leveldb::ReadOptions &options,
                             leveldb::Iterator **iterator) = 0;
};

class LevelDBConnector : public Connector {
public:
  LevelDBConnector() = default;
  ~LevelDBConnector() override;

  Status Open(const leveldb::Options &options,
              const std::string &name) override;
  Status Close() override;

  Status Put(const leveldb::WriteOptions &options, const std::string &key,
             const std::string &value) override;
  Status Get(const leveldb::ReadOptions &options, const std::string &key,
             std::string *value) override;
  Status Delete(const leveldb::WriteOptions &options,
                const std::string &key) override;

  Status Write(const leveldb::WriteOptions &options,
               leveldb::WriteBatch *updates) override;

  Status NewIterator(const leveldb::ReadOptions &options,
                     leveldb::Iterator **iterator) override;

private:
  leveldb::DB *db_{};
  leveldb::Iterator* iterator_{};
  leveldb::WriteOptions write_options_{};
  leveldb::ReadOptions read_options_{};
};

} // namespace leveldbext

#endif // LEVELDBEXT_INCLUDE_DB_CONNECTOR_CONNECTOR_H_
