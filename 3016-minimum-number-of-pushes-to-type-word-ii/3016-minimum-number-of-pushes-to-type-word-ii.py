class Solution:
    def minimumPushes(self, word: str) -> int:
        return sum(
            (i//8 +1)*v  for i,v in enumerate(sorted(Counter(word).values(), reverse=True))
        )
        