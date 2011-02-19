#ifndef CCAN_FAILTEST_OVERRIDE_H
#define CCAN_FAILTEST_OVERRIDE_H
/* This file is included before the source file to test. */

/* Replacement of allocators. */
#include <stdlib.h>

#undef calloc
#define calloc(nmemb, size)	\
	failtest_calloc((nmemb), (size), __FILE__, __LINE__)

#undef malloc
#define malloc(size)	\
	failtest_malloc((size), __FILE__, __LINE__)

#undef realloc
#define realloc(ptr, size)					\
	failtest_realloc((ptr), (size), __FILE__, __LINE__)

#undef free
#define free(ptr) \
	failtest_free(ptr)

/* Replacement of I/O. */
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#undef open
#define open(pathname, ...) \
	failtest_open((pathname), __FILE__, __LINE__, __VA_ARGS__)

#undef pipe
#define pipe(pipefd) \
	failtest_pipe((pipefd), __FILE__, __LINE__)

#undef read
#define read(fd, buf, count) \
	failtest_read((fd), (buf), (count), __FILE__, __LINE__)

#undef write
#define write(fd, buf, count) \
	failtest_write((fd), (buf), (count), __FILE__, __LINE__)

#undef pread
#define pread(fd, buf, count, off)				\
	failtest_pread((fd), (buf), (count), (off), __FILE__, __LINE__)

#undef pwrite
#define pwrite(fd, buf, count, off)					\
	failtest_pwrite((fd), (buf), (count), (off), __FILE__, __LINE__)

#undef close
#define close(fd) failtest_close(fd, __FILE__, __LINE__)

#undef fcntl
#define fcntl(fd, ...) failtest_fcntl((fd), __FILE__, __LINE__, __VA_ARGS__)

#include <ccan/failtest/failtest_proto.h>

#endif /* CCAN_FAILTEST_OVERRIDE_H */