#include <filesystem>
#include <iostream>
#include <regex>

int main() {
  using std::filesystem::path;
  path walRoot("/tmp/wal");
  for (const auto &entry : std::filesystem::directory_iterator(walRoot)) {
    std::cout << "extension:" << entry.path().extension() << '\n';
    if (entry.path().has_extension() && entry.path().extension() == ".wal") {
      auto filename = entry.path().filename().string();
      std::cout << "filename:" << filename << '\n';
      auto pos = filename.rfind(".wal");
      std::cout << "pos:" << pos << '\n';
      filename.replace(pos, 4, "");
      std::cout << "filename: " << filename << '\n';
      auto index = std::stoll(filename);
      std::cout << "index:" << index << '\n';
    }
  }

  return 0;
}