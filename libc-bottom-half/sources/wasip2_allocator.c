#include <wasi/wasip2_allocator.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    void* buffer;
    size_t len;
    int used;
} wasip2_allocator_t;

static _Thread_local wasip2_allocator_t _allocator = {0};

void wasip2_allocator_set(void *buffer, size_t len)
{
    _allocator.buffer = buffer;
    _allocator.len = len;
    _allocator.used = 0;
}

void wasip2_allocator_reset()
{
    memset(&_allocator, 0, sizeof(_allocator));
}

void* wasip2_allocator_alloc(size_t len)
{
    if (_allocator.used == 0 && len <= _allocator.len) {
        void *ret = _allocator.buffer;
        _allocator.used = 1;
        return ret;
    }
    return malloc(len);
}

int wasip2_allocator_is_buffer(void *buf)
{
    return buf == _allocator.buffer;
}