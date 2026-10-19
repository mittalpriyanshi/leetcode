class Solution:
    def frequencySort(self, s: str) -> str:
        mp= {}
        for x in s:
            mp[x] = mp.get(x,0)+1
        freq = sorted(mp.items(), key=lambda x: -x[1])
        copy=""
        for ch, count in freq:
            copy+=ch*count
        return copy
        
