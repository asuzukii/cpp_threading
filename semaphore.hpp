#include <atomic>
#include <condition_variable>
#include <mutex>

class Semaphore {
  std::mutex mtx_;
  std::condition_variable cv_;
  int counter_;

 public:
  Semaphore() : counter_(0) {}
  Semaphore(int default_count) : counter_(default_count) {}
  Semaphore(Semaphore const&) = delete;
  Semaphore(Semaphore&&) = delete;
  Semaphore& operator=(Semaphore const&) = delete;
  Semaphore& operator=(Semaphore&&) = delete;
  ~Semaphore() = default;
  void release() {
    std::lock_guard<std::mutex> lg(mtx_);
    ++counter_;
    cv_.notify_one();
  }
  void wait() {
    std::unique_lock<std::mutex> ul(mtx_);
    cv_.wait(ul, [this] { counter_ > 0; });
    --counter_;
  }
};