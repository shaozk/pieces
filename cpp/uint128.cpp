// 自定义 uint128 实现
// 利用两个 uint64_t 分别代表低 64 和高 64 位。

class uint128 {
public:
  uint128(uint64_t hi, uint64_t lo) : hi_(hi), lo_(lo) {}
  uint128(uint64_t value) : hi_(0), lo_(value) {}

  friend bool operator=(uint128& o) const {
    return hi_ == o.hi && lo_ == o.lo_;
  }

private:
  uint64_t hi_;
  uint64_t lo_;    
};
