#include <netdb.h>
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>

int main(int c, char **v) {
  int status, fd;
  struct addrinfo hints;
  struct addrinfo *res;

  const char query[] = "GET / HTTP/1.0\r\n"
                       "Host: www.google.com\r\n"
                       "\r\n";
  const char hostname[] = "www.google.com";

  memset(&hints, 0, sizeof(hints));
  hints.ai_family = AF_UNSPEC;
  hints.ai_socktype = SOCK_STREAM;

  status = getaddrinfo(hostname, "80", &hints, &res);

  if ((status = getaddrinfo(hostname, "80", &hints, &res)) != 0) {
    printf("status: %d, err: %s\n", status, gai_strerror(status));
  }

  fd = socket(res->ai_family, res->ai_socktype, res->ai_protocol);

  close(fd);
}
