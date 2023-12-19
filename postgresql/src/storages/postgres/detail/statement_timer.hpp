#pragma once

#include <userver/storages/postgres/detail/time_types.hpp>
#include <userver/storages/postgres/query.hpp>

USERVER_NAMESPACE_BEGIN

namespace storages::postgres::detail {

class ConnectionPtr;
class StatementTimingsStorage;

class StatementTimer final {
 public:
  StatementTimer(const Query& query, const ConnectionPtr& conn);

  void Account();

 private:
  static SteadyClock::time_point Now();

  const Query& query_;
  const StatementTimingsStorage* sts_;

  const SteadyClock::time_point start_;
};

}  // namespace storages::postgres::detail

USERVER_NAMESPACE_END
