long long str_cmp(register const char* str, const char* sub) {
        long long i = 0;
        for(;*str != 0; str++, i++) {
        	const register char* _str = str;
        	const register char* _sub = sub;
		if(*_str != *_sub) continue;
                while(*_str != 0 && *_sub != 0) {
			if(*_str != *_sub) break;
                        _str++, _sub++;
                }
                if(*_sub==0)
                        return i;
        }
        return -1;
}

extern long long str_cmp(register const char*, const char*);
