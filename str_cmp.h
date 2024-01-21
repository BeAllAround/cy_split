
long long str_cmp(const char* str, const char* sub) {
        long long i = 0;
        while(*str != 0) {
                const char* _sub = sub;
                const char* _str = str;
                while(*_str != 0 && *_sub != 0) {
                        if(*_str != *_sub){
                                break;
                        }
                        _str++, _sub++;
                }
                if(*_sub==0)
                        return i;
                str++, i++;
        }
        return -1;
}

extern long long str_cmp(const char*, const char*);
