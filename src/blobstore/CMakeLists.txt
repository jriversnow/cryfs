project (blobstore)

set(SOURCES
    implementations/onblocks/parallelaccessdatatreestore/ParallelAccessDataTreeStoreAdapter.cpp
    implementations/onblocks/parallelaccessdatatreestore/DataTreeRef.cpp
    implementations/onblocks/parallelaccessdatatreestore/ParallelAccessDataTreeStore.cpp
    implementations/onblocks/utils/Math.cpp
    implementations/onblocks/BlobStoreOnBlocks.cpp
    implementations/onblocks/datanodestore/DataNode.cpp
    implementations/onblocks/datanodestore/DataLeafNode.cpp
    implementations/onblocks/datanodestore/DataInnerNode.cpp
    implementations/onblocks/datanodestore/DataNodeStore.cpp
    implementations/onblocks/datatreestore/impl/algorithms.cpp
    implementations/onblocks/datatreestore/DataTree.cpp
    implementations/onblocks/datatreestore/DataTreeStore.cpp
    implementations/onblocks/BlobOnBlocks.cpp
)

add_library(${PROJECT_NAME} STATIC ${SOURCES})

target_link_libraries(${PROJECT_NAME} PUBLIC cpp-utils blockstore)

target_add_boost(${PROJECT_NAME} filesystem system thread)
target_enable_style_warnings(${PROJECT_NAME})
target_activate_cpp14(${PROJECT_NAME})
