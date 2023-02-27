#include <openssl/sha.h>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
  string mark;
  ifstream file("https://quod.lib.umich.edu/cgi/r/rsv/rsv-idx?type=DIV1&byte=4697892");
  if (file.is_open()) {
    string line;
    while (getline(file, line)) {
      mark += line;
    }
    file.close();
  }
  // Compute the SHA-256 hash of the book of Mark
  unsigned char hash[SHA-256_DIGEST_LENGTH];
  SHA256((const unsigned char*) mark.c_str(), mark.length(), hash);
  for (int i = 0; i < SHA-256_DIGEST_LENGTH; i++) {
    printf("%02x", hash[i]);
  }
  cout << endl;

  return 0;
}
