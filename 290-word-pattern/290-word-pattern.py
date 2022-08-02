class Solution:
    def wordPattern(self, pattern: str, s: str) -> bool:
        if len(pattern) != len(s.split()):
            return False
        D1 = {}
        D2 = {}
        for c, word in zip(pattern, s.split()):
            if c in D1:
                if D1[c] != word:
                    return False
            if word in D2:
                if D2[word] != c:
                    return False
            D1[c] = word
            D2[word] = c
        return True;
                