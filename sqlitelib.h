//
//  sqlitelib.h
//
//  Copyright (c) 2013 Yuji Hirose. All rights reserved.
//  The Boost Software License 1.0
//

#ifndef _CPPSQLITELIB_HTTPSLIB_H_
#define _CPPSQLITELIB_HTTPSLIB_H_

#include <sqlite3.h>

#include <cstring>
#include <memory>
#include <sstream>
#include <stdexcept>
#include <string>
#include <tuple>
#include <type_traits>
#include <vector>

#define SQLITELIB_ENABLE_TYPE_CHECKING


// STRUCT REGISTER MACRO

// clang-format:  off
#define DECLARE_SQLITE_FIELDS(structName, ...) \
static void registerFields(SqliteStruct<structName>& reg) { \
reg SQLITELIB_FOR_EACH_RMAP_IMPL_(structName, __VA_ARGS__); \
}

#define SQLITELIB_MAP_FIELD_(structName, field) .map(&structName::field, #field)

#define SQLITELIB_GET_TH_ARG_( _1,  _2,  _3,  _4,  _5,  _6,  _7,  _8,  _9, _10, \
                              _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, \
                              _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, \
                              NAME, ...) NAME

#define SQLITELIB_FOR_EACH_RMAP_IMPL_(structName, ...) \
    SQLITELIB_GET_TH_ARG_(__VA_ARGS__\
    , SQLITELIB_FOR_EACH_RMAP30_, SQLITELIB_FOR_EACH_RMAP29_, SQLITELIB_FOR_EACH_RMAP28_, SQLITELIB_FOR_EACH_RMAP27_, SQLITELIB_FOR_EACH_RMAP26_ \
    , SQLITELIB_FOR_EACH_RMAP25_, SQLITELIB_FOR_EACH_RMAP24_, SQLITELIB_FOR_EACH_RMAP23_, SQLITELIB_FOR_EACH_RMAP22_, SQLITELIB_FOR_EACH_RMAP21_ \
    , SQLITELIB_FOR_EACH_RMAP20_, SQLITELIB_FOR_EACH_RMAP19_, SQLITELIB_FOR_EACH_RMAP18_, SQLITELIB_FOR_EACH_RMAP17_, SQLITELIB_FOR_EACH_RMAP16_ \
    , SQLITELIB_FOR_EACH_RMAP15_, SQLITELIB_FOR_EACH_RMAP14_, SQLITELIB_FOR_EACH_RMAP13_, SQLITELIB_FOR_EACH_RMAP12_, SQLITELIB_FOR_EACH_RMAP11_ \
    , SQLITELIB_FOR_EACH_RMAP10_, SQLITELIB_FOR_EACH_RMAP09_, SQLITELIB_FOR_EACH_RMAP08_, SQLITELIB_FOR_EACH_RMAP07_, SQLITELIB_FOR_EACH_RMAP06_ \
    , SQLITELIB_FOR_EACH_RMAP05_, SQLITELIB_FOR_EACH_RMAP04_, SQLITELIB_FOR_EACH_RMAP03_, SQLITELIB_FOR_EACH_RMAP02_, SQLITELIB_FOR_EACH_RMAP01_ \
    )(structName, __VA_ARGS__)

#define SQLITELIB_FOR_EACH_RMAP01_(structName, field)      SQLITELIB_MAP_FIELD_(structName, field)
#define SQLITELIB_FOR_EACH_RMAP02_(structName, field, ...) SQLITELIB_MAP_FIELD_(structName, field) SQLITELIB_FOR_EACH_RMAP01_(structName, __VA_ARGS__)
#define SQLITELIB_FOR_EACH_RMAP03_(structName, field, ...) SQLITELIB_MAP_FIELD_(structName, field) SQLITELIB_FOR_EACH_RMAP02_(structName, __VA_ARGS__)
#define SQLITELIB_FOR_EACH_RMAP04_(structName, field, ...) SQLITELIB_MAP_FIELD_(structName, field) SQLITELIB_FOR_EACH_RMAP03_(structName, __VA_ARGS__)
#define SQLITELIB_FOR_EACH_RMAP05_(structName, field, ...) SQLITELIB_MAP_FIELD_(structName, field) SQLITELIB_FOR_EACH_RMAP04_(structName, __VA_ARGS__)
#define SQLITELIB_FOR_EACH_RMAP06_(structName, field, ...) SQLITELIB_MAP_FIELD_(structName, field) SQLITELIB_FOR_EACH_RMAP05_(structName, __VA_ARGS__)
#define SQLITELIB_FOR_EACH_RMAP07_(structName, field, ...) SQLITELIB_MAP_FIELD_(structName, field) SQLITELIB_FOR_EACH_RMAP06_(structName, __VA_ARGS__)
#define SQLITELIB_FOR_EACH_RMAP08_(structName, field, ...) SQLITELIB_MAP_FIELD_(structName, field) SQLITELIB_FOR_EACH_RMAP07_(structName, __VA_ARGS__)
#define SQLITELIB_FOR_EACH_RMAP09_(structName, field, ...) SQLITELIB_MAP_FIELD_(structName, field) SQLITELIB_FOR_EACH_RMAP08_(structName, __VA_ARGS__)
#define SQLITELIB_FOR_EACH_RMAP10_(structName, field, ...) SQLITELIB_MAP_FIELD_(structName, field) SQLITELIB_FOR_EACH_RMAP09_(structName, __VA_ARGS__)
#define SQLITELIB_FOR_EACH_RMAP11_(structName, field, ...) SQLITELIB_MAP_FIELD_(structName, field) SQLITELIB_FOR_EACH_RMAP10_(structName, __VA_ARGS__)
#define SQLITELIB_FOR_EACH_RMAP12_(structName, field, ...) SQLITELIB_MAP_FIELD_(structName, field) SQLITELIB_FOR_EACH_RMAP11_(structName, __VA_ARGS__)
#define SQLITELIB_FOR_EACH_RMAP13_(structName, field, ...) SQLITELIB_MAP_FIELD_(structName, field) SQLITELIB_FOR_EACH_RMAP12_(structName, __VA_ARGS__)
#define SQLITELIB_FOR_EACH_RMAP14_(structName, field, ...) SQLITELIB_MAP_FIELD_(structName, field) SQLITELIB_FOR_EACH_RMAP13_(structName, __VA_ARGS__)
#define SQLITELIB_FOR_EACH_RMAP15_(structName, field, ...) SQLITELIB_MAP_FIELD_(structName, field) SQLITELIB_FOR_EACH_RMAP14_(structName, __VA_ARGS__)
#define SQLITELIB_FOR_EACH_RMAP16_(structName, field, ...) SQLITELIB_MAP_FIELD_(structName, field) SQLITELIB_FOR_EACH_RMAP15_(structName, __VA_ARGS__)
#define SQLITELIB_FOR_EACH_RMAP17_(structName, field, ...) SQLITELIB_MAP_FIELD_(structName, field) SQLITELIB_FOR_EACH_RMAP16_(structName, __VA_ARGS__)
#define SQLITELIB_FOR_EACH_RMAP18_(structName, field, ...) SQLITELIB_MAP_FIELD_(structName, field) SQLITELIB_FOR_EACH_RMAP17_(structName, __VA_ARGS__)
#define SQLITELIB_FOR_EACH_RMAP19_(structName, field, ...) SQLITELIB_MAP_FIELD_(structName, field) SQLITELIB_FOR_EACH_RMAP18_(structName, __VA_ARGS__)
#define SQLITELIB_FOR_EACH_RMAP20_(structName, field, ...) SQLITELIB_MAP_FIELD_(structName, field) SQLITELIB_FOR_EACH_RMAP19_(structName, __VA_ARGS__)
#define SQLITELIB_FOR_EACH_RMAP21_(structName, field, ...) SQLITELIB_MAP_FIELD_(structName, field) SQLITELIB_FOR_EACH_RMAP20_(structName, __VA_ARGS__)
#define SQLITELIB_FOR_EACH_RMAP22_(structName, field, ...) SQLITELIB_MAP_FIELD_(structName, field) SQLITELIB_FOR_EACH_RMAP21_(structName, __VA_ARGS__)
#define SQLITELIB_FOR_EACH_RMAP23_(structName, field, ...) SQLITELIB_MAP_FIELD_(structName, field) SQLITELIB_FOR_EACH_RMAP22_(structName, __VA_ARGS__)
#define SQLITELIB_FOR_EACH_RMAP24_(structName, field, ...) SQLITELIB_MAP_FIELD_(structName, field) SQLITELIB_FOR_EACH_RMAP23_(structName, __VA_ARGS__)
#define SQLITELIB_FOR_EACH_RMAP25_(structName, field, ...) SQLITELIB_MAP_FIELD_(structName, field) SQLITELIB_FOR_EACH_RMAP24_(structName, __VA_ARGS__)
#define SQLITELIB_FOR_EACH_RMAP26_(structName, field, ...) SQLITELIB_MAP_FIELD_(structName, field) SQLITELIB_FOR_EACH_RMAP25_(structName, __VA_ARGS__)
#define SQLITELIB_FOR_EACH_RMAP27_(structName, field, ...) SQLITELIB_MAP_FIELD_(structName, field) SQLITELIB_FOR_EACH_RMAP26_(structName, __VA_ARGS__)
#define SQLITELIB_FOR_EACH_RMAP28_(structName, field, ...) SQLITELIB_MAP_FIELD_(structName, field) SQLITELIB_FOR_EACH_RMAP27_(structName, __VA_ARGS__)
#define SQLITELIB_FOR_EACH_RMAP29_(structName, field, ...) SQLITELIB_MAP_FIELD_(structName, field) SQLITELIB_FOR_EACH_RMAP28_(structName, __VA_ARGS__)
#define SQLITELIB_FOR_EACH_RMAP30_(structName, field, ...) SQLITELIB_MAP_FIELD_(structName, field) SQLITELIB_FOR_EACH_RMAP29_(structName, __VA_ARGS__)

// clang-format: on

namespace sqlitelib {

namespace {

void* enabler;

inline void verify(int rc, int expected = SQLITE_OK) {
  if (rc != expected) {
    throw std::exception();
  }
}
// sqlite3_value_double sqlite3_value

  template <typename T, typename R = T> R get_column_value(sqlite3_value* val);
  template <> int get_column_value<int>(sqlite3_value* val) { return sqlite3_value_int(val); }
  template <> int64_t get_column_value<int64_t>(sqlite3_value* val) { return sqlite3_value_int64(val); }
  template <> uint64_t get_column_value<uint64_t>(sqlite3_value* val) { return static_cast<uint64_t>(sqlite3_value_int64(val)); }
  template <> double get_column_value<double>(sqlite3_value* val) { return sqlite3_value_double(val); }
  template <> float get_column_value<float>(sqlite3_value* val) { return static_cast<float>(sqlite3_value_double(val)); }
  template <> bool get_column_value<bool>(sqlite3_value* val) { return sqlite3_value_int(val) == 1; }
  template <> std::string get_column_value<std::string>(sqlite3_value* val) {
    auto result = std::string(sqlite3_value_bytes(val), 0);
    memcpy(&result[0], sqlite3_value_text(val), result.size());
    return result;
  }
  template <>
  std::string get_column_value<char*, std::string>(sqlite3_value* val) {
    auto result = std::string(sqlite3_value_bytes(val), 0);
    memcpy(&result[0], sqlite3_value_blob(val), result.size());
    return result;
  }
  template <>
  std::string get_column_value<const char*, std::string>(sqlite3_value* val) {
    auto result = std::string(sqlite3_value_bytes(val), 0);
    memcpy(&result[0], sqlite3_value_blob(val), result.size());
    return result;
  }
  template <>
  std::vector<char> get_column_value<std::vector<char>>(sqlite3_value* val) {
    auto result = std::vector<char>(sqlite3_value_bytes(val));
    memcpy(&result[0], sqlite3_value_blob(val), result.size());
    return result;
  }
  template <>
  std::string get_column_value<unsigned char*, std::string>(sqlite3_value* val) {
    auto result = std::string(sqlite3_value_bytes(val), 0);
    memcpy(&result[0], sqlite3_value_blob(val), result.size());
    return result;
  }
  template <>
  std::string get_column_value<const unsigned char*, std::string>(sqlite3_value* val) {
    auto result = std::string(sqlite3_value_bytes(val), 0);
    memcpy(&result[0], sqlite3_value_blob(val), result.size());
    return result;
  }
  template <>
  std::vector<unsigned char> get_column_value<std::vector<unsigned char>>(sqlite3_value* val) {
    auto result = std::vector<unsigned char>(sqlite3_value_bytes(val));
    memcpy(&result[0], sqlite3_value_blob(val), result.size());
    return result;
  }


template <typename T>
T get_column_value(sqlite3_stmt* stmt, int col) {}

template <>
bool get_column_value<bool>(sqlite3_stmt* stmt, int col) {
#ifdef SQLITELIB_ENABLE_TYPE_CHECKING
  auto type = sqlite3_column_type(stmt, col);
  switch (type) {
    case SQLITE_INTEGER: return sqlite3_column_int(stmt, col) != 0;
    case SQLITE_TEXT: {
      std::string text = std::string(sqlite3_column_bytes(stmt, col), 0);
      memcpy(&text[0], sqlite3_column_text(stmt, col), text.size());
      std::transform(text.begin(), text.end(), text.begin(), [](unsigned char c) { return std::tolower(c); });
      // Note: This is not very efficient support, you can do better
      if (text == "1" || text == "t" || text == "true") return true;
      if (text.empty()|| text == "0" || text == "f" || text == "false") return false;
      throw std::runtime_error("Cannot convert column to bool('" + text + "')");
    }
    case SQLITE_NULL:
      return false;
    default:
      throw std::runtime_error("Cannot convert column to bool");
  }
#else
  return sqlite3_column_int(stmt, col) != 0;
#endif

}

  template <>
  int16_t get_column_value<int16_t>(sqlite3_stmt* stmt, int col) {
    auto val = sqlite3_column_int(stmt, col);
#ifdef SQLITELIB_ENABLE_TYPE_CHECKING
    if (val > std::numeric_limits<int16_t>::max() || val < 0) {
      throw std::runtime_error("Value is too large for short");
    }
#endif
    return static_cast<int16_t>(val);
  }

  template <>
  uint16_t get_column_value<uint16_t>(sqlite3_stmt* stmt, int col) {
    auto val = sqlite3_column_int(stmt, col);
#ifdef SQLITELIB_ENABLE_TYPE_CHECKING
    if (val > std::numeric_limits<uint16_t>::max() || val < 0) {
      throw std::runtime_error("Value is too large for ushort");
    }
#endif
    return static_cast<uint16_t>(val);
  }

template <>
int get_column_value<int>(sqlite3_stmt* stmt, int col) {
  return sqlite3_column_int(stmt, col);
}

  template <>
  uint32_t get_column_value<uint32_t>(sqlite3_stmt* stmt, int col) {
    auto val = sqlite3_column_int64(stmt, col);
#ifdef SQLITELIB_ENABLE_TYPE_CHECKING
    if (val > std::numeric_limits<uint32_t>::max() || val < 0) {
      throw std::runtime_error("Value is too large for uint");
    }
#endif
    return static_cast<uint32_t>(val);
  }

template <>
long get_column_value<long>(sqlite3_stmt* stmt, int col) {
  auto val = sqlite3_column_int64(stmt, col);
#ifdef SQLITELIB_ENABLE_TYPE_CHECKING
  if (val > std::numeric_limits<long>::max() || val < std::numeric_limits<long>::min()) {
    throw std::runtime_error("Value is too large for long");
  }
#endif
  return static_cast<long>(val);
}

  template <>
  unsigned long get_column_value<unsigned long>(sqlite3_stmt* stmt, int col) {
    auto val = sqlite3_column_int64(stmt, col);
#ifdef SQLITELIB_ENABLE_TYPE_CHECKING
    if (val > std::numeric_limits<unsigned long>::max() || val < 0) {
      throw std::runtime_error("Value is too large for ulong");
    }
#endif
    return static_cast<unsigned long>(val);
  }

template <>
int64_t get_column_value<int64_t>(sqlite3_stmt* stmt, int col) {
  return sqlite3_column_int64(stmt, col);
}

template <>
uint64_t get_column_value<uint64_t>(sqlite3_stmt* stmt, int col) {
  return static_cast<uint64_t>(sqlite3_column_int64(stmt, col));
}

template <>
double get_column_value<double>(sqlite3_stmt* stmt, int col) {
  return sqlite3_column_double(stmt, col);
}

template <>
float get_column_value<float>(sqlite3_stmt* stmt, int col) {
  return static_cast<float>(sqlite3_column_double(stmt, col));
}

template <>
std::string get_column_value<std::string>(sqlite3_stmt* stmt, int col) {
  std::string val = std::string(sqlite3_column_bytes(stmt, col), 0);
  memcpy(&val[0], sqlite3_column_text(stmt, col), val.size());
  return val;
}

template <>
std::vector<char> get_column_value<std::vector<char>>(sqlite3_stmt* stmt,
                                                      int col) {
  auto val = std::vector<char>(sqlite3_column_bytes(stmt, col));
  memcpy(&val[0], sqlite3_column_blob(stmt, col), val.size());
  return val;
}

template <int N, typename T, typename... Rest>
struct ColumnValues;

template <int N, typename T, typename... Rest>
struct ColumnValues {
  static std::tuple<T, Rest...> get(sqlite3_stmt* stmt, int col) {
    return std::tuple_cat(std::make_tuple(get_column_value<T>(stmt, col)),
                          ColumnValues<N - 1, Rest...>::get(stmt, col + 1));
  }
};

template <typename T>
struct ColumnValues<1, T> {
  static std::tuple<T> get(sqlite3_stmt* stmt, int col) {
    return std::make_tuple(get_column_value<T>(stmt, col));
  }
};

template <typename Arg>
void bind_value(sqlite3_stmt* stmt, int col, Arg val) {}

template <>
void bind_value<bool>(sqlite3_stmt* stmt, int col, bool val) {
  auto type = sqlite3_column_type(stmt, col);
  switch (type) {
    case SQLITE_NULL   : verify(sqlite3_bind_int(stmt, col, val ? 1 : 0)); break;
    case SQLITE_INTEGER: verify(sqlite3_bind_int(stmt, col, val ? 1 : 0)); break;
    case SQLITE_TEXT   : {
      std::string text = val ? "true" : "false";
      verify(sqlite3_bind_text(stmt, col, text.data(), static_cast<int>(text.size()), SQLITE_TRANSIENT));
    } break;
    default:
      throw std::runtime_error("bind value failed");
  }
}

template <>
void bind_value<int16_t>(sqlite3_stmt* stmt, int col, int16_t val) {
  verify(sqlite3_bind_int(stmt, col, val));
}
template <>
void bind_value<uint16_t>(sqlite3_stmt* stmt, int col, uint16_t val) {
  verify(sqlite3_bind_int(stmt, col, val));
}
template <>
void bind_value<int>(sqlite3_stmt* stmt, int col, int val) {
  verify(sqlite3_bind_int(stmt, col, val));
}

template <>
void bind_value<uint32_t>(sqlite3_stmt* stmt, int col, uint32_t val) {
  verify(sqlite3_bind_int64(stmt, col, val));
}

template <>
void bind_value<long>(sqlite3_stmt* stmt, int col, long val) {
  verify(sqlite3_bind_int64(stmt, col, val));
}
template <>
void bind_value<unsigned long>(sqlite3_stmt* stmt, int col, unsigned long val) {
  verify(sqlite3_bind_int64(stmt, col, val));
}

template <>
void bind_value<int64_t>(sqlite3_stmt* stmt, int col, int64_t val) {
  verify(sqlite3_bind_int64(stmt, col, static_cast<sqlite3_int64>(val)));
}

template <>
void bind_value<uint64_t>(sqlite3_stmt* stmt, int col, uint64_t val) {
  verify(sqlite3_bind_int64(stmt, col, static_cast<sqlite3_int64>(val)));
}

template <>
void bind_value<double>(sqlite3_stmt* stmt, int col, double val) {
  verify(sqlite3_bind_double(stmt, col, val));
}

template <>
void bind_value<float>(sqlite3_stmt* stmt, int col, float val) {
  verify(sqlite3_bind_double(stmt, col, static_cast<double>(val)));
}

template <>
void bind_value<std::string>(sqlite3_stmt* stmt, int col, std::string val) {
  verify(sqlite3_bind_text(stmt, col, val.data(), static_cast<int>(val.size()),
                           SQLITE_TRANSIENT));
}

template <>
void bind_value<const char*>(sqlite3_stmt* stmt, int col, const char* val) {
  verify(sqlite3_bind_text(stmt, col, val, static_cast<int>(strlen(val)),
                           SQLITE_TRANSIENT));
}

template <>
void bind_value<std::vector<char>>(sqlite3_stmt* stmt, int col,
                                   std::vector<char> val) {
  verify(sqlite3_bind_blob(stmt, col, val.data(), static_cast<int>(val.size()),
                           SQLITE_TRANSIENT));
}

template <bool isRestEmpty, typename T, typename... Rest>
struct ValueType;

template <typename T, typename... Rest>
struct ValueType<true, T, Rest...> {
  typedef T type;
};

template <typename T, typename... Rest>
struct ValueType<false, T, Rest...> {
  typedef std::tuple<T, Rest...> type;
};

};  // namespace

template <typename T, typename... Rest>
class Iterator {
 public:
  typedef std::forward_iterator_tag iterator_category;
  typedef typename ValueType<!sizeof...(Rest), T, Rest...>::type value_type;
  typedef std::ptrdiff_t difference_type;
  typedef value_type* pointer;
  typedef value_type& reference;

  Iterator() : stmt_(nullptr), id_(-1) {}

  Iterator(sqlite3_stmt* stmt) : stmt_(stmt), id_(-1) { operator++(); }

  template <int RestSize = sizeof...(Rest),
            typename std::enable_if<(RestSize == 0)>::type*& = enabler>
  value_type operator*() const {
    return get_column_value<T>(stmt_, 0);
  }

  template <int RestSize = sizeof...(Rest),
            typename std::enable_if<(RestSize != 0)>::type*& = enabler>
  value_type operator*() const {
    return ColumnValues<1 + sizeof...(Rest), T, Rest...>::get(stmt_, 0);
  }

  Iterator& operator++() {
    if (stmt_) {
      auto rc = sqlite3_step(stmt_);
      if (rc == SQLITE_ROW) {
        ++id_;
      } else if (rc == SQLITE_DONE) {
        id_ = -1;
      } else {
        throw std::exception();  // TODO:
      }
    } else {
      throw std::exception();  // TODO:
    }
    return *this;
  }

  bool operator==(const Iterator& rhs) { return id_ == rhs.id_; }

  bool operator!=(const Iterator& rhs) { return !operator==(rhs); }

  sqlite3_stmt* statement() { return stmt_; }
  int id() { return id_; }
 private:
  sqlite3_stmt* stmt_;
  int id_;
};

inline void sqlite3_stmt_deleter(sqlite3_stmt* stmt) {
  verify(sqlite3_finalize(stmt));
};

template <typename T, typename... Rest>
class Cursor {
 public:
  Cursor() = delete;
  Cursor(const Cursor&) = delete;
  Cursor& operator=(const Cursor&) = delete;

  Cursor(Cursor&& rhs) : stmt_(rhs.stmt_) {}

  Cursor(std::shared_ptr<sqlite3_stmt> stmt) : stmt_(stmt) {}

  Iterator<T, Rest...> begin() { return Iterator<T, Rest...>(stmt_.get()); }

  Iterator<T, Rest...> end() { return Iterator<T, Rest...>(); }

 private:
  std::shared_ptr<sqlite3_stmt> stmt_;
};

template <typename T, typename... Rest>
class Statement {
 public:
  Statement(sqlite3* db, const char* query)
      : stmt_(new_sqlite3_stmt(db, query), sqlite3_stmt_deleter) {}

  Statement(Statement&& rhs) : stmt_(rhs.stmt_) { rhs.stmt_ = nullptr; }

  Statement() = delete;
  Statement(Statement& rhs) = default;
  ~Statement() = default;

  template <typename... Args>
  Statement<T, Rest...>& bind(const Args&... args) {
    verify(sqlite3_reset(stmt_.get()));
    bind_values(1, args...);
    return *this;
  }

  template <
      typename U = T,
      typename std::enable_if<std::is_same<U, void>::value>::type*& = enabler,
      typename... Args>
  void execute(const Args&... args) {
    bind(args...);
    verify(sqlite3_step(stmt_.get()), SQLITE_DONE);
  }

  template <
      typename U = T,
      typename std::enable_if<!std::is_same<U, void>::value>::type*& = enabler,
      typename V = typename ValueType<!sizeof...(Rest), T, Rest...>::type,
      typename... Args>
  std::vector<V> execute(const Args&... args) {
    std::vector<V> ret;
    for (const auto& x : execute_cursor(args...)) {
      ret.push_back(x);
    }
    return ret;
  }

  template <typename... Args>
  T execute_value(const Args&... args) {
    auto cursor = execute_cursor(args...);
    return *cursor.begin();
  }

  template <typename... Args>
  Cursor<T, Rest...> execute_cursor(const Args&... args) {
    bind(args...);
    return Cursor<T, Rest...>(stmt_);
  }

 private:
  Statement& operator=(const Statement& rhs);

  sqlite3_stmt* new_sqlite3_stmt(sqlite3* db, const char* query) {
    sqlite3_stmt* p = nullptr;
    verify(sqlite3_prepare(db, query, static_cast<int>(strlen(query)), &p,
                           nullptr));
    return p;
  }

  void bind_values(int col) {}

  template <typename Arg, typename... ArgRest>
  void bind_values(int col, const Arg& val, const ArgRest&... rest) {
    bind_value(stmt_.get(), col, val);
    bind_values(col + 1, rest...);
  }

  std::shared_ptr<sqlite3_stmt> stmt_;
};

class Sqlite {
 public:
  Sqlite() = delete;
  Sqlite(const Sqlite&) = delete;
  Sqlite& operator=(const Sqlite&) = delete;

  Sqlite(const char* path) : db_(nullptr) {
    auto rc = sqlite3_open(path, &db_);
    if (rc) {
      sqlite3_close(db_);
      db_ = nullptr;
    }
  }

  Sqlite(Sqlite&& rhs) : db_(rhs.db_) {}

  ~Sqlite() {
    if (db_) {
      sqlite3_close(db_);
    }
  }

  bool is_open() const { return db_ != nullptr; }

  Statement<void> prepare(const char* query) const {
    return Statement<void>(db_, query);
  }

  template <typename... Types>
  Statement<Types...> prepare(const char* query) const {
    return Statement<Types...>(db_, query);
  }

  template <typename... Args>
  void execute(const char* query, const Args&... args) {
    prepare<void>(query).execute(args...);
  }

  template <
      typename T, typename... Rest,
      typename std::enable_if<!std::is_same<T, void>::value>::type*& = enabler,
      typename... Args>
  std::vector<typename ValueType<!sizeof...(Rest), T, Rest...>::type> execute(
      const char* query, const Args&... args) {
    return prepare<T, Rest...>(query).execute(args...);
  }

  template <typename T, typename... Args>
  T execute_value(const char* query, const Args&... args) {
    return prepare<T>(query).execute_value(args...);
  }

  template <typename T, typename... Rest, typename... Args>
  Cursor<T, Rest...> execute_cursor(const char* query, const Args&... args) {
    return prepare<T, Rest...>(query).execute_cursor(args...);
  }

  bool isTableExists(const char* tableName) const {
    const char* sql = "SELECT COUNT(name) FROM sqlite_master WHERE type='table' AND name=?;";
    const int val = this->prepare<int>(sql).execute_value(tableName);
    return val > 0;
  }
  void dropTable(const char* tableName) {
    const std::string sql = "DROP TABLE IF EXISTS " + std::string(tableName) + ";";
    execute(sql.c_str());
  }
  void dropTableData(const char* tableName, bool resetAutoIncrement = true) {
    if (!isTableExists(tableName)) return;
    std::string sql = "DELETE FROM " + std::string(tableName) + ";";
    execute(sql.c_str());
    if (resetAutoIncrement) {
      sql = "DELETE FROM sqlite_sequence WHERE name='" + std::string(tableName) + "';";
      execute(sql.c_str());
    }
  }

  enum IdentifierType { FieldName, TableName, FieldValue };

  static std::string escapeIdentifier(const std::string &identifier, IdentifierType type = FieldValue) {
    if (identifier.empty()) {
      return identifier;
    }

    std::string escaped = identifier;

    switch (type) {
      case FieldName:
      case TableName: {
        // Escape double quotes (" → "")
        size_t pos = 0;
        while ((pos = escaped.find('"', pos)) != std::string::npos) {
          escaped.replace(pos, 1, "\"\"");
          pos += 2;
        }

        // Handle dots (table.column → "table"."column")
        pos = 0;
        while ((pos = escaped.find('.', pos)) != std::string::npos) {
          escaped.replace(pos, 1, "\".\"");
          pos += 3;
        }

        // Wrap in double quotes (if not already)
        if (escaped.front() != '"') escaped.insert(0, 1, '"');
        if (escaped.back() != '"') escaped.append(1, '"');
      } break;

      case FieldValue: {
        // Escape single quotes (' → '')
        size_t pos = 0;
        while ((pos = escaped.find('\'', pos)) != std::string::npos) {
          escaped.replace(pos, 1, "''");
          pos += 2;
        }

        // Wrap in single quotes (if not already)
        if (escaped.front() != '\'') escaped.insert(0, 1, '\'');
        if (escaped.back() != '\'') escaped.append(1, '\'');
      } break;
    }

    return escaped;
  }

  template <typename T> class PreparedStatement;

  template <typename T>
  PreparedStatement<T> query(const char* sql) {
    return PreparedStatement<T>(db_, sql);
  }

  template <typename T> class ColumnBuilder;
  class TableBuilder;

  TableBuilder create_table(const std::string& name);

 private:

  sqlite3* db_;
  template <typename T> friend class PreparedStatement;
};

// =================== Table Builder ===================
class Sqlite::TableBuilder {
public:
  explicit TableBuilder(std::string tableName, Sqlite &db)
        : tableName_(std::move(tableName))
        ,  db_(db)
  {}

  TableBuilder* operator->() { return this; }

  TableBuilder& if_not_exists() {
    is_if_not_exists_ = "IF NOT EXISTS";
    return *this;
  }

  template <typename T>
  ColumnBuilder<T> column(const std::string& name) {
    return ColumnBuilder<T>(this, name);
  }

  void execute() {
    auto sql = build_sql();
    // printf("Executing: %s\n", sql.c_str());
    // fflush(stdout);
    db_.prepare(sql.c_str()).execute();
  }

private:
  std::string build_sql() const {
    std::ostringstream oss;
    oss << "CREATE TABLE ";
    if (!is_if_not_exists_.empty()) oss << is_if_not_exists_ << " ";
    oss << tableName_ << " (\n";

    for (size_t i = 0; i < columns_.size(); ++i) {
      const auto& col = columns_[i];
      oss << "  " << col.name << " ";
      switch (col.type) {
        case ColumnType::TEXT   : oss << "TEXT"      ; break;
        case ColumnType::INTEGER: oss << "INTEGER"   ; break;
        case ColumnType::Bool   : oss << "INTEGER(1)"; break;
        case ColumnType::REAL   : oss << "REAL"      ; break;
        case ColumnType::BLOB   : oss << "BLOB"      ; break;
      }

      if (col.type != ColumnType::Bool && col.options.size > 0) {
        oss << "(" << col.options.size << ")";
      }

      if (col.options.is_not_null) {
        oss << " NOT NULL";
      }

      if (!col.options.default_value.empty() && col.options.default_value != "AUTOINCREMENT") {
        oss << " DEFAULT " << col.options.default_value;
      }

      if (col.options.is_primary_key) {
        oss << " PRIMARY KEY";
        if (col.options.default_value == "AUTOINCREMENT") {
          oss << " AUTOINCREMENT";
        }
      }

      if (i != columns_.size() - 1) {
        oss << ",";
      }
      oss << "\n";
    }

    oss << ");\n";
    return oss.str();
  }

private:
  template <typename U> friend class Sqlite::ColumnBuilder;
  // friend class Sqlite::ColumnBuilder;

  // --- CreateTableStatement DSL for SQLite table creation ---
  enum class ColumnType {
    TEXT,
    INTEGER,
    Bool,
    REAL,
    BLOB
  };
  struct ColumnOptions {
    bool is_primary_key = false;
    bool is_not_null = false;
    std::string default_value;
    int size = 0;
  };

  struct Column {
    std::string name;
    ColumnType type;
    ColumnOptions options;
  };


  std::string tableName_;
  std::string is_if_not_exists_;
  std::vector<Column> columns_;

  Sqlite& db_;
};

// =================== Column Builder ===================
template <typename T>
class Sqlite::ColumnBuilder {
public:
  ColumnBuilder(TableBuilder* parent, const std::string& name)
      : parent_(parent)
  {
    using ColumnType = Sqlite::TableBuilder::ColumnType;
    if constexpr (std::is_same_v<T, std::string>) {
      col_.type = ColumnType::TEXT;
    } else if constexpr (std::is_same_v<T, unsigned char*>) {
      col_.type = ColumnType::BLOB;
    } else if constexpr (std::is_same_v<T, bool>) {
      col_.type = ColumnType::Bool;
      col_.options.size = 1;
    } else if constexpr (std::is_floating_point_v<T>) {
      col_.type = ColumnType::REAL;
    } else if constexpr (std::is_integral_v<T>) {
      col_.type = ColumnType::INTEGER;
    } else if constexpr (std::is_same_v<T, std::vector<char>>) {
      col_.type = ColumnType::BLOB;
    } else {
      static_assert(sizeof(T) == -1, "Unsupported column type");
    }

    col_.name                   = name ;
    col_.options.is_primary_key = false;
    col_.options.is_not_null    = false;
  }

  ColumnBuilder& not_null() {
    col_.options.is_not_null = true;
    return *this;
  }

  ColumnBuilder& default_value(const T &value) {
    std::ostringstream oss;

    if constexpr (std::is_same_v<T, std::string>) {
      oss << escapeIdentifier(value);
    } else if constexpr (std::is_same_v<T, bool>) {
      oss << (value ? 1 : 0);
    } else if constexpr (std::is_integral<T>::value) {
      oss << value;
    }

    col_.options.default_value = oss.str();
    return *this;
  }
  ColumnBuilder& primary_key() {
    col_.options.is_primary_key = true;
    return *this;
  }
  ColumnBuilder& autoincrement() {
    using ColumnType = Sqlite::TableBuilder::ColumnType;
    if (col_.type != ColumnType::INTEGER) {
      throw std::runtime_error("AUTOINCREMENT only allowed on INTEGER columns");
    }
    col_.options.default_value = "AUTOINCREMENT";
    return *this;
  }
  ColumnBuilder& size(int value) {
    static_assert(std::is_same_v<T, std::string>, "Only string columns can have a size.");
    col_.options.size = value;
    return *this;
  }

  TableBuilder* operator->() {
    parent_->columns_.push_back(col_);
    return parent_;
  }

  template <typename TT>
  ColumnBuilder<TT> column(const std::string& name) {
    parent_->columns_.push_back(col_);
    return ColumnBuilder<TT>(parent_, name);
  }

  void execute() const {
    parent_->columns_.push_back(col_);
    parent_->execute();
  }

private:
  Sqlite::TableBuilder* parent_;
  Sqlite::TableBuilder::Column col_;

  template <typename U> struct ColumnType;
  template <typename U> struct DefaultValue;
  // friend class Sqlite::TableBuilder<typename BuilderType::Sqlite::TableBuilder<T>>;
};


inline Sqlite::TableBuilder Sqlite::create_table(const std::string &name) {
  return TableBuilder(name, *this);
}

// =================== Struct Mapping Support ===================
template <typename T>
class SqliteStruct {
public:
  using FieldSetter = std::function<void(T*, sqlite3_value*)>;

  struct FieldMapping {
    const char* columnName;
    FieldSetter setter;

    FieldMapping() = default;
    FieldMapping(const char* name, FieldSetter func)
        : columnName(name), setter(func) {}
  };

  template <typename FieldType>
  SqliteStruct<T>& map(FieldType T::*field, const char* columnName) {
    return addMapping<FieldType>(field, columnName);
  }

  // template <typename FieldType>
  //   SqliteStruct<T>& map(FieldType T::*field, const char* columnName) {
  //   FieldMapping mapping;
  //   mapping.columnName = columnName;
  //   mapping.setter = [field](T* obj, sqlite3_value* value) {
  //     if constexpr (std::is_same_v<FieldType, int>) {
  //       obj->*field = sqlite3_value_int(value);
  //     } else if constexpr (std::is_same_v<FieldType, std::string>) {
  //       obj->*field = std::string((const char*)value);
  //     } else if constexpr (std::is_same_v<FieldType, bool>) {
  //       obj->*field = *(int*)value != 0;
  //     } else if constexpr (std::is_same_v<FieldType, const char*>) {
  //       obj->*field = (const char*)value;
  //     } else if constexpr (std::is_same_v<FieldType, unsigned char*>) {
  //       obj->*field = (unsigned char*)value;
  //     } else {
  //       // 可扩展其他类型
  //     }
  //   };
  //
  //   mappings_.push_back(mapping);
  //   return *this;
  // }

  static const std::vector<FieldMapping>& getRegisteredMappings() {
      static std::vector<FieldMapping> registeredMappings;
      if (registeredMappings.empty()) {
        SqliteStruct<T> reg;
        T::registerFields(reg);  // 用户注册字段
        registeredMappings = reg.mappings_;
      }
      return registeredMappings;
  }

private:
  template <typename TT>
  SqliteStruct<T>& addMapping(TT T::*field, const char* columnName) {
    FieldMapping mapping;
    mapping.columnName = columnName;
    mapping.setter = [field](T* obj, sqlite3_value* value) {
      obj->*field = get_column_value<TT>(value);
    };
    mappings_.push_back(mapping);
    return *this;
  }

private:
  std::vector<FieldMapping> mappings_;
};

// =================== PreparedStatement ===================
template <typename T> // , typename R
class Sqlite::PreparedStatement {
 public:
  PreparedStatement(sqlite3* db, const char* query)
      : stmt_(new_sqlite3_stmt(db, query), sqlite3_stmt_deleter) {}

  PreparedStatement(PreparedStatement&& rhs) : stmt_(rhs.stmt_) { rhs.stmt_ = nullptr; }

  PreparedStatement() = delete;
  PreparedStatement(PreparedStatement& rhs) = default;
  ~PreparedStatement() = default;

  template <typename... Args>
  PreparedStatement<T>& bind(const Args&... args) {
    verify(sqlite3_reset(stmt_.get()));
    bind_values(1, args...);
    return *this;
  }

  template <
      typename std::enable_if<!std::is_same<T, void>::value>::type*& = enabler,
      typename... Args>
  std::vector<T> execute(const Args&... args) {
    bind(args...);
    // verify(sqlite3_step(stmt_.get()), SQLITE_DONE);

    std::vector<T> results;
    auto cursor = execute_cursor(args...);
    for (auto it = cursor.begin(); it != cursor.end(); ++it) {
      T obj{};
      auto& mappings = SqliteStruct<T>::getRegisteredMappings();
      const int count = sqlite3_column_count(stmt_.get());
      for  (int i = 0; i < count; i++) {
        const char* colName = sqlite3_column_name(stmt_.get(), i);
        if (colName == nullptr) continue;
        // Check if the column name is registered in the mappings
        auto it = std::find_if(mappings.begin(), mappings.end(),
                               [colName](const typename SqliteStruct<T>::FieldMapping& mapping) {
                                 return strcmp(mapping.columnName, colName) == 0;
                               });
        if (it == mappings.end()) continue;
        // Call the setter function for the column
        sqlite3_value* value = sqlite3_column_value(stmt_.get(), i);
        it->setter(&obj, value);
      }
      results.push_back(std::move(obj));
    }
    return results;
  }


  template <typename... Args>
  T execute_value(const Args&... args) {
    auto cursor = execute_cursor(args...);
    return *cursor.begin();
  }

  template <typename... Args>
  Cursor<T> execute_cursor(const Args&... args) {
    bind(args...);
    return Cursor<T>(stmt_);
  }
 private:
  PreparedStatement& operator=(const PreparedStatement& rhs);

  sqlite3_stmt* new_sqlite3_stmt(sqlite3* db, const char* query) {
    sqlite3_stmt* p = nullptr;
    verify(sqlite3_prepare_v2(db, query, static_cast<int>(strlen(query)), &p,
                           nullptr));

    return p;
  }

  void bind_values(int col) {}

  template <typename Arg, typename... ArgRest>
  void bind_values(int col, const Arg& val, const ArgRest&... rest) {
    bind_value(stmt_.get(), col, val);
    bind_values(col + 1, rest...);
  }

  std::shared_ptr<sqlite3_stmt> stmt_;
};


}  // namespace sqlitelib

#endif
