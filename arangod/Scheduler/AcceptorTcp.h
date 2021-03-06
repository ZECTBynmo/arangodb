////////////////////////////////////////////////////////////////////////////////
/// DISCLAIMER
///
/// Copyright 2016 ArangoDB GmbH, Cologne, Germany
///
/// Licensed under the Apache License, Version 2.0 (the "License");
/// you may not use this file except in compliance with the License.
/// You may obtain a copy of the License at
///
///     http://www.apache.org/licenses/LICENSE-2.0
///
/// Unless required by applicable law or agreed to in writing, software
/// distributed under the License is distributed on an "AS IS" BASIS,
/// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
/// See the License for the specific language governing permissions and
/// limitations under the License.
///
/// Copyright holder is ArangoDB GmbH, Cologne, Germany
///
/// @author Andreas Streichardt
////////////////////////////////////////////////////////////////////////////////

#ifndef ARANGOD_SCHEDULER_ACCEPTORTCP_H
#define ARANGOD_SCHEDULER_ACCEPTORTCP_H 1

#include "Scheduler/Acceptor.h"

namespace arangodb {
class AcceptorTcp final : public Acceptor {
  public:
    AcceptorTcp(boost::asio::io_service& ioService, Endpoint* endpoint)
    : Acceptor(ioService, endpoint),
      _acceptor(ioService) {
    }

    void open() override;
    void close() override { _acceptor.close(); };
    void asyncAccept(Acceptor::AcceptHandler const& handler) override;
    void createPeer() override;

  private:
    boost::asio::ip::tcp::acceptor _acceptor;
};
}

#endif
