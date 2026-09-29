class Solution:
    def groupAnagrams(self, strs: list[str]) -> list[list[str]]:
        mp = defaultdict(list)
        for x in strs:
            sortedCopy = "".join(sorted(x))
            mp[sortedCopy].append(x)
        return list(mp.values())
            