void
permute_heap_recursive(wchar_t *wstr, size_t len)
{
	if (len == 1) {
		wprintf(L"%ls\n", wstr);
	} else {
		wchar_t tmp;
		for (size_t i = 0; i < len; i++) {
			permute_heap_recursive(wstr, len - 1);

			if (len % 2 == 0) {
				tmp = wstr[i];
				wstr[i] = wstr[len - 1];
				wstr[len - 1] = tmp;
			} else {
				tmp = wstr[0];
				wstr[0] = wstr[len - 1];
				wstr[len - 1] = tmp;
			}
		}
	}
}

void
permute_heap_nonrecursive(wchar_t *wstr, size_t len)
{
	size_t *p = calloc(len, sizeof(size_t));
	wprintf(L"%ls\n", wstr);

	size_t i = 0;
	while (i < len) {
		if (p[i] < i) {
			if (i % 2 == 0) {
				wstr[0] ^= wstr[i];
				wstr[i] ^= wstr[0];
				wstr[0] ^= wstr[i];
			} else {
				wstr[p[i]] ^= wstr[i];
				wstr[i] ^= wstr[p[i]];
				wstr[p[i]] ^= wstr[i];
			}
			wprintf(L"%ls\n", wstr);
			p[i]++;
			i = 0;
		} else {
			p[i] = 0;
			i++;
		}
	}
}

void
permute_ntuple(wchar_t *wstr, size_t len, size_t n)
{
	size_t *p = calloc(n, sizeof(size_t));
	bool inc = false;

	for (size_t i = 0, j = (size_t) pow((double) len, (double) n); i < j; i++) {
		for (size_t k = 0; k < n; k++) {
			if (k == 0) {
				p[k] = i % len;
			} else {
				if (inc) {
					if (p[k] + 1 != len) {
						inc = false;
					}
					p[k] = (p[k] + 1) % len;
				}
			}
			wprintf(L"%lc", wstr[p[k]]);
		}
		if (p[0] + 1 == len) {
			inc = true;
		}
		wprintf(L"\n");
	}
}

wchar_t *
permute_get_sequence(char *input, size_t inputLen)
{
	mblen(NULL, 0);
	mbtowc(NULL, NULL, 0);

	wchar_t *seq = malloc(sizeof(wchar_t) * MAX_INPUT);
	int len;
	wchar_t wc;

	for (size_t i = 0; i < inputLen; i++) {
		if ((unsigned char) input[i] < 0xC0) {
			mbtowc(&wc, &input[i], 1);
		} else {
			len = mblen(&input[i], 4);
			mbtowc(&wc, &input[i], len);
			i += len - 1;
		}
		size_t j = 0;
		while (seq[j]) {
			if (seq[j] == wc) break;
			j++;
		}
		if (seq[j] == '\0') {
			seq[j] = wc;
			seq[j + 1] = '\0';
		}
	}
	return seq;
}
