#pragma once
#ifndef BLOBSTORE_IMPLEMENTATIONS_ONBLOCKS_IMPL_DATANODE_H_
#define BLOBSTORE_IMPLEMENTATIONS_ONBLOCKS_IMPL_DATANODE_H_

#include "DataNodeView.h"

#include "blockstore/utils/Data.h"

namespace blobstore {
namespace onblocks {

class DataNode {
public:
  virtual ~DataNode();

  virtual void read(off_t offset, size_t count, blockstore::Data *result) const = 0;
  virtual void write(off_t offset, size_t count, const blockstore::Data &data) = 0;

  virtual void resize(uint64_t newsize_bytes) = 0;
  virtual uint64_t numBytesInThisNode() const = 0;

  static std::unique_ptr<DataNode> load(std::unique_ptr<blockstore::Block> block);
  static std::unique_ptr<DataNode> createNewLeafNode(std::unique_ptr<blockstore::Block> block);
  static std::unique_ptr<DataNode> createNewInnerNode(std::unique_ptr<blockstore::Block> block);

protected:
  DataNode(DataNodeView block);

  DataNodeView _node;
};

}
}


#endif