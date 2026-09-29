class Solution:
    def topKFrequent(self, nums: list[int], k: int) -> list[int]:
       mp={} #unorderd map
       ans =[] #vector
       for x in nums:
        mp[x]= mp.get(x,0)+1
       while k>0:
        maxi =-1
        max_num = None
        for num in mp:
            if mp[num] > maxi:
                maxi = mp[num]
                max_num = num

        ans.append(max_num)
        del mp[max_num]
        k-=1
       return ans

