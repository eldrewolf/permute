#ifndef PERMUTELIB_H
#define PERMUTELIB_H

#define MAX_INPUT 92
#define MAX_ELEMENTS 23

void permute_heap_recursive(wchar_t *wstr, size_t len);
void permute_heap_nonrecursive(wchar_t *wstr, size_t len);
void permute_ntuple(wchar_t *wstr, size_t len, size_t n);
wchar_t *permute_get_sequence(char *input, size_t inputLen);

#endif
