#ifndef SUPPLIER_HANDLER_H_
#define SUPPLIER_HANDLER_H_

#include <unordered_map>

#include "consumer_handler.h"

/**
 *
 * +-----------------+          +-----------------+
 * | remote supplier | -------> | SupplierHandler |
 *
 */

class SupplierHandler {
 public:
  void RouteMessage(const Message& msg);

 private:
  /**
   *  key is from message to define where to go.
   */
  std::unordered_map<std::string, ConsumerHandler*> routing_table_;

  // sock stream? to receive message from remote supplier.

  // need own thread?
};

#endif