import difflib

class Assert:
    assert_count = 0

    @classmethod
    def assert_v(cls, a, b, n = 0):
        # print(str(a), str(b))
        # print ( ''.join(list(difflib.ndiff(str(b), str(a)) )) )
        assert a == b
        if n == 0:
            print("assert #" + str(cls.assert_count))
            cls.assert_count += 1
        else:
            print("assert #" + str(n))
