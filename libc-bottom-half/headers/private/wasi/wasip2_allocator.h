#ifndef WASIP2_ALLOCATOR_H
#define WASIP2_ALLOCATOR_H

#include <inttypes.h>

void wasip2_allocator_reset();

void wasip2_allocator_set(void *buffer, size_t len);

void* wasip2_allocator_alloc(size_t len);

int wasip2_allocator_is_buffer(void *buf);

#endif