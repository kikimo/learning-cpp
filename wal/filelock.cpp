#include <string>
#include <cerrno>
#include <chrono>
#include <cstring>
#include <fcntl.h>
#include <iostream>
#include <sys/file.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <thread>
#include <unistd.h>

class FileLock {
public:
  void lock();
  bool tryLock();
  bool unlock();

private:
  std::string lockPath_;
};

void lock(int fd) {
  if (flock(fd, LOCK_EX) != 0) {
    std::cout << "error acquiring lock: " << std::strerror(errno) << '\n';
  } else {
    std::cout << "lock acuireed\n";
  }
}

void unlock(int fd) {
  if (flock(fd, LOCK_UN) != 0) {
    std::cout << "failed unlick file" << strerror(errno) << '\n';
  } else {
    std::cout << "file unlocked\n";
  }
}

int main() {
  int fd = open("./lock", O_WRONLY | O_CREAT);
  if (fd < 0) {
    std::cout << "error open lock file: " << std::strerror(errno) << '\n';
    return 1;
  } else {
    lock(fd);
  }

  std::this_thread::sleep_for(std::chrono::seconds(16));
  unlock(fd);
  if (close(fd) < 0) {
    std::cout << "error closing file: " << std::strerror(errno) << '\n';
  } else {
    std::cout << "file closed\n";
  }

  return 0;
}
