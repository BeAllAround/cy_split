
long long str_cmp(const char* str, const char* sub) {
        long long i = 0;
        while(*str != 0) {
                const char* _str = str;
                const char* _sub = sub;
                while(*_str != 0 && *_sub != 0 && *_str == *_sub) {
                        _str++, _sub++;
                }
                if(*_sub==0)
                        return i;
                str++, i++;
        }
        return -1;
}

extern long long str_cmp(const char*, const char*);
