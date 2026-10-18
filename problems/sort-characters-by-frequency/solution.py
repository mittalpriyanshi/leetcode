class Solution:
    def frequencySort(self, s: str) -> str:
        mp= {}
        for x in s:
            mp[x] = mp.get(x,0)+1
        mp = sorted(mp.items(), key=lambda x: -x[1])
        return ''.join([key * val for key,val in mp])
        
